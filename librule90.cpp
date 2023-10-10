#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "librule90.h"

using namespace std;

namespace GrowSpace
{
    int GetRand(int lower, int upper)
    {
        int number;
        int range = upper - lower + 1;
        number = rand() % range + lower;
        return number;
    }

    int ConvToInt(string strNumbers)
    {
        int numbers;
        stringstream ss {strNumbers};
        ss >> numbers;
        if(ss.fail())
        {
            cerr << "Could not convert " << strNumbers << " to integer\n";
            exit(ERR_CONVERSION);
        }
        return numbers;
    }

    bool* InitilizeArray(int arraySize)
    {
        bool* aryAutomaton;
        aryAutomaton = new bool[arraySize];

        for (int i = 0; i < arraySize; i++)
        {
            aryAutomaton[i] = false;
        }
        return aryAutomaton;
    }

    void DisplayArray(bool* ptrArray, int arraySize)
    {
        for (int i = 0; i < arraySize; i++)
        {
            switch(ptrArray[i])
            {
            case true:
                cout << '#' << " ";
                break;
            case false:
                cout << '.' << " ";
                break;
            }
        }
        cout << "\n";
    }

    int GetInt()
    {
        int number;
        cin >> number;
        while(cin.fail())
        {
            cerr << "Could not convert to integer. Please enter a number only.\n";
            string junk;
            cin >> junk;
            cin >> number;
        }
        return number;
    }

    int InitRounds()
    {
        int rounds;

        cout << "Enter the number of rounds (1 - 1000): ";
        rounds = GetInt();
        while(rounds <= 0 || rounds > 1000)
        {
            cerr << "Please make sure the number is between 1 and 1000\n";
            cout << "Retry: ";
            rounds = GetInt();
        }

        return rounds;
    }

    void AssignRandValues(bool* ptrArray, int arraySize)
    {
        for (int i = 0; i < arraySize; i++)
        {
            int randNum = GetRand(0,1);
            if(randNum==0)
            {
                ptrArray[i] = false;
            }
            else
            {
                ptrArray[i] = true;
            }
        }
    }

    void DisplayIndex(int index, int arraySize)
    {
        for(int i = 0; i < arraySize; i++)
        {
            cout << std::setw(2);
            if(i==index)
                cout << i;
            else
                cout << " ";
        }
        cout << "\n";
    }

    void AssignManualValues(bool* ptrArray, int arraySize)
    {
       bool cont {true};
       char input {'\0'};
       int activeIdx {0};

       do
       {
            system("clear");
            cout << " ";
            DisplayArray(ptrArray, arraySize);
            DisplayIndex(activeIdx, arraySize);
            cout << "n) Move cursor to the left\n"
                 << "m) Move cursor to the right\n"
                 << "t) Toggle current value\n"
                 << "x) Quit\n";
            cin >> input;

            switch(toupper(input))
            {
            case 'N':
                if(activeIdx>0)
                    activeIdx--;
                break;
            case 'M':
                if(activeIdx<arraySize-1)
                    activeIdx++;
                break;
            case 'T':
                ptrArray[activeIdx] = !ptrArray[activeIdx];
                break;
            case 'X':
                cont = false;
                break;
            default:
                cout << "Invalid input, try again\n";
            }
       }while(cont);
    }

    void CopyArray(bool* ptrArrOne, bool* ptrArrTwo, int arraySize)
    {
        for(int i = 0; i < arraySize; i++)
        {
            ptrArrOne[i] = ptrArrTwo[i];
        }
    }

    void AutomatonAlgo(bool* ptrArray, int arraySize)
    {
        bool* tempArray = InitilizeArray(arraySize);

        if(ptrArray[1]==ptrArray[arraySize-1])
            tempArray[0] = false;
        else
            tempArray[0] = true;

        if(ptrArray[0]==ptrArray[arraySize-2])
            tempArray[arraySize-1] = false;
        else
            tempArray[arraySize-1] = true;

        for(int i = 0; i < arraySize; i++)
        {
            if(ptrArray[(i-1)]==ptrArray[(i+1)])
                tempArray[i] = false;
            else
                tempArray[i] = true;
        }

        CopyArray(ptrArray, tempArray, arraySize);
        DeleteArray(tempArray);
    }

    void RunAutomaton(bool* ptrArray, int arraySize, int numRounds)
    {
        DisplayArray(ptrArray, arraySize);
        for(int i = 0; i < numRounds; i++)
        {
            AutomatonAlgo(ptrArray, arraySize);
            DisplayArray(ptrArray, arraySize);
        }
        // For windows only
        // system("pause")
        // can't figure out for linux/mac devices
    }

    void DeleteArray(bool* ptrArray)
    {
        delete[] ptrArray;
        ptrArray = nullptr;
    }
}
