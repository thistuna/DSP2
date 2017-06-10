#include "RGB_YCC.h"

/*

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
 T YCC<T>::y() {
	return this->Y;
}

template <class T>
 T YCC<T>::cb() {
	return this->Cb;
}

template <class T>
 T YCC<T>::cr() {
	return this->Cr;
}

template <class T>
 T YCC<T>::r() {
	return this->Y + 1.402*this->Cr;
}

template <class T>
 T YCC<T>::g() {
	return this->Y - 0.344*this->Cb - 0.714*this->Cr;
}

template <class T>
 T YCC<T>::b() {
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
}*/

rgb24::rgb24(){
	rgb24(0,0,0);
}

rgb24::rgb24(uint8_t r, uint8_t g, uint8_t b){
	this->red = r;
	this->green = g;
	this->blue = b;
}

void rgb24::r(uint8_t val){
	this->red = val;
}

void rgb24::g(uint8_t val){
	this->green = val;
}

void rgb24::b(uint8_t val){
	this->blue = val;
}

uint8_t rgb24::r() {
	return this->red;
}

uint8_t rgb24::g() {
	return this->green;
}

uint8_t rgb24::b() {
	return this->blue;
}

uint8_t rgb24::y() {
	return 0.299*this->red + 0.587*this->green + 0.114*this->blue;
}

uint8_t rgb24::cb() {
	return -0.169*this->red - 0.331*this->green + 0.500*this->blue;
}

uint8_t rgb24::cr() {
	return 0.500*this->red - 0.419*this->green - 0.081*this->blue;
}

rgb24 rgb24::operator=(rgbf x){
	this->red = x.r();
	this->green = x.g();
	this->blue = x.b();

	return *this;
}

rgb24 rgb24::operator=(yccf x){
	this->red = x.r();
	this->green = x.g();
	this->blue = x.b();

	return *this;
}

rgbf::rgbf(){
	rgbf(0.,0.,0.);
}

rgbf::rgbf(double r, double g, double b){
	this->red = r;
	this->green = g;
	this->blue = b;
}

void rgbf::r(double val){
	this->red = val;
}

void rgbf::g(double val){
	this->green = val;
}

void rgbf::b(double val){
	this->blue = val;
}

double rgbf::r() {
	return this->red;
}

double rgbf::g() {
	return this->green;
}

double rgbf::b() {
	return this->blue;
}

double rgbf::y() {
	return 0.299*this->red + 0.587*this->green + 0.114*this->blue;
}

double rgbf::cb() {
	return -0.169*this->red - 0.331*this->green + 0.500*this->blue;
}

double rgbf::cr() {
	return 0.500*this->red - 0.419*this->green - 0.081*this->blue;
}

rgbf rgbf::operator=(rgb24 x){
	this->red = x.r();
	this->green = x.g();
	this->blue = x.b();

	return *this;
}

rgbf rgbf::operator=(yccf x){
	this->red = x.r();
	this->green = x.g();
	this->blue = x.b();

	return *this;
}

yccf::yccf(double Y, double Cb, double Cr){
	this->Y = Y;
	this->Cb = Cb;
	this->Cr = Cr;
}

yccf::yccf(){
	yccf(0.,0.,0.);
}

void yccf::y(double val){
	this->Y = val;
}

void yccf::cb(double val){
	this->Cb = val;
}

void yccf::cr(double val){
	this->Cr = val;
}

 double yccf::y() {
	return this->Y;
}

 double yccf::cb() {
	return this->Cb;
}

 double yccf::cr() {
	return this->Cr;
}

 double yccf::r() {
	return this->Y + 1.402*this->Cr;
}

 double yccf::g() {
	return this->Y - 0.344*this->Cb - 0.714*this->Cr;
}

 double yccf::b() {
	return this->Y + 1.772*this->Cb;
}

yccf yccf::operator = (rgb24 x){
	rgbf temp;
	temp = x;
	this->Y = temp.y();
	this->Cb = temp.cb();
	this->Cr = temp.cr();

	return *this;
}

yccf yccf::operator = (rgbf x){
	this->Y = x.y();
	this->Cb = x.cb();
	this->Cr = x.cr();
	
	return *this;
}