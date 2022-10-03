#include <Windows.h>
#include "Main.h"
#include <fstream>
#include <nlohmann/json.hpp>
#include "Config.h"

template<typename T>
void WriteMemory(void* addr, T value) {
	DWORD oldProt = 0;
	VirtualProtect(addr, sizeof(T), PAGE_EXECUTE_READWRITE, &oldProt);
	*reinterpret_cast<T*>(addr) = value;
	VirtualProtect(addr, sizeof(T), oldProt, NULL);
}

float size = Config::Get()->SIZE * 8;
float playersSizeX = Config::Get()->PLAYERSSIZE / 640;
float playersSizeY = playersSizeX * 1.42857152;
float borderX = playersSizeX + 0.0001;
float borderY = playersSizeY + 0.0001;

SmallIcons::SmallIcons() {
	
	Config::Load();

	// Map Icons
	WriteMemory<void*>(reinterpret_cast<void*>(0x586047), &size);
	WriteMemory<void*>(reinterpret_cast<void*>(0x586060), &size);
	
	// radar_centre
	WriteMemory<void*>(reinterpret_cast<void*>(0x5886DC), &size);

	// Box Player
	WriteMemory<void*>(reinterpret_cast<void*>(0x584192), &playersSizeX); // PlayerBoxX
	WriteMemory<void*>(reinterpret_cast<void*>(0x5841B2), &playersSizeY); // PlayerBoxY
	WriteMemory<void*>(reinterpret_cast<void*>(0x58410D), &borderX); // PlayerBoxBorderX
	WriteMemory<void*>(reinterpret_cast<void*>(0x58412D), &borderY); // PlayerBoxBorderY

	// Down Triangle
	WriteMemory<void*>(reinterpret_cast<void*>(0x5842E8), &playersSizeX); // DownTriangleX
	WriteMemory<void*>(reinterpret_cast<void*>(0x5842C8), &playersSizeY); // DownTriangleY
	WriteMemory<void*>(reinterpret_cast<void*>(0x58424B), &borderX); // DownTriangleBorderX
	WriteMemory<void*>(reinterpret_cast<void*>(0x584209), &borderY); // DownTrianglexBorderY

	// Up Triangle
	WriteMemory<void*>(reinterpret_cast<void*>(0x584436), &playersSizeX); // UpTriangleX
	WriteMemory<void*>(reinterpret_cast<void*>(0x58440E), &playersSizeY); // UpTriangleY
	WriteMemory<void*>(reinterpret_cast<void*>(0x58439E), &borderX); // UpTriangleBorderX
	WriteMemory<void*>(reinterpret_cast<void*>(0x584348), &borderY); // UpTriangleBorderY
}

SmallIcons::~SmallIcons() {
}
