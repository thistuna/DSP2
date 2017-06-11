#include <vector>

std::vector<double> dct(std::vector<double> x);
std::vector<std::vector<double>> dct(std::vector<std::vector<double>> x);

namespace DCT{
	inline double C(int n, int k, int N);
}