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
    for (int i = 0; i < animes.size(); i++) {
        std::cout << animes[i].title << ", " << animes[i].genre << ", " << fixed<<setprecision(2)<<animes[i].score << ", " << animes[i].number_of_ratings << std::endl; //testing
    }
    return 0;
}