#pragma once
#include <bass.h>
#include <map>

class Audio
{
public:

	//static std::map<std::string, Audio*> sLoadedAudios; //para nuestro manager
	HSAMPLE sample; //aqui guardamos el handler del sample que retorna BASS_SampleLoad

	Audio(); //importante poner sample a cero aqui
	~Audio(); //aqui deberiamos liberar el sample con BASS_SampleFree

	HCHANNEL play(float volume); //lanza el audio y retorna el channel donde suena

	static void Stop(HCHANNEL channel); //para parar un audio necesitamos su channel
	static Audio* Get(const char* filename); //manager de audios 
	static HCHANNEL* Play(const char* filename); //version est�tica para ir mas rapido

	HSAMPLE LoadSample(const char* fileName, bool isLooped);
	void PlayGameSound(const char* fileName, bool isLooped);
};

