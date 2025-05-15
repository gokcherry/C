// === File: include/araclar/DosyaOkuma.h ===
#ifndef DOSYAOKUMA_H
#define DOSYAOKUMA_H

#include "modeller/Kisi.h"
#include "araclar/UzayGemisi.h"
#include "modeller/Gezegen.h"
#include "modeller/Zaman.h"

typedef struct {
    Kisi** kisiler; int kisi_say;
    UzayAraci** araclar; int arac_say;
    Gezegen** gezegenler; int gezegen_say;
} Veri;

Veri* veri_oku(const char* kisi_f, const char* arac_f, const char* gezegen_f);
void veri_yok_et(Veri* v);

#endif // DOSYAOKUMA_H