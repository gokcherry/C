#include "modeller/CuceGezegen.h"
#include "modeller/Gezegen.h"

Gezegen* cuce_yarat(const char* isim, int saat_gun, Zaman tarih) {
    return gezegen_yarat(isim, CUCE, saat_gun, tarih);
}
