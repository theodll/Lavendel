#pragma once

#include "lvpch.h"
#include "imgui.h"
#include "Lavendel/Renderer/Core/Swapchain.h"
#include "backends/imgui_impl_vulkan.h"
#include "backends/imgui_impl_sdl3.h"

struct VkDescriptorPool_T;
struct VkCommandBuffer_T;
struct VkRenderPass_T;
struct VkFramebuffer_T;

namespace Lavendel {
	class ImGuiRenderer {
	public:
		ImGuiRenderer(std::shared_ptr<RenderAPI::SwapChain>& swapchain);
		~ImGuiRenderer() = default;
		
		void Init(VkInstance instance, VkPhysicalDevice physicalDevice, VkDevice device, 
		          VkQueue queue, uint32_t queueFamily, VkRenderPass renderPass);
		void Render(VkCommandBuffer& commandBuffer);
		void Shutdown();
		void Begin();
		void End();
		
	private:
		RenderAPI::SwapChain& m_Swapchain;
		VkDescriptorPool_T* m_DescriptorPool = nullptr;
		float m_Time = 0.0f;
	};
}