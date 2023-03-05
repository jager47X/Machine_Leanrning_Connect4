//
// Created by Yuto on 3/2/2023.
//
#include "ML.h"

ML::AI::AI(int winChoice[],int lastFileIndex){

    for (int i = 0; i < ROWS_SIZE; i++) {
        this->winChoice[i] = winChoice[i];
    }

    this->lastFileIndex=lastFileIndex;

}

bool ML::AI::CheckArray(const Connect4& Current_Board,Connect4 *CSV) {

    int selection = -1;
    bool ValidArray=false;
    for(int i=0;i<ROWS_SIZE;i++){
        winChoice[i] = 0;
    }
    if (lastFileIndex > TEST) {//conduct if its not under test lap
        for (int i = 0; i < lastFileIndex; i++) {
            switch (WinMove(Current_Board,CSV)) {
                case 0:
                    winChoice[0]++;
                    ValidArray = true;
                    break;
                case 1:
                    winChoice[1]++;
                    ValidArray = true;
                    break;
                case 2:
                    winChoice[2]++;
                    ValidArray = true;
                    break;
                case 3:
                    winChoice[3]++;
                    ValidArray = true;
                    break;
                case 4:
                    winChoice[4]++;
                    ValidArray = true;
                    break;
                case 5:
                    winChoice[5]++;
                    ValidArray = true;
                    break;
                case 6:
                    winChoice[6]++;
                    ValidArray = true;
                    break;
                default:
                    ValidArray = false;
                    break;
            }
        }
    }
    return ValidArray;
}
int ML::AI::RandomSelection() {
    Sleep(500);
    std::cout << "Selction was Invalid\n";
    std::cout << " RAND value generated\n";
    int random=rand()%7;
    return random;
}
int ML::AI::WinMove(const Connect4& Current_Board,Connect4 *CSV) {
    Data_analysis DATA;

    Connect4 CurrentBoard = DATA.GetCurrentBoard(Current_Board);

    if (DATA.Compare_Board() == false) {return -1;}
    else {

        for (auto i = DATA.MatchedBoard.begin(); i != DATA.MatchedBoard.end(); ++i) {
            if (CSV[*i].winner == 1 && CSV[*i].turn % 2 == 0) {// when player2 win;
                for (int COLUMN = 0; COLUMN < COLS_SIZE; COLUMN++) {
                    for (int ROW = 0; ROW < ROWS_SIZE; ROW++) {
                        if (CSV[*i].Board[COLUMN][ROW].turnOfTile + 2 == CurrentBoard.turn) {

                            return ROW;
                        }
                    }
                }
            }else if (CSV[*i].winner != 1 && CSV[*i].turn % 2 != 0) {// when player1 win;
                for (int COLUMN = 0; COLUMN < COLS_SIZE; COLUMN++) {
                    for (int ROW = 0; ROW < ROWS_SIZE; ROW++) {
                        if (CSV[*i].Board[COLUMN][ROW].turnOfTile + 2 == CurrentBoard.turn) {

                            return ROW;
                        }
                    }
                }
            }
        }

    }
    return -1;
}
int ML::AI::FindSelection(int arr[]) {
    int max=0;
    int maxI=-1;
    for (int ROW=0;ROW<ROWS_SIZE;ROW++) {
        if (arr[ROW] > max) {
            max = arr[ROW];
            maxI = ROW;
        }
    }
    if(max==0||maxI==-1){
        return -1;
    }

    return maxI;

}
