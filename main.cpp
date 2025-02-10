#include <iostream>

int main() {
    bool isRunning = true;

    do {
        int input;
        std::cout << "Welcome to my CS230 Semester Project!!!" << std::endl;
        std::cout << "Please pick one of the options (1-6)" << std::endl;
        std::cout << "Inputting anything but the options will lead to the menu showing up again." << std::endl;
        std::cout << "Option 1: Read and display contest stats for the 12 finalists" << std::endl;
        std::cout << "Option 2: Calculate and display per post data values" << std::endl;
        std::cout << "Option 3: Filter and sort data by likes/post" << std::endl;
        std::cout << "Option 4: Display sorted data based on a novel performance metric" << std::endl;
        std::cout << "Option 5: Parametrized sorting, display and saving of processed data" << std::endl;
        std::cout << "Option 6: Exit the program" << std::endl;
        std::cin >> input;
        if (input == 1) {

        }
        else if (input == 2) {

        }
        else if (input == 3) {

        }
        else if (input == 4) {

        }
        else if (input == 5) {

        }
        else if (input == 6) {
            isRunning = false;
        }
    }while(isRunning);
    return 0;
}
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.