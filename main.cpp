#include <iostream>
#include <cstdlib>
#include "librule90.h"

// A rule 90 automaton
// Write a C++ program that will accomplish each of the following requirements:
// 1. The program should use a menu system.
// 2. The size of the one-dimensional array must be provided using a command line
// argument.
// 3. The user must have an option to define the number of rounds of evolution the cellular
//    automaton will undergo when run.
// 4. The user must have the option to have random values assigned to the initial array.
// 5. The user must also have the option to set the initial values of the array manually.
// 6. The user must have the option to run the cellular automaton for the number of rounds
//    specified in requirement 3. The program must output an easy-to-understand
//    representation of the automaton as it evolves from one round to the next.
// 7. The user must have the option to quit the program.

using namespace std;
using namespace GrowSpace;

int main(int argc, char* argv[])
{
    // random seed
    srand(time(nullptr));

    // Receiving user input via command line argument
    // Error checking
    if (argc != 2) {
        cerr << "Invalid input!\n";
        cout << "Please run " << argv[0] << " <arraySize>\n";
        exit(-2);
    }

    int arraySize = GetInt(argv[1]);

    if(arraySize <= 0 || arraySize > 1000)
    {
        cerr << "Please make sure array size value is greater than 0 and is less than 1000\n";
        exit(EXIT_RANGE);
    }

    // Init a 1-D array
    int* ptrArray = InitilizeArray(arraySize);
    bool isRunning = true;
    int choice = 0;
    int numRounds = 0;

    do
    {
        cout << "\n****************** Menu ******************\n"
             << "Select an option below (1-5)\n"
             << "1. Define number of rounds\n"
             << "2. Assign random values to the array\n"
             << "3. Set the values of the array manually\n"
             << "4. Run the cellular automaton\n"
             << "5. Exit\n"
             << "Number of rounds: " << numRounds << "\n"
             << "Choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            cout << "Enter the number of rounds: ";
            cin >> numRounds;
            if (numRounds <= 0)
            {
                cerr << "The number of rounds is zero or less than zero, try initializing it.";
                break;
            }
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
            cerr << "Invalid input!\n";
            break;
        }
    }while(isRunning);

    // Deallocating the array
    DeleteArray(ptrArray);
    return SUCCESS;
}
