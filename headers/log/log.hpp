#pragma once

#include <iostream>

namespace Engine
{
    namespace Log
    {
        class TerminalLog
        {
        private:
            int logLevel = 0;
            const char* message; 

        public:
            static void Print(int logLevel, std::string message);
            static void Print(int logLevel, int message);
        };
    }
}