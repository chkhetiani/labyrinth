namespace labyrinth {
	class Level {
		int height;
		int width;
		char map[][20];
		std::pair<int,int> start;
		std::pair<int,int> end;
		int moveCount;
	};
}
