#include "vtpch.h"
#include "Velt/Renderer/Renderer.h"

namespace Velt::Renderer::Vulkan
{
	class VELT_API VulkanRenderer : public Renderer
	{
	public:
		VulkanRenderer();
		~VulkanRenderer();



		virtual void drawFrame() override;
		void renderImGui(VkCommandBuffer commandBuffer);


		static void requestShutdown();
		static void Shutdown();

		virtual void setImGuiLayer(ImGuiLayer* layer) override { m_ImGuiLayer = layer; }
		virtual void setLayerStack(LayerStack* layerStack) override { m_LayerStack = layerStack; }

		//inline static VulkanDevice* getDevice() { return m_Device; }
		//inline static SwapChain* getSwapChain() { return m_SwapChain; }
		//inline static Pipeline* getPipeline() { return m_Pipeline; }

	private:
		void loadModels();
		void createPipelineLayout();
		void createPipeline();
		void createCommandBuffers();
		void freeCommandBuffers();
		void recreateSwapChain();
		void recordCommandBuffer(int imageIndex);


		std::shared_ptr<Model> m_Model;
		std::vector<VulkanCommandBuffer> m_CommandBuffers;
		VkPipelineLayout m_PipelineLayout;
		ImGuiLayer* m_ImGuiLayer = nullptr;
		LayerStack* m_LayerStack = nullptr;  // Reference to layer stack for calling OnRender on each layer
	};
}