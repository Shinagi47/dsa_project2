//
// Created by sophi on 6/3/2026.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include "dataset.h"
using namespace std;

int main() {
    std::vector<anime> animes = parseDataset1("../database/anime.csv"); //parse anime.csv. will parse rating.csv too
    animes = parseDataset2("../database/rating-1.csv", animes); //parce anime.csv. will parce rating.csv too
    animes = parseDataset2("../database/rating-2.csv", animes); //parce anime.csv. will parce rating.csv too

    //TESTING
    for (int i = 0; i < animes.size(); i++) {
        std::cout << animes[i].title << ", " << animes[i].genre << ", " << fixed<<setprecision(2)<<animes[i].score << ", " << animes[i].number_of_ratings << std::endl; //testing
    }

    //if action genre selected... if romance genre selected... etc
    //new array of only that genre ?
    //vector<anime> filteredAnimes = byGenre(animes, "Action");

    //if heapsort selected... take in struct vector
    //call heapsort based on niche score values
    //vector<anime> heapSorted = heapSort(animes);

    //if quicksort selected... take in struct vector
    //call quicksort based on niche score values
    //vector<anime> quickSorted = quickSort(animes);

    return 0;
}