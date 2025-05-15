#include "araclar/UzayGemisi.h"
#include <stdlib.h>
#include <string.h>

UzayAraci* arac_yarat(const char* isim, Gezegen* c, Gezegen* v, Zaman ct, double mesafe) {
    UzayAraci* a = malloc(sizeof(UzayAraci));
    a->isim = strdup(isim);
    a->cikis = c;
    a->varis = v;
    a->cikis_tarihi = ct;
    a->mesafe_saat = mesafe;
    a->kalan_sure = mesafe;
    a->yolcular = NULL;
    a->yolcu_say = 0;
    a->kapasite = 100;  // İstediğiniz gibi ayarlayabilirsiniz
    a->yolda = 0;
    a->imha = 0;
    return a;
}

void arac_yolcu_ekle(UzayAraci* a, Kisi* k) {
    a->yolcular = realloc(a->yolcular, sizeof(Kisi*) * (a->yolcu_say + 1));
    a->yolcular[a->yolcu_say++] = k;
}

void arac_guncelle(UzayAraci* a) {
    if (a->imha) return;
    if (a->yolda) {
        a->kalan_sure -= 1.0;
        if (a->kalan_sure <= 0) {
            a->kalan_sure = 0;
            a->yolda = 0;
            // Varış anındaki tarihe kaydet
            a->varis_tarihi = a->varis->tarih;
            // Varış gezegenine nüfus ekle
            a->varis->nufus += a->yolcu_say;
        }
    }
}

void arac_yok_et(UzayAraci* a) {
    free(a->isim);
    free(a->yolcular);
    free(a);
}
