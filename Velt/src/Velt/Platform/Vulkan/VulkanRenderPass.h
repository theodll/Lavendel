#include "vtpch.h"
#include "Velt/Renderer/RenderPass.h"

namespace Velt::Renderer::Vulkan 
{
	class VELT_API VulkanRenderPass : public RenderPass
	{
	public:
		VulkanRenderPass() = default;
		virtual ~VulkanRenderPass() = default;

		virtual void Init() override;
		virtual void Begin(Ref<RenderCommandBuffer> commandBuffer, void* framebuffer, bool explicitClear = false) override;
		virtual void End(Ref<RenderCommandBuffer> commandBuffer) override;
		virtual void* GetNativeHandle() override;

	private:
		VkRenderPass m_RenderPass = VK_NULL_HANDLE;
	};
}