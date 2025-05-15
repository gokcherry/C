// === File: include/modeller/Zaman.h ===
#ifndef ZAMAN_H
#define ZAMAN_H

typedef struct {
    int gun, ay, yil;
    int saat;
} Zaman;

int zaman_karsilastir(const Zaman* z1, const Zaman* z2);
void zaman_arttir(Zaman* z, int saat_gun);
char* zaman_to_string(const Zaman* z);

#endif // ZAMAN_H

