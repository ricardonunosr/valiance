#include "Sandbox.h"

#include "glad/glad.h"

using namespace Valiance;

int main()
{
    std::unique_ptr<Sandbox> app = std::make_unique<Sandbox>();
    app->Run();
}

SandboxLayer::SandboxLayer()
{
}

SandboxLayer::~SandboxLayer()
{
}

void SandboxLayer::OnAttach()
{
}

void SandboxLayer::OnDetach()
{
}

void SandboxLayer::OnImGuiRender()
{
}

void SandboxLayer::OnUpdate()
{
}
