#pragma once

#include "imgui.h"
#include "backends/imgui_impl_vulkan.h"
#include "backends/imgui_impl_sdl3.h"

struct VkDescriptorPool_T;
struct VkCommandBuffer_T;
struct VkRenderPass_T;
struct VkFramebuffer_T;

namespace Lavendel {
	class ImGuiRenderer {
	public:
		ImGuiRenderer() = default;
		~ImGuiRenderer() = default;
		
		void Init(VkInstance instance, VkPhysicalDevice physicalDevice, VkDevice device, 
		          VkQueue queue, uint32_t queueFamily, VkRenderPass renderPass);
		void Begin();
		void End();
		void Render(VkCommandBuffer commandBuffer);
		void Shutdown();
		
	private:
		VkDescriptorPool_T* m_DescriptorPool = nullptr;
	};
}