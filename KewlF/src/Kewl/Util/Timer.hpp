#pragma once

#include <iostream>
#include <chrono>

#include <Kewl/String.hpp>

namespace Kewl
{
    class Timer
    {
    public:
        Timer() { Reset(); }

        inline void Reset() { m_Start = std::chrono::high_resolution_clock::now(); }
        float Elapsed() { return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - m_Start).count() * 0.001f * 0.001f * 0.001f;}
        inline float ElapsedMillis() { return Elapsed() * 1000.0f; }

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> m_Start;
    };

    class ScopedTimer
    {
    public:
        ScopedTimer(const std::string& name) : m_name(name) {}
        ~ScopedTimer()
        {
            float time = m_Timer.ElapsedMillis();
            std::cout << "[TIMER] " << m_name << " - " << time << "ms\n";
        }
    private:
        String m_name;
        Timer m_Timer;
    };
} // namespace Kewl