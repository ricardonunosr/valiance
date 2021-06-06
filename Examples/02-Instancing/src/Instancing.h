#include "VLCore.h"

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
