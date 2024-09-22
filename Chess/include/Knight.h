#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H
#pragma once

#include "Piece.h"
#include "BoardManager.h"
#include <vector>
#include <string>

class Knight: public Piece {
public:
    Knight(const Player &color, const Location &location);

    void move(const Location &destination) override;

    bool is_legal_move(const Location &destination) override;

    vector<shared_ptr<Location>> all_possible_moves() override;
};

#endif // CHESS_KNIGHT_H
