#include <iostream>
#include <string>
#include <sstream>
#include "librule90.h"

using namespace std;

namespace GrowSpace
{
    // Method to convert string to integer
    int GetInt(string strNumbers)
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

    // Method to initialize the array using the array size
    int* InitilizeArray(int arraySize)
    {
        // New pointer to integer and store the address of the value in the heap stack
        int* aryAutomaton = new int[arraySize];
        // Fill the array with zeros
        for(int i = 0; i < arraySize; i++)
        {
            // Equivalent to *(aryAutomaton + 1) = 0
            aryAutomaton[i] = 0;
        }
        return aryAutomaton;
    }

    // Method to assign random values to the array
    void AssignRandValues(int* ptrArray, int arraySize)
    {
        int randNum = 0;
        // Loop through the array and assign each index a random value between 0 and 1
        for (int i = 0; i < arraySize; i++)
        {
            randNum = rand() % 2;
            ptrArray[i] = randNum;
        }
    }

    // Method to assign each value manually
    void AssignManualValues(int* ptrArray, int arraySize)
    {
        int aryValue = 0;
        // Loop the array and manually ask the user for the value
        cout << "You have to enter " << arraySize << " values.\n";
        for (int i = 0; i < arraySize; i++)
        {
            cout << "Enter the array value " << (i + 1) << ", enter either 1 or 0: ";
            cin >> aryValue;

            if (aryValue < 0 || aryValue > 1)
            {
                cerr << "Wrong input, enter either 0 or 1!\n";
                break;
            }

            ptrArray[i] = aryValue;
        }
        cout << "All values have been filled\n";
    }

    // The automaton algorithm
    // 0 is dead and 1 is alive
    void AutomatonAlgo(int* ptrArray, int arraySize)
    {
        int copyArray[arraySize];
        for (int i = 0; i < arraySize; i++)
        {
            copyArray[i] = ptrArray[i];
        }

        int prev = 0;
        int next = 0;
        for (int i = 1; i < arraySize - 1; i ++)
        {
            prev = copyArray[i-1];
            next = copyArray[i+1];
            if (prev != next)
            {
                ptrArray[i] = 1;
            }
            else if (prev == next)
            {
                ptrArray[i] = 0;
            }
        }
    }

    // Method to run and print the automaton
    void RunAutomaton(int* ptrArray, int arraySize, int numRounds)
    {
        for(int i = 0; i < numRounds; i ++)
        {
            AutomatonAlgo(ptrArray, arraySize);

            for (int i = 0; i < arraySize; i ++)
            {
                if (ptrArray[i] == 0)
                {
                    cout << " # ";
                    // cout << "| Dead |";
                }
                else if(ptrArray[i] == 1)
                {
                    cout << " % ";
                    // cout << "| Alive |";
                }
            }
            cout << "\n";
        }
    }

    // Method to de-allocate the array
    void DeleteArray(int* ptrArray)
    {
        delete[] ptrArray;
        ptrArray = nullptr;
    }
}
