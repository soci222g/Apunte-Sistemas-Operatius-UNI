#include <iostream>
#include<string>
#include<list>

//#include"Utils/ConsoleControl.h"
#include"1TutoThreads/ThreadTuto.h"

#include <functional>

typedef std::function<int(int, int)> SumaFunction;

void TestLambda(SumaFunction funcion) {

	std::cout << "ejecutar funcion" << std::endl;

	int number  = funcion(5,7);

	std::cout << "resulatado: " << number << std::endl;
	std::cout << "funcion ejecutada" << std::endl;

}
typedef std::list<std::list<int>> ListaDeListasINT; // permet renumbrar sistema de guardat com variavles o functions i les pots renumbrar.
int main()
{
	std::string name = "Marco";

	ListaDeListasINT listaDeLista;

	//una funcio lanmda permet guarda contingut de una funcio en una varaible.
		SumaFunction functionQueHaceCosasPeroEsUnaVariable = [name](int a, int b){ //aixo es una estructura de una funcio lambda aixo es per copia, normalment son punters.
		std::cout << "Esto no se como per funciona XD --> " << name << std::endl;
		return a + b;
		};

	TestLambda(functionQueHaceCosasPeroEsUnaVariable);
}


