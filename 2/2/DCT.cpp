#define _USE_MATH_DEFINES
#include "DCT.h"
#include <cmath>

std::vector<double> dct(std::vector<double> x){
	std::vector<double> X(x.size());

	for(int k=0; k<X.size(); ++k){
		X[k]=0.;
		for(int n=0; n<X.size(); ++n){
			X[k] += x[n] * DCT::C(n,k,X.size());
		}
	}

	return X;
}

std::vector<std::vector<double>> dct(std::vector<std::vector<double>> x){
	std::vector<std::vector<double>> X = x;

	for(int k1=0; k1<X.size(); ++k1){
		for(int k2=0; k2<X[0].size(); ++k2){
			X[k1][k2] = 0.;
			for(int n1=0; n1<X.size(); ++n1){
				for(int n2=0; n2<X[0].size(); ++n2){
					X[k1][k2] += x[n1][n2] * DCT::C(n1,k1,X.size()) * DCT::C(n2,k2,X[0].size());
				}
			}
		}
	}

	return X;
}

namespace DCT{
	inline double C(int n, int k, int N){
		return k? sqrt(2./N)*cos((2*n+1)*k*M_PI/2./N) : 1./sqrt(N);
	}
}
