#include "lvpch.h"
#include "ImGuiLayer.h"
#include <SDL3/SDL.h>
#include "ImGuiRenderer.h"
#include "Log.h"

namespace Lavendel {
	ImGuiLayer::ImGuiLayer(std::shared_ptr<RenderAPI::SwapChain>& swapchain, std::shared_ptr<RenderAPI::GPUDevice>& device) : Layer("ImGuiLayer"), m_Swapchain(swapchain), m_Device(device)
	{
	}
	
	ImGuiLayer::~ImGuiLayer() 
	{
	}

	void ImGuiLayer::OnAttach()
	{
		
		m_Renderer.Init(m_Device->getInstance(),
						m_Device->getPhysicalDevice(),
						m_Device->device(),
						m_Device->getGraphicsQueue(),
						m_Device->getQueueFamilyIndex(),
						m_Swapchain->getRenderPass()
						);

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		
		LV_CORE_INFO("ImGuiLayer attached");

	}

	void ImGuiLayer::OnDetach()
	{
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

		m_Renderer.Render();
	}
