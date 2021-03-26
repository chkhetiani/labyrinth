namespace labyrinth{
	bool loadLevels(int number){
		if (number > LevelsUnlocked){
			return true;
		}
		else{
			return false;
		}
	}
	void printLevels(){
		for(int i=1;i<=5;i++){
			std::cout << "level: " << i;
			if (loadLevels(i) == true){
				std::cout << " [level locked]";
			}
			std::cout << "\n";
			}
	}
	void loadInfo(){
		std::ifstream levelCountF("info.txt");
		std::string line;
		getline(levelCountF,line);
		LevelsUnlocked = stoi(line);
		levelCountF.close();
		
		std::ifstream iconF("icon.txt");
		std::string symbol;
		getline(iconF,symbol);
		icon = symbol[0];
		iconF.close();
	}
}
