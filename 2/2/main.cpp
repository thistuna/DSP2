#include <iostream>
#include <string>
#include <cstdio>
#include "RGB_YCC.h"
#include "bmp.h"
#include "DCT.h"

extern std::string startMessage;

std::string bmpfilename = "..\\samp.bmp";

int main(){
	bmp24 bmpdata;

	std::cout << startMessage << std::endl;

	bmpdata.read(bmpfilename);

	puts("read");

	#define N 4

	std::vector<std::vector<double>> x(bmpdata.height(),std::vector<double>(bmpdata.width()));

	for(int xx=0; xx<x.size(); ++xx){
		for(int yy=0; yy<x[xx].size(); ++yy){
			yccf ycctemp;
			ycctemp = bmpdata.px(xx,yy);
			x[xx][yy] = ycctemp.y();
		}
	}

	puts("convert");

	auto X = dct(x);

	puts("dct");

	FILE* fout = fopen("out.txt", "w");

	for(int yy=0; yy<X.size(); ++yy){
		for(int xx=0; xx<X[yy].size(); ++xx){
			fprintf(fout, "%f",X[xx][yy]);
			putc(xx == X[yy].size()-1 ? '\n' : '\t', fout);
		}
	}

	puts("output");
}

std::string startMessage =
"dsp2-2";
