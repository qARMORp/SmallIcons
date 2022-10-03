#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <filesystem>
#include <nlohmann/json.hpp>

class Config
{
public:
	struct ConfigData
	{
		float SIZE = 0.7;
		float PLAYERSSIZE = 0.7;
	};

	static void Save();
	static void Load();

	static struct ConfigData* Get();
private:
	static std::filesystem::path GetConfig();
}; // class Config

#endif // !_CONFIG_H_