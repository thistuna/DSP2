#ifndef __BMP__
#define __BMP__

#include <stdint.h>
#include <vector>
#include <string>
#include "./RGB_YCC.h"

#pragma pack(2)
typedef struct{					/* ファイルヘッダ */
	uint16_t bfType;			/* ファイルタイプ */
	uint32_t bfSize;			/* ファイルサイズ */
	uint16_t bfReserved1;		/* 予約領域 */
	uint16_t bfReserved2;		/* 予約領域 */
	uint32_t bfOffBits;			/* ファイル先頭から画像データまでのオフセット[byte] */
}fileHeader_t;
#pragma pack()

#pragma pack(4)
typedef struct{					/* 情報ヘッダ */
	uint32_t biSize;			/* 情報ヘッダサイズ[byte] : 40 */
	uint32_t biWidth;			/* 画像の幅[ピクセル] */
	uint32_t biHeight;			/* 画像の高さ[ピクセル] */
	uint16_t biPlanes;			/* プレーン数 */
	uint16_t biBitCount;		/* 色ビット数[bit] */
	uint32_t biCompression;		/* 圧縮形式 */
	uint32_t biSizeImage;		/* 画像データサイズ[byte] */
	uint32_t biXPixPerMeter;	/* 水平解像度[dot/m] */
	uint32_t biYPixPerMeter;	/* 垂直解像度[dot/m] */
	uint32_t biClrUsed;			/* 格納パレット数[使用色数] */
	uint32_t biCirImportant;	/* 重要色数 */
}infomationHeader_t;
#pragma pack()

#pragma pack(4)
typedef struct{
	uint32_t bcSize;			/* 情報ヘッダサイズ[byte] : 12 */
	uint16_t bcWidth;			/* 画像の幅[ピクセル] */
	uint16_t bcHeight;			/* 画像の高さ[ピクセル] */
	uint16_t bcPlanes;			/* プレーン数 */
	uint16_t bcBitCount;		/* 色ビット数[bit] */
}coreHeader_t;
#pragma pack()

class bmp24{
private:
	fileHeader_t* fileHeader;
	infomationHeader_t* infomationHeader;
	coreHeader_t* coreHeader;
	std::vector<std::vector<rgb24>> data;
	int Width;
	int Height;
	int BitCount;
public:
	bmp24();
	bmp24(std::string& filename);
	int read(std::string& filename);
	int write(std::string& filename);
	int height(){return this->Height;}
	int width(){return this->Width;}
	rgb24 px(int x, int y){return data[x][y];}
};

#endif
