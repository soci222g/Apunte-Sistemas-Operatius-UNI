#pragma once
#include<iostream>
#include<string>
#include<thread>
#include<chrono>

#pragma region Fucntions Declaration Header

void PrintLapseTime(
	std::chrono::system_clock::time_point start,
	std::chrono::system_clock::time_point ends,
	std::string threadName);
void Count(unsigned long long maxCounter, std::string threadName);

void Example01();
void Example02();
void Example03();
void Example04();
void Example05();
void Example06();
void Example07();

#pragma endregion

#pragma region Global Variables
std::chrono::system_clock::time_point startDate;

#pragma endregion



void ThreadTutorialTest() {
	
	startDate = std::chrono::system_clock::now(); //guardem el moment del temps on iniciem el programa
	
	int exampleUser = 1;

	switch (exampleUser)
	{
	case 1: 
		Example01();
		break;
	case 2:
		Example02();
		break;
	case 3:
		Example03();
		break;
	case 4:
		Example04();
	case 5:
		Example05();
		break;
	case 6:
		Example06();
		break;
	case 7:
		Example07();
		break;
		
	default:
		break;
	}

	std::cout << "Example: " << exampleUser << " Finished" << std::endl;

	std::string text = "";
	std::getline(std::cin, text);
}

void PrintLapseTime(
	std::chrono::system_clock::time_point start,
	std::chrono::system_clock::time_point ends,
	std::string threadName) {

	std::chrono::duration<double> elapseTime = ends - start;
	std::cout << "thread: " << threadName << " - Element Time: " << elapseTime.count() << "seconds" << std::endl;

}

void Count(unsigned long long maxCounter, std::string threadName) {
	for (unsigned long long i = 0; i< maxCounter; i++) {	}

	std::chrono::system_clock::time_point endDate = std::chrono::system_clock::now();
	PrintLapseTime(startDate, endDate, threadName);

}


void Example01() {
	unsigned long long totalCount = 1000000000ull;
	std::thread* Coubnter1 = new std::thread(Count, totalCount, "1");   //tots els threads tene que ser punters
	std::thread* Coubnter2 = new std::thread(Count, totalCount, "2");
	std::thread* Coubnter3 = new std::thread(Count, totalCount, "3");

	Coubnter1->join();
	Coubnter2->join();
	Coubnter3->join();

	Count(totalCount, "0");
}
void Example02() {

}
void Example03() {

}
void Example04() {

}
void Example05() {

}
void Example06() {

}
void Example07() {

}