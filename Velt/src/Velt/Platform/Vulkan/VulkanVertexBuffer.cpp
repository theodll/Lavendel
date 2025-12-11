#include "vtpch.h"
#include "VulkanVertexBuffer.h"
#include "VulkanContext.h"
#include "VulkanDevice.h"

namespace Velt::Renderer::Vulkan
{
	

	VulkanVertexBuffer::VulkanVertexBuffer(VertexBufferElement& elements)
	{
		VT_PROFILE_FUNCTION();
		VT_CORE_TRACE("Creating Vulkan Vertex Buffer");
		m_Device = VulkanContext::getDevice();
	
	}
	VulkanVertexBuffer::~VulkanVertexBuffer()
	{
		VT_PROFILE_FUNCTION();
		VT_CORE_TRACE("Destroying Vulkan Vertex Buffer");

	}
	void VulkanVertexBuffer::Bind() const
	{
		VT_PROFILE_FUNCTION();

	}
	void VulkanVertexBuffer::Unbind() const
	{
		VT_PROFILE_FUNCTION();

	}
}