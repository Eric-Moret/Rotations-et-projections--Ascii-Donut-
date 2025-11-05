#include <iostream>
#include <windows.h> // For console settings
#include "Settings.h"
#include "Screen.h"
#include "Mesh.h"

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
    Settings settings(argc, argv);
    Screen screen(settings);
    Mesh mesh(settings);
    mesh.GenerateRectangle(50.f, 80.f);
    std::cout << "Rectangle 50x80:" << std::endl;
    screen.Display(mesh);
    mesh.GenerateSquare(60.f);
    std::cout << "Square 60x60:" << std::endl;
    screen.Display(mesh);
    mesh.GenerateCircle(70.f);
    std::cout << "Circle radius 70:" << std::endl;
    screen.Display(mesh);
    mesh.GenerateHalfCircle(45.f);
    std::cout << "Half Circle radius 45:" << std::endl;
    screen.Display(mesh);
    SetCursorVisible(true);
    return 0;
}