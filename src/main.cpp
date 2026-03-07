//
// Created by sophi on 6/3/2026.
//

#include <iostream>
#include <vector>
#include "dataset.h"

int main() {
    std::vector<anime> animes = parseDataset("../database/anime.csv"); //parce anime.csv. will parce rating.csv too
    for (int i = 0; i < animes.size(); i++) {
        std::cout << animes[i].title << ", " << animes[i].genre << std::endl; //testing
    }
    return 0;
}