#ifndef HOOK_H_
#define HOOK_H_

#include <cstdio>

#include <Windows.h>

namespace Hook
{
	bool init();
	void shutdown();
	bool getIsInit();
}

#endif