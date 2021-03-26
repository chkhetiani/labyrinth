namespace labyrinth {
	struct Level {
		int height;
		int width;
		char map[][100];
		std::pair<int,int> start;
		std::pair<int,int> end;
		int moveCount;
		bool won = false;
	};
}
