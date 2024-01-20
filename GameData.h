#ifndef GAMEDATA_H
#define GAMEDATA_H
#include <fstream>
#include <iostream>
using namespace std;
class Game{
    public:
    Game(string Username, string Opponent);
    int NewGame(string username, string opponent);
    int WriteToSave(string filename);
    private:
    string filename;
    fstream File;

};
#endif