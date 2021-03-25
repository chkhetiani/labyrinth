#include <iostream>
#include "game\player.h"
#include "game\game.h"
using namespace std;
using namespace labyrinth;

int main() {
	loadCount();
	bool started = true;
	while(started){
		string nn;
		cin >> nn;
		if (nn == "icon"){
			char a;
			cin >> a;
			newIcon(a);
		}
		cout << LevelsUnlocked;
		if (nn=="a"){
			LevelsUnlocked++;
		}
		if (nn == "exit"){
			saveGame();
			return 0;
		}
	}
}
