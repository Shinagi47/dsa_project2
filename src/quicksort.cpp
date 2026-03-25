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
    float pivot = animes[low].score;
    int up = low;
    int down = high;
    while (up < down) {
        for (int i = up; i < high; i++) {
            if (animes[up].score > pivot) {
                break;
            }
            up++;
        }
        for (int j = high; j>low; j--) {
            if (animes[down].score < pivot) {
                break;
            }
            down--;
        }
        if (up < down) {
            swap(animes[up], animes[down]);
        }
    }
    swap(animes[low], animes[down]);
    return down;
}
vector<anime> quickSortByScore(std::vector<anime>& animes, int low, int high) {
    if (low < high) {
        int pivot = partitionByScore(animes, low, high);
        quickSortByScore(animes, low, pivot-1);
        quickSortByScore(animes, pivot+1, high);
    }
    return animes;
}

int partitionByNumRatings(vector<anime> &animes, int low, int high) {
    int pivot = animes[low].number_of_ratings;
    int up = low;
    int down = high;
    while (up < down) {
        for (int i = up; i < high; i++) {
            if (animes[up].number_of_ratings > pivot) {
                break;
            }
            up++;
        }
        for (int j = high; j>low; j--) {
            if (animes[down].number_of_ratings < pivot) {
                break;
            }
            down--;
        }
        if (up < down) {
            swap(animes[up], animes[down]);
        }
    }
    swap(animes[low], animes[down]);
    return down;
}

vector<anime> quickSortByNumRatings(vector<anime>& animes, int low, int high) {
    if (low < high) {
        int pivot = partitionByNumRatings(animes, low, high);
        quickSortByNumRatings(animes, low, pivot-1);
        quickSortByNumRatings(animes, pivot+1, high);
    }
    return animes;
}





