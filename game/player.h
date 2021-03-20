#include <fstream>
namespace labyrinth {
	int currentMoveCount;
	position currentPosition;
	char icon;
	void newIcon(char newIcon){
		ofstream icon("icon.txt");
		icon << newIcon;
	}
}
