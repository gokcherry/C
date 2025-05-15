// === File: src/Main.c ===
#include <stdio.h>
#include "simulasyon/Simulasyon.h"
#include "araclar/DosyaOkuma.h"

int main(void) {
    Veri* v = veri_oku("data/Kisiler.txt", "data/Araclar.txt", "data/Gezegenler.txt");
    Simulasyon* s = simulasyon_yarat(v);
    simulasyon_calistir(s);
    simulasyon_yok_et(s);
    veri_yok_et(v);
    return 0;
}
