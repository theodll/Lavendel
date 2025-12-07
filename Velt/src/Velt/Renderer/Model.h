#pragma once
#include "Velt/Core/Core.h"
#include <vector>

namespace Velt::Renderer
{
	class VELT_API Model
	{
	public:
		virtual ~Model() = default;

		virtual void Bind(void* commandBuffer) = 0;
		virtual void Draw(void* commandBuffer) = 0;
		virtual uint32_t GetVertexCount() const = 0;

		static Ref<Model> Create(void* device, const void* vertices, size_t vertexSize, uint32_t vertexCount);
	};
}

