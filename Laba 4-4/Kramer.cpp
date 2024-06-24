#include "Kramer.h"


vector<double> Kramer::solve()
{
	vector<double> solutions;

	double determinant = matrix_for_sol.CalculateDeterminant();
	if (determinant==0) 
	{
		cerr << "Determinant is zero. Try another matrix..." << std::endl;
		return solutions;
	}
	Matrix orig_matrix = matrix_for_sol;
	for (size_t i = 0; i < matrix_for_sol.GetRows(); ++i) {
		matrix_for_sol = orig_matrix;
		for (size_t j = 0; j < matrix_for_sol.GetRows(); ++j) {
			matrix_for_sol(j, i) = constants[j];
		}
	}

	solutions.push_back(matrix_for_sol.CalculateDeterminant() / determinant);
	return solutions;
}