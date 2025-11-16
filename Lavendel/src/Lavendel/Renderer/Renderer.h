#pragma once
#include "lvpch.h"
#include "Window.h"
#include "Core/Device.h"
#include "Pipeline/Pipeline.h"
#include "Core/Swapchain.h"
#include "Model/Model.h"
#include "ImGui/ImGuiRenderer.h"


namespace Lavendel
{
	// Forward declaration
	class Application;

	namespace RenderAPI
	{
		class LAVENDEL_API Renderer
		{
		public:
			Renderer(Window& window);
			~Renderer();
			
			void drawFrame();
			
			// ImGui integration
			void initImGui();
			void beginImGuiFrame();
			void endImGuiFrame();

			inline std::shared_ptr<GPUDevice> getDevice() { return m_Device; }
			inline std::shared_ptr<SwapChain> getSwapChain() { return m_SwapChain; }
			inline std::shared_ptr<Pipeline> getPipeline() { return m_Pipeline; }

			ImGuiRenderer& getImGuiRenderer() { return m_ImGuiRenderer; }

		private:
			void loadModels();
			void createPipelineLayout();
			void createPipeline();
			void createCommandBuffers();
			void freeCommandBuffers();
			void recreateSwapChain();
			void recordCommandBuffer(int imageIndex);
			


			Window& m_Window;
			std::shared_ptr<GPUDevice> m_Device;
			std::shared_ptr<SwapChain> m_SwapChain;
			std::shared_ptr<RenderAPI::Pipeline> m_Pipeline;
			std::shared_ptr<Model> m_Model;
			std::vector<VkCommandBuffer> m_CommandBuffers;
			VkPipelineLayout m_PipelineLayout;
			ImGuiRenderer m_ImGuiRenderer;
			bool m_ImGuiInitialized = false;
		};
	}
}
