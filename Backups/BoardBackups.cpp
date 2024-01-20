void Board::VisualBoard2(){//W/O Lines, Wide
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
void Board::VisualBoard3(){//W/O Lines Wide
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
void Board::VisualBoard1(){
        char letter;
        string ColorCode = "\033[0m";
        for (int y = 8; y > 0; y--){
            for (int x = 0; x <= 8; x++){
                if(x == 0){ //Left Numbers
                    if (y == 0){
                        cout << "  ";
                    }
                    else{
                    cout << y <<" ";
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
                        cout << ColorCode << "  \033[0m";
                    }
                    else{
                        cout << ColorCode << VisualPieces[x-1][y-1] <<" \033[0m";
                    }
                
                }
            }
            cout << endl;
        }
        //bottom letters
        cout << "  A B C D E F G H " << endl;
        cout << ErrorMess << endl;
        ErrorMess = "";
    }
    void Board::VisualBoard4(){
        char letter;
        for (int y = 8; y > 0; y--){
            for (int x = 0; x <= 8; x++){
                if(x == 0){ //Left Numbers
                    if (y == 0){
                        cout << " |";
                    }
                    else{
                    cout << y <<"\033[4m|\033[0m";
                    }
                }
                else{//Middle
                    if (VisualPieces[x-1][y-1] == ""){
                        cout << "\033[4m |\033[0m";
                    }
                    else{
                        cout << "\033[4m" << VisualPieces[x-1][y-1] <<"|\033[0m";
                    }
                
                }
            }
        cout << endl;
        }
        //bottom letters
        cout << " |A|B|C|D|E|F|G|H|" << endl;
        cout << ErrorMess << endl;
        ErrorMess = "";
    }