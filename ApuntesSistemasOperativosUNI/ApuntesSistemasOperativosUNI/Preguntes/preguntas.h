#pragma once
#include <string>
#include <vector>


class Preguntes
{
public:
	Preguntes(std::vector<std::string> Respuestes, int PreguntaCorrecta,  int timerPregunta);

	int GetNumRespuestas() { return numeroPreguntes; }




private:
	int preguntaCorrecta;

	int numeroPreguntes;
	std::vector<std::string> respuestes;

	float TimerPregunta;
	float currentTimePregunta;
};

