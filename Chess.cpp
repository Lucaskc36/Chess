#include <iostream>
#include "Chess.h"
using namespace std;
Chess::Chess(string Map[8][8]){
    for(int x = 0; x < 8; x++){
        for(int y = 0; y < 8; y++){
            Board[x][y] = Map[x][y];
        }
    }
}
bool Chess::Empty(int x, int y){//test ignores other color
    if(Board[x][y] == ""){
        return true;
    }
    return false;
}
string Chess::translate(char type, int color){
    string ret_Val;
    if(color == 1){
        switch(type){
            case '0':
            ret_Val = Characters[0];
            break;
            case 'K':
            ret_Val = Characters[1];
            break;
            case 'Q':
            ret_Val = Characters[2];
            break;
            case 'R':
            ret_Val = Characters[3];
            break;
            case 'B':
            ret_Val = Characters[4];
            break;
            case 'N':
            ret_Val = Characters[5];
            break;
            case 'P':
            ret_Val = Characters[6];
            break;
        }
    }
    else if(color == 2){
        switch(type){
            case 'K':
            ret_Val = Characters[7];
            break;
            case 'Q':
            ret_Val = Characters[8];
            break;
            case 'R':
            ret_Val = Characters[9];
            case 'B':
            ret_Val = Characters[10];
            break;
            case 'N':
            ret_Val = Characters[11];
            break;
            case 'P':
            ret_Val = Characters[12];
            break;
        }
    }
    return ret_Val;
}
/*
This functions purpose is to be able to credify that each move is possible.

*/
bool Chess::LegalMove(int x, int y, char Piece, int type){
    bool retVal;
    switch(Piece){
        case 'K': //White King

        break;
        case 'Q'://Queen
        if (fQueen(x,y,type)){
            retVal = Empty(x,y);
        }

        break;
        case 'R'://Rook
        /*
        Can Move Horizontally or vertically no diagnal
        */
       if(fRook(x,y,type)){
            retVal = Empty(x,y);
       }
        break;
        case 'B'://Bishop
            if(fBishop(x,y,type)){
                retVal = Empty(x,y);
            }
        break;
        case 'N'://Knight
            if (fKnight(x,y,type)){
                retVal = Empty(x,y);
            }
        break;

        case 'P'://Pawn 
        /**
        1)Can move up two places if starting at one
        2)Cannot move when opponent's in the way
        3)Computer must be able to know if there is a pawn underneath
         **/
        //Remember y is - 1
        if (fPawn(x,y,type)){ 
            if(type == 1){
                if(fy == 1){// if it's a starting pawn you can move 2 up
                    if(x == fx && y - fy <= 2 && y - fy >= 1 &&  y < 7){
                        retVal = true;
                    }
                }
                else if(fy > 1){ // if it has already moved
                    if(x == fx && y-fy <= 1 && y - fy >= 1 && y < 7){
                        retVal = true;
                    }
                }
            }
            else if(type == 2){
                if(fy == 6){// if it's a starting pawn you can move 2 DOWN
                    if(x == fx && fy - y <= 2 && fy - y >= 1 &&  y < 7){
                        retVal = true;
                    }
                }
                else if(fy > 1){ // if it has already moved
                    if(x == fx && y-fy <= 1 && y - fy >= 1 && y < 7){
                        retVal = true;
                    }
                }
            }
        }
        if(retVal != true){
        ErrorMessage = "Pawn could not be Moved";
        }
        break;
    }
    return retVal;
}
string Chess::GetErrorMess(){
    return ErrorMessage;
}
bool Chess::fPawn(int x, int y, int Color){//Locate Starting position in order to delete and Validate Move
    if(Color == 1){//white
        for(int idy = 1; idy < y; idy++){//indexing through y values for white
            if(Board[x][idy] == translate('P', Color)){
                fx = x;
                fy = idy;
                return true;
            }
        }
    }
    else if(Color == 2)//black
    for(int idy = 6; idy > y; idy--){
        if(Board[x][idy] == translate('P',Color)){
                fx = x;
                fy = idy;
                return true;
            }
    }
    return false;
}
bool Chess::fRook(int x, int y, int Color){// Find Starting position to validate and delete
    int rooks = 0;
    int vx,vy;
    for(int idy = y + 1; idy <= 7;idy++){//check up
        if(Board[x][idy] == translate('R',Color)){
            vx = x;
            vy = idy;
            rooks++;
            break;
        }
        else if(Empty(x,idy) == false){
            break;
        }
    }
    for(int idx = x + 1; idx <= 7;idx++){//check right
        if(Board[idx][y] == translate('R',Color)){
            vx = idx;
            vy = y;
            rooks++;
            break;
        }
        if(Empty(idx,y) == false){
            break;
        }
    }
    for(int idy = y - 1; idy >= 0;idy--){//check down
        if(Board[x][idy] == translate('R',Color)){
            vx = x;
            vy = idy;
            rooks++;
            break;
        }
        else if(Empty(x,idy) == false){
            break;
        }
    }
    for(int idx = x - 1; idx >= 0;idx--){//check left
        if(Board[idx][y] == translate('R',Color)){
            vx = idx;
            vy = y;
            rooks++;
            break;
        }
        else if(Empty(idx,y) == false){
            break;
        }
    }
    if(rooks == 1){
        fx = vx;
        fy = vy;
        return true;
    }
    else if(rooks == 2){
        ErrorMessage = "Two Rooks Cannot Move to the same spot";
    }
    return false;
}
bool Chess::fKnight(int x, int y, int Color){
    int Knights = 0;//checking for 2 nights going to same position: invalid move;
    int xv,yv; //x y values must be held before being passed
    /*
    Bounderies:
    Short:
    x <= 6
    x >= 1
    Long:
    y <= 5
    y >= 2
    */
    if(x >= 1 && y <= 5){//Up left;X Long y, Short x
        if(Board[x - 1][ y + 2] == translate('N',Color)){
            Knights++;
            xv = x -1;
            yv = y + 2;
        }
    }
    if(x <= 6 && y <= 5){//Up Right;X Long y: Short x
        if(Board[x + 1][ y + 2] == translate('N',Color)){
            Knights++;
            xv = x + 1;
            yv = y + 2;
        }
    }
    if(x <= 5 && y <= 6){//Right Up;X Short y: Long x
        if(Board[x + 2][y + 1] == translate('N',Color)){
            Knights++;
            xv = x + 2;
            yv = y + 1;

        }
    }
    if(x <= 5 && y >= 1){//Right Down; Short y: Long x
        if(Board[x + 2][ y - 1] == translate('N',Color)){
            Knights++;
            xv = x + 2;
            yv = x - 1;
        }
    }
    if(x <= 6 &&  y >= 2){//Down Right; Long y: Short x
        if(Board[x+1][y-2] == translate('N',Color)){
            Knights++;
            xv = x + 1;
            yv = y - 2;
        }
    }
    if(x >= 1 && y >= 2){//Down Left; Long Y: short x
        if(Board[x - 1][ y - 2] == translate('N',Color)){
            Knights++;
            xv = x - 1;
            yv = y - 2;
        }
    }
    if(x >= 1 &&  y >= 1){//Left Down; Short X: Long Y
        if(Board[x - 2][ y - 1] == translate('N',Color)){
            Knights++;
            xv = x - 2;
            yv = y - 1;
        }
    }
    if(x >= 1 && y <= 6){//left Up; Short X: Long Y
        if(Board[x - 2][ x + 1] == translate('N',Color)){
            Knights++;
            xv = x - 1;
            yv = x + 2;
        }
    }
    if (Knights == 2){
        ErrorMessage = "Clarify which knight is moving.";
    }
    else if (Knights == 1){
        fx = xv;
        fy = yv;
        return true;
    }
    else{
        ErrorMessage = "Invalid Knight Move";
    }
    return false;
}
bool Chess::fBishop(int x, int y, int color){// to do: overall ret value for mulitples, save position see Rook;
    //Check Left:
    int bishops = 0; //checking for multiple Bishops
    int xv,yv;//Value must wait
    int idy = y + 1;
    //immidiate out of boundery failsafe must be added for x variable + 1 could be sent ouf of boundries;
    for(int idx = x - 1; idx >= 0 ; idx--,idy++){//left up
        if(idy == 8 || idx == -1){
            break;
        }
        else{
            if(Board[idx][idy] == translate('B',color)){
                xv = idx;
                yv = idy;
                bishops++;
            }
            else if(Empty(idx,idy) == false){
                break;
            }
        }
        
    }
    idy = y - 1;
    for(int idx = x - 1; idx >= 0 && idy <= 8; idx--,idy--){// left down
            if(x == -1){
                break;
            }
            if(Board[idx][idy] == translate('B',color)){
                xv = idx;
                yv = idy;
                bishops++;
            }
            else if(Empty(idx,idy) == false){
                break;
            }
        
    }
    idy = y + 1;
    for(int idx = x + 1; idx <= 8 && idy <= 8; idx++,idy++){// right up
    if(x == 8){
        break;
    }
        
            if(Board[idx][idy] == translate('B',color)){
                xv = idx;
                yv = idy;
                bishops++;
            }
            else if(Empty(idx,idy) == false){
                break;
            }
        
    }
    idy = y - 1;
    for(int idx = x + 1; idx >= 0 && idy >= 0 && idx < 8; idx++,idy--){// right down
            if(x == 8){
                break;
            }
            if(Board[idx][idy] == translate('B',color)){
                xv = idx;
                yv = idy;
                bishops++;
                break;
            }
            else if(Empty(idx,idy) == false){
                break;
            }
        
    }
    if(bishops == 1){
        fx = xv;
        fy = yv;
        return true;
    }
    else if(bishops == 2){
        ErrorMessage = "Multiple Bishops can move to this position";
    }
    return false;
}
bool Chess::fQueen(int x, int y, int color){
    for(int idy = y; idy <= 7;idy++){//check up
        if(Board[x][idy] == translate('Q',color)){
            fx = x;
            fy = idy;
            return true;
        }
        else if(Empty(x,idy) == false){
            break;
        }
    }
    for(int idx = x; idx <= 7;idx++){//check right
        if(Board[idx][y] == translate('Q',color)){
            fx = idx;
            fy = y;
            return true;
        }
        if(Empty(idx,y) == false){
            break;
        }
    }
    for(int idy = y; idy >= 0;idy--){//check down
        if(Board[x][idy] == translate('Q',color)){
            fx = x;
            fy = idy;
            return true;
        }
        if(Empty(x,idy) == false){
            break;
        }
    }
    for(int idx = x; idx >= 0;idx--){//check left
        if(Board[idx][y] == translate('Q',color)){
            fx = idx;
            fy = y;
            return true;
        }
        else if(Empty(idx,y) == false){
            break;
        }
    }
    int idy = y + 1;
    for(int idx = x - 1; idx >= 0 ; idx--,idy++){//left up
        if(idy == 8 || idx == -1){
            break;
        }
        else{
            if(Board[idx][idy] == translate('Q',color)){
                fx = idx;
                fy = idy;
                return true;
            }
            else if(Empty(idx,idy) == false){
                break;
            }
        }
        
    }
    idy = y - 1;
    for(int idx = x - 1; idx >= 0 && idy <= 8; idx--,idy--){// left down
            if(x == -1){
                break;
            }
            if(Board[idx][idy] == translate('Q',color)){
                fx = idx;
                fy = idy;
                return true;
            }
            else if(Empty(idx,idy) == false){
                break;
            }
        
    }
    idy = y + 1;
    for(int idx = x + 1; idx <= 8 && idy <= 8; idx++,idy++){// right up
    if( x == 8){
        break;
    }
        
            if(Board[idx][idy] == translate('Q',color)){
                fx = idx;
                fy = idy;
                return true;
            }
            else if(Empty(idx,idy) == false){
                break;
            }
        
    }
    idy = y - 1;
    for(int idx = x + 1; idx >= 0 && idy >= 0 && idx < 8; idx++,idy--){// right down
            if(x == 8){
                break;
            }
            if(Board[idx][idy] == translate('Q',color)){
                fx = idx;
                fy = idy;
                return true;
            }
            else if(Empty(idx,idy) == false){
                break;
            }
        
    }
    return false;
}
bool Chess::isOpponent(int x, int y, int Color){
    if(Color == 1){
        for(int idx = 7; idx <= 12; idx++){
            if(Board[x][y] == Characters[idx]){
                return true;
            }
        }
    }
    else if(Color == 2){
        for(int idx = 1; idx < 7; idx++){
            if(Board[x][y] == Characters[idx]){
                return true;
            }
        }
    }
    return false;
}
bool Chess::InCheck(int x, int y, int Col){
    int sx = fx,sy = fy;//Save previous values for fx fy,
    int Checks;
    int Color;
    if(Col == 1){
        Color = 2;
    }
    else if(Col == 2){
        Color = 1;
    }
    if(fQueen(x,y,Color)){
        fx = sx;
        fy = sy;
        return true;//early exit saves time
    }
    if(fRook(x,y,Color)){
        fx = sx;
        fy = sy;
        return true;
    }
    if(fPawn(x,y,Color)){
        fx = sx;
        fy = sy;
        return true;
    }
    if(fBishop(x,y,Color)){
        fx = sx;
        fy = sy;
    return true;
    }
    if(fKnight(x,y,Color)){
        fx = sx;
        fy = sy;
    return true;
    }
        fx = sx;
        fy = sy;
    return false;
}
int Chess::getfx(){
    return fx;
}
int Chess::getfy(){
    return fy;
}