#include <iostream>
#include <windows.h> // For console settings

void InitConsole()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hConsole, &mode);
    SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

void ClearConsole()
{
    std::cout << "\x1b[2J"; // Remove all characters in console
    std::cout << "\x1b[H"; // Set cursor pos to "home" position (0,0)
}

void SetCursorVisible(bool visible)
{
    if(visible)
    {
        std::cout << "\x1b[?25h"; // Make cursor visible
    }
    else
    {
        std::cout << "\x1b[?25l"; // Make cursor invisible
    }
}

int main(int argc, char** argv)
{
    InitConsole();
    ClearConsole();
    SetCursorVisible(false);
    std::cout << "Hello World" << std::endl;
    SetCursorVisible(true);
    return 0;
}