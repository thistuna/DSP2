#include <iostream>
#include <string>
#include <cstdio>
#include "./bmp.h"

extern std::string startMessage;

std::string bmpfilename = "..\\samp.bmp";

int main(){
	bmp24 bmpdata;

	RGB<uint8_t> rgbclass(0,0,0);

	std::cout << startMessage << std::endl;

	bmpdata.read(bmpfilename);
}

std::string startMessage =
"dsp2-2";
