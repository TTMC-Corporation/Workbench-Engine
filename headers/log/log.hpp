#pragma once 
class Log
{
private:
    int logLevel = 0;
    const char* message; 

public:
    void Print(int logLevel, const char* message);
};