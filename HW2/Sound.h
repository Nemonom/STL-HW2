#pragma once

#include "FMOD\include\fmod.hpp"

#pragma comment(lib, "FMOD/lib/fmod64_vc.lib")


using namespace FMOD;

class Sound_Func
{
public:
	Sound_Func();
	~Sound_Func();

public:
	System * pSystem;
	Sound * pSound[SOUND_NUM];
	Channel * pChannel[2];

	void Add_sound();
	void Play_bgm(ENUM_SOUND type);
	void Play_effect(ENUM_SOUND type);
	void Stop_bgm(ENUM_SOUND type);
};

