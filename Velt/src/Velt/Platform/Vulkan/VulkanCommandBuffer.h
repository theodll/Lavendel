#include "vtpch.h"
#include "Velt/Renderer/RenderCommandBuffer.h"

namespace Velt::Renderer::Vulkan
{
	class VELT_API VulkanCommandBuffer : public RenderCommandBuffer
	{
	public:
		VulkanCommandBuffer(VkCommandBuffer commandBuffer)
			: m_CommandBuffer(commandBuffer) {}

		virtual void* GetNativeHandle() override { return m_CommandBuffer; }
		virtual void Begin() override;
		virtual void End() override;
		virtual void Reset() override;

		inline VkCommandBuffer get() const { return m_CommandBuffer; }
	private:
		VkCommandBuffer m_CommandBuffer;
	};
}