namespace labyrinth {
	class Game {
		int moves;
		int level;
		Position player_position;
		Level level;
	};
//	void getInput(){
//		char a;
//		cin >>> a;
//		if(a=='w'){
//		}
//	}
	void drawLevel(char map[][],int heigth,int width){
		for(int i=0;i<height;i++){
			for(int j=0;j<width;j++){
				cout << map[i][j];
			}
		}
	}
}
