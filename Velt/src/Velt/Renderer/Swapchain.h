#pragma once
#include "Velt/Core/Core.h"

namespace Velt::Renderer
{
	class VELT_API Swapchain
	{
	public:
		virtual ~Swapchain() = default;

		virtual void* GetFramebuffer(int index) = 0;
		virtual void* GetRenderPass() = 0;
		virtual void* GetImageView(int index) = 0;
		virtual size_t GetImageCount() const = 0;
		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		virtual float GetAspectRatio() const = 0;

		virtual int AcquireNextImage(uint32_t& imageIndex) = 0;
		virtual int SubmitCommandBuffers(const void* buffers, uint32_t* imageIndex) = 0;

		static Ref<Swapchain> Create(void* device, void* windowExtent);
		static Ref<Swapchain> Create(void* device, void* windowExtent, Ref<Swapchain> oldSwapchain);
	};
}
