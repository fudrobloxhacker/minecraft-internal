#include <thread>
#include <chrono>
#include <Windows.h>
#include "modules/Cheat.h"
#include "javaclass.h"
#include "hook/hook.h"

void __stdcall MainThread(HINSTANCE instance)
{
	mci->jvm->AttachCurrentThread((void**)&mci->env, nullptr);

	if (Hook::init())
		goto _shutdown;

	while (!GetAsyncKeyState(VK_DELETE))
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(4));
	}

_shutdown:
	Hook::shutdown();
	FreeLibrary(instance);
}

bool __stdcall DllMain(HINSTANCE instance, DWORD reason, LPVOID p_reserved)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(instance);

		AllocConsole();
		freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);

		if (static std::thread main_thread([instance] { MainThread(instance); }); main_thread.joinable())
			main_thread.detach();
	}
	else if (reason == DLL_PROCESS_DETACH)
	{
		FreeConsole();
		fclose(stdout);
	}

	return true;
}