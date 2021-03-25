#include <fstream>
#include <iostream>

namespace labyrinth{
	void loadLevelCount(){
		std::ifstream info("info.txt");
		std::string line;
		getline(info,line);
		std::cout << line << std::endl;
		info.close();
	}
}
