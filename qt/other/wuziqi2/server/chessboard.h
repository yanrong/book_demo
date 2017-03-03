#ifndef CHESSBOARD_HH
#define CHESSBOARD_HH

enum Chess{null, white, black};

class ChessBoard{
public:
    ChessBoard();
    bool SetChess(int, int, enum Chess);
    enum Chess GetStatus(int, int);
    bool Judge(int, int, enum Chess);
    void initBoard();
private:
    enum Chess board[19][19];
};

#endif
