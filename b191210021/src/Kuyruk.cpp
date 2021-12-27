/* 
* @file Kuyruk.cpp
* @description Kuyruğa veri ekleme - öncelikli siralama 
* @course 1.Öğretim C grubu
* @assignment 2.Ödev
* @date 23.12.2021
* @author Eren Bekmezci eren.bekmezci@sakarya.ogr.edu.tr
*/


#include <Kuyruk.hpp>
#include <iomanip>

Kuyruk::Kuyruk()
{
    ilk=son=0;
    veriSayisi=0;
    
}
Kuyruk::~Kuyruk()
{
    while(ilk!=0)
    {
        Dugum*gec= ilk;
        ilk=ilk->sonraki;

        delete gec;

        
    }
}


void Kuyruk::ekle(int veri)
{
    if(ilk==0)
    {
        ilk=new Dugum(veri);
        son= ilk;
        veriSayisi++;

    }
    else
    {
        Dugum* yeni = new Dugum(veri);
        son->sonraki = yeni;
        son = yeni;
        veriSayisi++;

    }
}
void Kuyruk::sirala(){
    
    Dugum* enKucuk = ilk;
    Dugum* gec = ilk;
    Dugum* gec2 = ilk;
        
    for (int i = 0; i < veriSayisi; i++)
    {
        
        while (gec->sonraki != 0)
        {
            if (gec->sonraki->veri < enKucuk->veri)
            {
                enKucuk = gec->sonraki;
                
            }
            
            gec = gec->sonraki;
        }
        
        int deger = enKucuk->veri;
        
        enKucuk->veri = gec2->veri;
        gec2->veri = deger;
        
        
        gec2 = gec2->sonraki;
        gec = gec2;
        
        enKucuk = gec;
    }
       
}


void Kuyruk::kuyrukYazdir(){
   
    Dugum* gec= ilk;
    
    while(gec!=0)
    {
        cout<<gec->veri<<"  ";
           
        gec = gec->sonraki;  
    }
   cout<<endl;


}