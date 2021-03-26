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
	Position endPosition;
	Level currentLevel;
	
	bool translateLevelFile(char file){
		if (file-'0' <= LevelsUnlocked){
			std::string fileN = std::string("levels\\") + file + std::string(".txt");
			std::ifstream level(fileN);
			
			std::string line;
			
			getline(level,line);
			currentLevel.height = stoi(line);
			
			getline(level,line);
			currentLevel.width = stoi(line);
			
			getline(level,line);
			currentLevel.start.first = stoi(line);
			currentPosition.x = currentLevel.start.first-1;
			
			getline(level,line);
			currentLevel.start.second = stoi(line);
			currentPosition.y = currentLevel.start.second-1;
			
			getline(level,line);
			currentLevel.end.first = stoi(line);
			endPosition.x = currentLevel.end.first-1;
			
			getline(level,line);
			currentLevel.end.second = stoi(line);
			endPosition.y = currentLevel.end.second-1;
			
			getline(level,line);
			currentLevel.moveCount = stoi(line);
			currentMoveCount = currentLevel.moveCount;
			
			currentLevel.map[currentLevel.start.first-1][currentLevel.start.second-1] = icon;
			currentLevel.map[currentLevel.end.first-1][currentLevel.end.second-1] = 'O';
			for(int i=0;i<=currentLevel.height;i++){
				getline(level,line);
				for(int j=0;j<currentLevel.width;j++){
					if (i == endPosition.x && j == endPosition.y){
						currentLevel.map[i][j];
					}
					else{
						currentLevel.map[i][j] = line[j];
					}
				}
			}
			currentLevel.map[currentPosition.x][currentPosition.y] = icon;
			currentLevel.map[endPosition.x][endPosition.y] = 'O';
			
			level.close();
			return true;
		}
		else {
			std::cout << "level locked\n";
			return false;
		}
	}
	void drawLevel(){
		for(int i=0;i<currentLevel.height;i++){
			for(int j=0;j<currentLevel.width;j++){
			std::cout << currentLevel.map[i][j];
			}
			if (i<currentLevel.height-1){
				std::cout << "\n";
			}
		}
	}
	void makeMove(char character){
		char space = '-';
		if(character == 'w'){
			if (currentLevel.map[currentPosition.x-1][currentPosition.y] == space ||currentLevel.map[currentPosition.x-1][currentPosition.y] =='O'){
				currentLevel.map[currentPosition.x][currentPosition.y] = space;
				currentPosition.x--;
				currentLevel.map[currentPosition.x][currentPosition.y] = icon;
				currentMoveCount--;
			}
		}
		else if(character == 'a'){
			if (currentLevel.map[currentPosition.x][currentPosition.y-1] == space ||currentLevel.map[currentPosition.x][currentPosition.y-1] =='O'){
				currentLevel.map[currentPosition.x][currentPosition.y] = space;
				currentPosition.y--;
				currentLevel.map[currentPosition.x][currentPosition.y] = icon;
				currentMoveCount--;
			}
		}
		else if(character == 'd'){
			if (currentLevel.map[currentPosition.x][currentPosition.y+1] == space ||currentLevel.map[currentPosition.x][currentPosition.y+1] =='O'){
				currentLevel.map[currentPosition.x][currentPosition.y] = space;
				currentPosition.y++;
				currentLevel.map[currentPosition.x][currentPosition.y] = icon;
				currentMoveCount--;
			}
		}
		else if(character == 's'){
			if (currentLevel.map[currentPosition.x+1][currentPosition.y] == space||currentLevel.map[currentPosition.x+1][currentPosition.y] == 'O'){
				currentLevel.map[currentPosition.x][currentPosition.y] = space;
				currentPosition.x++;
				currentLevel.map[currentPosition.x][currentPosition.y] = icon;
				currentMoveCount--;
			}
		}
		if (currentPosition.x == endPosition.x && currentPosition.y == endPosition.y){
			currentLevel.won=true;
		}
	}
	
	void drawLevel(char map[][100],int height,int width){
		for(int i=0;i<height;i++){
			for(int j=0;j<width;j++){
				std::cout << map[i][j];
			}
		}
	}
	
	void saveGame(){
		std::ofstream file("info.txt");
		file << LevelsUnlocked;
	}
}
