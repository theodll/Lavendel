#include "Framebuffer.h"
#include "Velt/Platform/Vulkan/VulkanFramebuffer.h"
#include "Velt/Renderer/Renderer.h"
#include "vtpch.h"

namespace Velt::Renderer {

    Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec) {
        return CreateRef<VulkanFramebuffer>(Renderer::getDevice(), spec);

    };
} // namespace Velt
