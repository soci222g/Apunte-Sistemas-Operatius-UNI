#pragma once
#include<iostream>
#include<string>
#include<thread>
#include<chrono>
#include<list>
#include<mutex>

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
std::mutex* consoleMutex;
#pragma endregion



void ThreadTutorialTest() {
	consoleMutex = new std::mutex(); //nomes utilitzarem el lock i unlock.
	startDate = std::chrono::system_clock::now(); //guardem el moment del temps on iniciem el programa
	
	int exampleUser = 6;

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
	
	//les lines que hem de bloquejar han de ser les minimes pusibles sempre. si no es pot perdre optimitzacio.
	consoleMutex->lock();
	std::cout << "thread: " << threadName << " - Element Time: " << elapseTime.count() << "seconds" << std::endl;
	consoleMutex->unlock();
}

void Count(unsigned long long maxCounter, std::string threadName) {
	for (unsigned long long i = 0; i< maxCounter; i++) {	}



	std::chrono::system_clock::time_point endDate = std::chrono::system_clock::now();
	PrintLapseTime(startDate, endDate, threadName);

}


void Example01() {
	unsigned long long totalCount = 1000000000ull;
	std::thread* Counter1 = new std::thread(Count, totalCount, "1");   //tots els threads tene que ser punters
	std::thread* Counter2 = new std::thread(Count, totalCount, "2");
	std::thread* Counter3 = new std::thread(Count, totalCount, "3");

	//los joins esperan a que todos los threads terminen.
	Counter1->join();
	Counter2->join();
	Counter3->join();
	//tarde al doble perque s'espera a que acavi el primera cade de threads i despres fa el seu.
	Count(totalCount, "0");
}
void Example02() {
	unsigned long long totalCount = 1000000000ull;
	std::thread* Counter1 = new std::thread(Count, totalCount, "1");

	Counter1->join();
	//acava de executar aquest threads i despres prosegeix en crear els altres dos.

	std::thread* Counter2 = new std::thread(Count, totalCount, "2");
	std::thread* Counter3 = new std::thread(Count, totalCount, "3");

	Counter2->join();
	Counter3->join();

	Count(totalCount, "0");

}
void Example03() {
	unsigned long long totalCount = 1000000000ull;
	std::thread* Counter1 = new std::thread(Count, totalCount, "1");   //tots els threads tene que ser punters
	std::thread* Counter2 = new std::thread(Count, totalCount, "2");
	std::thread* Counter3 = new std::thread(Count, totalCount, "3");

	//los joins esperan a que todos los threads terminen.
	Counter1->detach();
	Counter2->detach();
	Counter3->detach();
	//tarde al doble perque s'espera a que acavi el primera cade de threads i despres fa el seu.
	Count(totalCount, "0");
}
void Example04() {

	std::list<std::thread*>* threads = new std::list<std::thread*>();
	unsigned long long totalCount = 1000000000ull;

	for (int i = 0; i < 3; i++) {
		std::thread* counterThread = new std::thread(Count, totalCount, std::to_string(i + 1));
		threads->push_back(counterThread);

		counterThread->join();
	}

	Count(totalCount, "0");
}
void Example05() {
	std::list<std::thread*>* threads = new std::list<std::thread*>();
	unsigned long long totalCount = 1000000000ull;

	for (int i = 0; i < 3; i++) {
		std::thread* counterThread = new std::thread(Count, totalCount, std::to_string(i + 1));
		threads->push_back(counterThread);

		counterThread->detach();
	}

	Count(totalCount, "0");
}
void Example06() {

	//les dames porgrames tambe afectan als threads esa dir com mes programes mes lents.
	unsigned int maxThreads = std::thread::hardware_concurrency();

	std::cout << maxThreads << " current threads are suported" << std::endl;

	int extraThreads = 20;

	unsigned long long totalCount = 1000000000ull;
	unsigned int totalThreads = maxThreads + extraThreads;
	
	std::list<std::thread*>* threads = new std::list<std::thread*>();
	
	for (int i = 0; i < totalThreads; i++) {
		std::thread* counterThread = new std::thread(Count, totalCount, std::to_string(i + 1));
		threads->push_back(counterThread);
	}

	for (std::thread* t : *threads) {
		t->join();
	}
	Count(totalCount, "0");
	//la grafica es tenir un collo de nuclis especuialitzats per calculs matematics senzills. si nesecites calculs matematics a gran escala exemple: 10000 osells. simplificas els calcols i li pasas a la grafica.

}

class ThreadTester
{
public:

	ThreadTester() {}
	~ThreadTester() {}


	void Exemple07();

private:

	void TestFunction(unsigned long long testInt);
};


void ThreadTester::Exemple07() {
	std::thread* testThread = new std::thread(&ThreadTester::TestFunction, this, 14ull);
	testThread->join();
}

void ThreadTester::TestFunction(unsigned long long testInt) {
	std::cout << "Number is: " << testInt << std::endl;
}

void Example07() {
	ThreadTester* threadTester = new ThreadTester();
	threadTester->Exemple07();
}