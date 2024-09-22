#ifndef ALGORITHMD_H
#define ALGORITHMD_H

// Funzione principale di decompressione
void decompression(char *L, int original_index, int lunghezza);

// Funzioni modulari
void create_F(char *L, char *F, int lunghezza);
void create_T(char *L, char *F, int *T, int lunghezza);
void reconstruct_original(char *L, int *T, int original_index, int lunghezza);

#endif
