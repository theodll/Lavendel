#include "lvpch.h"
#include "ImGuiLayer.h"
#include <SDL3/SDL.h>
#include "ImGuiRenderer.h"
#include "Lavendel/Log.h"

namespace Lavendel {
	
	
	ImGuiLayer::~ImGuiLayer() 
	{
		m_Renderer->Shutdown();
	}

	void ImGuiLayer::OnAttach()
	{
		m_Renderer = std::make_shared<ImGuiRenderer>(
			Lavendel::RenderAPI::Renderer::Get()->getSwapChain(),
			Lavendel::RenderAPI::Renderer::Get()->getDevice(),
			Lavendel::RenderAPI::Renderer::Get()->getDevice()->getWindow().GetSDLWindow()
		);

		// Setup Dear ImGui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		// io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; // Commented out - may not be available in all versions
		
		// Setup Dear ImGui style
		ImGui::StyleColorsDark();

		// Initialize platform/renderer backends
		m_Renderer->Init();

		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
		
		LV_CORE_INFO("ImGuiLayer attached");
	}

	void ImGuiLayer::OnDetach()
	{
		m_Renderer->Shutdown();
		ImGui::DestroyContext();
		LV_CORE_INFO("ImGuiLayer detached");
	}

	void ImGuiLayer::OnEvent(Event& event)
	{
		// Handle ImGui input events
		ImGuiIO& io = ImGui::GetIO();
		// Event handling can be extended based on specific event types
	}

	void ImGuiLayer::OnUpdate()
	{
		// Begin ImGui frame
		m_Renderer->Begin();

		// Render demo widget
		m_DemoWidget.OnRender();

		// End ImGui frame (prepares draw data)
		m_Renderer->End();
	}

	void ImGuiLayer::Begin()
	{
		m_Renderer->Begin();
	}

	void ImGuiLayer::End()
	{
		m_Renderer->End();
	}
}
