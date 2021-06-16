#pragma once

#include <string>

namespace Valiance
{
    class Texture
    {
      public:
        Texture(const std::string &path);
        ~Texture();

        void Bind(unsigned int slot = 0) const;
        void Unbind() const;

        inline int GetWidth()
        {
            return m_Width;
        }

        inline int GetHeight()
        {
            return m_Height;
        }

      private:
        unsigned int m_RendererID;
        int m_Width, m_Height, m_BPP;
    };
} // namespace Valiance