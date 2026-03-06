//
// Created by sophi on 6/3/2026.
//

#ifndef DSA_PROJECT2_DATASET_H
#define DSA_PROJECT2_DATASET_H

using namespace std;
#include <iosfwd>
#include <vector>
#include <string>

struct anime {
    string title;
    string genre;
    float score;
    int number_of_ratings;
    float niche_score; //hmmm gotta think about how this will be calculated
};

class dataset {
    vector<anime> animes;

};

vector<anime> parseDataset(std::string filename);

#endif //DSA_PROJECT2_DATASET_H