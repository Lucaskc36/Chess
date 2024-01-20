#include "GameData.h"
#include <iostream>
#include <fstream>

using namespace std;

Game::Game(string Username, string Opponent){
    filename = Username + "VS" + Opponent;
    ifstream Check(filename+".txt");
    int x = 1;
    if(Check.good() == true){
        cout << "Ur In I guess" << endl;
    }
    
}