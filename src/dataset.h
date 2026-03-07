//
// Created by sophi on 6/3/2026.
//

#ifndef DSA_PROJECT2_DATASET_H
#define DSA_PROJECT2_DATASET_H

#include <iosfwd>
#include <vector>
#include <string>

struct anime {
    std::string title;
    std::string genre;
    float score;
    int number_of_ratings;
    float niche_score; //hmmm gotta think about how this will be calculated
};

std::vector<anime> parseDataset(const std::string& filename);

#endif //DSA_PROJECT2_DATASET_H