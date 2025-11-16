#include "lvpch.h"
#include "Application.h"
#include "Renderer/Renderer.h"
#include "Log.h"

// CONSTRUCTOR 
namespace Lavendel {



	Application::Application()
	{
		m_Renderer = std::make_shared<RenderAPI::Renderer>(m_Window);
		
		
		m_ImGuiLayer = new ImGuiLayer(&m_Renderer->getPipeline(), &m_Renderer->getDevice());
		PushOverlay(m_ImGuiLayer);
	}

	Application::~Application()
	{
	
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		// dispatcher.Dispatch<WindowCloseEvent>([](WindowCloseEvent& e) { return true; });
		//LV_CORE_TRACE("{0}", e.ToString());

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.IsHandled())
				break;
		}
	}



	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
	}

	void Lavendel::Application::Run()
	{

		while (!m_Window.ShouldClose())
		{
			m_Window.PollEvents();
			
			m_Renderer->beginImGuiFrame();
			
			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();
			
			m_Renderer->endImGuiFrame();
			m_Renderer->drawFrame();
		};
	}

}
