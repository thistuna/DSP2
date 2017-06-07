#include <iostream>
#include <string>
#include <cstdio>
//#include "./RGB_YCC.h"
#include "./bmp.h"

extern std::string startMessage;

std::string bmpfilename = "..\\samp.bmp";

int main(){
	bmp24 bmpdata;

	rgb24 temp;

	std::cout << startMessage << std::endl;

	bmpdata.read(bmpfilename);
}

std::string startMessage =
"dsp2-2";
