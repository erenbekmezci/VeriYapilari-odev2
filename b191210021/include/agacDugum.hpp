#ifndef agacDugum_hpp
#define agacDugum_hpp

#include "Kuyruk.hpp"
class agacDugum
{
public:
    agacDugum(Kuyruk* veri);
    Kuyruk* veri;
   
    agacDugum* sol;
    agacDugum* sag;
};

#endif