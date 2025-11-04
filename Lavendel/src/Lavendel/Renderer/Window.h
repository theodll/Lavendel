#pragma once

#include "../Core.h"
#include <GLFW/glfw3.h>
#include <string>

namespace Lavendel {

    namespace RendererAPI {
	    class LAVENDEL_API Window
	    {

        public:
            Window(int width, int height, const std::string& title, bool bResizable);
            ~Window();

            void PollEvents() const { glfwPollEvents(); };
            bool ShouldClose() const { return glfwWindowShouldClose(m_Window); };
            // void* GetNativeHandle() const { return m_Window; };

        private:
            void Init(int width, int height, const std::string& title, bool bResizable);
            void Shutdown();
        
            GLFWwindow* m_Window;


            int m_Width, m_Height;
		    bool m_Resizable;
            std::string m_Title;

	    };

	}
}
