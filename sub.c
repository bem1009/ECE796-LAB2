#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Algorithm to encrypt strings using "Simple-letter substitution cipher
How it works: Maps string to new "alphabet"

EXAMPLE:
Reference alphabet: "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
Encrpyted (key) alphabet: "DUPLICATEWORMSBFGHJKNQVXYZ"

so for any string you pass in each char is mapped to new alphabet
A = D
B = U
C = P
D = L

etc...

*/



void sub(int key, char *plain, char *cipher)
{
    int i;
    char c;
    for (i = 0; plain[i]; i++) {
        c = plain[i];
        if (c >= 'a' && c <= 'z')
            c = 'A' + c - 'a';

        if (c >= 'A' && c <= 'Z')
            // do cipher logic here
            cipher[i] = c;
            //cipher[i] = caesar_char(key, c);
        else
            cipher[i] = c;
    }
    cipher[i] = 0;
}
int main(int argc, char **argv)
{
    int key;
    char *plain;
    char *cipher;
    int n;
    if (argc != 3) {
        printf("Usage: %s KEY PLAINTEXT\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    key = atoi(argv[1]);
    /* Verify the key is a valid number */
    plain = argv[2];
    n = strlen(plain);
    cipher = malloc(n + 1);
    sub(key, plain, cipher);
    puts(cipher);
    exit(EXIT_SUCCESS);
}

