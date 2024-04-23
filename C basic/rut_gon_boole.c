#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TERMS 1024
#define MAX_BITS 10 // S? bit t?i da

typedef struct {
    int minterm;
    char term[MAX_BITS + 1]; // +1 d? ch?a ký t? null '\0'
    int combined;
} PrimeImplicant;

void decimalToBinary(int num, int numBits, char binary[]) {
    for (int i = numBits - 1; i >= 0; i--) {
        binary[i] = (num % 2) + '0';
        num /= 2;
    }
    binary[numBits] = '\0';
}

int countOnes(char *binary) {
    int count = 0;
    while (*binary != '\0') {
        if (*binary == '1') {
            count++;
        }
        binary++;
    }
    return count;
}

void combineTerms(char *term1, char *term2, char *combinedTerm) {
    int length = strlen(term1);
    for (int i = 0; i < length; i++) {
        if (term1[i] != term2[i]) {
            combinedTerm[i] = '-';
        } else {
            combinedTerm[i] = term1[i];
        }
    }
    combinedTerm[length] = '\0';
}

void findPrimeImplicants(int minterms[], int numMinterms, int numVariables, PrimeImplicant *primeImplicants, int *numPrimeImplicants) {
    char binary[MAX_TERMS][MAX_BITS + 1]; // +1 d? ch?a ký t? null '\0'

    for (int i = 0; i < numMinterms; i++) {
        decimalToBinary(minterms[i], MAX_BITS, binary[i]);
    }

    int groups[MAX_BITS + 1][MAX_TERMS];
    int groupSizes[MAX_BITS + 1] = {0};

    for (int i = 0; i < numMinterms; i++) {
        int onesCount = countOnes(binary[i]);
        groups[onesCount][groupSizes[onesCount]++] = minterms[i];
    }

    *numPrimeImplicants = 0;

    for (int i = 0; i < MAX_BITS; i++) {
        for (int j = 0; j < groupSizes[i]; j++) {
            for (int k = 0; k < groupSizes[i + 1]; k++) {
                char combinedTerm[MAX_BITS + 1];
                combineTerms(binary[i], binary[i + 1], combinedTerm);
                if (strcmp(binary[i], combinedTerm) == 0) {
                    primeImplicants[*numPrimeImplicants].minterm = groups[i][j];
                    strcpy(primeImplicants[*numPrimeImplicants].term, binary[i]);
                    primeImplicants[*numPrimeImplicants].combined = 0;
                    (*numPrimeImplicants)++;
                }
            }
        }
    }
}

void generateSimplifiedExpression(PrimeImplicant *primeImplicants, int numPrimeImplicants, int numVariables) {
    char variableNames[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char expression[MAX_TERMS * MAX_BITS + 1]; // +1 d? ch?a ký t? null '\0'
    int expressionLength = 0;

    for (int i = 0; i < numPrimeImplicants; i++) {
        if (!primeImplicants[i].combined) {
            if (expressionLength > 0) {
                expression[expressionLength++] = '+';
            }
            for (int j = 0; primeImplicants[i].term[j] != '\0'; j++) {
                if (primeImplicants[i].term[j] == '1') {
                    expression[expressionLength++] = variableNames[j];
                } else if (primeImplicants[i].term[j] == '0') {
                    expression[expressionLength++] = variableNames[j];
                    expression[expressionLength++] = '\'';
                }
            }
        }
    }

    expression[expressionLength] = '\0';
    printf("Simplified Expression: %s\n", expression);
}

int main() {
    int numMinterms;
    printf("Nhap so luong minterms: ");
    scanf("%d", &numMinterms);

    int minterms[MAX_TERMS];
    printf("Nhap cac minterms: ");
    for (int i = 0; i < numMinterms; i++) {
        scanf("%d", &minterms[i]);
    }

    int numVariables;
    printf("Nhap so luong bien: ");
    scanf("%d", &numVariables);

    PrimeImplicant primeImplicants[MAX_TERMS];
    int numPrimeImplicants;

    findPrimeImplicants(minterms, numMinterms, numVariables, primeImplicants, &numPrimeImplicants);

    printf("Prime Implicants: ");
    for (int i = 0; i < numPrimeImplicants; i++) {
        printf("(%d, %s) ", primeImplicants[i].minterm, primeImplicants[i].term);
    }
    printf("\n");

    generateSimplifiedExpression(primeImplicants, numPrimeImplicants, numVariables);

    return 0;
}

