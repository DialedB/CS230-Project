#include <iostream>
#include <vector>
#include "Contestant.h"
#include "FileIO.h"
#include "Calculations.h"
#include "Sorting.h"
#include "Menu.h"

using namespace std;

int main() {
    vector<Contestant> contestants = readData();
    int choice;
    string sortField;
    bool ascending;
    do {
        displayMenu();
        choice = getMenuChoice();
        switch(choice) {
            case 1:
                displayData(contestants);
            break;
            case 2:
                calculatePerPost(contestants);
            break;
            case 3:
                double minLikes;
                cout << "Enter minimum likes per post: ";
                cin >> minLikes;
                filterAndSortByLikesPerPost(contestants, minLikes);
                break;
            case 4:
                calculateNewMetric(contestants);
                saveProcessedData(contestants);
                break;
            case 5:
                cout << "Enter sorting field (VIW/PST, ENG/PST, LIK/PST, CMT/PST, SHR/PST, NEW): ";
                cin >> sortField;
                cout << "Sort in ascending order? (1 for Yes, 0 for No): ";
                cin >> ascending;

                parametrizedSort(contestants, sortField, ascending);
                displayData(contestants);
                break;
            case 6:
                cout << "Exiting..." << endl;
            break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while(choice != 6);
    return 0;
}
