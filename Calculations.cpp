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
        double viewsPerPost = (double)c.views / c.posts;
        double engPerPost = (double)c.engagements / c.posts;
        double likesPerPost = (double)c.likes / c.posts;
        double cmtPerPost = (double)c.comments / c.posts;
        double shrPerPost = (double)c.shares / c.posts;
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