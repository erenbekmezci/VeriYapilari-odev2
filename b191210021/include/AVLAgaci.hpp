#ifndef AVLAgaci_hpp
#define AVLAgaci_hpp
#include<iostream>
#include "Kuyruk.hpp"
#include "agacDugum.hpp"
using namespace std;

class AVLAgaci
{
public:
	
	AVLAgaci();

	~AVLAgaci();
	
	void ekle(Kuyruk* kuyruk);
	
    void postOrderSil();
	int yukseklik();
	
	
	void postOrder();
	

private:
	
	agacDugum* solaDondur(agacDugum* dugum);
	agacDugum* sagaDondur(agacDugum* dugum);
	
	
	void postOrderSil(agacDugum* aktif);
	void postOrder(agacDugum* aktif);
	
	int yukseklik(agacDugum* aktifDugum);
	agacDugum* ekle(Kuyruk* kuyruk,agacDugum* aktifDugum);
	
	
	
	agacDugum* kok;
};

#endif