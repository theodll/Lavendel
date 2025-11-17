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
		ImGuiRenderer(std::shared_ptr<RenderAPI::SwapChain> swapchain, std::shared_ptr<RenderAPI::GPUDevice> device, SDL_Window* window);
		~ImGuiRenderer() = default;

		
		void Init();
		void Render(VkCommandBuffer& commandBuffer);
		void Shutdown();
		void Begin();
		void End();
		
	private:
		std::shared_ptr<RenderAPI::SwapChain> m_Swapchain;
		std::shared_ptr<RenderAPI::GPUDevice> m_Device;
		VkDescriptorPool_T* m_DescriptorPool = nullptr;
		SDL_Window* m_Window = nullptr;

		float m_Time = 0.0f;
	};
}