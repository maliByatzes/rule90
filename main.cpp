#include <iostream>
#include <cstdlib>
#include "librule90.h"

using namespace std;
using namespace GrowSpace;

int main(int argc, char* argv[])
{
    srand(time(nullptr));

    if (argc != 2) {
        cerr << "Invalid input!\n";
        cout << "Please run application as: " << argv[0] << " <arraySize>\n";
        exit(EXIT_ARGC);
    }

    int arraySize = ConvToInt(argv[1]);

    if(arraySize < 20)
    {
        cerr << "Please make sure array size value is at least 20\n";
        exit(EXIT_RANGE);
    }

    bool* ptrArray = InitilizeArray(arraySize);
    bool isRunning {true};
    int choice {0};
    int numRounds {0};

    do
    {
        system("clear");
        cout << "****************** Menu ******************\n"
             << "Select an option below (1-5)\n"
             << "1. Define number of rounds\n"
             << "2. Assign random values to the array\n"
             << "3. Set the values of the array manually\n"
             << "4. Run the cellular automaton\n"
             << "5. Exit\n"
             << "Number of rounds: " << numRounds << "\n";
             DisplayArray(ptrArray, arraySize);
        cout << "Choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            numRounds = InitRounds();
            cout << "Successfully recorded the number of rounds.\n";
            break;
        case 2:
            AssignRandValues(ptrArray, arraySize);
            cout << "Array has been filled with random values.\n";
            break;
        case 3:
            AssignManualValues(ptrArray, arraySize);
            break;
        case 4:
            if (numRounds == 0)
            {
                cerr << "The number of rounds is zero, try initializing it.";
                break;
            }
            RunAutomaton(ptrArray, arraySize, numRounds);
            break;
        case 5:
            cout << "Good bye!\n";
            isRunning = false;
            break;
        default:
            cerr << "Invalid input!";
        }
    }while(isRunning);

    DeleteArray(ptrArray);
    return SUCCESS;
}
