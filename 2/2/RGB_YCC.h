#ifndef __RGB_YCC__
#define __RGB_YCC__

/*template <class T> class YCC;

template <class T>
class YCC{
	T Y;
	T Cb;
	T Cr;
public:
	YCC(T,T,T);
	void y(T val);
	void cb(T val);
	void cr(T val);
	constexpr T y() const;
	constexpr T cb() const;
	constexpr T cr() const;
	constexpr T r() const;
	constexpr T g() const;
	constexpr T b() const;
	RGB<T> rgb();
	YCC operator = (RGB<T>&);
};*/

#include <stdint.h>

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
	constexpr uint8_t r() const;
	constexpr uint8_t g() const;
	constexpr uint8_t b() const;
	constexpr uint8_t y() const;
	constexpr uint8_t cb() const;
	constexpr uint8_t cr() const;
//	YCC<T> ycc();
//	RGB operator = (YCC<T>&);
};

#endif
