#include "./bmp.h"
#include <stdio.h>

bmp24::bmp24(){
	this->fileHeader = NULL;
	this->infomationHeader = NULL;
	this->coreHeader = NULL;
}

bmp24::bmp24(std::string& filename){
	bmp24();
}

int bmp24::read(std::string& filename){
	FILE* fin = fopen(filename.c_str(), "rb");
	if(!fin)return -1;

	this->fileHeader = new fileHeader_t;

	if(!fread(this->fileHeader, sizeof fileHeader_t, 1, fin)){
		fclose(fin);
		return -2;
	}

	{
		uint32_t headerSize;
		if(!fread(&headerSize, sizeof uint32_t, 1, fin)){
			fclose(fin);
			return -3;
		}

		if(headerSize == 40){
			this->infomationHeader = new infomationHeader_t;
			this->infomationHeader->biSize = 40;
			if(!fread(&this->infomationHeader->biWidth, 36, 1, fin)){
				fclose(fin);
				return -4;
			}
			this->Height = this->infomationHeader->biHeight;
			this->Width  = this->infomationHeader->biWidth;
		}
		else if(headerSize == 12){
			this->coreHeader = new coreHeader_t;
			this->coreHeader->bcSize = 12;
			if(!fread(&this->coreHeader->bcWidth, 8, 1, fin)){
				fclose(fin);
				return -5;
			}
			this->Height = this->coreHeader->bcHeight;
			this->Width  = this->coreHeader->bcWidth;
		}
		else{
			fclose(fin);
			return -6;
		}
	}

	for(int i=this->fileHeader->bfOffBits - sizeof fileHeader_t - sizeof infomationHeader_t; i-->0; getc(fin));

	printf("height: %d", this->infomationHeader->biHeight);
	printf("width:  %d", this->infomationHeader->biWidth);

	return 0;
}

int bmp24::write(std::string& filename){
	FILE* fout = fopen(filename.c_str(), "wb");
	if(!fout)return -1;
	return 0;
}
