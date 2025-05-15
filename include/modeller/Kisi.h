// === File: include/modeller/Kisi.h ===
#ifndef KISI_H
#define KISI_H

#include "araclar/UzayGemisi.h"

typedef struct {
    char* isim;
    int yas;
    double kalan_omur;
    UzayAraci* arac;
    int yasiyor;
} Kisi;

Kisi* kisi_yarat(const char* isim, int yas, double kalan_omur, UzayAraci* arac);
void kisi_yok_et(Kisi* k);
void kisi_yaslandir(Kisi* k, double faktor);

#endif // KISI_H