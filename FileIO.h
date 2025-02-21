//
// Created by Dusan Boljevic on 18/2/25.
//
#pragma once
#include <vector>
#include "Contestant.h"

vector<Contestant> readData();
void saveProcessedData(const vector<Contestant>& contestants);
void displayData(const vector<Contestant>& contestants);