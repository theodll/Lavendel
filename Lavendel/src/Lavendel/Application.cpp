#include "lvpch.h"
#include "Application.h"
#include "Renderer/Renderer.h"

// CONSTRUCTOR 
namespace Lavendel {



	Application::Application()
	{
		m_Renderer = std::make_shared<RenderAPI::Renderer>(m_Window);
	}

	Application::~Application()
	{
	
	}

	// PUBLIC METHODS
	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer)
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer)
	}

	void Lavendel::Application::Run()
	{
		// 1st and 2nd param are width and height, 3rd is title, 4th is resizable bool

		while (!m_Window.ShouldClose())
		{
			m_Window.PollEvents();
			m_Renderer->drawFrame();
		}
	}

}
