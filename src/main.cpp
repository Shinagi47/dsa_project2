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

    //if action genre selected... if romance genre selected... etc
    //new array of only that genre ?

    while (true) {
        cout << "Enter a genre:";
        string genre;
        cin >> genre;
        for (int i = 0; i < genre.size(); i++) {
            if (i == 0) {
                genre[0] = toupper(genre[0]);
            }
            else {
                genre[i] = tolower(genre[i]);
            }
        }

        std::vector<anime> filtered = animes;

        filtered = filterByGenre(animes, genre);
        //TESTING
        for (int i = 0; i < filtered.size(); i++) {
            std::cout << filtered[i].title << ": " << filtered[i].genre << ", " << fixed<<setprecision(2)<<filtered[i].score << ", " << filtered[i].number_of_ratings << std::endl; //testing
        }
        filtered = animes;
    }

    /*
    if (genre == "action") {

    }
    else if (genre == "adventure") {

    }
    else if (genre == "comedy") {

    }
    else if (genre == "drama") {

    }
    else if (genre == "fantasy") {

    }
    else if (genre == "historical") {

    }
    else if (genre == "horror") {

    }
    else if (genre == "mystery") {

    }
    else if (genre == "romance") {

    }
    else if (genre == "sci-fi") {

    }
    else if (genre == "slice of life") {

    }
    else if (genre == "supernatural") {

    }
    else if (genre == "thriller") {

    }
    */

    //if heapsort selected... take in struct vector
    //call heapsort based on niche score values
    //vector<anime> heapSorted = heapSort(animes);

    //if quicksort selected... take in struct vector
    //call quicksort based on niche score values
    //vector<anime> quickSorted = quickSort(animes);

    return 0;
}