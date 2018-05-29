#include "header.h"
#include "Sound.h"


Sound_Func::Sound_Func()
{
	FMOD::System_Create(&pSystem);
	pSystem->init(
		FMOD_MAX_CHANNEL_WIDTH
		, FMOD_INIT_NORMAL
		, nullptr
	);

	for (auto& p : pSound) p = nullptr;
}


Sound_Func::~Sound_Func()
{
	for (int i = 0; i < SOUND_NUM; ++i)
	{
		pSound[i]->release();
	}



	pSystem->release();
	pSystem->close();
}


void Sound_Func::Add_sound()
{
	pSystem->createSound(
		"Sound/VIOLA_SKILL1.mp3"
		, FMOD_DEFAULT | FMOD_LOOP_OFF
		, nullptr
		, &pSound[(int)ENUM_SOUND::TEST]
	);

	
	pSystem->createStream(
		"Sound/Fez - Adventure.mp3"
		, FMOD_LOOP_NORMAL | FMOD_2D
		, nullptr
		, &pSound[(int)ENUM_SOUND::BACK1]
	);
	
}

void Sound_Func::Play_bgm(ENUM_SOUND type)
{
	pSystem->playSound(pSound[(int)type]
		, nullptr, false, &pChannel[0]);
}

void Sound_Func::Play_effect(ENUM_SOUND type)
{
	pSystem->update();
	pSystem->playSound(pSound[(int)type]
		, nullptr, false, &pChannel[1]);
}

void Sound_Func::Stop_bgm(ENUM_SOUND type)
{
	bool bPlaying;
	pChannel[0]->isPlaying(&bPlaying);
	if (bPlaying)
		pChannel[0]->stop();
}
