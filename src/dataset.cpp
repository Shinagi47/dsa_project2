//
// Created by sophi on 6/3/2026.
//

#include "dataset.h"
#include <vector>
#include <fstream>
#include <iostream>

std::vector<anime> parseDataset(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<anime> animes;

    std::string line;
    size_t location = 0;

    if (!file.is_open()) {
        std::cout << "Could not open file" << std::endl;
    }

    getline(file, line); //skips first line

    while (getline(file, line)) {
        anime anime;

        location = line.find(','); //skips id
        line = line.substr(location + 1, line.length());

        location = line.find(","); //gets title
        anime.title = line.substr(0, location);
        line = line.substr(location + 1, line.length());

        size_t location2 = line.find('"'); //finds second quotation mark for genres
        location = line.find('"', location2 + 1);
        anime.genre = line.substr(1, location - 1);
        line = line.substr(location + 1, location - location2 - 1);

        location = line.find(','); //skips type
        line = line.substr(location + 1, line.length());

        location = line.find(','); //skips number of episodes
        line = line.substr(location + 1, line.length());

        location = line.find(','); //skips score
        line = line.substr(location + 1, line.length());

        location = line.find(','); //skips number of ratings
        line = line.substr(location + 1, line.length());

        animes.push_back(anime);
    }
    return animes;
}
