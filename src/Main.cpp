
// Ca va groooos ?
//============================================================================
// Name        : Deepov.cpp
// Author      : Romain Goussault
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "Position.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Rook.hpp"


using namespace std;

int main()
{
    Position position2(1, 0);
    Board board;
	board.init(); //seg fault in this method?

    Rook rook2(position2, BLACK);
    board.addPiece(rook2);


/*
    std::vector<Move> rookMoves = rook.getPseudoLegalMoves(board); // should be 14
    cout << "number of pseudo legal moves should be 7: " << rookMoves.size() << endl;

   for( std::vector<Move>::const_iterator i = rookMoves.begin(); i != rookMoves.end(); ++i)
    {
        cout << *i << endl;
    }
   cout << "should be 1 :" << b << endl;*/
    return 0;
}


