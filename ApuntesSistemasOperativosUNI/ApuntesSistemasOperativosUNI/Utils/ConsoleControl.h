#pragma once
#include<mutex>
#include<iostream>
#include<sstream>
#include<Windows.h>
#include<conio.h>

static class ConsoleControl
{
public:
	enum ConsoleColor {
		BLACK, DARKBLUE, DARKGREEN, DARKCYAN, DARKRED, DARKMAGENTA, DARKGREY,
		BLUE, GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE
	};

private:

	HANDLE _controle = GetStdHandle(STD_OUTPUT_HANDLE);  //ens guardem la linia que cria la consola 
	std::mutex* _consoleMutex = new std::mutex;

	static ConsoleControl GetInstance(); //aixo es el que ens fa que sigui un silgenton
	static HANDLE GetConsole();


public:

	static void SetColor(ConsoleColor TextColor = WHITE, ConsoleColor backgroundColor = BLACK);

	static void SetPosition(short int x, short int y);

	static void Clear();

	static void FillwithCharacters(char character, ConsoleColor textColor, ConsoleColor backgroundColor);

	static void clearKeyBufer();
	
	static int ReadNextKey();
	
	static int WaitForRearNextKey();
	
	static char WaitForReadNextChar();
	
	static void Lock();
	
	static void Unlock();


};


using CC = ConsoleControl; //metemos un sininima del nomber de una clase 
