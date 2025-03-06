//
// Created by Dusan Boljevic on 18/2/25.
//
#include "Sorting.h"
#include <algorithm>
#include <iostream>

using namespace std;

void filterAndSortByLikesPerPost(const vector<Contestant>& contestants, double minLikesPerPost) {
    vector<Contestant> filtered;
    for (const auto& c : contestants) {
        double likesPerPost = (double)c.likes / c.posts;
        if (likesPerPost >= minLikesPerPost) {
            filtered.push_back(c);
        }
    }
    sort(filtered.begin(), filtered.end(), [](const Contestant& a, const Contestant& b) {
        return (a.likes / a.posts) > (b.likes / b.posts);
    });
    // Display the filtered and sorted list
    cout << "NAME\tLAST\tORG\tSEX\tLIK/PST" << endl;
    for (const auto& c : filtered) {
        cout << c.name << "\t" << c.surname << "\t" << c.origin << "\t" << c.sex << "\t"
             << (double)c.likes / c.posts << endl;
    }
}

void sortByNewMetric(vector<Contestant>& contestants) {
    sort(contestants.begin(), contestants.end(), [](const Contestant& a, const Contestant& b) {
        return a.newMetric > b.newMetric;
    });
}

void parametrizedSort(vector<Contestant>& contestants, const string& sortField, bool ascending) {
    sort(contestants.begin(), contestants.end(), [&sortField, ascending](const Contestant& a, const Contestant& b) {
        double aVal = 0, bVal = 0;

        // Compute per post metric based on the selected field
        if (sortField == "VIW/PST") {
            aVal = (double)a.views / a.posts;
            bVal = (double)b.views / b.posts;
        } else if (sortField == "ENG/PST") {
            aVal = (double)a.engagements / a.posts;
            bVal = (double)b.engagements / b.posts;
        } else if (sortField == "LIK/PST") {
            aVal = (double)a.likes / a.posts;
            bVal = (double)b.likes / b.posts;
        } else if (sortField == "CMT/PST") {
            aVal = (double)a.comments / a.posts;
            bVal = (double)b.comments / b.posts;
        } else if (sortField == "SHR/PST") {
            aVal = (double)a.shares / a.posts;
            bVal = (double)b.shares / b.posts;
        } else if (sortField == "NEW") {
            aVal = a.newMetric; // Assuming 'NEW' is already a precomputed value
            bVal = b.newMetric;
        } else {
            throw invalid_argument("Invalid sorting field");
        }

        return ascending ? (aVal < bVal) : (aVal > bVal);
    });
}
