#include "knight.h"
#include "game.h"
extern Game * game;
Knight::Knight(QString side, bool promotionPiece) : ChessPiece(side, promotionPiece)
{
    setImage();
}


QString Knight::type()
{
    return "KNIGHT";
}

void Knight::setImage()
{
    if(m_side == "WHITE") {
        setPixmap(QPixmap(":/chesspiece/images/ChessPieces/WhiteKnight.png"));
    } else {
        setPixmap(QPixmap(":/chesspiece/images/ChessPieces/BlackKnight.png"));
    }
}

void Knight::generatePossibleMoves()
{
    m_possibleMoves.clear();
    int row = this->currentField()->row();
    int col = this->currentField()->column();

    int i, j;
    //first position top-top-left
    i = row - 2;
    j = col - 1;
    if(i >= 0 && j >= 0 && (game->board->fieldAt(i, j)->isItFree()
                            || (!game->board->fieldAt(i, j)->isItFree() && game->board->fieldAt(i, j)->currentPiece->side() != this->side()))) {
        m_possibleMoves.append(game->board->fieldAt(i, j));
        if(!isLegalMove(game->board->fieldAt(i, j))) {
            m_possibleMoves.removeLast();
        } else {
            colorAvailableFields(m_possibleMoves.last());
        }
    }

    //second position top-top-right
    i = row - 2;
    j = col + 1;
    if(i >= 0 && j <= 7 && (game->board->fieldAt(i, j)->isItFree()
                            || (!game->board->fieldAt(i, j)->isItFree() && game->board->fieldAt(i, j)->currentPiece->side() != this->side()))) {
        m_possibleMoves.append(game->board->fieldAt(i, j));
        if(!isLegalMove(game->board->fieldAt(i, j))) {
            m_possibleMoves.removeLast();
        } else {
            colorAvailableFields(m_possibleMoves.last());
        }
    }

    //third position top-right-right
    i = row - 1;
    j = col + 2;
    if(i >= 0 && j <= 7 && (game->board->fieldAt(i, j)->isItFree()
                            || (!game->board->fieldAt(i, j)->isItFree() && game->board->fieldAt(i, j)->currentPiece->side() != this->side()))) {
        m_possibleMoves.append(game->board->fieldAt(i, j));
        if(!isLegalMove(game->board->fieldAt(i, j))) {
            m_possibleMoves.removeLast();
        } else {
            colorAvailableFields(m_possibleMoves.last());
        }
    }

    //fourth position top-left-left
    i = row - 1;
    j = col - 2;
    if(i >= 0 && j >= 0 && (game->board->fieldAt(i, j)->isItFree()
                            || (!game->board->fieldAt(i, j)->isItFree() && game->board->fieldAt(i, j)->currentPiece->side() != this->side()))) {
        m_possibleMoves.append(game->board->fieldAt(i, j));
        if(!isLegalMove(game->board->fieldAt(i, j))) {
            m_possibleMoves.removeLast();
        } else {
            colorAvailableFields(m_possibleMoves.last());
        }
    }

    //fifth position bottom-left-left
    i = row + 1;
    j = col - 2;
    if(i <= 7 && j >= 0 && (game->board->fieldAt(i, j)->isItFree()
                            || (!game->board->fieldAt(i, j)->isItFree() && game->board->fieldAt(i, j)->currentPiece->side() != this->side()))) {
        m_possibleMoves.append(game->board->fieldAt(i, j));
        if(!isLegalMove(game->board->fieldAt(i, j))) {
            m_possibleMoves.removeLast();
        } else {
            colorAvailableFields(m_possibleMoves.last());
        }
    }

    //sixth position bottom-right-right
    i = row + 1;
    j = col + 2;
    if(i <= 7 && j <= 7 && (game->board->fieldAt(i, j)->isItFree()
                            || (!game->board->fieldAt(i, j)->isItFree() && game->board->fieldAt(i, j)->currentPiece->side() != this->side()))) {
        m_possibleMoves.append(game->board->fieldAt(i, j));
        if(!isLegalMove(game->board->fieldAt(i, j))) {
            m_possibleMoves.removeLast();
        } else {
            colorAvailableFields(m_possibleMoves.last());
        }
    }

    //seventh position bottom-bottom-right
    i = row + 2;
    j = col + 1;
    if(i <= 7 && j <= 7 && (game->board->fieldAt(i, j)->isItFree()
                            || (!game->board->fieldAt(i, j)->isItFree() && game->board->fieldAt(i, j)->currentPiece->side() != this->side()))) {
        m_possibleMoves.append(game->board->fieldAt(i, j));
        if(!isLegalMove(game->board->fieldAt(i, j))) {
            m_possibleMoves.removeLast();
        } else {
            colorAvailableFields(m_possibleMoves.last());
        }
    }

    //eighth position bottom-bottom-left
    i = row + 2;
    j = col - 1;
    if(i <= 7 && j >= 0 && (game->board->fieldAt(i, j)->isItFree()
                            || (!game->board->fieldAt(i, j)->isItFree() && game->board->fieldAt(i, j)->currentPiece->side() != this->side()))) {
        m_possibleMoves.append(game->board->fieldAt(i, j));
        if(!isLegalMove(game->board->fieldAt(i, j))) {
            m_possibleMoves.removeLast();
        } else {
            colorAvailableFields(m_possibleMoves.last());
        }
    }


}
