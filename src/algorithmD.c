#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algorithmD.h"

// Funzione di confronto per ordinare i caratteri in ordine lessicografico
int compare_char(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

// Funzione per creare la colonna F ordinata da L
void create_F(char *L, char *F, int lunghezza) {
    strcpy(F, L);  // Copia L in F
    qsort(F, lunghezza, sizeof(char), compare_char);  // Ordina F
}

// Funzione per creare il vettore di corrispondenza T
void create_T(char *L, char *F, int *T, int lunghezza) {
    int countL[256] = {0};  // Frequenza dei caratteri in L
    int countF[256] = {0};  // Frequenza dei caratteri in F
    int positionL[256] = {0}; // Posizioni di inizio per i caratteri in L
    int positionF[256] = {0}; // Posizioni di inizio per i caratteri in F

    // Conta le occorrenze dei caratteri in L e F
    for (int i = 0; i < lunghezza; i++) {
        countL[(unsigned char)L[i]]++;
        countF[(unsigned char)F[i]]++;
    }

    // Calcola le posizioni iniziali per i caratteri in L e F
    for (int i = 1; i < 256; i++) {
        positionL[i] = positionL[i - 1] + countL[i - 1];
        positionF[i] = positionF[i - 1] + countF[i - 1];
    }

    // Crea il vettore T
    for (int i = 0; i < lunghezza; i++) {
        // Trova l'indice della prossima occorrenza di L[i] in F
        int ch = (unsigned char)L[i];
        T[positionF[ch]] = i;
        positionF[ch]++;
    }

    // Debug: stampa il vettore T
    printf("Vettore T: ");
    for (int i = 0; i < lunghezza; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");
}

// Funzione per ricostruire la stringa originale
void reconstruct_original(char *L, int *T, int original_index, int lunghezza) {
    char *originale = (char *)malloc((lunghezza + 1) * sizeof(char));
    int current_pos = original_index;

    // Debug: iniziamo la decompressione
    printf("Inizio ricostruzione dalla posizione %d\n", original_index);

    // Ricostruisce la stringa partendo da T
    for (int i = 0; i < lunghezza; i++) {  // Correzione: da 0 a lunghezza
        originale[i] = L[current_pos];  // Aggiungiamo il carattere corrente
        current_pos = T[current_pos];  // Vai alla prossima posizione con T

        // Debug: stampa il carattere e la nuova posizione
        printf("Posizione attuale: %d, Carattere: %c\n", current_pos, originale[i]);
    }
    originale[lunghezza] = '\0';  // Terminatore di stringa

    // Stampa la stringa originale ricostruita
    printf("Stringa originale ricostruita: %s\n", originale);

    free(originale);
}

// Funzione principale che esegue Algorithm D
void decompression(char *L, int original_index, int lunghezza) {
    // Step 1: Crea la colonna F ordinando L
    char *F = (char *)malloc((lunghezza + 1) * sizeof(char));
    create_F(L, F, lunghezza);

    // Debug: stampa F
    printf("Colonna F (ordinata): %s\n", F);

    // Step 2: Crea il vettore T
    int *T = (int *)malloc(lunghezza * sizeof(int));
    create_T(L, F, T, lunghezza);

    // Step 3: Ricostruisci la stringa originale usando T
    reconstruct_original(L, T, original_index, lunghezza);

    // Libera la memoria
    free(F);
    free(T);
}
