#pragma once
#include "vtpch.h"
#include "Velt/Renderer/Window.h"

namespace Velt::Renderer::Vulkan
{
    class VELT_API VulkanWindow
    {
    public:
        VulkanWindow(RenderAPI::Window& window) : m_Window(window) {}

        void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);
        VkExtent2D getExtent() const { return { static_cast<uint32_t>(m_Window.GetWidth()), static_cast<uint32_t>(m_Window.GetHeight()) }; }

        RenderAPI::Window& GetWindow() { return m_Window; }

    private:
        RenderAPI::Window& m_Window;
    };
}
