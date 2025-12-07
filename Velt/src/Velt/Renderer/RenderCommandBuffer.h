#pragma once
#include "Velt/Core/Core.h"

namespace Velt::Renderer {

	class VELT_API RenderCommandBuffer
	{
	public:
		virtual ~RenderCommandBuffer() = default;

		virtual void* GetNativeHandle() = 0;
		virtual void Begin() = 0;
		virtual void End() = 0;
		virtual void Reset() = 0;

		static Ref<RenderCommandBuffer> Create(void* nativeBuffer);
	};
}