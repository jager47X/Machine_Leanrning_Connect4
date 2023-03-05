//
// Created by Yuto on 3/2/2023.
//


#include "ML.h"
ML::File_management::File_management(int lastFileIndex) {
    this->lastFileIndex=lastFileIndex;
    lastFileIndex = New_Log_Index();
   CombineFiles(lastFileIndex);
}


ML::File_management::File_management(Connect4 *CSV) {

}
ML::File_management::File_management() {
    this->lastFileIndex=lastFileIndex;

}
int ML::File_management:: New_Log_Index() {
    std::string filepath = "..\\cmake-build-debug\\database_1\\";
    std::string logIndex = filepath + "logIndex.txt";
    std::string log_csv = filepath + "logAll.csv";

    std::cout << "New_Log_Index Opened\n";
    int index = 0;
    std::ifstream read;

    //absolute path... :( just for the test 
    read.open(logIndex.c_str());
    
    if (read.is_open()) {
        while (!read.eof()) {
            read >> index;
        }
    } else {
        std::cout << "No log files are found\n";
        std::ofstream write;
        write.open(logIndex.c_str());
        write << 0;
        write.close();
    }
    std::cout << "New_Log_Index Passed\n";
    read.close();
    return index;
}

void ML::File_management::CombineFiles(int FileIndex) {
    std::string filepath = "..\\cmake-build-debug\\database_1\\";
    std::string log_csv = filepath + "logAll.csv";
    std::string logpath = "logfile\\";


    std::cout<<"CombineFiles is opened\n";
    std::ofstream Write_Csv;
    std::ifstream Read_Txt;
    std::string line;

    Write_Csv.open(log_csv.c_str());


    if (Write_Csv.is_open()) {
        for (int i = 0; i <=FileIndex; i++) {

            std::string Current_fileIndex = std::to_string(i);
            std::string txtfiles = filepath + logpath + "log" + Current_fileIndex + ".txt";

            Read_Txt.open(txtfiles.c_str());
            //  std::cout<<txtfiles<<" IS open\n";
            std::getline(Read_Txt, line);
            // std::cout<<line<<" IS FROM LINE:"<<i<<std::endl;
            Write_Csv << line << std::endl;
            Read_Txt.close();
        }
    }
    else {
        std::cout << "Error Opening Files to combine\n";
    }
    Write_Csv.close();
    std::cout<<"CombineFile passed\n";
}


std::string ML::File_management::NameFile(int CURRENT_LOG_FILE_INDEX) {

    std::string filepath = "..\\cmake-build-debug\\database_1\\";
    std::string logpath= "logfile\\";
    std::string logIndex = filepath + "logIndex.txt";
    std::string log_csv= filepath + "logAll.csv";

    CURRENT_LOG_FILE_INDEX++;
    std::cout << "SAVE new log\n";
    std::string string_CURRENT_LOG_FILE_INDEX = std::to_string(CURRENT_LOG_FILE_INDEX);
    std::string NewFile_Name = filepath + logpath + "log" + string_CURRENT_LOG_FILE_INDEX + ".txt";
    std::ofstream update_IndexFile;
    update_IndexFile.open(logIndex.c_str());
    update_IndexFile << CURRENT_LOG_FILE_INDEX;
    update_IndexFile.close();
    std::cout << "SAVE is done\n";
    return NewFile_Name;
}

void ML::File_management::InputCsv(Connect4 *CSV,int index) {

    std::string filepath = "..\\cmake-build-debug\\database_1\\";
    std::string log_csv = filepath + "logAll.csv";

    std::string Logfile = " ";
    int CSV_Selction;
    std::ifstream read;
    read.open(log_csv.c_str());

    if (read.is_open())
    {
        std::cout<<"INPUT CSV file is open\n";

        //        std::cout<<"csv_line:"<<csv_line<<"/MAX_LINE"<<lastFileIndex<<std::endl;
        for (int col = 0;col< COLS_SIZE; col++) {
            for (int ROW = 0; ROW < ROWS_SIZE; ROW++) {

                //std::cout<<"COL:"<<col<<" ROW:"<<ROW<<std::endl;
                int line=0;
                while(line<index){
                    std::getline(read, Logfile, ',');
                    line++;
                }
                int posB = 0, posE = 0;
                CSV[index].winner = atoi(Logfile.substr(posB, posE).c_str());//-1,1,2;
                posB = posE + 1;
                posE = posB; //one digit
                CSV[index].Board[col][ROW].OwnerOfTile = atoi(Logfile.substr(posB, posE).c_str());//0,1,2
                posB = posE + 1;
                posE = posB + 2;//two digit
                CSV[index].Board[col][ROW].turnOfTile = atoi(Logfile.substr(posB, posE).c_str());//1-42

            }
        }

    }else {
        std::cout << "INVALID FILE(not opened)\n";
    }


    read.close();
    std::cout<<"INPUT CSV file is closed\n";
}

void ML::File_management::OutputCsv(const Connect4& Current_Board, int lastFileIndex) {//output to log.txtfile
     this->lastFileIndex=lastFileIndex;
    std::string NewName=NameFile(this->lastFileIndex);
    NewFile.open(NewName.c_str());

    for (int COLUMN = 0; COLUMN < COLS_SIZE; COLUMN++) {
        for (int ROW = 0; ROW < ROWS_SIZE; ROW++) {
            //has 3 val to output
            std::string A_Imported_Game_Data = std::to_string(Current_Board.winner);//0-2
            A_Imported_Game_Data += std::to_string(Current_Board.Board[COLUMN][ROW].OwnerOfTile);//0-2
            if (Current_Board.Board[COLUMN][ROW].turnOfTile < 10) {
                A_Imported_Game_Data = A_Imported_Game_Data +"0"+std::to_string(Current_Board.Board[COLUMN][ROW].turnOfTile);//0-9
            }
            else {
                A_Imported_Game_Data += std::to_string(Current_Board.Board[COLUMN][ROW].turnOfTile);//0-42
            }
            NewFile << A_Imported_Game_Data << ',';
        }

    }
    NewFile.close();
}


