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
			puts("Windows Bitmap");
			this->infomationHeader = new infomationHeader_t;
			this->infomationHeader->biSize = 40;
			if(!fread(&this->infomationHeader->biWidth, 36, 1, fin)){
				fclose(fin);
				return -4;
			}
			this->Height    = this->infomationHeader->biHeight;
			this->Width     = this->infomationHeader->biWidth;
			this->BitCount  = this->infomationHeader->biBitCount;
		}
		else if(headerSize == 12){
			puts("OS2 bitmap");
			this->coreHeader = new coreHeader_t;
			this->coreHeader->bcSize = 12;
			if(!fread(&this->coreHeader->bcWidth, 8, 1, fin)){
				fclose(fin);
				return -5;
			}
			this->Height   = this->coreHeader->bcHeight;
			this->Width    = this->coreHeader->bcWidth;
			this->BitCount = this->coreHeader->bcBitCount;
		}
		else{
			fclose(fin);
			return -6;
		}
	}

	for(int i=this->fileHeader->bfOffBits - sizeof fileHeader_t - sizeof infomationHeader_t; i-->0; getc(fin));


	printf("size:         %d\n", this->infomationHeader->biSize);
	printf("width:        %d\n", this->infomationHeader->biWidth);
	printf("height:       %d\n", this->infomationHeader->biHeight);
	printf("planes:       %d\n", this->infomationHeader->biPlanes);
	printf("bitcount:     %d\n", this->infomationHeader->biBitCount);
	printf("compression:  %d\n", this->infomationHeader->biCompression);
	printf("sizeimage:    %d\n", this->infomationHeader->biSizeImage);
	printf("XPixPerMeter: %d\n", this->infomationHeader->biXPixPerMeter);
	printf("YPixPerMeter: %d\n", this->infomationHeader->biYPixPerMeter);
	printf("ClrUsed:      %d\n", this->infomationHeader->biClrUsed);
	printf("CirImportant: %d\n", this->infomationHeader->biCirImportant);

	data = std::vector<std::vector<rgb24>>(this->Height,std::vector<rgb24>(this->Width));

	for(int i=this->Height; i; ){
		--i;
		if(this->BitCount == 24){
			int count=0;
			for(int j=0; j<this->Width; ++j){
				data[i][j].b(getc(fin));
				data[i][j].g(getc(fin));
				data[i][j].r(getc(fin));
				count += 3;
				count &= 3;
			}
			while(count){
				--count;
				getc(fin);
			}
		}
		else if(this->BitCount == 32){
			for(int j=0; j<this->Width; ++j){
				data[i][j].b(getc(fin));
				data[i][j].g(getc(fin));
				data[i][j].r(getc(fin));
				getc(fin);
			}
		}
	}

	fclose(fin);
	puts("end");

	return 0;
}

int bmp24::write(std::string& filename){
	FILE* fout = fopen(filename.c_str(), "wb");
	if(!fout)return -1;
	return 0;
}
