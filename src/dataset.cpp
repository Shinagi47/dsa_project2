//
// Created by sophi on 6/3/2026.
//

#include "dataset.h"
#include <vector>
#include <fstream>
#include <iostream>

std::vector<anime> parseDataset1(const std::string& filename) {
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

        location = line.find(','); //gets anime_id
        anime.anime_id = std::stoi(line.substr(0, location));
        line = line.substr(location + 1, line.length());

        std::string title;
        bool is_genre = false;

        while (!is_genre) {
            location = line.find(","); //gets title
            if (location == std::string::npos) { //prevents inf loop
                break;
            }

            if (line[location + 1] == '"') { //if quotation marks are right after a comma, it's part of the genre
                title.append(line.substr(0, location));
                is_genre = true;
                line = line.substr(location + 1, line.length());
            }
            else {
                title.append(line.substr(0, location + 1)); //comma is in title
                line = line.substr(location + 1, line.length());
            }
        }

        anime.title = title;

        size_t location2 = line.find('"'); //finds second quotation mark for genres
        is_genre = true;
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

std::vector<anime> parseDataset2(const std::string& filename, std::vector<anime>& animes) {
    std::ifstream file(filename);

    std::string line; //format "user_id","anime_id","rating"
    int id;
    size_t location = 0;

    if (!file.is_open()) {
        std::cout << "Could not open file" << std::endl;
    }

    getline(file, line); //skips first line

    while (getline(file, line)) {
        location = line.find(','); //skips user_id
        line = line.substr(location + 1, line.length());

        location = line.find(','); //gets anime_id
        id = std::stoi(line.substr(1, location - 2));
        line = line.substr(location + 1, line.length());

        location = line.find(','); //gets rating
        if (stoi(line.substr(1, line.length() - 2)) == -1) {
            line = line.substr(location + 1, line.length());
            continue;
        }
        else {
            for (size_t i = 0; i < animes.size(); i++) {
                if (animes[i].anime_id == id) {
                    float old_score = animes[i].score;
                    float new_score = std::stoi(line.substr(1, line.length() - 2));
                    float avg_score = (old_score * animes[i].number_of_ratings + new_score) / (animes[i].number_of_ratings + 1);
                    animes[i].number_of_ratings += 1;
                    animes[i].score = avg_score;
                }
            }
            line = line.substr(location + 1, line.length());
        }
    }

    //fix this function, then do rating-2.csv
    return animes;
}
