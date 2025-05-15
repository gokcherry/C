// === File: include/modeller/Gezegen.h ===
#ifndef GEZEGEN_H
#define GEZEGEN_H

#include "modeller/Zaman.h"

enum { KAYAC, GAZ_DEVI, BUZ_DEVI, CUCE } GezegenTur;

typedef struct {
    char* isim;
    int tur;
    int saat_gun;
    Zaman tarih;
    int nufus;
    double yaslanma_katsayisi;
} Gezegen;

Gezegen* gezegen_yarat(const char* isim, int tur, int saat_gun, Zaman tarih);
void gezegen_yok_et(Gezegen* g);

#endif // GEZEGEN_H