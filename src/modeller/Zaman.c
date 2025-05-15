// === File: src/modeller/Zaman.c ===
#include "modeller/Zaman.h"
#include <stdio.h>
#include <stdlib.h>

static int ay_gun_sayisi(int ay, int yil) {
    switch (ay) {
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: return 28;
        default: return 30;
    }
}

int zaman_karsilastir(const Zaman* z1, const Zaman* z2) {
    if (z1->yil != z2->yil) return z1->yil - z2->yil;
    if (z1->ay != z2->ay) return z1->ay - z2->ay;
    if (z1->gun != z2->gun) return z1->gun - z2->gun;
    return z1->saat - z2->saat;
}

void zaman_arttir(Zaman* z, int saat_gun) {
    z->saat++;
    if (z->saat >= saat_gun) {
        z->saat = 0;
        z->gun++;
        if (z->gun > ay_gun_sayisi(z->ay, z->yil)) {
            z->gun = 1;
            z->ay++;
            if (z->ay > 12) {
                z->ay = 1;
                z->yil++;
            }
        }
    }
}

char* zaman_to_string(const Zaman* z) {
    char* buf = malloc(20);
    snprintf(buf, 20, "%02d.%02d.%04d %02d:00", z->gun, z->ay, z->yil, z->saat);
    return buf;
}