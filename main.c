#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algorithmC.h"

int main() {
    char stringa[100];

    printf("Inserisci una stringa: ");
    scanf("%s", stringa);

    int lunghezza = strlen(stringa);

    // Crea una matrice di stringhe NxN
    char **matrice = (char **)malloc(lunghezza * sizeof(char *));
    for (int i = 0; i < lunghezza; i++) {
        matrice[i] = (char *)malloc((lunghezza + 1) * sizeof(char));  // +1 per '\0'
    }

    // Genera tutte le rotazioni della stringa
    generate_rotations(stringa, matrice, lunghezza);

    // Ordina la matrice in ordine lessicografico
    qsort(matrice, lunghezza, sizeof(char *), compare);

    // Trova l'indice della stringa originale dopo l'ordinamento
    int original_index = find_original_index(stringa, matrice, lunghezza);

    // Crea la stringa dell'ultima colonna 'L'
    char L[lunghezza + 1];  // +1 per il terminatore di stringa
    find_last_column(matrice, L, lunghezza);  // Trova l'ultima colonna

    // Stampa la tupla (L, I)
    printf("(%s, %d)\n", L, original_index);

    // Scrivi la matrice in un file esterno nella cartella "matrices"
    write_to_file(stringa, matrice, lunghezza);

    // Libera la memoria
    for (int i = 0; i < lunghezza; i++) {
        free(matrice[i]);
    }
    free(matrice);

    return 0;
}
