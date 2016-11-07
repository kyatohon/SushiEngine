//AbstractRenderer - The purpose of an abstract renderer is to make it possible
//to extend different types of Renderers which use different graphical libraries,
//while maintaining a consistent interface amongst all of them.

#ifndef ABSTRACT_RENDERER_H
#define ABSTRACT_RENDERER_H

#include "Window.h"

namespace SushiEngine {
	class AbstractRenderer
	{
	public:
		AbstractRenderer(Window*);
		virtual ~AbstractRenderer() = 0;

		virtual void render() = 0;

	protected:
		Window* window;
	};
}
#endif