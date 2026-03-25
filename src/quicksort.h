//
// Created by sophi on 6/3/2026.
//

#ifndef DSA_PROJECT2_QUICKSORT_H
#define DSA_PROJECT2_QUICKSORT_H


#include <iostream>
#include <vector>
#include <iomanip>
#include "dataset.h"
using namespace std;

int partitionByScore(vector<anime>& animes, int low, int high);
void quickSortByScore(std::vector<anime>& animes, int low, int high);

int partitionByNumRatings(vector<anime>& animes, int low, int high);
void quickSortByNumRatings(vector<anime>& animes, int low, int high);


#endif //DSA_PROJECT2_QUICKSORT_H