#include "VLCore.h"

#include "Core/IndexBuffer.h"
#include "Core/Shader.h"
#include "Core/VertexArray.h"
#include "Core/VertexBuffer.h"

class SandboxLayer : public Valiance::Layer
{
  public:
    SandboxLayer();
    virtual ~SandboxLayer();

    virtual void OnAttach() override;
    virtual void OnDetach() override;
    virtual void OnImGuiRender() override;
    virtual void OnUpdate() override;

  private:
};

class Sandbox : public Valiance::Application
{
  public:
    Sandbox()
    {
        PushLayer(new SandboxLayer());
    }

  private:
};
