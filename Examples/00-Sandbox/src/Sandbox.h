#include "VLCore.h"

#include "Core/IndexBuffer.h"
#include "Core/Shader.h"
#include "Core/VertexArray.h"
#include "Core/VertexBuffer.h"
#include "Util/PerspectiveCamera.h"

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
    std::unique_ptr<Valiance::VertexArray> m_VAOCube;
    std::unique_ptr<Valiance::VertexArray> m_VAOLight;
    std::unique_ptr<Valiance::VertexBuffer> m_Vb;
    std::unique_ptr<Valiance::Shader> m_ShaderLighting;
    std::unique_ptr<Valiance::Shader> m_ShaderLightCube;
    std::unique_ptr<Valiance::Utils::PerspectiveCamera> m_Camera;
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
