//
// Created by sophi on 6/3/2026.
//

#include "quicksort.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <ranges>

#include "dataset.h"
using namespace std;

int partitionByScore(vector<anime>& animes, int low, int high) {
    vector<anime> vecCopy = animes;
    float pivot = vecCopy[low].score;
    int up = low;
    int down = high;
    while (up < down) {
        for (int i = up; i < high; i++) {
            if (vecCopy[up].score > pivot) {
                break;
            }
            up++;
        }
        for (int j = high; j>low; j--) {
            if (vecCopy[down].score < pivot) {
                break;
            }
            down--;
        }
        if (up < down) {
            swap(vecCopy[up], vecCopy[down]);
        }
    }
    swap(vecCopy[low], vecCopy[down]);
    return down;
}
void quickSortByScore(std::vector<anime>& animes, int low, int high) {
    vector<anime> vecCopy = animes;
    if (low < high) {
        int pivot = partitionByScore(vecCopy, low, high);
        quickSortByScore(vecCopy, low, pivot-1);
        quickSortByScore(vecCopy, pivot+1, high);
    }
}

int partitionByNumRatings(vector<anime> &animes, int low, int high) {
    vector<anime> vecCopy = animes;
    int pivot = vecCopy[low].number_of_ratings;
    int up = low;
    int down = high;
    while (up < down) {
        for (int i = up; i < high; i++) {
            if (vecCopy[up].number_of_ratings > pivot) {
                break;
            }
            up++;
        }
        for (int j = high; j>low; j--) {
            if (vecCopy[down].number_of_ratings < pivot) {
                break;
            }
            down--;
        }
        if (up < down) {
            swap(vecCopy[up], vecCopy[down]);
        }
    }
    swap(vecCopy[low], vecCopy[down]);
    return down;
}

void quickSortByNumRatings(vector<anime> &animes, int low, int high) {
    vector<anime> vecCopy = animes;
    if (low < high) {
        int pivot = partitionByNumRatings(vecCopy, low, high);
        quickSortByNumRatings(vecCopy, low, pivot-1);
        quickSortByNumRatings(vecCopy, pivot+1, high);
    }
}





