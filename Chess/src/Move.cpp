//
// Created by ramih on 7/20/2024.
//
#include "Move.h"

shared_ptr<Move> Move::instance = nullptr;

Move::Move(BoardManager &b): board(b) {

}

ostream& operator<<(std::ostream& os, const Move& move) {
    os << move.board;
    return os;
}

Move &Move::getInstance(BoardManager &b) {
    if (!instance) {
        instance = shared_ptr<Move>(new Move(b));
    }
    return *instance;
}

Move &Move::getInstance() {
    return *instance;
}