//
//  main.cpp
//  Connect four game
//  Created by Kenneth Gonzalez on 8/1/19.

#include <iostream>
#include <string>

using namespace std;
struct playerInfo
{
    char playerName[81];
    char playerID;
};
int PlayerDrop( char board[][10], playerInfo activePlayer );
void CheckBellow ( char board[][10], playerInfo activePlayer, int dropChoice );
void DisplayBoard ( char board[][10] );
int CheckFour ( char board[][10], playerInfo activePlayer );
int FullBoard( char board[][10] );
void PlayerWin ( playerInfo activePlayer );
string restart ( char board[][10] );
int main()
{
    playerInfo playerOne, playerTwo;
    char board[9][10];
    
    int dropChoice, win, full;
    string again;
    cout << "Connect Four" << endl << endl;
    cout << "Player one please enter your name: ";
    cin  >> playerOne.playerName;
    playerOne.playerID = 'R';
    cout << "Player two please enter your name: ";
    cin  >> playerTwo.playerName;
    playerTwo.playerID = 'Y';
    full = 0;
    win = 0;
    again = "";
    DisplayBoard( board );
    do
    {
        dropChoice = PlayerDrop( board, playerOne );
        CheckBellow( board, playerOne, dropChoice );
        DisplayBoard( board );
        win = CheckFour( board, playerOne );
        if ( win == 1 )
        {
            PlayerWin(playerOne);
            again = restart(board);
            if (again == "no")
            {
                break;
            }
        }
        dropChoice = PlayerDrop( board, playerTwo );
        CheckBellow( board, playerTwo, dropChoice );
        DisplayBoard( board );
        win = CheckFour( board, playerTwo );
        if ( win == 1 )
        {
            PlayerWin(playerTwo);
            again = restart(board);
            if (again == "no")
            {
                break;
            }
        }
        full = FullBoard( board );
        if ( full == 7 )
        {
            cout << "The board is full, it is a draw!" << endl;
            again = restart(board);
        }
    }while ( again != "no" );
    return 0;
}

int PlayerDrop( char board[][10], playerInfo activePlayer )
{
    int dropChoice;
    do
    {
        cout << activePlayer.playerName << "'s Turn ";
        cout << "Please enter a number between 1 and 7: ";
        cin  >> dropChoice;
        while ( board[1][dropChoice] == 'R' || board[1][dropChoice] == 'Y' )
        {
            cout << "That row is full, please enter a new row: ";
            cin  >> dropChoice;
        }
    }while ( dropChoice < 1 || dropChoice > 7 );
    return dropChoice;
}

void CheckBellow ( char board[][10], playerInfo activePlayer, int dropChoice )
{
    int length, turn;
    length = 6;
    turn = 0;
    do
    {
        if ( board[length][dropChoice] != 'R' && board[length][dropChoice] != 'Y' )
        {
            board[length][dropChoice] = activePlayer.playerID;
            turn = 1;
        }
        else
            --length;
    }while (  turn != 1 );
}

void DisplayBoard ( char board[][10] )
{
    int rows = 6, columns = 7, i, ix;
    for(i = 1; i <= rows; i++)
    {
        cout << "|";
        for(ix = 1; ix <= columns; ix++)
        {
            if(board[i][ix] != 'R' && board[i][ix] != 'Y')
                board[i][ix] = '*';
            cout << board[i][ix];
        }
        cout << "|" << endl;
    }
}

int CheckFour ( char board[][10], playerInfo activePlayer )
{
    char player_ID;
    int win;
    player_ID = activePlayer.playerID;
    win = 0;
    for( int i = 8; i >= 1; --i )
    {
        for( int ix = 9; ix >= 1; --ix )
        {
            if( board[i][ix] == player_ID     &&
               board[i-1][ix-1] == player_ID &&
               board[i-2][ix-2] == player_ID &&
               board[i-3][ix-3] == player_ID )
            {
                win = 1;
            }
            else if( board[i][ix] == player_ID   &&
               board[i][ix-1] == player_ID &&
               board[i][ix-2] == player_ID &&
               board[i][ix-3] == player_ID )
            {
                win = 1;
            }
            else if( board[i][ix] == player_ID   &&
               board[i-1][ix] == player_ID &&
               board[i-2][ix] == player_ID &&
               board[i-3][ix] == player_ID )
            {
                win = 1;
            }
            else if( board[i][ix] == player_ID     &&
               board[i-1][ix+1] == player_ID &&
               board[i-2][ix+2] == player_ID &&
               board[i-3][ix+3] == player_ID )
            {
                win = 1;
            }
            else if ( board[i][ix] == player_ID   &&
                board[i][ix+1] == player_ID &&
                board[i][ix+2] == player_ID &&
                board[i][ix+3] == player_ID )
            {
                win = 1;
            }
        }
    }
    return win;
}


int FullBoard( char board[][10] )
{
    int full;
    full = 0;
    for ( int i = 1; i <= 7; ++i )
    {
        if ( board[1][i] != '*' )
            ++full;
    }
    return full;
}
void PlayerWin ( playerInfo activePlayer )
{
    cout << endl << activePlayer.playerName << " Won the Game!" << endl;
}


string toUpper(string &upperCase){
    string val = "";
    for(int i = 0; i < upperCase.length(); i++){
        val += toupper(upperCase[i]);
    }
    return val;
}

string restart ( char board[][10] )
{
    string restart;
    do{
    cout << "Would you like to play again? Yes or No: ";
    cin  >> restart;
        restart = toUpper(restart);
    }while (restart !="YES" && restart!= "NO");
    
    if ( restart == "YES")
    {
        for(int i = 1; i <= 6; i++)
        {
            for(int ix = 1; ix <= 7; ix++)
            {
                board[i][ix] = '*';
            }
        }
    }
    else if(restart == "NO"){
        cout << "Game finished......" <<endl;
        cout << "Closing Console...." << endl;}
    
        return restart;
    
}

