#include "./RGB_YCC.h"

template <class T>
RGB<T>::RGB(T r, T g, T b){
	this->red = r;
	this->green = g;
	this->blue = b;
}

template <class T>
void RGB<T>::r(T val){
	this->red = val;
}

template <class T>
void RGB<T>::g(T val){
	this->green = val;
}

template <class T>
void RGB<T>::b(T val){
	this->blue = val;
}

template <class T>
constexpr T RGB<T>::r() const{
	return this->red;
}

template <class T>
constexpr T RGB<T>::g() const{
	return this->green;
}

template <class T>
constexpr T RGB<T>::b() const{
	return this->blue;
}

template <class T>
constexpr T RGB<T>::y() const{
	return 0.299*this->red + 0.587*this->green + 0.144*this->blue;
}

template <class T>
constexpr T RGB<T>::cb() const{
	return -0.169*this->red - 0.331*this->green + 0.500*this->blue;
}

template <class T>
constexpr T RGB<T>::cr() const{
	return 0.500*this->red - 0.419*this->green - 0.081*this->blue;
}

template <class T>
YCC<T> RGB<T>::ycc(){
	return YCC(this->y(), this->cb(), this->cr());
}

template <class T>
RGB<T> RGB<T>::operator = (YCC<T>& obj){
	*this = obj.rgb();
	return *this;
}

template <class T>
YCC<T>::YCC(T Y, T Cb, T Cr){
	this->Y = Y;
	this->Cb = Cb;
	this->Cr = Cr;
}

template <class T>
void YCC<T>::y(T val){
	this->Y = val;
}

template <class T>
void YCC<T>::cb(T val){
	this->Cb = val;
}

template <class T>
void YCC<T>::cr(T val){
	this->Cr = val;
}

template <class T>
constexpr T YCC<T>::y() const{
	return this->Y;
}

template <class T>
constexpr T YCC<T>::cb() const{
	return this->Cb;
}

template <class T>
constexpr T YCC<T>::cr() const{
	return this->Cr;
}

template <class T>
constexpr T YCC<T>::r() const{
	return this->Y + 1.402*this->Cr;
}

template <class T>
constexpr T YCC<T>::g() const{
	return this->Y - 0.344*this->Cb - 0.714*this->Cr;
}

template <class T>
constexpr T YCC<T>::b() const{
	return this->Y + 1.772*this->Cb;
}
template <class T>
RGB<T> YCC<T>::rgb(){
	return RGB(this->r(), this->g(), this->b());
}

template <class T>
YCC<T> YCC<T>::operator = (RGB<T>& obj){
	*this = obj.ycc();
	return *this;
}
