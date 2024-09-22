#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algorithmC.h"

// Funzione di confronto per ordinare le stringhe in ordine lessicografico
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Funzione per generare tutte le rotazioni di una stringa
void generate_rotations(char *stringa, char **matrice, int lunghezza) {
    for (int i = 0; i < lunghezza; i++) {
        for (int j = 0; j < lunghezza; j++) {
            // Genera la rotazione ciclata
            matrice[i][j] = stringa[(i + j) % lunghezza];
        }
        matrice[i][lunghezza] = '\0'; // Aggiungi il terminatore di stringa
    }
}

// Funzione per scrivere la matrice in un file nella cartella matrices
void write_to_file(char *stringa, char **matrice, int lunghezza) {
    // Creare il nome del file con estensione ".txt"
    char filename[105];
    snprintf(filename, sizeof(filename), "matrices/%s.txt", stringa);

    // Aprire il file in modalità scrittura
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Errore nell'apertura del file %s!\n", filename);
        return;
    }

    // Scrivere la matrice nel file
    for (int i = 0; i < lunghezza; i++) {
        fprintf(file, "%s\n", matrice[i]);
    }

    // Chiudere il file
    fclose(file);

    printf("Matrice scritta con successo nel file: %s\n", filename);
}

// Funzione per trovare l'indice della stringa originale dopo l'ordinamento
int find_original_index(char *stringa, char **matrice, int lunghezza) {
    for (int i = 0; i < lunghezza; i++) {
        if (strcmp(stringa, matrice[i]) == 0) {
            return i;  // Indice trovato
        }
    }
    return -1;  // Errore, non dovrebbe accadere
}

// Funzione per trovare l'ultima colonna della matrice (L)
void find_last_column(char **matrice, char *L, int lunghezza) {
    for (int i = 0; i < lunghezza; i++) {
        L[i] = matrice[i][lunghezza - 1];  // Prende l'ultimo carattere di ogni riga
    }
    L[lunghezza] = '\0';  // Terminatore di stringa
}
