#pragma once
#include <string>

//Load .ini file and provide 
class Setting {
public:
	static void Init(std::string path);
	static void ReadAll();
	static void Read(std::string key);
	static void Write();

/*
			attributes
*/

//Video
	static unsigned int FPS_LIMIT;
	static float FOV;
//Resolution
	static unsigned int WIDTH;
	static unsigned int HEIGHT;
//Input
	static float SENS;
	static uint32_t FORWARD;
	static uint32_t BACKWARD;
	static uint32_t RIGHT;
	static uint32_t LEFT;
	static uint32_t JUMP; //also up
	static uint32_t DOWN;
	//static uint32_t SHOOT;
	//static uint32_t RELOAD;
//Volume

private:
	static std::string file_path;
};