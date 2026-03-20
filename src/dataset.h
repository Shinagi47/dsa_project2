//
// Created by sophi on 6/3/2026.
//

#ifndef DSA_PROJECT2_DATASET_H
#define DSA_PROJECT2_DATASET_H

#include <iosfwd>
#include <vector>
#include <string>
#include <iomanip>

struct anime {
    std::string title;
    std::string genre;
    float score = 0;
    int anime_id, number_of_ratings = 0;
    float niche_score; //hmmm gotta think about how this will be calculated
};

std::vector<anime> parseDataset1(const std::string& filename);
std::vector<anime> parseDataset2(const std::string& filename, std::vector<anime>& animes);

std::vector<anime> byGenre(const std::vector<anime>& animes, std::string& genre);

#endif //DSA_PROJECT2_DATASET_H