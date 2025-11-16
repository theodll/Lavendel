#pragma once

#include "lvpch.h"
#include "Lavendel/Layers/Layer.h"
#include "ImGuiRenderer.h"
#include "Widgets/DemoWidget.h"

#include "Lavendel/Renderer/Core/Device.h"	
#include "Lavendel/Renderer/Renderer.h"

namespace Lavendel {
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer(std::shared_ptr<RenderAPI::SwapChain>& swapchain, std::shared_ptr<RenderAPI::GPUDevice>& device);
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& event) override;
		virtual void OnUpdate() override;

		void Begin();
		void End();

	private:
		ImGuiRenderer m_Renderer;
		DemoWidget m_DemoWidget;

		std::shared_ptr<RenderAPI::SwapChain>& m_Swapchain;
		std::shared_ptr<RenderAPI::GPUDevice>& m_Device;


	}; 
}
