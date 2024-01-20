#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>

using namespace std;
class Board{
public:
    Board();
    int setPieceAt(int x, int y, int color, char type); //returns error codes
    void VisualBoard();//1:Small 2:Wide //3:Small with lines
    bool UserInput(string Input, int color);
    void RemovePiece(int x, int y);
    
private:
    int PiecesPos[8][8];
    string VisualPieces[8][8];
    int const size = 8;
    string ErrorMess;

};
#endif