#include "Connect4.h"

Connect4::Connect4() {
    ResetBoard();

}

Connect4::~Connect4() {////////fix delte

}

bool Connect4::PlayerDrop(int dropChoice, char activePlayer){
    dropChoice--;//adjust to array size selection for user is 1-7; so minus 1 to fit array.

    std::cout << "dropChoice is " << dropChoice;

    if(FullBoard()==false) {
        if (dropChoice >=0&&dropChoice<=6) {//0-6
            for (int BOARD_COLUMN = 5; BOARD_COLUMN >=0; BOARD_COLUMN--){
                if(Board[BOARD_COLUMN][dropChoice].OwnerOfTile==0){
                    Board[BOARD_COLUMN][dropChoice].ToOwnerOfTile(activePlayer);
                    Board[BOARD_COLUMN][dropChoice].turnOfTile=turn;
                    turn++;
                    return true;
                }
            }

        }
        else {
            std::cout << ("(!)Invalid Selection\n");
            return false;
        }
    }



    std::cout<<("No Space to put tiles\n");
    return false;
}
void Connect4::DisplayBoard()  {
    for (int BOARD_COLUMN = 0; BOARD_COLUMN <= COLS_SIZE-1; ++BOARD_COLUMN)
    {
        for (int BOARD_ROW = 0; BOARD_ROW <= ROWS_SIZE-1; ++BOARD_ROW)
        {
            std::cout << ToactivePlayer(Board[BOARD_COLUMN][BOARD_ROW]);
        }std::cout<<std::endl;
    }
    std::cout << "1234567" << std::endl;
}
void Connect4::ResetBoard()
{

    for (int BOARD_COLUMN = 0;  BOARD_COLUMN<=COLS_SIZE-1; BOARD_COLUMN++)
    {
        for (int BOARD_ROW = 0; BOARD_ROW <= ROWS_SIZE-1; BOARD_ROW++)
        {

            Board[BOARD_COLUMN][BOARD_ROW].OwnerOfTile=0;
            Board[BOARD_COLUMN][BOARD_ROW].turnOfTile = 0;
        }
    }
}
char Connect4::ToactivePlayer(Tile tile) {
    if (tile.OwnerOfTile == 1)
        return PLAYER1;
    if (tile.OwnerOfTile == 2)
        return PLAYER2;
    //if (tile.OwnerOfTile == 0)
    return EMPTY;


}
bool Connect4::WinCheck(char activePlayer)
{
    for (int BOARD_COLUMN = COLS_SIZE-1; BOARD_COLUMN >=0 ; BOARD_COLUMN--) {
        for (int BOARD_ROW = ROWS_SIZE - 1; BOARD_ROW >= 0; BOARD_ROW--) {
            if (
                (BOARD_COLUMN>3)&&
                    (Board[BOARD_COLUMN][BOARD_ROW].ToactivePlayer() == activePlayer) &&
                    (Board[BOARD_COLUMN-1][BOARD_ROW].ToactivePlayer() == activePlayer) &&
                    (Board[BOARD_COLUMN-2][BOARD_ROW].ToactivePlayer() == activePlayer) &&
                    (Board[BOARD_COLUMN-3][BOARD_ROW].ToactivePlayer() == activePlayer)
                    ) {
                if (activePlayer == PLAYER1) {
                    winner = 1;
                }
                else {
                    winner = 2;
                }
                return true;
            }
            if (
                    (Board[BOARD_COLUMN][BOARD_ROW].ToactivePlayer() == activePlayer) &&
                    (Board[BOARD_COLUMN ][BOARD_ROW-1].ToactivePlayer() == activePlayer) &&
                    (Board[BOARD_COLUMN][BOARD_ROW-2].ToactivePlayer() == activePlayer) &&
                    (Board[BOARD_COLUMN] [BOARD_ROW-3].ToactivePlayer() == activePlayer)
                    ) {
                if (activePlayer == PLAYER1) {
                    winner = 1;
                }
                else {
                    winner = 2;
                }
                return true;
            }
            if (
                    (Board[BOARD_COLUMN][BOARD_ROW].ToactivePlayer() == activePlayer) &&
                    (Board[BOARD_COLUMN - 1][BOARD_ROW + 1].ToactivePlayer() == activePlayer) &&
                    (Board[BOARD_COLUMN - 2][BOARD_ROW + 2].ToactivePlayer() == activePlayer) &&
                    (Board[BOARD_COLUMN - 3][BOARD_ROW + 3].ToactivePlayer() == activePlayer)
                    ) {
                if (activePlayer == PLAYER1) {
                    winner = 1;
                }
                else {
                    winner = 2;
                }
                return true;
            }
            if (
                    (Board[BOARD_COLUMN][BOARD_ROW].ToactivePlayer() == activePlayer) &&
                    (Board[BOARD_COLUMN + 1][BOARD_ROW - 1].ToactivePlayer() == activePlayer) &&
                    (Board[BOARD_COLUMN + 2][BOARD_ROW - 2].ToactivePlayer() == activePlayer) &&
                    (Board[BOARD_COLUMN + 3][BOARD_ROW - 3].ToactivePlayer() == activePlayer)
                    ) {
                if (activePlayer == PLAYER1) {
                    winner = 1;
                }
                else {
                    winner = 2;
                }
                return true;

            }

        }
    }

    winner=0;
    return false;
}

bool Connect4::FullBoard() {

    int full = 0;
    for (int BOARD_ROW = 0; BOARD_ROW <= ROWS_SIZE+1; BOARD_ROW++) {
        if( ToactivePlayer(Board[0][BOARD_ROW]) != EMPTY)
            full++;
    }
    if (full >= 7) {
        std::cout << "Board is full. Withdraw.\n";
        return true;
    }
    winner=-1;
    return false;
}


void Connect4::SetTile(Tile New_tile,int col, int row)
{
    Board[col][row] = New_tile;
}
Connect4::Tile Connect4::GetTile( int col, int row) {
    return Board[col][row];
}

void Connect4::SetWinner(int New_Winner) {
    this->winner = New_Winner;
}
int  Connect4::GetWinner() {
    return this->winner;
}

void Connect4::SetTurn(int New_Turn) {
    this->turn = New_Turn;
}
int  Connect4::GetTurn() {
    return this->turn;
}
