#include "Board.h"
#include "Chess.h"
#include <iostream>

using namespace std;

int Board::setPieceAt(int x, int y, int color, char type){
    if(x >= size || x < 0 || y >= size || y < 0){
        ErrorMess = "Outside of bounds";
        return 1;
    }
    else{
            if (color == 1){ //white
                switch (type){
                    case 'K': //White King
                    VisualPieces[x][y] = "♔";
                    break;
                    case 'Q': //White Queen
                    VisualPieces[x][y] = "♕";
                    break;
                    case 'R': //White Rook
                    VisualPieces[x][y] = "♖";
                    break;
                    case 'B'://White Bishop
                    VisualPieces[x][y] = "♗";
                    break;
                    case 'N': //White Knight
                    VisualPieces[x][y] = "♘";
                    break;
                    case 'P': //White Pawn
                    VisualPieces[x][y] = "♙";
                    break;
                }
            }
            else if (color == 2){//Black
                switch (type){
                    case 'K': //Black King
                    VisualPieces[x][y] = "♚";
                    break;
                    case 'Q'://Black Queen
                    VisualPieces[x][y] = "♛";
                    break;
                    case 'R'://Black Rook
                    VisualPieces[x][y] = "♜";
                    break;
                    case 'B'://Black Bishop
                    VisualPieces[x][y] = "♝";
                    break;
                    case 'N'://Black Knight
                    VisualPieces[x][y] = "♞";
                    break;
                    case 'P'://Black Pawn
                    VisualPieces[x][y] = "♟";
                    break;
                }
            }
    }
    return 0;
}
void Board::RemovePiece(int x, int y){
    VisualPieces[x][y] = "";
}
    Board::Board(){
        //initialize piece positions
        for(int x = 0; x < 8; x++){
            setPieceAt(x,1,1,'P'); //White Pawn
            setPieceAt(x,6,2,'P'); //Black Pawn
        }
        //White Pieces
        setPieceAt(0,0,1,'R');
        setPieceAt(1,0,1,'N');
        setPieceAt(2,0,1, 'B');
        setPieceAt(3,0,1,'K');
        setPieceAt(4,0,1,'Q');
        setPieceAt(5,0,1,'B');
        setPieceAt(6,0,1,'N');
        setPieceAt(7,0,1,'R');
        //Black Pieces
        setPieceAt(0,7,2,'R');
        setPieceAt(1,7,2,'N');
        setPieceAt(2,7,2, 'B');
        setPieceAt(3,7,2,'K');
        setPieceAt(4,7,2,'Q');
        setPieceAt(5,7,2,'B');
        setPieceAt(6,7,2,'N');
        setPieceAt(7,7,2,'R');

        return;
    }
bool Board::UserInput(string input, int color){//Using Chess notation
int x, y, fx,fy; //fx, fy, are the analysed of where the peice is coming from
bool ret_val;
    if(input.length() == 2){
        
        if(tolower(input[0]) < 97 ||tolower(input[0]) > 104 || input[1] > 56 || input[1] < 49){ //add Chess class for each peices moves?
            ErrorMess = "Small String:: invalid";
        }
        else{
            cout << input[0]-97 << " " << input[1] - 49 << endl;
            Chess Evaluate(VisualPieces);
            if(Evaluate.LegalMove(input[0]-97,input[1]-49,'P', color) == true){
                cout << "Evaluation True" << endl;
                setPieceAt(input[0]-97, input[1] - 49, color,'P');
                RemovePiece(Evaluate.getfx(),Evaluate.getfy());
                ret_val = true;
            //color 1 for now
            }
            else{
                ErrorMess = Evaluate.GetErrorMess();
                ret_val = false;
            }
        }
    }
    /*
    length 3:: assume for regular move
    */
    if(input.length() == 3){ //verifying first letter to start reading.
        if(input[0] == 'R'|| input[0] == 'N'|| input[0] == 'B'|| input[0] == 'K'|| input[0] == 'Q'){ //Read for specific Characters
            if(input[1] >= 97 && input[1] <= 104 && input[2] < 56 && input[2] > 49 ){ //Read for coordinates //Rook not fitting conditions;
                Chess Evaluate(VisualPieces);
                if(Evaluate.LegalMove(input[1]-97,input[2]-49, input[0],color)){
                    setPieceAt(input[1]-97,input[2]-49, color, input[0]);
                    RemovePiece(Evaluate.getfx(),Evaluate.getfy());
                    ret_val = true;
                }
                else{
                    ErrorMess = Evaluate.GetErrorMess();
                    ret_val = false;
                }
            }
        }
    }
    return ret_val;
}
void Board::VisualBoard(){//W/O Lines, Wide
        char letter;
        string ColorCode = "\033[0m";
        for (int y = 8; y > 0; y--){
            for (int x = 0; x <= 8; x++){
                if(x == 0){ //Left Numbers
                    if (y == 0){
                        cout << " ";
                    }
                    else{
                    cout << y << "\033[0m";
                    }
                }
                else{//Middle
                    if(x % 2 == 0){//checker pattern conditional ||changes Color Code accordingly
                        if(y % 2 == 0){
                            ColorCode = "\033[7;49;90m"; //Primary
                        }
                        else{
                            ColorCode = "\033[7;49;39m"; //secondary
                        }
                    }
                    else{
                        if(y % 2 != 0){
                            ColorCode = "\033[7;49;90m"; //primary
                        }
                        else{
                            ColorCode = "\033[7;49;39m"; //secondary
                        }
                    }//Fills in Empty pieces with spaces! *Allignment fix
                    if (VisualPieces[x-1][y-1] == ""){
                        cout << "\033[0m"<< ColorCode << "   \033[0m";
                    }
                    else{
                        cout << "\033[0m" << ColorCode << " "<< VisualPieces[x-1][y-1] <<" \033[0m";
                    }
                
                }
            }
            cout << endl;
        }
        //bottom letters
        cout << "  A  B  C  D  E  F  G  H " << endl;
        cout << ErrorMess << endl;
        ErrorMess = "";
}