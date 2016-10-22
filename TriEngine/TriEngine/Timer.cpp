// Currently untested, don't use yet.

#include "Timer.h"

namespace TriEngine {

	Timer::Timer() :prevTicks(0), currTicks(0) {}

	Timer::~Timer() {}

	void Timer::UpdateFrameTicks() {
		prevTicks = currTicks;
		currTicks = glfwGetTime();
	}

	void Timer::Start() {
		prevTicks = glfwGetTime();
		currTicks = glfwGetTime();
	}

	float Timer::GetDeltaTime() const {
		return (currTicks - prevTicks) / 1000.0f;
	}

	unsigned int Timer::GetSleepTime(const unsigned int fps) const {
		unsigned int milliSecsPerFrame = 1000 / fps;
		if (milliSecsPerFrame == 0) {
			return 0;
		}

		unsigned int sleepTime = milliSecsPerFrame - (glfwGetTime() - currTicks);
		if (sleepTime > milliSecsPerFrame) {
			return milliSecsPerFrame;
		}

		return sleepTime;
	}
}