// === File: include/simulasyon/Simulasyon.h ===
#ifndef SIMULASYON_H
#define SIMULASYON_H

#include "araclar/DosyaOkuma.h"

typedef struct {
    Veri* veri;
} Simulasyon;

Simulasyon* simulasyon_yarat(Veri* v);
void simulasyon_calistir(Simulasyon* s);
void simulasyon_yok_et(Simulasyon* s);

#endif // SIMULASYON_H