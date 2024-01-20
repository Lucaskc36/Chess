#ifndef CHESS_H
#define CHESS_H
#include <iostream>
using namespace std;
/* Takes in chess board set up to evaluate rules, and positions.
*/
class Chess{
    public:
    Chess(string Map[8][8]);
    bool LegalMove(int x, int y, char Type, int Color);
    int getfx();
    int getfy();
    bool InCheck(int x, int y, int Color);
    bool Empty(int x, int y);
    string GetErrorMess();
    
    private:
    //|Private Methods|
    /*From postions: 
    -Takes implied new position and tries to find it's piece where it's coming from.
    -sets fx,fy if true;
    -Finds where pawn comes from, sets fx,fy if true.
    -returns Boolean,
    */
    bool fPawn(int x, int y, int color);//FromPawn
    bool fRook(int x, int y, int color);//FromRook
    bool fKnight(int x, int y, int color);//FromKnight
    bool fBishop(int x, int y, int color);//FromBishop
    //Mix Bishop and Rook remove looking for multiples;
    bool fQueen(int x, int y, int color);//almost there!!
    bool isOpponent(int x, int y, int color);
    //|Vars|
    int fx, fy;
    string translate(char type,int color);
    string ErrorMessage;
    string Board[8][8];
    string Characters[13] = {"","♔","♕","♖","♗","♘", "♙", "♚","♛","♜","♝","♞","♟"};//black starts at 7 end at 12
};
#endif