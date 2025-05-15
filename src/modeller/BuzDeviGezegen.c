#include "modeller/BuzDeviGezegen.h"
#include "modeller/Gezegen.h"

Gezegen* buz_devi_yarat(const char* isim, int saat_gun, Zaman tarih) {
    return gezegen_yarat(isim, BUZ_DEVI, saat_gun, tarih);
}
