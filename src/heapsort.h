//
// Created by sophi on 6/3/2026.
//

#ifndef DSA_PROJECT2_HEAPSORT_H
#define DSA_PROJECT2_HEAPSORT_H


#include <iostream>
#include <vector>
#include <iomanip>
#include "dataset.h"
using namespace std;

vector<anime> heapifyByNumRatings(vector<anime>& animes, int heapSize, int root); // heapify a subtree by number of ratings
vector<anime> heapifyByAvgScore(vector<anime>& animes, int heapSize, int root); // heapify a subtree by avg score

vector<anime> heapSortByNumRatings(vector<anime>& animes, int heapSize); // heap sort by number of ratings
vector<anime> heapSortByAvgScore(vector<anime>& animes, int heapSize); // heap sort by avg score



#endif //DSA_PROJECT2_HEAPSORT_H