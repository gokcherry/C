#include "modeller/Gezegen.h"
#include <stdlib.h>
#include <string.h>

Gezegen* gezegen_yarat(const char* isim, int tur, int saat_gun, Zaman tarih) {
    Gezegen* g = malloc(sizeof(Gezegen));
    g->isim = strdup(isim);
    g->tur = tur;
    g->saat_gun = saat_gun;
    g->tarih = tarih;
    g->nufus = 0;
    switch (tur) {
        case KAYAC:    g->yaslanma_katsayisi = 1.0;  break;
        case GAZ_DEVI: g->yaslanma_katsayisi = 0.1;  break;
        case BUZ_DEVI: g->yaslanma_katsayisi = 0.5;  break;
        case CUCE:     g->yaslanma_katsayisi = 0.01; break;
        default:       g->yaslanma_katsayisi = 1.0;  break;
    }
    return g;
}

void gezegen_yok_et(Gezegen* g) {
    free(g->isim);
    free(g);
}
