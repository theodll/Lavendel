#include "Application.h"
#include "Renderer/Window.h"

// CONSTRUCTOR 

Lavendel::Application::Application()
{
}

Lavendel::Application::~Application()
{
}

// PUBLIC METHODS

void Lavendel::Application::Run()
{
	// 1st and 2nd param are width and height, 3rd is title, 4th is resizable bool
	Lavendel::RendererAPI::Window window(1280, 720, "Lavendel Engine", false);
	
	while (!window.ShouldClose())
	{
		window.PollEvents();
	}
}

