#include <iostream>
#include "dist/json/json.h"
#include <fstream>


#include "TutorialThreads/ThreadTutorial.h"
#include "Utils/ConsoleControl.h"
#include "3NodeMap/NodeMap.h"
#include "InputSytem/InputSystem.h"
#include "4Json/ICodeable.h"
#include "4Json/Apple.h"
#include "4Json/Banana.h"





int main()
{
	ICodeable::SaveDecodeProcces<Banana>();
	ICodeable::SaveDecodeProcces<Apple>();


	std::vector<Fruta*> frutas{

		new Banana(),
		new Apple(),
		new Apple()
	};

	Json::Value jsonArray = Json::Value(Json::arrayValue);
	for (Fruta* fruta : frutas) {
		jsonArray.append(fruta->Code());
	}

	std::ofstream jsonWriteFile = std::ofstream("FrutasTest.json", std::ifstream::binary);

	if (!jsonWriteFile.fail()) {
		jsonWriteFile << jsonArray;
		jsonWriteFile.close();
	}

	std::cout << "finsh Writhe";
	std::ifstream jsonReadFile = std::ifstream("FrutasTest.json", std::ifstream::binary);
	std::vector<Fruta*> readFrutas;

	if (!jsonReadFile.fail()) {
		Json::Value readedJson;

		jsonReadFile >> readedJson;

		for (Json::Value value : readedJson) {
			Fruta* f = ICodeable::FormJson<Fruta>(value);
			readFrutas.push_back(f);
		}
	}
	while (true)
	{

	}
}

