#ifndef ALGORITHMC_H
#define ALGORITHMC_H

// Funzione di confronto per ordinare le stringhe in ordine lessicografico
int compare(const void *a, const void *b);

// Funzione per generare tutte le rotazioni di una stringa
void generate_rotations(char *stringa, char **matrice, int lunghezza);

// Funzione per scrivere la matrice in un file
void write_to_file(char *stringa, char **matrice, int lunghezza);

// Funzione per trovare l'indice della stringa originale dopo l'ordinamento
int find_original_index(char *stringa, char **matrice, int lunghezza);

// Funzione per trovare l'ultima colonna della matrice (L)
void find_last_column(char **matrice, char *L, int lunghezza);

#endif
