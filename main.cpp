#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <limits>  // Added for numeric_limits

// Trim whitespace from both ends of a string
std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    if (start == std::string::npos) return "";
    return str.substr(start, end - start + 1);
}

// Function prototypes
void displayContestStats(std::fstream& file);
void calculatePerPostData(std::fstream& file);
void filterAndSortByLikesPerPost(std::fstream& file);
void displaySortedByPerformanceMetric(std::fstream& file);
void parametrizedSortingAndSave(std::fstream& file);

int main() {
    bool isRunning = true;
    const std::string filename = "social_media_contest_data.csv";

    // Check file existence first
    if (!std::filesystem::exists(filename)) {
        std::cerr << "Error: File not found at: "
                  << std::filesystem::absolute(filename) << std::endl;
        return 1;
    }

    // Open the file properly
    std::fstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file at: "
                  << std::filesystem::absolute(filename) << std::endl;
        return 1;
    }

    do {
        int input;
        std::cout << "\nWelcome to my CS230 Semester Project!!!\n";
        std::cout << "Please pick one of the options (1-6)\n\n";
        std::cout << "1. Display contest stats\n";
        std::cout << "2. Calculate per-post data\n";
        std::cout << "3. Sort by likes/post\n";
        std::cout << "4. Performance metric sort\n";
        std::cout << "5. Parametrized sorting\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter choice: ";

        if (!(std::cin >> input)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
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
                break;
            default:
                std::cout << "Invalid option. Please try again.\n";
                break;
        }
    } while (isRunning);

    file.close();
    std::cout << "Exiting the program. Goodbye!\n";
    return 0;
}

void displayContestStats(std::fstream& file) {
    file.clear();
    file.seekg(0, std::ios::beg);
    std::string line;

    std::cout << "\nContest Stats:\n";
    std::cout << "==============\n";
    while (std::getline(file, line)) {
        std::cout << line << '\n';
    }
}

void calculatePerPostData(std::fstream& file) {
    file.clear();
    file.seekg(0, std::ios::beg);
    std::string line;
    std::getline(file, line);  // Skip header

    std::cout << "\nPer-Post Metrics:\n";
    std::cout << "=================\n";
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<std::string> fields;
        std::string field;

        while (std::getline(iss, field, ',')) {
            fields.push_back(trim(field));
        }

        if (fields.size() < 8) {
            std::cerr << "Skipping invalid line: " << line << '\n';
            continue;
        }

        try {
            int posts = std::stoi(fields[2]);
            int likes = std::stoi(fields[5]);

            if (posts <= 0) {
                std::cerr << "Invalid post count for " << fields[0] << '\n';
                continue;
            }

            double likesPerPost = static_cast<double>(likes) / posts;
            std::cout << std::left << std::setw(15) << fields[0]
                      << std::fixed << std::setprecision(2)
                      << "Likes/Post: " << likesPerPost << '\n';
        } catch (const std::exception& e) {
            std::cerr << "Error processing " << fields[0]
                      << ": " << e.what() << '\n';
        }
    }
}

void filterAndSortByLikesPerPost(std::fstream& file) {
    file.clear();
    file.seekg(0, std::ios::beg);
    std::string line;
    std::getline(file, line);  // Skip header

    std::vector<std::pair<std::string, double>> data;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<std::string> fields;
        std::string field;

        while (std::getline(iss, field, ',')) {
            fields.push_back(trim(field));
        }

        if (fields.size() < 8) continue;

        try {
            int posts = std::stoi(fields[2]);
            int likes = std::stoi(fields[5]);

            if (posts <= 0) continue;

            double likesPerPost = static_cast<double>(likes) / posts;
            data.emplace_back(fields[0], likesPerPost);
        } catch (const std::exception& e) {
            std::cerr << "Error processing " << fields[0]
                      << ": " << e.what() << '\n';
        }
    }

    // Sort in descending order
    std::sort(data.begin(), data.end(),
        [](const auto& a, const auto& b) { return a.second > b.second; });

    std::cout << "\nSorted by Likes/Post:\n";
    std::cout << "=====================\n";
    for (const auto& [name, metric] : data) {
        std::cout << std::left << std::setw(15) << name
                  << std::fixed << std::setprecision(2)
                  << metric << '\n';
    }
}

void displaySortedByPerformanceMetric(std::fstream& file) {
    std::cout << "\nPerformance metric sorting not implemented yet.\n";
}

void parametrizedSortingAndSave(std::fstream& file) {
    std::cout << "\nParametrized sorting not implemented yet.\n";
}
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.