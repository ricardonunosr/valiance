#include "Instancing.h"

#include "glad/glad.h"

using namespace Valiance;

int main()
{
    std::unique_ptr<Instancing> app = std::make_unique<Instancing>();
    app->Run();
}

InstancingLayer::InstancingLayer()
{
}

InstancingLayer::~InstancingLayer()
{
}

void InstancingLayer::OnAttach()
{
}

void InstancingLayer::OnDetach()
{
}

void InstancingLayer::OnImGuiRender()
{
}

void InstancingLayer::OnUpdate()
{
}
