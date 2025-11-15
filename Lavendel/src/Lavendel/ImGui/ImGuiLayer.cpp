#include "lvpch.h"
#include "ImGuiLayer.h"
#include "Log.h"

namespace Lavendel {
	ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer")
	{
	}
	
	ImGuiLayer::~ImGuiLayer() 
	{
	}

	void ImGuiLayer::OnAttach()
	{
		LV_CORE_INFO("ImGuiLayer attached");
		// Note: Renderer initialization requires Vulkan objects from the application
		// This should be called after the Renderer is fully initialized
	}

	void ImGuiLayer::OnDetach()
	{
		m_Renderer.Shutdown();
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
		// ImGui rendering happens in Begin/End calls
	}

	void ImGuiLayer::Begin()
	{
		m_Renderer.Begin();
	}

	void ImGuiLayer::End()
	{
		m_Renderer.End();
	}
}