// === File: include/modeller/UzayGemisi.h ===
#ifndef UZAYGEMISI_H
#define UZAYGEMISI_H

#include "modeller/Gezegen.h"
#include "modeller/Zaman.h"
#include "modeller/Kisi.h"

typedef struct UzayAraci {
    char* isim;
    Gezegen* cikis;
    Gezegen* varis;
    Zaman cikis_tarihi;
    Zaman varis_tarihi;
    double mesafe_saat;
    double kalan_sure;
    Kisi** yolcular;
    int yolcu_say;
    int kapasite;
    int yolda;
    int imha;
} UzayAraci;

UzayAraci* arac_yarat(const char* isim, Gezegen* c, Gezegen* v, Zaman ct, double mesafe);
void arac_yok_et(UzayAraci* a);
void arac_guncelle(UzayAraci* a);
void arac_yolcu_ekle(UzayAraci* a, Kisi* k);

#endif // UZAYGEMISI_H

