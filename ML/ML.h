#ifndef MLHPP
#define MLHPP

#pragma once

#include <fstream>
#include <string>
#include "../Connect4/Connect4.h"
#include <vector>
#include <string>
#include <algorithm>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif


class ML :public Connect4
{
public:
    ML();
    ML(Connect4 &CURRENT_BOARD);
    ~ML();
    int ML_main(Connect4 game);
    void OutputCSV(Connect4 &CURRENT_BOARD);

private:
    const static int TEST=100;
    int  winChoice[ROWS_SIZE];
    int lastFileIndex=100;

    Connect4 *CSV;//dynamic allocation needed
    int selection;

    class AI{
    public:
        bool CheckArray(const Connect4& Current_Board,Connect4 *CSV);
        int  WinMove(const Connect4& Current_Board,Connect4 *CSV);
        int FindSelection(int arr[]);
        int RandomSelection();
        AI(int winChoice[],int lastFileIndex);
        AI();
    private:
        int  winChoice[ROWS_SIZE];
        int lastFileIndex;
    };
    class File_management{
    private:
        int lastFileIndex;
        std::ofstream NewFile;
    public:
        File_management(int lastFileIndex);
        int  GetlastFileIndex()const;
        int New_Log_Index();
        std::string  NameFile(int FileIndex);
        void CombineFiles(int FileIndex);
        void InputCsv(Connect4 *CSV,int index);
        void  OutputCsv(const Connect4& Current_Board,int lastFileIndex);

        File_management(Connect4 *CSV);
        File_management();
    };
    class Data_analysis{
    private:
        int lastFileIndex;
        std::string boardArray[42];
        Connect4 *CSV;
    public:
        std::vector<int> MatchedBoard;
        Data_analysis(Connect4& CURRENT_BOARD);
        Data_analysis(int lastFileIndex,Connect4 *CSV);//,Connect4 CSV[]);
        int numberOfReinforcement;
        void Current_Output(Connect4 Current_Board);
        bool Compare_Board();
        int GetNumberOfReinforcement();
        Connect4 GetCurrentBoard(const Connect4& Current_Board);

        Data_analysis();
    };
};

#endif

#ifndef MLHPP
#define MLHPP

#pragma once

#include <fstream>
#include <string>
#include "../Connect4/Connect4.h"
#include <vector>
#include <string>
#include <algorithm>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif


class ML :public Connect4
{
public:
ML();
ML(Connect4 &CURRENT_BOARD);
~ML();
int ML_main(Connect4 game);
void OutputCSV(Connect4 &CURRENT_BOARD);

private:
    const static int TEST=100;
    int  winChoice[ROWS_SIZE];
    int lastFileIndex;
    std::ofstream static NewFile;
    Connect4 *CSV;
    int selection;

    class AI{
    public:
        bool CheckArray(const Connect4& Current_Board,Connect4 *CSV);
         int  WinMove(const Connect4& Current_Board,Connect4 *CSV);
        int FindSelection(int arr[]);
        int RandomSelection();
        AI(int winChoice[],int lastFileIndex);
        AI();
    private:
        int  winChoice[ROWS_SIZE];
        int lastFileIndex;
    };
    class File_management{
    private:
        std::string filepath = "database_1\\";
        std::string logpath= "logfile\\";
        std::string logIndex = filepath + "logIndex.txt";
        std::string log_csv= filepath + "logAll.csv";
        int lastFileIndex;

    public:
        File_management(int lastFileIndex);
        int  GetlastFileIndex()const;
        int New_Log_Index();
        std::string  NameFile(int FileIndex);
        void CombineFiles(int FileIndex);
        void InputCsv(Connect4 *CSV,int index);
        void  OutputCsv(const Connect4& Current_Board,int lastFileIndex);

        File_management(Connect4 *CSV);
        File_management();
    };
    class Data_analysis{
    private:
        int lastFileIndex;
        std::string static boardArray[42];
        Connect4 *CSV;
    public:
         std::vector<int> MatchedBoard;
        Data_analysis(Connect4& CURRENT_BOARD);
        Data_analysis(int lastFileIndex,Connect4 *CSV);
        int numberOfReinforcement;
        void Current_Output(Connect4 Current_Board);
        bool Compare_Board();
        int GetNumberOfReinforcement();
        Connect4 GetCurrentBoard(const Connect4& Current_Board);

        Data_analysis();
    };
};

#endif

