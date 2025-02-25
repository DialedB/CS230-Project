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

void parametrizedSort(vector<Contestant>& contestants, bool ascending) {
    sort(contestants.begin(), contestants.end(), [ascending](const Contestant& a, const Contestant& b) {
        double aVal = (double)a.views / a.posts;
        double bVal = (double)b.views / b.posts;
        return ascending ? (aVal < bVal) : (aVal > bVal);
    });
}