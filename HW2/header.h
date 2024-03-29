// header.h: 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
//

#pragma once

#ifdef UNICODE

#else

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console") 

#endif

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#include <math.h>
#include <iostream>
#include <fstream>

#define WIDTH 800
#define HEIGHT 600

#define MAX_TIME 15

#define NUM 6

enum class state
{
	Normal,
	PlayRecord,
	StartRecord
};