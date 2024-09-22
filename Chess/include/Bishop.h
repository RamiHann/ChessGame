#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H
#pragma once

#include "Piece.h"
#include "BoardManager.h"
#include <vector>
#include <string>

class Bishop : virtual public Piece {
public:

    Bishop(const Player &color, const Location &location);

    void move(const Location &destination) override;

    bool is_legal_move(const Location &destination) override;

    vector<shared_ptr<Location>> all_possible_moves() override;
};

#endif // CHESS_BISHOP_H