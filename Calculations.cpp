//
// Created by Dusan Boljevic on 18/2/25.
//
#include "Calculations.h"
#include <iomanip>
#include <iostream>

using namespace std;

void calculatePerPost(const vector<Contestant>& contestants) {
    cout << "LAST\tVIW/PST\tENG/PST\tLIK/PST\tCMT/PST\tSHR/PST" << endl;
    for (const auto& c : contestants) {
        // Calculate metrics, ensuring no division by zero
        double viewsPerPost = (c.posts > 0) ? (double)c.views / c.posts : 0.0;
        double engPerPost = (c.posts > 0) ? (double)c.engagements / c.posts : 0.0;
        double likesPerPost = (c.posts > 0) ? (double)c.likes / c.posts : 0.0;
        double cmtPerPost = (c.posts > 0) ? (double)c.comments / c.posts : 0.0;
        double shrPerPost = (c.posts > 0) ? (double)c.shares / c.posts : 0.0;

        // Display the calculated metrics
        cout << c.surname << "\t"
             << fixed << setprecision(2) << viewsPerPost << "\t"
             << engPerPost << "\t"
             << likesPerPost << "\t"
             << cmtPerPost << "\t"
             << shrPerPost << endl;
    }
}

void calculateNewMetric(vector<Contestant>& contestants) {
    for (auto& c : contestants) {
        c.newMetric = (c.followers + 2*c.likes + c.engagements + c.comments + c.shares) / (double)c.posts;
    }
}