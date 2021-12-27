/* 
* @file main.cpp
* @description -- Dosyalama işlemleri - Kuyruk oluşturma - ağaca ekleme - toplam mesafe bulup kuyruğa ekleme
* @course 1.Öğretim C grubu
* @assignment 2.Ödev
* @date 23.12.2021
* @author Eren Bekmezci eren.bekmezci@sakarya.ogr.edu.tr
*/

#include <iostream>
#include "Kuyruk.hpp"
#include "AVLAgaci.hpp"
#include <fstream>
#include <math.h>
#include<iomanip>

using namespace std;
#include <string>


int main()
{
    
    int x;
    int y;
    int z;

    AVLAgaci* agac = new AVLAgaci();
    fstream dosya;

    dosya.open("Noktalar.txt" , ios::in);
    if(dosya.is_open() == true)
    {
        
        string dizi;
        
        int s;
        string sayi = "";
        
        int nokta[3];
        while (!dosya.eof())
        {
            
            getline(dosya,dizi);
            Kuyruk* kuyruk = new Kuyruk();
            int sayac= 0;
            int noktaAl;
            int toplam;
            int syc = 0;
            for (int i = 0; i < dizi.length(); i++)
            {
                
                if(isdigit(dizi[i]))
                {
                    sayi += dizi[i];
                    
                }
                else
                {
                    s = stoi(sayi);
                 
                    sayi="";
                    nokta[sayac] = s;
                    
                    if(sayac != 2)
                        sayac++;
                    else
                    {
                        int a = nokta[0] * nokta[0]  +  nokta[1] * nokta[1]  + nokta[2] * nokta[2] ;
                        noktaAl= sqrt(a);
                        
                        kuyruk->ekle(noktaAl);
                        

                        if(syc == 0)
                        {
                            x = nokta[0];
                            y = nokta[1];
                            z = nokta[2];
                            syc++;
                        }
                        else
                        {
                            int _x =  (nokta[0] - x) * (nokta[0] - x);
                            int _y =  (nokta[1] - y) * (nokta[1] - y);
                            int _z =  (nokta[2] - z) * (nokta[2] - z);
                            
                            int l = sqrt(_x + _y + _z);
                           
                            kuyruk->mesafe +=l;
                            x = nokta[0];
                            y = nokta[1];
                            z = nokta[2];
                            
                        }
                        
                       
                        sayac = 0;
                        
                    }

                }
                    
            }
            kuyruk->sirala();
            
            agac->ekle(kuyruk);
            
            
            
            
            
            


        }
        
    }
    else
        cout<<"dosya okuma başarısız"<<endl;
    
    agac->postOrder();
    delete agac;
    
    dosya.close();




}