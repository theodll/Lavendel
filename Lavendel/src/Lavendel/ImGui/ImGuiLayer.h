#pragma once

#include "lvpch.h"
#include "Lavendel/Layers/Layer.h"
#include "ImGuiRenderer.h"

namespace Lavendel {
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& event) override;
		virtual void OnUpdate() override;

		void Begin();
		void End();

	private:
		ImGuiRenderer m_Renderer;
	}; 
}
