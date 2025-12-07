#include "vtpch.h"
#include "VulkanWindow.h"
#include <SDL3/SDL_vulkan.h>

namespace Velt::Renderer::Vulkan
{
    void VulkanWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface)
    {
        VT_PROFILE_FUNCTION();
        if (!SDL_Vulkan_CreateSurface(static_cast<SDL_Window*>(m_Window.GetNativeHandle()), instance, nullptr, surface))
        {
            VT_CORE_ERROR("Failed to create window surface: {}", SDL_GetError());
            throw std::runtime_error("Failed to create window surface");
        }
    }
}
