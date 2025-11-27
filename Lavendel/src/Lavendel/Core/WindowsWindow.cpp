#include "lvpch.h"
#include WindowsWindow.h"

namespace Lavendel {
	static bool s_SDLInitialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		LV_PROFILE_FUNCTION();
		return new WindowsWindow(props);
	}
	
	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		LV_PROFILE_FUNCTION();
		Init(WindowProps(props));
	}

	WindowsWindow::~WindowsWindow()
	{
		LV_PROFILE_FUNCTION();
		Shutdown();
	}
}