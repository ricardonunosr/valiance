#pragma once

#include <string>

namespace Valiance
{
    class Layer
    {
      public:
        Layer(const std::string &name = "Layer");
        virtual ~Layer() = default;

        virtual void OnAttach()
        {
        }
        virtual void OnDetach()
        {
        }
        virtual void OnUpdate()
        {
        }
        virtual void OnImGuiRender()
        {
        }

        inline const std::string &GetName() const
        {
            return m_DebugName;
        }

      protected:
        std::string m_DebugName;
    };
} // namespace Valiance
