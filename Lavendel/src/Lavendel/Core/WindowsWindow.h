#include "lvpch.h"
#include "Renderer/Window.h"

#include <SDL3/SDL.h>

namespace Lavendel {
	class WindowsWindow : public RenderAPI::Window
	{
	public:
		WindowsWindow(int width, int height, const std::string& title, bool bResizable);
		virtual ~WindowsWindow();

		void OnUpdate() override;
		
		// Getters
		uint16_t GetWidth() const override { return m_Width; }
		uint16_t GetHeight() const override { return m_Height; }
		
		void SetEventCallback(const EventCallbackFn& callback) override { m_EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
	private:
		virtual void Init(const WindowProps);
		virtual void Shutdown();

	private: 
		SDL3_Window* m_Window;
	
		struct WindowData
		{
			std::string Title;
			uint16_t Width, Height;
			bool bVSync;
			bool bResizable;

			EventCallbackFn EventCallback
		};
	
		WindowData m_Data;
	}


}