#include "Apple.h"

Json::Value Apple::Code()
{
	Json::Value json = Fruta::Code();
	json["Applidad"] = Applidad;
	json[Decodekey()] = typeid(Apple).name();
	ICodeable::CodeSubClassType<Apple>(json);
	return json;
}

void Apple::Decode(Json::Value json)
{

	Fruta::Decode(json);
	Applidad = json[Applidad].asUInt();
}
