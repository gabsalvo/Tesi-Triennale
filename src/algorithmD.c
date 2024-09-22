#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare characters for qsort
int compare_char(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

// Function to create the first column F by sorting L
void create_F(char *L, char *F, int length) {
    strcpy(F, L);  // Copy L into F
    qsort(F, length, sizeof(char), compare_char);  // Sort F
}

// Function to create the mapping vector T
void create_T(char *L, char *F, int *T, int length) {
    int countF[256] = {0};          // Counts of characters in F
    int firstOccurrence[256];       // First occurrence of characters in F

    // Count the occurrences of characters in F
    for (int i = 0; i < length; i++) {
        countF[(unsigned char)F[i]]++;
    }

    // Compute the first occurrence of each character in F
    int sum = 0;
    for (int c = 0; c < 256; c++) {
        if (countF[c] > 0) {
            firstOccurrence[c] = sum;
            sum += countF[c];
        } else {
            firstOccurrence[c] = -1;  // Character not present
        }
    }

    // Initialize count of occurrences in L
    int countL[256] = {0};

    // Create the T vector
    for (int i = 0; i < length; i++) {
        int ch = (unsigned char)L[i];
        int k = countL[ch];  // Number of times ch has occurred in L so far
        T[i] = firstOccurrence[ch] + k;
        countL[ch]++;
    }

    // Debug: print the T vector
    printf("Vettore T: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");
}

// Funzione per ricostruire la stringa originale
void reconstruct_original(char *L, int *T, int original_index, int length) {
    char *original = (char *)malloc((length + 1) * sizeof(char));
    int current_pos = original_index;

    // Ricostruisce la stringa partendo da T in ordine inverso
    for (int i = length - 1; i >= 0; i--) {
        original[i] = L[current_pos];
        current_pos = T[current_pos];
    }
    original[length] = '\0';  // Terminatore di stringa

    // Stampa la stringa originale ricostruita
    printf("Stringa originale ricostruita: %s\n", original);

    free(original);
}


// Main function that executes Algorithm D
void decompression(char *L, int original_index, int length) {
    // Step 1: Create the first column F by sorting L
    char *F = (char *)malloc((length + 1) * sizeof(char));
    create_F(L, F, length);

    // Debug: print F
    printf("Colonna F (ordinata): %s\n", F);

    // Step 2: Create the T vector
    int *T = (int *)malloc(length * sizeof(int));
    create_T(L, F, T, length);

    // Step 3: Reconstruct the original string using T
    reconstruct_original(L, T, original_index, length);

    // Free allocated memory
    free(F);
    free(T);
}
