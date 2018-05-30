#include "header.h"
#include "Sound.h"


Sound_Func::Sound_Func()
{
	FMOD::System_Create(&pSystem);
	pSystem->init(
		NUM
		, FMOD_INIT_NORMAL
		, nullptr
	);

	for (auto& p : pSound) p = nullptr;
}


Sound_Func::~Sound_Func()
{
	for (int i = 0; i < NUM; ++i)
	{
		pSound[i]->release();
	}


	pSystem->release();
	pSystem->close();
}


void Sound_Func::Add_sound()
{
	pSystem->createStream(
		"Sound/Back.MP3"
		, FMOD_DEFAULT | FMOD_LOOP_NORMAL
		, nullptr
		, &pSound[0]
	);
	pSystem->createStream(
		"Sound/no money.mp3"
		, FMOD_DEFAULT | FMOD_LOOP_NORMAL
		, nullptr
		, &pSound[1]
	);
	pSystem->createStream(
		"Sound/stage up.mp3"
		, FMOD_DEFAULT | FMOD_LOOP_NORMAL
		, nullptr
		, &pSound[2]
	);
	pSystem->createStream(
		"Sound/tesla sound.mp3"
		, FMOD_DEFAULT | FMOD_LOOP_NORMAL
		, nullptr
		, &pSound[3]
	);
	pSystem->createStream(
		"Sound/VIOLA_SKILL1.mp3"
		, FMOD_DEFAULT | FMOD_LOOP_NORMAL
		, nullptr
		, &pSound[4]
	);
	pSystem->createStream(
		"Sound/VIOLA_SKILL2.mp3"
		, FMOD_DEFAULT | FMOD_LOOP_NORMAL
		, nullptr
		, &pSound[5]
	);
	
}

void Sound_Func::Play_bgm(int type)
{
	pSystem->playSound(pSound[type]
		, nullptr, false, &pChannel[type]);
}

void Sound_Func::Stop_bgm(int type)
{
	bool bPlaying;
	pChannel[type]->isPlaying(&bPlaying);
	if (bPlaying)
		pChannel[type]->stop();
}
