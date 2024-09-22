//
// Created by ramih on 7/20/2024.
//

#ifndef CHESS_EXCEPTIONS_H
#define CHESS_EXCEPTIONS_H


#include <exception>
#include <string>
#include <memory>

using namespace std;
class IllegalMoveException : public exception {
private:
    string message;
    static shared_ptr<IllegalMoveException> instance;
    explicit IllegalMoveException(const string& msg);
public:
    static shared_ptr<IllegalMoveException> getInstance(const string& msg);
    static shared_ptr<IllegalMoveException> getInstance();
    virtual const char* what() const noexcept override;
};

class BoardStateException : public std::exception {
private:
    string message;
    static shared_ptr<BoardStateException> instance;

    // Private constructor
    explicit BoardStateException(const string &msg);

public:
    static shared_ptr<BoardStateException> getInstance(const string &msg);

    static shared_ptr<BoardStateException> getInstance();

    virtual const char *what() const noexcept override;
};


#endif //CHESS_EXCEPTIONS_H
