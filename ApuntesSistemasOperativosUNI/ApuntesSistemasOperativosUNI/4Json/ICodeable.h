#pragma once
#include "../dist/json/json.h"
#include<functional>
#include<string>



class ICodeable
{
public:
	typedef std::function<ICodeable* ()> subClassDecode;
	typedef std::map<std::string, subClassDecode> DecoMap;

public:
	static std::string Decodekey();
	static void SaveDecodeProcces(std::string ClassName, subClassDecode decodeProcces);

	template<typename T, typename = typename std::enable_if<
			std::is_base_of<
				ICodeable, T
			>::value
		>::type >
	static void SaveDecodeProcces() {
		SaveDecodeProcces(typeid(T).name(), []() {
			return new T();
			});
	}

	virtual Json::Value Code() = 0;
	virtual void Decode(Json::Value json);

	template<typename T, typename = typename std::enable_if<
		std::is_base_of<
		ICodeable, T
		>::value
		>::type 
	>
	static T* FormJson(Json::Value json) {
		std::string className = json[Decodekey()].asString();

		ICodeable* codeable = (*GetDecodeMap())[className]();

		DecoMap* DecoMap = GetDecodeMap();
		subClassDecode decodeLamda = (*DecoMap)[className];
		ICodeable* codable = decodeLamda();


		T* CodableCasted = dynamic_cast<T*>(codable);
		CodableCasted->Decode(json);
		return CodableCasted;
	}
protected:
	template<typename T, typename = typename std::enable_if<
		std::is_base_of<
		ICodeable, T
		>::value
	>::type
	>
	void CodeSubClassType(Json::Value& json) {
		json[Decodekey()] = typeid(T).name();
	}



private:
	static DecoMap* GetDecodeMap();
};

