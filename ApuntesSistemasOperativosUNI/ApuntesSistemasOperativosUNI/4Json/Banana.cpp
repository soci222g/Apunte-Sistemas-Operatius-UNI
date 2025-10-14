#include "Banana.h"

Json::Value Banana::Code()
{
	Json::Value json = Fruta::Code();
	json["bananidad"] = banananidad;
	json[Decodekey()] = typeid(Banana).name();
	ICodeable::CodeSubClassType<Banana>(json);
	return json;

}

void Banana::Decode(Json::Value json)
{
	Fruta::Decode(json);
	banananidad = json[banananidad].asUInt();

}
