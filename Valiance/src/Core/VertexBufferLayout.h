#pragma once

#include "glad/glad.h"
#include <string>
#include <vector>

namespace Valiance
{
    enum class DataType
    {
        None = 0,
        Float,
        Float2,
        Float3,
        Float4,
        Mat3,
        Mat4,
        Int,
        Int2,
        Int3,
        Int4,
        Bool
    };

    static uint32_t DataTypeSize(DataType type)
    {
        switch (type)
        {
        case DataType::Float:
            return 4;
        case DataType::Float2:
            return 4 * 2;
        case DataType::Float3:
            return 4 * 3;
        case DataType::Float4:
            return 4 * 4;
        case DataType::Mat3:
            return 4 * 3 * 3;
        case DataType::Mat4:
            return 4 * 4 * 4;
        case DataType::Int:
            return 4;
        case DataType::Int2:
            return 4 * 2;
        case DataType::Int3:
            return 4 * 3;
        case DataType::Int4:
            return 4 * 4;
        case DataType::Bool:
            return 1;
        }

        return 0;
    }

    struct VertexBufferElement
    {
        std::string name;
        DataType type;
        uint32_t size;
        size_t offset;
        bool normalized;
        bool instanced;

        VertexBufferElement() = default;

        VertexBufferElement(const std::string &name, DataType type, bool normalized = false, bool instanced = false)
            : name(name), type(type), size(DataTypeSize(type)), offset(0), normalized(normalized), instanced(instanced)
        {
        }

        uint32_t GetComponentCount() const
        {
            switch (type)
            {
            case DataType::Float:
                return 1;
            case DataType::Float2:
                return 2;
            case DataType::Float3:
                return 3;
            case DataType::Float4:
                return 4;
            case DataType::Mat3:
                return 3;
            case DataType::Mat4:
                return 4;
            case DataType::Int:
                return 1;
            case DataType::Int2:
                return 2;
            case DataType::Int3:
                return 3;
            case DataType::Int4:
                return 4;
            case DataType::Bool:
                return 1;
            }

            return 0;
        }
    };

    class VertexBufferLayout
    {
      public:
        VertexBufferLayout(std::initializer_list<VertexBufferElement> elements) : m_Elements{elements}
        {
            CalculateOffsetsAndStride();
        }

        inline unsigned int GetStride() const
        {
            return m_Stride;
        }
        inline std::vector<VertexBufferElement> GetElements() const
        {
            return m_Elements;
        }

      private:
        std::vector<VertexBufferElement> m_Elements;
        unsigned int m_Stride;

      private:
        void CalculateOffsetsAndStride()
        {
            size_t offset = 0;
            m_Stride = 0;
            for (auto &element : m_Elements)
            {
                element.offset = offset;
                offset += element.size;
                m_Stride += element.size;
            }
        }
    };
} // namespace Valiance