//
// Created by Dusan Boljevic on 18/2/25.
//
#pragma once
#include <string>
using namespace std;

struct Contestant {
    string name, surname, origin, sex;
    int followers, posts, views, engagements, likes, comments, shares;
    double newMetric;
};