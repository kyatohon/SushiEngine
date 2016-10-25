#include "GameSceneManager.h"

namespace SushiEngine
{
	/// See the header file reguarding unique_ptr
	std::unique_ptr<GameSceneManager> GameSceneManager::gameInstance(nullptr);

	//Creates the GameSceneManager.
	GameSceneManager::GameSceneManager() {
		Debug::Log(EMessageType::S_INFO, "GameSceneManager() Created", __FILENAME__, __LINE__);
	}

	//Destroys the GameSceneManager.
	GameSceneManager::~GameSceneManager() {
		Debug::Log(EMessageType::S_INFO, "GameSceneManager() Destroyed", __FILENAME__, __LINE__);

		delete(window);
		delete(renderer);
	}

	//Updates the current scene and handles if the user has attempted to close the window.
	void GameSceneManager::Update()
	{
		currentScene->Update();
	}

	//Renders the current scene.
	void GameSceneManager::Render()
	{
		currentScene->Render();
	}

	//Returns the current instance of the GameSceneManager.
	GameSceneManager* GameSceneManager::GetInstance() {
		if (gameInstance == nullptr) {
			gameInstance.reset(new GameSceneManager());
		}		
		return gameInstance.get();
	}

	static void CloseWindowCallback(GLFWwindow* glfwWindow);

	//Initialzes all the components necessary for a game scene to function properly.
	bool GameSceneManager::Initialize()
	{
		Debug::Log(EMessageType::S_INFO, "GameSceneManager() Initialize", __FILENAME__, __LINE__);
		
		//Instantiate main components - order is important; a renderer is dependent on a window
		window = new Window("Hau5tastic", 300, 300);
		renderer = new VkRenderer();

		//initialize glfw callbacks
		glfwSetWindowUserPointer(window->GetWindowHandle(), this);
		glfwSetWindowCloseCallback(window->GetWindowHandle(), CloseWindowCallback);

		// Key and Character are both for Keyboard Event Polling, see documentation for the difference between the two.
		glfwSetKeyCallback(window->GetWindowHandle(), InputManager::KeyCallback);
		// glfwSetCharCallback(glfwWindow, character_callback);
		glfwSetMouseButtonCallback(window->GetWindowHandle(), InputManager::ClickCallback);
		
		return true;
	}
	
	//Initializes and runs the game. Contains the main loop.
	void GameSceneManager::Run(Scene* startingScene)
	{
		isRunning = Initialize();
		currentScene = startingScene;
		currentScene->Initialize();

		//The main loop of the whole program.
		while (isRunning)
		{
			Update();
			Render();

			//Gracefully shutdown scene and window
			if (glfwWindowShouldClose(window->GetWindowHandle())) {
				currentScene->Destroy();
				window->Destroy();
				isRunning = false;
			}
		}
	}
	
	//Returns the window instance.
	Window* GameSceneManager::getWindowInstance() {
		return window;
	}

	// ---- Callback Functions ---
	static void CloseWindowCallback(GLFWwindow* glfwWindow) {
		glfwSetWindowShouldClose(glfwWindow, GLFW_TRUE);
	}
}