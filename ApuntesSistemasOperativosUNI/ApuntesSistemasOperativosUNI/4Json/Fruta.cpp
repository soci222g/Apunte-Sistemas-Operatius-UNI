#include "Fruta.h"
Json::Value Fruta::Code() {
	Json::Value json;
	json["Semillas"] = semillas;
	json["hexColor"] = hexColor;
	return json;

}

void Fruta::Decode(Json::Value json)
{
	semillas = json["Semillas"].asUInt();
	hexColor = json["hexColor"].asString();
}



