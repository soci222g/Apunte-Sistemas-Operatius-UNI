#pragma once
#include"ICodeable.h"

class Fruta : public ICodeable
{
public:
	unsigned int semillas = 0;
	std::string hexColor = "";
	

	virtual Json::Value Code() override;

	virtual void Decode(Json::Value json) override;
};


