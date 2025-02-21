#include "FileIO.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm> // For trim
#include <string>

using namespace std;

// Helper function to trim whitespace from strings
string trim(const string& str) {
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    return (start == string::npos) ? "" : str.substr(start, end - start + 1);
}

vector<Contestant> readData() {
    vector<Contestant> contestants;
    ifstream file("social_media_contest_data.txt"); // Ensure the correct file extension
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return contestants;
    }

    string line;
    getline(file, line); // Skip header

    while (getline(file, line)) {
        stringstream ss(line);
        Contestant c;
        string cell;

        // Read each cell with error handling
        try {
            getline(ss, c.name, '\t'); // Use tab as delimiter
            c.name = trim(c.name);

            getline(ss, c.surname, '\t');
            c.surname = trim(c.surname);

            getline(ss, c.origin, '\t');
            c.origin = trim(c.origin);

            getline(ss, c.sex, '\t');
            c.sex = trim(c.sex);

            // Parse numeric fields
            auto parseField = [&](int& field) {
                getline(ss, cell, '\t'); // Use tab as delimiter
                cell = trim(cell);
                if (cell.empty()) field = 0; // Default to 0 if empty
                else field = stoi(cell);
            };

            parseField(c.followers);
            parseField(c.posts);
            parseField(c.views);
            parseField(c.engagements);
            parseField(c.likes);
            parseField(c.comments);
            parseField(c.shares);

            contestants.push_back(c);
        } catch (const exception& e) {
            cerr << "Error parsing line: " << line << "\nReason: " << e.what() << endl;
        }
    }

    file.close();
    return contestants;
}

void displayData(const vector<Contestant>& contestants) {
    cout << "Contestant Data:\n";
    cout << "NAME\tSURNAME\tORIGIN\tSEX\tXTRA_FOLLOWERS\tPOSTS\tVIEWS\tENGAGEMENTS\tLIKES\tCOMMENTS\tSHARES\n";
    for (const auto& c : contestants) {
        cout << c.name << "\t" << c.surname << "\t" << c.origin << "\t"
             << c.sex << "\t" << c.followers << "\t"
             << c.posts << "\t" << c.views << "\t" << c.engagements << "\t"
             << c.likes << "\t" << c.comments << "\t" << c.shares << "\n";
    }
}

void saveProcessedData(const vector<Contestant>& contestants) {
    ofstream file("social_media_contest_processed_data.csv");
    file << "NAME,SURNAME,ORIGIN,SEX,XTRA_FOLLOWERS,POSTS,VIEWS,ENGAGEMENTS,LIKES,COMMENTS,SHARES,NEW_METRIC\n";
    for (const auto& c : contestants) {
        file << c.name << "," << c.surname << "," << c.origin << ","
             << c.sex << "," << c.followers << ","
             << c.posts << "," << c.views << "," << c.engagements << ","
             << c.likes << "," << c.comments << "," << c.shares << ","
             << c.newMetric << "\n";
    }
    file.close();
    cout << "Processed data saved to social_media_contest_processed_data.csv" << endl;
}
