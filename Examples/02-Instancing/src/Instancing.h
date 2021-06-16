#include "VLCore.h"

#include "Core/IndexBuffer.h"
#include "Core/Shader.h"
#include "Core/Texture.h"
#include "Core/VertexArray.h"
#include "Core/VertexBuffer.h"
#include "Util/PerspectiveCamera.h"

class InstancingLayer : public Valiance::Layer
{
  public:
    InstancingLayer();
    virtual ~InstancingLayer();

    virtual void OnAttach() override;
    virtual void OnDetach() override;
    virtual void OnImGuiRender() override;
    virtual void OnUpdate() override;

  private:
    std::unique_ptr<Valiance::VertexArray> vao;
    std::unique_ptr<Valiance::VertexBuffer> vb;
    std::unique_ptr<Valiance::IndexBuffer> ib;
    std::unique_ptr<Valiance::Shader> shader;
    std::unique_ptr<Valiance::Texture> texture;
    glm::mat4 m_MVP;
    glm::mat4 m_Proj;
    glm::mat4 m_View;
    glm::mat4 m_Model;
    glm::vec3 m_RotationVector;
    std::unique_ptr<Valiance::Utils::PerspectiveCamera> m_Camera;
    float m_Radians;
};

class Instancing : public Valiance::Application
{
  public:
    Instancing()
    {
        PushLayer(new InstancingLayer());
    }

  private:
};
