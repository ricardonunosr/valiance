#include "VLCore.h"

#include "Core/IndexBuffer.h"
#include "Core/Shader.h"
#include "Core/VertexArray.h"
#include "Core/VertexBuffer.h"

class HelloWorldLayer : public Valiance::Layer
{
  public:
    HelloWorldLayer();
    virtual ~HelloWorldLayer();

    virtual void OnAttach() override;
    virtual void OnDetach() override;
    virtual void OnImGuiRender() override;
    virtual void OnUpdate() override;

  private:
    float m_ClearColor[4];
    std::unique_ptr<Valiance::VertexArray> vao;
    std::unique_ptr<Valiance::VertexBuffer> vb;
    std::unique_ptr<Valiance::IndexBuffer> ib;
    std::unique_ptr<Valiance::Shader> shader;
};

class HelloWorld : public Valiance::Application
{
  public:
    HelloWorld()
    {
        PushLayer(new HelloWorldLayer());
    }

  private:
};
