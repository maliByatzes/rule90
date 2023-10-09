#ifndef LIBRULE90_H_INCLUDED
#define LIBRULE90_H_INCLUDED

#include <string>

// Return constants
const int SUCCESS = 0;
const int ERR_CONVERSION = -1;
const int EXIT_ARGC = -2;
const int EXIT_RANGE = -3;

// Pointer to integer
//typedef int* ptrArray;

namespace GrowSpace
{
    int GetInt(std::string strNumbers);
    int* InitilizeArray(int arraySize);
    void AssignRandValues(int* ptrArray, int arraySize);
    void AssignManualValues(int* ptrArray, int arraySize);
    void RunAutomaton(int* ptrArray, int arraySize, int numRounds);
    void DeleteArray(int* ptrArray);
}

#endif // LIBRULE90_H_INCLUDED
