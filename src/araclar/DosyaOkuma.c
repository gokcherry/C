// === File: src/araclar/DosyaOkuma.c ===
#define _GNU_SOURCE
#include "araclar/DosyaOkuma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* satir_oku(FILE* f) {
    char* ln = NULL; size_t sz = 0;
    if (getline(&ln, &sz, f) == -1) { free(ln); return NULL; }
    ln[strcspn(ln, "\r\n")] = 0;
    return ln;
}

Veri* veri_oku(const char* kisi_f, const char* arac_f, const char* gezegen_f) {
    Veri* v = calloc(1, sizeof(Veri));
    char* ln;
    FILE* fp;

    // Gezegenler
    fp = fopen(gezegen_f, "r");
    while ((ln = satir_oku(fp))) {
        char* t = strtok(ln, "#"); char* isim = t;
        t = strtok(NULL, "#"); int tur = atoi(t);
        t = strtok(NULL, "#"); int sg = atoi(t);
        t = strtok(NULL, "#"); Zaman z = {0}; sscanf(t, "%d.%d.%d", &z.gun, &z.ay, &z.yil); z.saat = 0;
        Gezegen* g = NULL;
        switch (tur) {
            case KAYAC:    g = kayac_gec_yarat(isim, sg, z); break;
            case GAZ_DEVI: g = gaz_devi_yarat(isim, sg, z); break;
            case BUZ_DEVI: g = buz_devi_yarat(isim, sg, z); break;
            case CUCE:     g = cuce_yarat(isim, sg, z); break;
        }
        v->gezegenler = realloc(v->gezegenler, sizeof(Gezegen*) * (v->gezegen_say + 1));
        v->gezegenler[v->gezegen_say++] = g;
        free(ln);
    }
    fclose(fp);

    // Uzay Araclari
    fp = fopen(arac_f, "r");
    while ((ln = satir_oku(fp))) {
        char* t = strtok(ln, "#"); char* isim = t;
        t = strtok(NULL, "#"); char* co = t;
        t = strtok(NULL, "#"); char* va = t;
        t = strtok(NULL, "#"); Zaman z = {0}; sscanf(t, "%d.%d.%d", &z.gun, &z.ay, &z.yil); z.saat = 0;
        t = strtok(NULL, "#"); double ms = atof(t);
        Gezegen *c = NULL, *d = NULL;
        for (int i = 0; i < v->gezegen_say; i++) {
            if (!c && strcmp(v->gezegenler[i]->isim, co) == 0) c = v->gezegenler[i];
            if (!d && strcmp(v->gezegenler[i]->isim, va) == 0) d = v->gezegenler[i];
        }
        UzayAraci* a = arac_yarat(isim, c, d, z, ms);
        v->araclar = realloc(v->araclar, sizeof(UzayAraci*) * (v->arac_say + 1));
        v->araclar[v->arac_say++] = a;
        free(ln);
    }
    fclose(fp);

    // Kisiler
    fp = fopen(kisi_f, "r");
    while ((ln = satir_oku(fp))) {
        char* t = strtok(ln, "#"); char* isim = t;
        t = strtok(NULL, "#"); int yas = atoi(t);
        t = strtok(NULL, "#"); double omur = atof(t);
        t = strtok(NULL, "#"); char* ad = t;
        UzayAraci* a = NULL;
        for (int i = 0; i < v->arac_say; i++)
            if (strcmp(v->araclar[i]->isim, ad) == 0) a = v->araclar[i];
        Kisi* k = kisi_yarat(isim, yas, omur, a);
        arac_yolcu_ekle(a, k);
        v->kisiler = realloc(v->kisiler, sizeof(Kisi*) * (v->kisi_say + 1));
        v->kisiler[v->kisi_say++] = k;
        free(ln);
    }
    fclose(fp);
    return v;
}

void veri_yok_et(Veri* v) {
    for (int i = 0; i < v->kisi_say; i++) kisi_yok_et(v->kisiler[i]);
    for (int i = 0; i < v->arac_say; i++) arac_yok_et(v->araclar[i]);
    for (int i = 0; i < v->gezegen_say; i++) gezegen_yok_et(v->gezegenler[i]);
    free(v->kisiler);
    free(v->araclar);
    free(v->gezegenler);
    free(v);
}

