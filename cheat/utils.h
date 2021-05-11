#pragma once

struct Utilities
{
	inline void* GetVirtual(void* thisPtr, size_t index)
	{
		return (*static_cast<void***>(thisPtr))[index];
	}

	template <typename T, typename ... Args>
	inline T CallVirtual(void* thisPtr, size_t index, Args... args)
	{
		return (*static_cast<T(__thiscall*)(void*, decltype(args)...)**>(thisPtr))[index](thisPtr, args...);
	}
};

inline Utilities utils{};
