#pragma once

#include "Velt/Core/Core.h"
#include "Velt/Renderer/VertexBuffer.h"

#include "VulkanContext.h"
#include "VulkanDevice.h"

#include <vulkan/vulkan.h>

namespace Velt::Renderer::Vulkan
{
    class VulkanVertexBuffer : public VertexBuffer
    {
    public:
        VulkanVertexBuffer(
            const void* vertexData,
            u32 vertexCount,
            VkDeviceSize vertexStride
        );

        ~VulkanVertexBuffer() override;

        void Bind() const override;
        void Unbind() const override;

        u32 GetVertexCount() const override { return m_VertexCount; }

    private:
        void CreateBuffer(const void* data);

    private:
        const VulkanDevice& m_Device;

        VkBuffer m_VertexBuffer = VK_NULL_HANDLE;
        VkDeviceMemory m_VertexBufferMemory = VK_NULL_HANDLE;

        u32 m_VertexCount = 0;
        VkDeviceSize m_VertexStride = 0;
    };
}
