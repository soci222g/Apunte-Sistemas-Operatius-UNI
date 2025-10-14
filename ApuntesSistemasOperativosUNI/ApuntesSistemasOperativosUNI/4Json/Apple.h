#pragma once
#include "Fruta.h"


class Apple : public Fruta
{
public:
	int Applidad = 0;


	virtual Json::Value Code() override;

	virtual void Decode(Json::Value json) override;
};
