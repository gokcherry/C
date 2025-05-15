#include "modeller/Kisi.h"
#include <stdlib.h>
#include <string.h>

Kisi* kisi_yarat(const char* isim, int yas, double kalan_omur, UzayAraci* arac) {
    Kisi* k = malloc(sizeof(Kisi));
    k->isim = strdup(isim);
    k->yas = yas;
    k->kalan_omur = kalan_omur;
    k->arac = arac;
    k->yasiyor = 1;
    return k;
}

void kisi_yaslandir(Kisi* k, double faktor) {
    k->kalan_omur -= faktor;
    if (k->kalan_omur <= 0) {
        k->kalan_omur = 0;
        k->yasiyor = 0;
    }
}

void kisi_yok_et(Kisi* k) {
    free(k->isim);
    free(k);
}
