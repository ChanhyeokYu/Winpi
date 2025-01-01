#include "pch.h"
#include "ReadingManager.h"
#include <fstream>
#include "json.hpp"

using namespace nlohmann;

void ReadingManager::OpenFile()
{
	SetConsoleOutputCP(CP_UTF8);
	ifstream file("test.json", ios::in);

	if (!file.is_open())
	{
		cerr << "Error open!";
	}
	
	json j;
	file >> j;

	map<string, string> word_map;
	for (const auto& result : j["results"])
	{
		word_map[result["Wording"].get<string>()] = result["Wordresult"].get<string>();
	}

	for (const auto& pair : word_map)
	{
		cout << pair.first << ": " << pair.second << "\n";
	}

	file.close();
}
