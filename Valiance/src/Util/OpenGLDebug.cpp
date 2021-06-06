#include "OpenGLDebug.h"
#include "glad/glad.h"
#include <iostream>

namespace Valiance::Utils
{
    static DebugLogLevel s_DebugLogLevel = DebugLogLevel::HighAssert;

    void SetOpenGLDebugLevel(DebugLogLevel level)
    {
        s_DebugLogLevel = level;
    }

    void OpenGLMessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
                               const GLchar *message, const void *userParam)
    {
        switch (severity)
        {
        case GL_DEBUG_SEVERITY_HIGH:
            if ((int)s_DebugLogLevel > 0)
                std::cout << "OpenGL Debug High: " << message << std::endl;
            break;
        case GL_DEBUG_SEVERITY_MEDIUM:
            if ((int)s_DebugLogLevel > 2)
                std::cout << "OpenGL Debug Medium: " << message << std::endl;
            break;
        case GL_DEBUG_SEVERITY_LOW:
            if ((int)s_DebugLogLevel > 3)
                std::cout << "OpenGL Debug Low: " << message << std::endl;
            break;
        case GL_DEBUG_SEVERITY_NOTIFICATION:
            if ((int)s_DebugLogLevel > 4)
                std::cout << "OpenGL Debug Notification: " << message << std::endl;
            break;
        }
    }

    void EnableOpenGLDebugging()
    {
        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(OpenGLMessageCallback, 0);
    }

} // namespace Valiance::Utils