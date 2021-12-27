#ifndef Kuyruk_hpp
#define Kuyruk_hpp
#include<iostream>
#include "Dugum.hpp"
using namespace std;

class Kuyruk
{
public:
	Kuyruk();
	~Kuyruk();
	void ekle(int veri);
	
   
	
	void sirala();
	int mesafe = 0;
	int veriSayisi;
	void kuyrukYazdir();
    
private:
	Dugum* 	ilk;
	Dugum*	son;
};

#endif