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

vector<anime> heapify(vector<anime>& animes, int heapSize, int root); // heapify a subtree
vector<anime> heapSort(vector<anime>& animes, int heapSize); // heap sort


#endif //DSA_PROJECT2_HEAPSORT_H