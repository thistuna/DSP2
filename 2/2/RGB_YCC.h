#ifndef __RGB_YCC__
#define __RGB_YCC__

/* templateégÇ¢ÇΩÇ©Ç¡ÇΩÅcÅc */

#include <stdint.h>

class rgb24;
class rgbf;
class yccf;

class rgb24{
	uint8_t red;
	uint8_t green;
	uint8_t blue;
public:
	rgb24();
	rgb24(uint8_t,uint8_t,uint8_t);
	void r(uint8_t val);
	void g(uint8_t val);
	void b(uint8_t val);
	uint8_t r();
	uint8_t g();
	uint8_t b();
	uint8_t y();
	uint8_t cb();
	uint8_t cr();
	rgb24 operator = (rgbf x);
	rgb24 operator = (yccf x);
};

class rgbf{
	double red;
	double green;
	double blue;
public:
	rgbf(double,double,double);
	rgbf();
	void r(double val);
	void g(double val);
	void b(double val);
	double r();
	double g();
	double b();
	double y();
	double cb();
	double cr();
	rgbf operator = (rgb24 x);
	rgbf operator = (yccf x);
};

class yccf{
	double Y;
	double Cb;
	double Cr;
public:
	yccf(double,double,double);
	yccf();
	void y(double val);
	void cb(double val);
	void cr(double val);
	double y();
	double cb();
	double cr();
	double r();
	double g();
	double b();
	yccf operator = (rgb24);
	yccf operator = (rgbf);
};

#endif
