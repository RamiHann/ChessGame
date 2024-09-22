#ifndef EXERCISE_1_CHESS_RAMIHANN_LOCATION_H
#define EXERCISE_1_CHESS_RAMIHANN_LOCATION_H


#include <iostream>
#include "BoardManager.h"

using namespace std;

class Move {
    BoardManager &board;
    static shared_ptr<Move> instance;

    Move(BoardManager &b);

public:
    Move(const Move &) = delete;

    Move &operator=(const Move &) = delete;

    static Move &getInstance(BoardManager &b);

    static Move &getInstance();

    friend ostream &operator<<(std::ostream &os, const Move &move);
};

#endif //EXERCISE_1_CHESS_RAMIHANN_LOCATION_H
