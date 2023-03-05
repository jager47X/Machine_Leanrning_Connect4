#include "ML.h"

ML::ML() {
    srand((unsigned)time(NULL));
    File_management fm(this->lastFileIndex);
   
    std::cout << "lastfileidx" << lastFileIndex << "\n";
    for(int i=0; i < lastFileIndex; i++) {
        CSV[i] = *new Connect4();
        File_management FM(CSV);
          fm.InputCsv(CSV,i+1);
    }
    selection=0;
}
ML::~ML(){
    //delete CSV;
}

int ML::ML_main(Connect4 CURRENT_BOARD) {

    Data_analysis DATA(this->lastFileIndex,this->CSV);
    AI ai(this->winChoice,this->lastFileIndex);

    Connect4 CurrentBoard = DATA.GetCurrentBoard(CURRENT_BOARD);//every input read current board
    DATA.Compare_Board();
    bool ValidArray=ai.CheckArray(CurrentBoard,this->CSV);
    if(ValidArray==true) {
        selection = ai.FindSelection(winChoice);
        std::cout << "Selction from WinChoice\n";
    }else {selection=ai.RandomSelection();}

    return selection+1;
}

void ML::OutputCSV(Connect4 &CURRENT_BOARD){
    File_management output;
    output.OutputCsv(CURRENT_BOARD,this->lastFileIndex);
}

