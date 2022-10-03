#include "Config.h"
#include <Windows.h>
#include <fstream>


struct Config::ConfigData ConfigData_;

struct Config::ConfigData* Config::Get() {
	return &ConfigData_;
}

using json = nlohmann::json;


void Config::Save() {

	json j;

	j["Settings"]["SIZE"] = ConfigData_.SIZE;
	j["Settings"]["PLAYERSSIZE"] = ConfigData_.PLAYERSSIZE;


	std::ofstream(GetConfig().string()) << j.dump(4);
}

void Config::Load() {
	std::ifstream config(GetConfig().string());
	if (!config.is_open()) {
		return Save();
	}

	try {
		std::string content = std::string((std::istreambuf_iterator<char>(config)), std::istreambuf_iterator<char>());
		auto json = nlohmann::json::parse(content);

		// Settings
		json["Settings"]["SIZE"].get_to<float>(ConfigData_.SIZE);
		json["Settings"]["PLAYERSSIZE"].get_to<float>(ConfigData_.PLAYERSSIZE);

	}
	catch (...) {
		Save();
	}

	config.close();
}

std::filesystem::path Config::GetConfig() {
	std::filesystem::path path = std::filesystem::current_path();
	std::filesystem::path name = "SmallIcons";
	return (path / (name.string() + ".json"));
}