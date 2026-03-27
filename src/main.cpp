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
#include "quicksort.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    std::vector<anime> animes = parseDataset1("../database/anime.csv"); //parse anime.csv. will parse rating.csv too
    animes = parseDataset2("../database/rating-1.csv", animes); //parce anime.csv. will parce rating.csv too
    animes = parseDataset2("../database/rating-2.csv", animes); //parce anime.csv. will parce rating.csv too

    cout << "-------------------------" << endl;
    cout << "  Welcome to yourNiche!" << endl;
    cout << "-------------------------" << endl;

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
            //tracking time
            auto start = high_resolution_clock::now(); //start clock

            //1. heap sort by number of ratings
            //2. remove anime with top 50% of num of ratings
            //3. heap sort by avg score
            //4. display top 10
            vector<anime> heapSortedVec = heapSortByNumRatings(filtered, filtered.size()); // heap sort by num of ratings

            for (int i = 0; i < ceil(heapSortedVec.size() * .20); i++) { //remove anime with top 20% of num of ratings
                heapSortedVec.pop_back();
            }

            for (int i = 0; i < heapSortedVec.size(); i++) {
                if (heapSortedVec[i].number_of_ratings < 10) { //remove series with less than 10 num of ratings
                    heapSortedVec.erase(heapSortedVec.begin() + i);
                    i = i - 1;
                }
            }

            reverse(heapSortedVec.begin(), heapSortedVec.end()); // place into descending order

            heapSortedVec = heapSortByAvgScore(heapSortedVec, heapSortedVec.size()); // heap sort by score

            reverse(heapSortedVec.begin(), heapSortedVec.end()); // place into descending order

            //display top 10, score to 2 s.f.
            cout << "Top 10 Niche " << "'" << genre << "'" << " Anime Series" << endl;
            if (heapSortedVec.size() >= 10) {
                for (int i = 1; i < 11; i++) {
                    cout << i << ") " << heapSortedVec[i].title << ", Score: " << fixed<<setprecision(2)<<heapSortedVec[i].score << ", Number of Ratings: " << heapSortedVec[i].number_of_ratings << endl;
                }
            }
            else {
                for (int i = 1; i < heapSortedVec.size(); ++i) {
                    cout << i << ") " << heapSortedVec[i].title << ", Score: " << fixed<<setprecision(2)<<heapSortedVec[i].score << ", Number of Ratings: " << heapSortedVec[i].number_of_ratings << endl;
                }
            }
            cout << endl;

            auto stop = high_resolution_clock::now(); //stop clock
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Heap Sort Time Taken: " << duration.count() << " microseconds" << endl;
        }
        else if (sortingMethod == 2) {
            //tracking time
            auto start = high_resolution_clock::now(); //start clock

            //1. quick sort by number of ratings
            //2. remove anime with top 50% of ratings
            //3. quick sort by avg score
            //4. display top 10
            vector<anime> quickSortVec = quickSortByNumRatings(filtered, 0, filtered.size()-1); //quick sort by num of ratings

            for (int i = 0; i < ceil(quickSortVec.size() * .20); i++) { //remove anime with top 20% of num of ratings
                quickSortVec.pop_back();
            }

            for (int i = 0; i < quickSortVec.size(); i++) {
                if (quickSortVec[i].number_of_ratings < 10) { //remove series with less than 10 num of ratings
                    quickSortVec.erase(quickSortVec.begin() + i);
                    i = i - 1;
                }
            }

            quickSortVec = quickSortByScore(quickSortVec, 0, quickSortVec.size()-1); //quick sort by score

            reverse(quickSortVec.begin(), quickSortVec.end());


            //display top 10, score to 2 s.f.
            cout << "Top 10 Niche " << genre << " Anime Series" << endl;
            if (quickSortVec.size() >= 10) {
                for (int i = 1; i < 11; i++) {
                    cout << i << ") " << quickSortVec[i].title << ", Score: " << fixed<<setprecision(2)<<quickSortVec[i].score << ", Number of Ratings: " << quickSortVec[i].number_of_ratings << endl;
                }
            }
            else {
                for (int i = 1; i < quickSortVec.size(); ++i) {
                    cout << i << ") " << quickSortVec[i].title << ", Score: " << fixed<<setprecision(2)<<quickSortVec[i].score << ", Number of Ratings: " << quickSortVec[i].number_of_ratings << endl;
                }
            }
            cout << endl;

            auto stop = high_resolution_clock::now(); //stop clock
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Quick Sort Time Taken: " << duration.count() << " microseconds" << endl;
        }

        filtered = animes; //resets list
    }

    return 0;
}
