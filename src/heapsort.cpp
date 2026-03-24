//
// Created by sophi on 6/3/2026.
//

#include "heapsort.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include "dataset.h"
using namespace std;

// heapify a subtree using 0-based indexing
vector<anime> heapify(vector<anime>& animes, int heapSize, int root) {
    vector<anime> vecCopy = animes; // create a copy

    int largest = root;
    int left = 2*root + 1;
    int right = 2*root + 2; 

    // if the left childs number_of_ratings is higher than the largest's number_of_ratings
    if (left < heapSize && vecCopy[left].number_of_ratings > vecCopy[largest].number_of_ratings) largest = left;

    // if right child number_of_ratings is larger than the largest number_of_ratings
    if (right < heapSize && vecCopy[right].number_of_ratings > vecCopy[largest].number_of_ratings) largest = right; 

    // if the largest is not the root
    if (largest != root) {
        swap(vecCopy[root], vecCopy[largest]);
        vecCopy = heapify(vecCopy, heapSize, largest); // recursion hooray
    }

    return vecCopy;
};

// using a max heap, so the array will be sorted in aascending order!
// top 10 will be found in the last 10 elements in the array
// can use, reverse(animes.begin(), animes.end()); , if we want to use the first 10 elements of the array
vector<anime> heapSort(vector<anime>& animes, int heapSize) {
    vector<anime> vecCopy = animes; // create a copy

    // build the heap
    for (int i = heapSize/2 - 1; i >= 0; i--) vecCopy = heapify(vecCopy, heapSize, i);

    for (int i = heapSize - 1; i >= 0; i--) {
        swap(vecCopy[0], vecCopy[i]);
        vecCopy = heapify(vecCopy, i, 0);
    }

    return vecCopy;
};

