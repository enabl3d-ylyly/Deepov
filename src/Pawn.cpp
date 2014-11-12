/*
 * Pawn.hpp
 */

#include "Pawn.hpp"

Pawn::Pawn(Position position, int color) : Piece(position, color)
{
}

std::vector<Move> Pawn::getPseudoLegalMoves(Board &board)
{
    std::vector<Move> pawnMoves;
    PiecePtr otherPiece;
    int direction = getDirection();

   if (isOnStartingRank())
   {
       if (board.isPositionFree(myPosition.deltaY(direction)) && board.isPositionFree(myPosition.deltaY(2*direction)))
       {
            Position destination(myPosition.deltaY(2*direction));
            Move possibleMove(myPosition,destination);
            pawnMoves.push_back(possibleMove);
       }
   }

   else if (isEnPassantPossible(board))
   {
            Position enemyPawnPosition(board.getEnemyLastMove()->getDestination());
            Move possibleMove(myPosition,enemyPawnPosition.deltaY(direction));
            possibleMove.setCapturedPiece(board.getPiecePtr(enemyPawnPosition));
            pawnMoves.push_back(possibleMove);
   }

    Position destination(myPosition.deltaY(direction));
    if (board.isPositionFree(destination))
    {
        if (this->isGoingToPromote())
        {

        }
        else
        {
            Move possibleMove(myPosition,destination);
            pawnMoves.push_back(possibleMove);
        }

    }
/*   else if
   int i = 1;
    Position destination = myPosition.deltaX(i);
    destination = destination.deltaY(i);
    while (board.isPositionOnBoard(destination))
    {
        Move possibleMove(myPosition, destination);

        if (board.isPositionFree(destination))
        {
            bishopMoves.push_back(possibleMove);
        }
        else
        {
            otherPiece = board.getPiecePtr(destination);
            // look for capture
            if (piecePtr->areColorDifferent(*otherPiece))
            {
                possibleMove.setCapturedPiece(otherPiece);
                bishopMoves.push_back(possibleMove);
            }
            break;
        }

        ++i;
        destination = myPosition.deltaX(i);
        destination = destination.deltaY(i);
    }
*/

    return pawnMoves;
}

std::vector<Move> Pawn::getPromotionMoves(Board &board, Position const& destination)
{
    std::vector<Move> movesList;
    Move possibleMove(myPosition,destination);
    possibleMove.setIsPromotion();

    return movesList;
}


int Pawn::getDirection() const {
    if (myColor == WHITE) {
        return 1;
    }
    else {
        return -1;
    }
}

bool Pawn::isOnGoodRankForEnPassant() const {
    if (myColor == WHITE) {
        return (myPosition.getY() == 4);
    }
    else {
        return (myPosition.getY() == 3);
    }
}

bool Pawn::isEnPassantPossible(Board &board) const {
    if (!isOnGoodRankForEnPassant())
    {
        return false;
    }
    else
    {
        boost::optional<Move> enemyLastMove(board.getEnemyLastMove());
        //bool isNotFirstMove = enemyLastMove; // True if there is a move in enemyLastMove

        if (enemyLastMove)
        {
            Position enemyMoveOrigin = enemyLastMove->getOrigin();
            Position enemyMoveDestination = enemyLastMove->getDestination();
            PiecePtr enemyPiece(board.getPiecePtr(enemyMoveDestination));

            std::shared_ptr<Pawn> isPawn = std::dynamic_pointer_cast<Pawn>(enemyPiece);
            // Convert to pawn shared pointer

            bool isEnemyPiecePawn(false);

            if (isPawn!=NULL) // if isPawn = NULL, enemyPiece was not a Pawn subclass of Piece
            {
                isEnemyPiecePawn = true;
            }

            bool isPlus2Move(std::abs(enemyMoveOrigin.getY() - enemyMoveDestination.getY()) == -2*getDirection());
            bool isOnNextColumn((enemyMoveDestination.getX() - myPosition.getX()) == 1);

            return(isEnemyPiecePawn && isPlus2Move && isOnNextColumn);
        }
        else
        {
            return false;
        }
    }

        return false;

}

bool Pawn::isOnStartingRank() const {
    if (myColor == WHITE) {
        return (myPosition.getY() == 1);
    }
    else {
        return (myPosition.getY() == 6);
    }
}

bool Pawn::isOnLastRank() const {
    if (myColor == WHITE) {
        return (myPosition.getY() == 7);
    }
    else {
        return (myPosition.getY() == 0);
    }
}

bool Pawn::isGoingToPromote() const{
    if (myColor == WHITE) {
        return (myPosition.getY() == 6);
    }
    else {
        return (myPosition.getY() == 1);
    }
}

