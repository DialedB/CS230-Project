#include <iostream>
#include <fstream>

int main() {

    bool isRunning = true;

    do {
        std::ifstream file("Resources/social_media_contest_data.txt");
        int input;
        std::cout << "Welcome to my CS230 Semester Project!!!" << std::endl;
        std::cout << "Please pick one of the options (1-6)" << std::endl;
        std::cout << std::endl;
        std::cout << "Inputting anything but the options will lead to the menu showing up again." << std::endl;
        std::cout << std::endl;
        std::cout << "Option 1: Read and display contest stats for the 12 finalists" << std::endl;
        std::cout << "Option 2: Calculate and display per post data values" << std::endl;
        std::cout << "Option 3: Filter and sort data by likes/post" << std::endl;
        std::cout << "Option 4: Display sorted data based on a novel performance metric" << std::endl;
        std::cout << "Option 5: Parametrized sorting, display and saving of processed data" << std::endl;
        std::cout << "Option 6: Exit the program" << std::endl;
        std::cin >> input;
        if (input == 1) {
            std::string line;
            // LAST|FOL|PST|VIW|ENG|LIK|CMT|SHR
            while (getline(file, line)) {
                std::cout << line << std::endl;
            }
        }
        else if (input == 2) {
            // DATA/POST for every piece of data
        }
        else if (input == 3) {
            // Data filtering with lower limit of LIK/PST
        }
        else if (input == 4) {
            // Custom performance metric added to new txt file (VIW/ENG) - NEW
            // Display: NAME|LAST|ORG|SEX|NEW
        }
        else if (input == 5) {
            // Sorting by selected data (notebook has the data)
            // Saves sorted data into new file called: social_media_sorted_stats.txt
        }
        else if (input == 6) {
            //Ends running loop - Exits program
            isRunning = false;
        }
    }while(isRunning);
    return 0;
}
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.