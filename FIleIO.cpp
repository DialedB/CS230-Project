//
// Created by Dusan Boljevic on 18/2/25.
//
#include "FileIO.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

vector<Contestant> readData() {
    vector<Contestant> contestants;
    ifstream file("social_media_contest_data.txt");
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return contestants;
    }
    string line;
    getline(file, line); // skip header
    while (getline(file, line)) {
        stringstream ss(line);
        Contestant c;
        string cell;
        getline(ss, c.name, '\t');
        getline(ss, c.surname, '\t');
        getline(ss, c.origin, '\t');
        getline(ss, c.sex, '\t');
        getline(ss, cell, '\t'); c.followers = stoi(cell);
        getline(ss, cell, '\t'); c.posts = stoi(cell);
        getline(ss, cell, '\t'); c.views = stoi(cell);
        getline(ss, cell, '\t'); c.engagements = stoi(cell);
        getline(ss, cell, '\t'); c.likes = stoi(cell);
        getline(ss, cell, '\t'); c.comments = stoi(cell);
        getline(ss, cell, '\t'); c.shares = stoi(cell);
        contestants.push_back(c);
    }
    file.close();
    return contestants;
}

void saveProcessedData(const vector<Contestant>& contestants) {
    ofstream file("social_media_contest_processed_data.txt");
    file << "NAME\tSURNAME\tORIGIN\tSEX\tXTRA_FOLLOWERS\tPOSTS\tVIEWS\tENGAGEMENTS\tLIKES\tCOMMENTS\tSHARES\tNEW_METRIC\n";
    for (const auto& c : contestants) {
        file << c.name << "\t" << c.surname << "\t" << c.origin << "\t"
             << c.sex << "\t" << c.followers << "\t"
             << c.posts << "\t" << c.views << "\t" << c.engagements << "\t"
             << c.likes << "\t" << c.comments << "\t" << c.shares << "\t"
             << c.newMetric << "\n";
    }
    file.close();
    cout << "Processed data saved to social_media_contest_processed_data.txt" << endl;
}