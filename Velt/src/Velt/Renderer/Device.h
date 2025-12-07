#pragma once
#include "Velt/Core/Core.h"
#include <vector>

namespace Velt::Renderer
{
	class VELT_API Device
	{
	public:
		virtual ~Device() = default;

		virtual void* GetNativeDevice() = 0;
		virtual void* GetPhysicalDevice() = 0;
		virtual void* GetCommandPool() = 0;
		virtual void* GetGraphicsQueue() = 0;
		virtual void* GetPresentQueue() = 0;
		virtual void* GetInstance() = 0;

		virtual void CreateBuffer(size_t size, uint32_t usage, uint32_t properties, void** buffer, void** bufferMemory) = 0;
		virtual void* BeginSingleTimeCommands() = 0;
		virtual void EndSingleTimeCommands(void* commandBuffer) = 0;
		virtual void CopyBuffer(void* srcBuffer, void* dstBuffer, size_t size) = 0;

		virtual uint32_t FindMemoryType(uint32_t typeFilter, uint32_t properties) = 0;

		static Ref<Device> Create(void* window);
	};
}
