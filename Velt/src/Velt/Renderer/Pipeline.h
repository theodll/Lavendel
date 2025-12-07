#pragma once
#include "Velt/Core/Core.h"
#include <string>

namespace Velt::Renderer
{
	class VELT_API Pipeline
	{
	public:
		virtual ~Pipeline() = default;

		virtual void Bind(void* commandBuffer) = 0;
		virtual void Destroy() = 0;

		static Ref<Pipeline> Create(void* device, const std::string& vertPath, const std::string& fragPath, void* configInfo);
	};
}