#pragma once


#define GLFW_INCLUDE_VULKAN
#include <string>
#include <GLFW/glfw3.h>

namespace Lavendel
{
	namespace Renderer 
	{
	
		class _declspec(dllexport) Window
		{
		public:
			Window(const char* title, int width, int height);

		private:

			void initWindow(const char* title, int width, int height);

            const int m_Width = 960;
			const int m_Height = 540;
			const std::string m_Title = "Lavendel Engine Vulkan";

            GLFWwindow* m_Window;
		};

	}
}


