#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H
#pragma once

#include "Piece.h"
#include "BoardManager.h"
#include <vector>
#include <string>

class Pawn : public Piece {
public:
    Pawn(const Player &color, const Location &location);

    void move(const Location &destination) override;

    bool is_legal_move(const Location &destination) override;

    bool is_legal_move(shared_ptr<Piece> piece_to_attack);

    vector<shared_ptr<Location>> all_possible_moves() override;
};

#endif // CHESS_PAWN_H
