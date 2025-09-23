#include "ConsoleControl.h"

ConsoleControl ConsoleControl::GetInstance()
{
	static ConsoleControl instance; //si ja esta creat el reutilitza estelvian recursos.

	return instance;
}

HANDLE ConsoleControl::GetConsole()
{
	return GetInstance()._controle;
}

void ConsoleControl::SetColor(ConsoleColor TextColor, ConsoleColor backgroundColor)
{
	WORD color = (backgroundColor << 4) | TextColor; //aixo crae una maskara de bits
	SetConsoleTextAttribute(GetConsole(), color);
}

void ConsoleControl::SetPosition(short int x, short int y)
{
	COORD pos{ x,y };
	SetConsoleCursorPosition(GetConsole(), pos);
}

void ConsoleControl::Clear()
{
	//FillwithCharacters(' ', WHITE, BLACK);
	std::cout << "\033[2j\033[1;1H"; //enviem una ordre directa a la console per nateja el buffer.

}

void ConsoleControl::FillwithCharacters(char character, ConsoleColor textColor, ConsoleColor backgroundColor)
{

	COORD topLeft = { 0,0 }; //agafa adal a la esquerra

	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD Written;
	HANDLE console = GetConsole();

	WORD color = (backgroundColor << 4) | textColor;

	GetConsoleScreenBufferInfo(console, &screen);

	FillConsoleOutputCharacterA(console, character, screen.dwSize.X * screen.dwSize.Y, topLeft, &Written); //llenamos del character
	FillConsoleOutputAttribute(console, color, screen.dwSize.X * screen.dwSize.Y, topLeft, &Written); //llenamos del color
	SetConsoleCursorPosition(console, topLeft);

}

void ConsoleControl::clearKeyBufer()
{
	while (_kbhit()) { //mira si el buffer te algun input en espera
		_getch(); // nateja el buffer
	}
}

int ConsoleControl::ReadNextKey()
{
	int KB_code = 0;


	if (_kbhit) {
		KB_code = _getch();

	}

	return KB_code;
}

int ConsoleControl::WaitForRearNextKey()
{
	int KB_code = 0;

	while (KB_code == 0)
	{
		if (_kbhit) {
			KB_code = _getch();

		}
	}
	

	return KB_code;
}

char ConsoleControl::WaitForReadNextChar()
{

	char c = 0;

	while (c == 0)
	{
		if (_kbhit) {
			c = _getch();

		}
	}


	return c;
}

void ConsoleControl::Lock()
{
	GetInstance()._consoleMutex->lock();
}

void ConsoleControl::Unlock()
{
	GetInstance()._consoleMutex->unlock();
}


