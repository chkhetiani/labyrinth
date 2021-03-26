#include <iostream>
#include "game\player.h"
#include "game\game.h"
#include "Menu.h"
#include <conio.h>

using namespace std;
using namespace labyrinth;

int main() {
	loadInfo();
	bool started = true;
	while(started){
		cout << ":::::::::::::: MAIN MENU ::::::::::::::\n";
		cout << "Icon :: " << icon <<"\n";
		cout << ":: Commands :: \n:icon:\n:exit:\n:play:\n";
		string nn;
		cin >> nn;
		if (nn == "icon"){
			system("cls");
			cout << "Please Type In Your New Icon:";
			char a;
			cin >> a;
			newIcon(a);
			system("cls");
		}
		if (nn == "exit"){
			saveGame();
			return 0;
		}
		if (nn == "play"){
			system("cls");
			while(true){
				printLevels();
				cout << ":To Go Back To Main Menu Please Type 'M':\n";
				char levelNumber;
				cin >> levelNumber;
				if(levelNumber == 'M'){
					break;
				}
				while(translateLevelFile(levelNumber) == false){
					cin >> levelNumber;
					if (levelNumber == 'M'){
						break;
					}
				}
				while(currentMoveCount > 0){
					system("cls");
					char charr;
					drawLevel();
					charr = getch();
					makeMove(charr);
					if (currentLevel.won){
						LevelsUnlocked++;
						break;
					}
				}
				system("cls");
			}
		}
		system("cls");
	}
}
