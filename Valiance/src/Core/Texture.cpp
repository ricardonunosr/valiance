#include "Texture.h"

#include "glad/glad.h"
#include "stb_image.h"
#include <iostream>

namespace Valiance
{
    Texture::Texture(const std::string &path) : m_RendererID(0), m_Width(0), m_Height(0), m_BPP(0)
    {
        stbi_set_flip_vertically_on_load(1);
        glGenTextures(1, &m_RendererID);
        glBindTexture(GL_TEXTURE_2D, m_RendererID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        unsigned char *data = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            std::cout << "Failed to load texture" << std::endl;
        }
        stbi_image_free(data);
    }

    Texture::~Texture()
    {
        glDeleteTextures(1, &m_RendererID);
    }

    void Texture::Bind(unsigned int slot /*= 0*/) const
    {
        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, m_RendererID);
    }

    void Texture::Unbind() const
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

} // namespace Valiance