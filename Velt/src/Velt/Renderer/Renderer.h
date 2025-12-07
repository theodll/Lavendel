#pragma once
#include "vtpch.h"
#include "Window.h"
#include "RenderCommandBuffer.h"
#include "RenderPass.h"


namespace Velt::Renderer
{
	class Application;
	class ImGuiLayer;
	class LayerStack;

	class VELT_API Renderer
	{
	public:
		Renderer();
		~Renderer();

		virtual void drawFrame();

		virtual void setImGuiLayer(ImGuiLayer* layer) = 0;
		virtual void setLayerStack(LayerStack* layerStack) = 0;
		
		static void requestShutdown();
		static void Shutdown();

		static void BeginRenderPass(Ref<RenderCommandBuffer> renderCommandbuffer, Ref<RenderPass> renderPass, bool explicitClear = false);
		static void EndRenderPass(Ref<RenderCommandBuffer> renderCommandbuffer);

	private:
		virtual void loadModels() = 0;
		virtual void createPipelineLayout() = 0;
		virtual void createPipeline() = 0;


	};
}
