#ifndef __RGB_YCC__
#define __RGB_YCC__

template <class T> class RGB;
template <class T> class YCC;

template <class T>
class RGB{
	T red;
	T green;
	T blue;
public:
	RGB(T,T,T);
	void r(T val);
	void g(T val);
	void b(T val);
	constexpr T r() const;
	constexpr T g() const;
	constexpr T b() const;
	constexpr T y() const;
	constexpr T cb() const;
	constexpr T cr() const;
	YCC<T> ycc();
	RGB operator = (YCC<T>&);
};

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
};

#endif
