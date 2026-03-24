//
// Created by sophi on 6/3/2026.
//

#include <iostream>
#include "math.h"
#include <vector>
#include <iomanip>
#include <algorithm>
#include "dataset.h"
#include "heapsort.h"
using namespace std;

int main() {
    std::vector<anime> animes = parseDataset1("../database/anime.csv"); //parse anime.csv. will parse rating.csv too
    animes = parseDataset2("../database/rating-1.csv", animes); //parce anime.csv. will parce rating.csv too
    animes = parseDataset2("../database/rating-2.csv", animes); //parce anime.csv. will parce rating.csv too

    while (true) {
        cout << "Enter a genre: ";
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

        cout << "Select sorting method: (enter number) " << endl;
        cout << "1. Heap Sort" << endl;
        cout << "2. Quick Sort" << endl;

        int sortingMethod;
        cin >> sortingMethod;
        if (sortingMethod == 1) {
            //1. heap sort by number of ratings
            //2. remove anime with top 50% of ratings
            //3. heap sort by avg score
            //4. display top 10
            vector<anime> heapSortedVec = heapSort(animes, animes.size()); 
            // if heap sort selected: rmv top 60% anime in # of ratings; descending order; heap sort again; display top 10
            for (int i = 0; i < ceil(animes.size() * .40); i++) {
                heapSortedVec.pop_back();
            }
            reverse(heapSortedVec.begin(), heapSortedVec.end());
            vector<anime> heapSortedVec = heapSort(animes, animes.size()); // make another function to heap sort by avg score
            for (int i = 0; i < 10; i++) {
                cout << i << ")" << heapSortedVec[i].title << ", Number of Ratings: " << heapSortedVec[i].number_of_ratings << endl;
            }
        }
        else if (sortingMethod == 2) {
            //1. quick sort by number of ratings
            //2. remove anime with top 50% of ratings
            //3. quick sort by avg score
            //4. display top 10
        }

        //TESTING
        for (int i = 0; i < filtered.size(); i++) {
            std::cout << filtered[i].title << ": " << filtered[i].genre << ", " << fixed<<setprecision(2)<<filtered[i].score << ", " << filtered[i].number_of_ratings << std::endl; //testing
        }

        filtered = animes;
    }

    return 0;
}
