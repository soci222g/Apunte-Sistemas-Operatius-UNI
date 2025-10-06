#include "preguntas.h"

Preguntes::Preguntes(std::vector<std::string> Respuestes, int PreguntaCorrecta, int timerPregunta)
{

	respuestes = Respuestes;


	numeroPreguntes = respuestes.size();
	preguntaCorrecta = PreguntaCorrecta;

	TimerPregunta = timerPregunta;
}

