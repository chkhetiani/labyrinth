#include <fstream>
#include "position.h">
namespace labyrinth {
	int currentMoveCount;
	Position currentPosition;
	char icon;
	int LevelsUnlocked;
	
	void newIcon(char newIcon){
		std::ofstream iconF("icon.txt");
		icon = newIcon;
		iconF << newIcon;
		iconF.close();
	}
}
