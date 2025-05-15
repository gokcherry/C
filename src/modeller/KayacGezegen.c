#include "modeller/KayacGezegen.h"
#include "modeller/Gezegen.h"

Gezegen* kayac_gec_yarat(const char* isim, int saat_gun, Zaman tarih) {
    return gezegen_yarat(isim, KAYAC, saat_gun, tarih);
}
