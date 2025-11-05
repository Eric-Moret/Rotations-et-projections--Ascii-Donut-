#include <iostream>
#include <windows.h> // For console settings
#include <vector>

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

void GetScreenSize(int argc, char** argv, int& width, int& height)
{
    // Elegant solution from @T.Rosselet
    for (int i = 1; i < argc; i++) //i starts at 1 because command line arguments start with argv[1] (argv[0] is the name of the exe)
    {
        std::string arg = argv[i];
        if (arg == "-w" && i + 1 < argc)
        {
            width = std::atoi(argv[i+1]);
            i++;
        }
        else if (arg == "-h" && i + 1 < argc)
        {
            height = std::atoi(argv[i+1]);
            i++;
        }
    }
}

int main(int argc, char** argv)
{
    InitConsole();
    ClearConsole();
    SetCursorVisible(false);
    int width = 100;
    int height = 20;
    GetScreenSize(argc, argv, width, height);
    std::vector<char> screen(width * height, '.');
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            std::cout << screen[width * i + j];
        }
        std::cout << std::endl;
    }
    SetCursorVisible(true);
    return 0;
}