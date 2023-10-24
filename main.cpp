#include<iostream>
#include<string>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

class TicTacToe{
    public: 
        void runGame();
        void initializeGameBoard(string gameBoard[ROWS][COLS]);
        void printCurrentBoard(string gameBoard[ROWS][COLS]);
        void getUserInput(bool xTurn, string gameBoard[ROWS][COLS]);
        bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS]);
        string getWinner(string gameBoard[ROWS][COLS]);
        bool isBoardFull(string gameBoard[ROWS][COLS]); 
};

void TicTacToe::runGame(){
    string winner = "";
    bool xTurn = true;
    string gameBoard[ROWS][COLS];
    initializeGameBoard(gameBoard);
    printCurrentBoard(gameBoard);

    while(winner == ""){
        if(xTurn){
            cout << "Its X's turn " << endl;
        }
        else{
            cout << "Its O's turn " << endl;
        }
        
        getUserInput(xTurn, gameBoard);
        printCurrentBoard(gameBoard);
        xTurn = !xTurn;

        winner = getWinner(gameBoard);
        if(winner == "" && isBoardFull(gameBoard)){
            winner = "TIE";
        }
    }

    if(winner == "X"){
        cout << "X is winner..." << endl;
    }
    else if(winner == "O"){
        cout << "O is winner..." << endl;
    }
    else{
        cout << "Match Tied, There no winner...!" << endl;
    }
}

void TicTacToe::initializeGameBoard(string gameBoard[ROWS][COLS]){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            gameBoard[i][j] = " ";
        }
    }
}

void TicTacToe::printCurrentBoard(string gameBoard[ROWS][COLS]){
    cout << endl;
    int temp = 2;
    for(int j = 0; j < ROWS; j++){
        cout << gameBoard[0][j];
        if(temp--){
            cout << "  |  ";
        }
    }
    cout << endl;
    cout << "--- ----- ----";
    cout << endl;

    temp = 2;
    for(int j = 0; j < ROWS; j++){
        cout << gameBoard[1][j];
        if(temp--){
            cout << "  |  ";
        }
    }
    cout << endl;
    cout << "--- ----- ----";
    cout << endl;

    temp = 2;
    for(int j = 0; j < ROWS; j++){
        cout << gameBoard[2][j];
        if(temp--){
            cout << "  |  ";
        }
    }
    cout << endl << endl;
}

void TicTacToe::getUserInput(bool xTurn, string gameBoard[ROWS][COLS]){
    int row = -1;
    int col = -1;
    bool keepAsking = true;

    while(keepAsking){

        cout << "Enter the place position : ";
        cin >> row;
        cin >> col;

        if(row >= 0 && row <= 2 && col >= 0 && col <= 2){
            if(!cellAlreadyOccupied(row, col, gameBoard)){
                keepAsking = false;
            }
            else{
                cout << "Place already occupied!" << endl;
            }
        }
    }

    if(xTurn){
        gameBoard[row][col] = "X";
    }
    else{
        gameBoard[row][col] = "O";
    }

    
}

bool TicTacToe::cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS]){
    if(gameBoard[row][col] != " "){
        return true;
    }
    else{
        return false;
    }
}

string TicTacToe::getWinner(string gameBoard[ROWS][COLS]){
    
    // Checking all rows
    for(int i = 0; i < ROWS; i++){
        if(gameBoard[i][0] != " " && gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2]){
            return gameBoard[i][0];
        }
    }

    // Checking the columns
    for(int i = 0; i < COLS; i++){
        if(gameBoard[0][i] != " " && gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i]){
            return gameBoard[0][i];
        }
    }

    // Checking the Diagonals
    if(gameBoard[0][0] != " " && gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]){
        return gameBoard[0][0];
    }

    if(gameBoard[0][2] != " " && gameBoard[0][2] == gameBoard[2][2] && gameBoard[2][2] == gameBoard[2][1]){
        return gameBoard[0][2];
    }

    return "";
}

bool TicTacToe::isBoardFull(string gameBoard[ROWS][COLS]){
    int count_occupied = 0;
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(gameBoard[i][j] != " "){
                count_occupied++;
            }
        }
    }
    if(count_occupied == 9){
        return true;
    }
    else{
        return false;
    }
}


int main()
{
    TicTacToe t;
    t.runGame();

    return 0;
}