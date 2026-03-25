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
            vector<anime> heapSortedVec = heapSortByNumRatings(filtered, filtered.size()); // heap sort by num of ratings
            for (int i = 0; i < ceil(heapSortedVec.size() * .50); i++) {
                heapSortedVec.pop_back();
            }
            //reverse(heapSortedVec.begin(), heapSortedVec.end()); // place into descending order
            heapSortedVec = heapSortByAvgScore(heapSortedVec, heapSortedVec.size()); // heap sort by score
            // display top 10
            for (int i = 1; i < 11; i++) {
                cout << i << ")" << heapSortedVec[i].title << ", Score: " << heapSortedVec[i].score << endl;
            }
        }
        else if (sortingMethod == 2) {
            //1. quick sort by number of ratings
            //2. remove anime with top 50% of ratings
            //3. quick sort by avg score
            //4. display top 10
        }

        //TESTING
        /*for (int i = 0; i < filtered.size(); i++) {
            std::cout << filtered[i].title << ": " << filtered[i].genre << ", " << fixed<<setprecision(2)<<filtered[i].score << ", " << filtered[i].number_of_ratings << std::endl; //testing
        }*/

        filtered = animes;
    }

    return 0;
}
