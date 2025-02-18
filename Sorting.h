//
// Created by Dusan Boljevic on 18/2/25.
//
#pragma once
#include <vector>
#include "Contestant.h"

void filterAndSortByLikesPerPost(const vector<Contestant>& contestants, double minLikesPerPost);
void sortByNewMetric(vector<Contestant>& contestants);
void parametrizedSort(vector<Contestant>& contestants, int sortField, bool ascending);