#pragma once

#include "lvpch.h"
#include "Lavendel/Layers/Layer.h"
#include "ImGuiRenderer.h"
#include "Widgets/DemoWidget.h"

#include "Lavendel/Renderer/Core/Device.h"	
#include "Lavendel/Renderer/Renderer.h"

struct SDL_Window;

namespace Lavendel {
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		ImGuiLayer(const ImGuiLayer&) = delete;
		ImGuiLayer& operator=(const ImGuiLayer&) = delete;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& event) override;
		virtual void OnUpdate() override;

		void Begin();
		void End();
		
		// Allow renderer to record ImGui commands
		ImGuiRenderer& GetRenderer() { return *m_Renderer; }

	private:
		std::shared_ptr<ImGuiRenderer> m_Renderer;
		
		std::shared_ptr<RenderAPI::GPUDevice>& m_Device;

		DemoWidget m_DemoWidget;

	}; 
}
