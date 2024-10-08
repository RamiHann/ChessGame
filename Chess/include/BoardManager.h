#ifndef CHESS_BOARD_MANAGER_H
#define CHESS_BOARD_MANAGER_H
#pragma once

#include "Piece.h"
#include "PriorityQueue.h"
#include <vector>
#include <string>
#include <array>

using namespace std;


class Move;
const Location CLEAR(-1,-1);
const int DEPTH=2;
enum Response{
    // Illegal movements
    NoPieceAtSource = 11,
    PieceOfOpponentAtSource = 12,
    YourPieceAtDestination = 13,
    IllegalMovementOfPiece = 21,
    WillCauseCheckmate = 31,

    // Legal movements
    LegalCheck = 41,
    LegalNextTurn = 42,
    Castling = 43,
    Checkmate = 44
};

enum Values{
    PawnValue=1,
    KnightValue=3,
    BishopValue=3,
    RookValue=5,
    QueenValue=9,
    KingValue=100,
    Threatened=-2, // threatened by weaker piece
    Threatening=2 // threatening a stronger piece
};

class BoardManager {
    array<array<shared_ptr<Piece>, 8>, 8> _board;
    shared_ptr<Piece> white_king, black_king;
    Player current_player;
    PriorityQueue<pair<vector<pair<Location, Location>>, int>> best_moves;

    //functions
    int check_illegal_moves(const Location &current, const Location &destination) const;

    int check_legal_moves(const Location &current, const Location &destination);

    vector<Location> is_piece_threatened(const Location &location) const;

    shared_ptr<Piece> get_current_king() const;

    void to_lower(string &str) const;

    Player get_player_color(const char &ch);

    bool is_valid_location(const Location &location);

    template<class PieceType>
    shared_ptr<PieceType> create_piece(const char &ch, Location starting_location);

    bool will_preform_castling(const Location &current, const Location &destination);

    Location is_way_clear(const Location &current, const Location &destination) const;

    bool is_this_types(const string &types, const int &x, const int &y) const;

    bool will_cause_checkmate();

    void
    change_places(const Location &current, const Location &destination, shared_ptr<Piece> destination_piece = nullptr);

    vector<shared_ptr<Piece>> get_all_pieces_of_player(Player player) const;

    pair<vector<pair<Location, Location>>, int>
    calculate_values(BoardManager board, Player current_player, const int &depth, const int &starting_depth);

    int threatened_by_weaker_piece(const Location &location);

    int threatening_stronger_piece(const Location &location);

    int get_piece_value(const Location &location) const;

public:
    explicit BoardManager(const string &board = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr");

    int move(const string &input);

    friend ostream &operator<<(ostream &os, BoardManager &board);

    friend class Move;
};


#endif // CHESS_BOARD_MANAGER_H