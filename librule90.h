#ifndef LIBRULE90_H_INCLUDED
#define LIBRULE90_H_INCLUDED

#include <string>

const int SUCCESS = 0;
const int ERR_CONVERSION = -1;
const int EXIT_ARGC = -2;
const int EXIT_RANGE = -3;

namespace GrowSpace
{
    int ConvToInt(std::string strNumbers);
    bool* InitilizeArray(int arraySize);
    void DisplayArray(bool* ptrArray, int arraySize);
    int InitRounds();
    void AssignRandValues(bool* ptrArray, int arraySize);
    void AssignManualValues(bool* ptrArray, int arraySize);
    void RunAutomaton(bool* ptrArray, int arraySize, int numRounds);
    void DeleteArray(bool* ptrArray);
}

#endif // LIBRULE90_H_INCLUDED
