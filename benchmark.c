#include <stdio.h>

#define SIZE 50000
#define EXPECTED_CHECKSUM 41667916675000ULL

// Statical allocation of arrays
int A[SIZE];
int B[SIZE];
unsigned long long C[SIZE]; // Use unsigned long long to prevent overflow

int main() {
    // Step 1: Initialize arrays
    // A[i] = i
    // B[i] = 50000 - i
    // C[i] = 0
    for (int i = 0; i < SIZE; i++) {
        A[i] = i;
        B[i] = SIZE - i;
        C[i] = 0ULL;
    }
    C[0] = B[0];


    // Step 2: For each element in C, sum all elements in B up to and including i
    for (int i = 1; i < SIZE; i++) {
        C[i] = C[i-1] + (unsigned long long)B[i];
    }

    // Step 3: Compute checksum by summing all elements in C
    unsigned long long checksum = 0ULL;
    for (int i = 0; i < SIZE; i++) {
        checksum += C[i];
    }

    // Step 4: Output the checksum
    printf("Checksum: %llu\n", checksum);

    // Step 5: Compare the checksum to the expected value
    if (checksum != EXPECTED_CHECKSUM) {
        fprintf(stderr, "Error: Checksum mismatch! Expected %llu but got %llu.\n",
                EXPECTED_CHECKSUM, checksum);
        return 1; // Non-zero return value indicates failure
    }

    return 0; // Success
}