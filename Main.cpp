#include <iostream>
#include <vector>
#include "Contestant.h"
#include "FileIO.h"
#include "Calculations.h"
#include "Sorting.h"
#include "Menu.h"

using namespace std;

int main() {
    vector<Contestant> contestants;
    int choice;
    do {
        displayMenu();
        choice = getMenuChoice();
        switch(choice) {
            case 1:
                contestants = readData();
            break;
            case 2:
                calculatePerPost(contestants);
            break;
            case 3: {
                double minLikes;
                cout << "Enter minimum likes per post: ";
                cin >> minLikes;
                filterAndSortByLikesPerPost(contestants, minLikes);
                break;
            }
            case 4:
                calculateNewMetric(contestants);
                saveProcessedData(contestants);
            break;
            case 5: {
                // Implement sorting and saving logic here
                break;
            }
            case 6:
                cout << "Exiting..." << endl;
            break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while(choice != 6);
    return 0;
}