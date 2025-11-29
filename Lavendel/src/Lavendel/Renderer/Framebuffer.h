#pragma once

namespace Lavendel {
namespace RenderAPI {

struct FramebufferSpecification {};

class Framebuffer {
public:
  static Ref<Framebuffer> Create(FramebufferSpecification specs);
}

} // namespace RenderAPI
} // namespace Lavendel
