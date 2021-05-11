#include <windows.h>
#include <thread>

constexpr auto SERVERBROWSER = "serverbrowser.dll";

void Main(HINSTANCE instance)
{
	while (!GetModuleHandle(SERVERBROWSER))
		std::this_thread::sleep_for(std::chrono::milliseconds(200));

	FreeLibraryAndExitThread(instance, EXIT_SUCCESS);
}

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(instance);

		if (const auto handle = CreateThread(0, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(Main), instance, 0, 0))
			CloseHandle(handle);
	}

	return TRUE;
}
