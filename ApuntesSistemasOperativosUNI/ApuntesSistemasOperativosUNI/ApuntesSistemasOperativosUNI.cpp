#include <iostream>
#include<string>
#include<list>

#include"Utils/ConsoleControl.h"
#include"Utils/Timer.h"

#include"1TutoThreads/ThreadTuto.h"
#include"2InputSistem/InputSystem.h"
#include"3NodeMap/INodeContent.h"



#include <functional>
#include "3NodeMap/Node.h"
#include "3NodeMap/NodeMap.h"

typedef std::function<int(int, int)> SumaFunction;

void TestLambda(SumaFunction funcion) {

	std::cout << "ejecutar funcion" << std::endl;

	int number  = funcion(5,7);

	std::cout << "resulatado: " << number << std::endl;
	std::cout << "funcion ejecutada" << std::endl;

}
typedef std::list<std::list<int>> ListaDeListasINT; // permet renumbrar sistema de guardat com variavles o functions i les pots renumbrar.



/*
std::string name = "Marco";

ListaDeListasINT listaDeLista;

//una funcio lanmda permet guarda contingut de una funcio en una varaible.
	SumaFunction functionQueHaceCosasPeroEsUnaVariable = [name](int a, int b){ //aixo es una estructura de una funcio lambda aixo es per copia, normalment son punters.
	std::cout << "Esto no se como per funciona XD --> " << name << std::endl;
	return a + b;
	};

TestLambda(functionQueHaceCosasPeroEsUnaVariable);
*/



//input sistem

/* 

	InputSystem* IS = new InputSystem();
	InputSystem::KeyBinding* KB1 = IS->addListener(K_1, []() {
		CC::Lock();
		std::cout << "prest 1" << std::endl;
		CC::Unlock();
	});

	InputSystem::KeyBinding* KB2 = IS->addListener(K_2, []() {
		CC::Lock();
		std::cout << "prest 2" << std::endl;
		CC::Unlock();
		});

	InputSystem::KeyBinding* KB3 = IS->addListener(K_3, []() {
		CC::Lock();
		std::cout << "prest 3" << std::endl;
		CC::Unlock();
		});

	InputSystem::KeyBinding* KB4 = IS->addListener(K_4, []() {
		CC::Lock();
		std::cout << "prest 4" << std::endl;
		CC::Unlock();
		});





	IS->StartListener();
*/



class Tree : public INodeContent {
	
	void Draw(Vector2 offset) override {
		CC::Lock();
		CC::SetColor(CC::DARKBLUE, CC::BLACK);
		CC::SetPosition(offset.X, offset.Y);
		std::cout << "T";

		CC::Unlock();

	}

};

class Potatoe {

};


int main()
{

	NodeMap* myMap = new NodeMap(Vector2(30, 30), Vector2(2, 2));

	Tree* t1 = new Tree();
	Tree* t2 = new Tree();
	Tree* t3 = new Tree();
	Tree* t4 = new Tree();
	Tree* t5 = new Tree();

	myMap->SafePickNode(Vector2(0, 0), [t1](Node* node) {

		node->setContent(t1);
		});


	myMap->SafePickNode(Vector2(29, 0), [t2](Node* node) {

		node->setContent(t2);
		});


	myMap->SafePickNode(Vector2(0, 29), [t3](Node* node) {

		node->setContent(t3);
		});


	myMap->SafePickNode(Vector2(16, 16), [t4](Node* node) {

		node->setContent(t4);
		});


	myMap->SafePickNode(Vector2(29, 29), [t5](Node* node) {

		node->setContent(t5);
		});



	while (true)
	{

	}
}


