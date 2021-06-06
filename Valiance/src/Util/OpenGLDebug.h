#pragma once

namespace Valiance::Utils
{
    enum class DebugLogLevel
    {
        None = 0,
        HighAssert = 1,
        High = 2,
        Medium = 3,
        Low = 4,
        Notification = 5
    };

    void EnableOpenGLDebugging();
    void OpenGLMessageCallback();
    void SetOpenGLDebugLevel(DebugLogLevel level);
} // namespace Valiance::Utils