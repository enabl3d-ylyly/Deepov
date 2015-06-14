//============================================================================
// Name        : Deepov.cpp
// Author      : Romain Goussault
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <vector>
#include <memory>
#include <iostream>
#include <chrono>
#include <ctime>
#include <ratio>

#include "Color.hpp"
#include "Eval.hpp"
#include "Search.hpp"
#include "Board.hpp"
#include "MoveGen.hpp"
#include "Move.hpp"
#include "MagicMoves.hpp"
#include "Utils.hpp"



int main() {

	MagicMoves::initmagicmoves();

	std::shared_ptr<Board> sp = std::shared_ptr<Board>(new Board("k4K2/8/8/3q4/8/1R3N1P/8/8 b - -"));

	Search search(sp);
	std::cout << search.negaMaxRoot(3,0,0) << std::endl;
	Move move = search.myBestMove;

	std::cout << *sp << std::endl;
	std::cout << move.toShortString()<< std::endl;

	sp->executeMove(move);

	std::cout << *sp << std::endl;

/*
	Utils::getPerformanceIndicator();
	Utils::getPerformanceIndicator();
	//Romain : 9sec = 1 705 014 Nodes/sec
	// -O3  10 024 446 Nodes/sec
	// Navid -O3  100 000 Nodes/sec
	//Stockfish 180 385 601Nodes/sec

*/
    std::string str;
    std::cin >> str;
	return 0;
}
