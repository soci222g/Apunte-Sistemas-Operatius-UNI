#include "ICodeable.h"

std::string ICodeable::Decodekey()
{
	return "IcodeableType";
}

void ICodeable::SaveDecodeProcces(std::string ClassName, subClassDecode decodeProcces)
{
	ICodeable::GetDecodeMap()->emplace(ClassName, decodeProcces);

}

ICodeable::DecoMap* ICodeable::GetDecodeMap()
{
	static DecoMap* map = new DecoMap();
	return map;
}
