#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
Vigenere cipher algorithm: C[i] = ( P[i] + K[i mod klength] ) mod N
C = output
P = Plaintext
K = key
N = number of letters in alphabet
*/
void vigenere(char *key, char *plain, char *cipher)
{
    int len = strlen(key);
    int ciphervalue;
    int i;
    char c;
    for (i = 0; plain[i]; i++) {
        c = plain[i];
        if (c >= 'a' && c <= 'z')
            c = 'A' + c - 'a';

        if (c >= 'A' && c <= 'Z')
        {
            // ASCII characters start at 65
            ciphervalue = ( (int)plain[i]-65 + (int)key[i%len]-65) % 26 +65;
            cipher[i] = (char) ciphervalue;
        }

        else
            cipher[i] = c;
    }
    cipher[i] = 0;
}
int main(int argc, char **argv)
{
    char *key;
    char *plain;
    char *cipher;
    int n;
    if (argc != 3) {
        printf("Usage: %s KEY PLAINTEXT\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    key = argv[1];
    plain = argv[2];
    n = strlen(plain);
    cipher = malloc(n + 1);
    vigenere(key, plain, cipher);
    puts(cipher);
    exit(EXIT_SUCCESS);
}

