#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H
#pragma once

#include "Piece.h"
#include "BoardManager.h"
#include "Bishop.h"
#include "Rook.h"
#include <vector>
#include <string>

class Queen: public Rook,public Bishop {
public:
    Queen(const Player &color, const Location &location);

    void move(const Location &destination) override;

    bool is_legal_move(const Location &destination) override;

    vector<shared_ptr<Location>> all_possible_moves() override;
};

#endif // CHESS_QUEEN_H
