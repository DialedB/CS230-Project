#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

// Function prototypes
void displayContestStats(std::ifstream& file);
void calculatePerPostData(std::ifstream& file);
void filterAndSortByLikesPerPost(std::ifstream& file);
void displaySortedByPerformanceMetric(std::ifstream& file);
void parametrizedSortingAndSave(std::ifstream& file);

int main() {
    bool isRunning = true;
    std::ifstream file("social_media_contest_data.txt");

    // Check if the file opened successfully
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return 1;
    }

    do {
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

        // Input validation
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 6." << std::endl;
            continue;
        }

        switch (input) {
            case 1:
                displayContestStats(file);
                break;
            case 2:
                calculatePerPostData(file);
                break;
            case 3:
                filterAndSortByLikesPerPost(file);
                break;
            case 4:
                displaySortedByPerformanceMetric(file);
                break;
            case 5:
                parametrizedSortingAndSave(file);
                break;
            case 6:
                isRunning = false;
                std::cout << "Exiting the program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
                break;
        }
    } while (isRunning);

    file.close();
    return 0;
}

// Function to display contest stats
void displayContestStats(std::ifstream& file) {
    std::string line;
    file.clear(); // Clear any error flags
    file.seekg(0, std::ios::beg); // Reset file pointer to the beginning

    // Skip the header line
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
}

// Function to calculate and display per post data values
void calculatePerPostData(std::ifstream& file) {
    std::string line;
    file.clear();
    file.seekg(0, std::ios::beg);

    // Skip the header line
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string lastName, followers, posts, views, engagements, likes, comments, shares;
        iss >> lastName >> followers >> posts >> views >> engagements >> likes >> comments >> shares;

        // Calculate per post data (example: likes per post)
        int likesPerPost = std::stoi(likes) / std::stoi(posts);
        std::cout << lastName << ": " << likesPerPost << " likes/post" << std::endl;
    }
}

// Function to filter and sort data by likes/post
void filterAndSortByLikesPerPost(std::ifstream& file) {
    std::string line;
    file.clear();
    file.seekg(0, std::ios::beg);

    // Skip the header line
    std::getline(file, line);

    std::vector<std::pair<std::string, int>> data;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string lastName, followers, posts, views, engagements, likes, comments, shares;
        iss >> lastName >> followers >> posts >> views >> engagements >> likes >> comments >> shares;

        int likesPerPost = std::stoi(likes) / std::stoi(posts);
        data.emplace_back(lastName, likesPerPost);
    }

    // Sort by likes/post in descending order
    std::sort(data.begin(), data.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    // Display sorted data
    for (const auto& entry : data) {
        std::cout << entry.first << ": " << entry.second << " likes/post" << std::endl;
    }
}

// Function to display sorted data based on a novel performance metric
void displaySortedByPerformanceMetric(std::ifstream& file) {
    // Placeholder for custom metric logic
    std::cout << "Option 4: Custom performance metric logic goes here." << std::endl;
}

// Function for parametrized sorting, display, and saving of processed data
void parametrizedSortingAndSave(std::ifstream& file) {
    // Placeholder for parametrized sorting logic
    std::cout << "Option 5: Parametrized sorting logic goes here." << std::endl;
}
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.