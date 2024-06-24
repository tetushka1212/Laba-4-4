#pragma once
#include "Matrix.h"
#include <vector>
#include <cmath>
#include <fstream>

class Kramer
{
private:
    Matrix matrix_for_sol;
    vector <double> constants;
public:
    Kramer(Matrix& new_matrix, vector<double> new_constants) : matrix_for_sol(new_matrix), constants(new_constants) {}
    vector<double> solve();
    friend std::ostream& operator<< (std::ostream& out, Kramer& cramer) {
        Matrix original_matrix = cramer.matrix_for_sol;

        out << "Original Matrix:" << std::endl << original_matrix << std::endl;
        out << "Constants Vector:" << std::endl;
        for (const auto& constant : cramer.constants) {
            out << constant << " ";
        }
        out << std::endl;

        vector<double> solutions = cramer.solve();

        out << "Solutions:" << std::endl;
        for (int i = 0; i < solutions.size(); ++i) {
            out << "x" << i << " = " << solutions[i] << std::endl;
        }

        return out;
    }
};
			