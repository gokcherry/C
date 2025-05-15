#include "modeller/GazDeviGezegen.h"
#include "modeller/Gezegen.h"

Gezegen* gaz_devi_yarat(const char* isim, int saat_gun, Zaman tarih) {
    return gezegen_yarat(isim, GAZ_DEVI, saat_gun, tarih);
}
