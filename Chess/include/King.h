#ifndef CHESS_KING_H
#define CHESS_KING_H
#pragma once

#include "Piece.h"
#include "BoardManager.h"
#include <vector>
#include <string>

class King: public Piece {
    bool did_move;
public:
    King(const Player &color, const Location &location);

    void move(const Location &destination) override;

    bool is_legal_move(const Location &destination) override;

    bool is_first_move();

    vector<shared_ptr<Location>> all_possible_moves() override;
};

#endif // CHESS_KING_H
