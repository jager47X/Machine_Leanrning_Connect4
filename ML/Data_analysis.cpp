//
// Created by Yuto on 3/1/2023.
//
#include "ML.h"

ML::Data_analysis::Data_analysis(Connect4& CURRENT_BOARD) {
    Current_Output(CURRENT_BOARD);
}
void ML::Data_analysis::Current_Output(Connect4 CURRENT_BOARD){
    Connect4 Current_Board=CURRENT_BOARD;
    std::string winner,turn,owner;
    for (int COLUMN = 0; COLUMN < COLS_SIZE; COLUMN++) {
        for (int ROW = 0; ROW < ROWS_SIZE; ROW++) {
            winner=std::to_string(Current_Board.winner);
            if (Current_Board.Board[COLUMN][ROW].turnOfTile < 10) {
                turn = turn +"0"+std::to_string(Current_Board.Board[COLUMN][ROW].turnOfTile);//0-9
            }else{
                turn = std::to_string(Current_Board.Board[COLUMN][ROW].turnOfTile);
            }
            owner=std::to_string(Current_Board.Board[COLUMN][ROW].OwnerOfTile);
        }
    }
    for(int i;i<42;i++){
        boardArray[i]=winner+turn+owner;
    }
}

ML::Data_analysis::Data_analysis(int lastFileIndex,Connect4 *CSV) {
    this->CSV=CSV;
    this->lastFileIndex=lastFileIndex;
}


bool ML::Data_analysis::Compare_Board(){
    int Match;
    for(int csv_line=1;csv_line<lastFileIndex+1;csv_line++) {
        int index=0;
        for (int COLUMN = 0; COLUMN <COLS_SIZE; COLUMN++) {
            for (int ROW = 0; ROW < ROWS_SIZE; ROW++) {
                index++;
                std::string csv_str="";
                csv_str+=CSV[csv_line].winner;
                csv_str+=CSV[csv_line].Board[COLUMN][ROW].OwnerOfTile;
                csv_str+=CSV[csv_line].Board[COLUMN][ROW].turnOfTile;
                if (csv_str==boardArray[index]){
                    Match++;
                    MatchedBoard.push_back(csv_line);
                }
            }
        }
    }
    if(Match==42){
        return true;
    }
    return false;
}
ML::Data_analysis::Data_analysis() {

}
Connect4 ML::Data_analysis::GetCurrentBoard(const Connect4 &Current_Board) {
    Connect4 CurrentBoard;
    for (int COLUMN = 0; COLUMN < COLS_SIZE; COLUMN++) {
        for (int ROW = 0; ROW < ROWS_SIZE; ROW++) {
            CurrentBoard.turn = Current_Board.turn;
            CurrentBoard.winner = Current_Board.winner;
            CurrentBoard.Board[COLUMN][ROW].OwnerOfTile = Current_Board.Board[COLUMN][ROW].OwnerOfTile;
            CurrentBoard.Board[COLUMN][ROW].turnOfTile = Current_Board.Board[COLUMN][ROW].turnOfTile;
        }
    }
    return CurrentBoard;
}
