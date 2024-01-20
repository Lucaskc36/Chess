#include "Board.h"
#include <iostream>

using namespace std;

int main(){
    string input;
    Board NewGame;
    bool test = 0;
    int color;
    string Arguments[10] = {"a5","Na6","b4","Ra4","Ra3"};
    if(test == false){
        while (input != "q"){
            NewGame.VisualBoard();
            getline(cin, input);
            //input = "a4";
            NewGame.UserInput(input,2);
        }
    }
    else{
        for(int x = 0; x < 5; x++){
            NewGame.VisualBoard();
            input = Arguments[x];
            NewGame.UserInput(input,2);
        }
        NewGame.VisualBoard();
    }
    return 1;
}//b4, Bb2,Bd4