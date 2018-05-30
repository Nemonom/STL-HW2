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
	Sound * pSound[NUM];
	Channel * pChannel[NUM];

	void Add_sound();
	void Play_bgm(int type);
	void Stop_bgm(int type);
};

