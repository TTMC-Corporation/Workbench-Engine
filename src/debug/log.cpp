#include "../../headers/debug/log.hpp"


void Engine::Debug::TerminalLog::Print(int logLevel, std::string message)
{
    if (logLevel == 0)
    {
        std::cout << "\033[1;32m[INFO]\033[0m "  << message << "\n";
    }

    if (logLevel == 1)
    {
        std::cout << "\033[1;33m[WARNING]\033[0m " << message << "\n";
    }

    if (logLevel == 2)
    {
        std::cout << "\033[1;31m[ERROR]\033[0m " << message << "\n";
    }
}