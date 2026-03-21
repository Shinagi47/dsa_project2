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
void heapify(vector<anime>& animes, int heapSize, int root) {
    int largest = root;
    int left = 2*root + 1;
    int right = 2*root + 2; 

    // if the left childs niche score is higher than the largest's niche score
    if (left < heapSize && animes[left].niche_score > animes[largest].niche_score) largest = left;

    // if right child niche score is larger than the largest niche score
    if (right < heapSize && animes[right].niche_score > animes[largest].niche_score) largest = right; 

    // if the largest is not the root
    if (largest != root) {
        swap(animes[root], animes[largest]);
        heapify(animes, heapSize, largest); // recursion hooray
    }

};

// using a max heap, so the array will be sorted in aascending order!
// top 10 will be found in the last 10 elements in the array
// can use, reverse(animes.begin(), animes.end()); , if we want to use the first 10 elements of the array
void heapSort(vector<anime>& animes, int heapSize) {
    // build the heap
    for (int i = heapSize/2 - 1; i >= 0; i--) heapify(animes, heapSize, i);

    for (int i = heapSize - 1; i >= 0; i--) {
        swap(animes[0], animes[i]);
        heapify(animes, i, 0);
    }
};

