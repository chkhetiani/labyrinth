#include "level.h"
#include "info.h"
#include <fstream>
namespace labyrinth {
	class Game {
		int moves;
		int level1;
		Position player_position;
		Level level;
	};
	void loadCount(){
		std::ifstream info("info.txt");
		std::string line;
		getline(info,line);
		int ll=0,k=1;
		for(int i=line.length()-1;i>=0;i--){
			ll+=(line[i]-'0')*k;
			k*=10;
			cout << ll << endl;
		}
		LevelsUnlocked = ll;
		info.close();
	}
	
	void translateLevelFile(char file){
		if (file-'0' <= LevelsUnlocked){
			std::string fileN = std::string("levels\'") + file + std::string(".txt");
			std::ifstream level(fileN);
		}
	}
	
	void saveGame(){
		std::ofstream file("info.txt");
		file << LevelsUnlocked;
	}
	
	void drawLevel(char map[][20],int height,int width){
		for(int i=0;i<height;i++){
			for(int j=0;j<width;j++){
				std::cout << map[i][j];
			}
		}
	}
}
