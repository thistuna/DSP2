#ifndef __BMP__
#define __BMP__

#include "./RGB_YCC.h"
#include <stdint.h>
#include <vector>
#include <string>

#pragma pack(2)
typedef struct{					/* �t�@�C���w�b�_ */
	uint16_t bfType;			/* �t�@�C���^�C�v */
	uint32_t bfSize;		/* �t�@�C���T�C�Y */
	uint16_t bfReserved1;			/* �\��̈� */
	uint16_t bfReserved2;		/* �\��̈� */
	uint32_t bfOffBits;			/* �t�@�C���擪����摜�f�[�^�܂ł̃I�t�Z�b�g[byte] */
}fileHeader_t;
#pragma pack()

#pragma pack(4)
typedef struct{					/* ���w�b�_ */
	uint32_t biSize;			/* ���w�b�_�T�C�Y[byte] : 40 */
	uint32_t biWidth;			/* �摜�̕�[�s�N�Z��] */
	uint32_t biHeight;			/* �摜�̍���[�s�N�Z��] */
	uint16_t biPlanes;			/* �v���[���� */
	uint16_t biBitCount;		/* �F�r�b�g��[bit] */
	uint32_t biCompression;		/* ���k�`�� */
	uint32_t biSizeImage;		/* �摜�f�[�^�T�C�Y[byte] */
	uint32_t biXPixPerMeter;	/* �����𑜓x[dot/m] */
	uint32_t biYPixPerMeter;	/* �����𑜓x[dot/m] */
	uint32_t biClrUsed;			/* �i�[�p���b�g��[�g�p�F��] */
	uint32_t biCirImportant;	/* �d�v�F�� */
}infomationHeader_t;
#pragma pack()

#pragma pack(4)
typedef struct{
	uint32_t bcSize;			/* ���w�b�_�T�C�Y[byte] : 12 */
	uint16_t bcWidth;			/* �摜�̕�[�s�N�Z��] */
	uint16_t bcHeight;			/* �摜�̍���[�s�N�Z��] */
	uint16_t bcPlanes;			/* �v���[���� */
	uint16_t bcBitCount;		/* �F�r�b�g��[bit] */
}coreHeader_t;
#pragma pack()

class bmp24{
private:
	fileHeader_t* fileHeader;
	infomationHeader_t* infomationHeader;
	coreHeader_t* coreHeader;
	std::vector<std::vector<RGB<uint8_t>>> data;
	int Width;
	int Height;
public:
	bmp24();
	bmp24(std::string& filename);
	int read(std::string& filename);
	int write(std::string& filename);
};

#endif