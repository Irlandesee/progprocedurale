//
// Created by Mattia Lunardi on 13/05/22.
//
#include <string>
#include <vector>
#include <random>

#ifndef PROGPROCEDURALE_MATRIX_H
#define PROGPROCEDURALE_MATRIX_H

#define DEFAULT_ROWS 3
#define DEFAULT_COLS 3

class matrix {
public:
    matrix() : rows{DEFAULT_ROWS}, cols{DEFAULT_COLS}, item_count{0}{
        for(int i = 0; i < rows; i++)
            vectors.emplace_back(std::vector<int>(cols));
        init_matrix();
    }
    matrix(int r, int c) : rows{r}, cols{c}, item_count{0}{
        for(int i = 0; i < rows; i++)
            vectors.emplace_back(std::vector<int>(cols));
        init_matrix();
    }

    matrix(matrix&);
    [[nodiscard]] std::string to_string() const;
    void build_random_matrix();
private:
    int item_count;
    int rows, cols;
    std::vector<std::vector<int>> vectors;
    void init_matrix();
};


#endif //PROGPROCEDURALE_MATRIX_H
