/* 
* @file AVLAgaci.cpp
* @description AVLAgacina kuyruğunu toplam mesafesine göre kuyruk ekleme - postorder işlemleri
* @course 1.Öğretim C grubu
* @assignment 2.Ödev
* @date 23.12.2021
* @author Eren Bekmezci eren.bekmezci@sakarya.ogr.edu.tr
*/


#include "AVLAgaci.hpp"
#include <cmath>
#include <iomanip>
#include<iostream>

using namespace std;
AVLAgaci::AVLAgaci()
{
    kok= 0;
}
AVLAgaci::~AVLAgaci()
{
    postOrderSil();
}

void AVLAgaci::ekle(Kuyruk* kuyruk)
{
    kok = ekle(kuyruk,kok);
}

int AVLAgaci::yukseklik() 
{
	return yukseklik(kok);
}

 void AVLAgaci::postOrder() {
 	postOrder(kok);
}



void AVLAgaci::postOrder(agacDugum* aktif) 
{
    
	if(aktif)
    {
        
        postOrder(aktif->sol);

        postOrder(aktif->sag);
      

        aktif->veri->kuyrukYazdir();
       

    }	
}

int AVLAgaci::yukseklik(agacDugum* aktifDugum) 
{
	if(aktifDugum)
    {
        return 1+max(   yukseklik(aktifDugum->sol),
                        yukseklik(aktifDugum->sag));
    }
    return -1;
}
agacDugum* AVLAgaci::ekle(Kuyruk* kuyruk,agacDugum* aktifDugum) 
{
    if(aktifDugum==0)
        return new agacDugum(kuyruk);

	else if(aktifDugum->veri->mesafe<kuyruk->mesafe)
    {
        aktifDugum->sag=ekle(kuyruk,aktifDugum->sag);
        if(yukseklik(aktifDugum->sag)-yukseklik(aktifDugum->sol)>1)
        {   
            if(kuyruk->mesafe>aktifDugum->sag->veri->mesafe)
                aktifDugum = solaDondur(aktifDugum);
                
            else
            {
                aktifDugum->sag = sagaDondur(aktifDugum->sag);
                aktifDugum =solaDondur(aktifDugum);
            }
        }
    }
    else if(aktifDugum->veri->mesafe>kuyruk->mesafe)
    {
        aktifDugum->sol = ekle(kuyruk,aktifDugum->sol);
        if(yukseklik(aktifDugum->sol)-yukseklik(aktifDugum->sag)>1)
        {

            if(kuyruk->mesafe<aktifDugum->sol->veri->mesafe)
                aktifDugum = sagaDondur(aktifDugum);
            else
            {
                aktifDugum->sol = solaDondur(aktifDugum->sol);
                aktifDugum =sagaDondur(aktifDugum);
            }
        }

    }
    return aktifDugum;
}
agacDugum* AVLAgaci::solaDondur(agacDugum* buyukEbeveyn) 
{
	agacDugum* sagCocuk = buyukEbeveyn->sag;
    buyukEbeveyn->sag = sagCocuk->sol;
    sagCocuk->sol = buyukEbeveyn;
    return sagCocuk;
}
agacDugum* AVLAgaci::sagaDondur(agacDugum* buyukEbeveyn) 
{
	agacDugum* solCocuk = buyukEbeveyn->sol;
    buyukEbeveyn->sol = solCocuk->sag;
    solCocuk->sag = buyukEbeveyn;
    return solCocuk;
}



 void AVLAgaci::postOrderSil() {
 	postOrderSil(kok);
}



void AVLAgaci::postOrderSil(agacDugum* aktif) 
{
	if(aktif)
    {
        
        postOrderSil(aktif->sol);
        postOrderSil(aktif->sag);
        delete aktif->veri;//kuyruk silindi
        delete aktif;   //agacDugumu silindi
        
        
    }	
}
