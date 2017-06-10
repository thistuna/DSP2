#include <iostream>
#include <string>
#include <cstdio>
#include "RGB_YCC.h"
#include "bmp.h"

extern std::string startMessage;

std::string bmpfilename = "..\\samp.bmp";

int main(){
	bmp24 bmpdata;

	std::cout << startMessage << std::endl;

	bmpdata.read(bmpfilename);

	while(1){
		unsigned int x,y;
		std::cin >> x >> y;
		if(x>=bmpdata.width() || y>=bmpdata.height()) break;
		yccf a;
		a = bmpdata.px(x,y);
		printf("(%d,%d) r:%f g:%f b:%f y:%f cb:%f cr:%f\n",x,y,a.r(),a.g(),a.b(),a.y(),a.cb(),a.cr());

	}
}

std::string startMessage =
"dsp2-2";
