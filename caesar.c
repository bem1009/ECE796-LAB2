#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char caesar_char(int key, char c)
{
    /* Shift the given character by "key" digits */
    for( int i = 0; i < key; i++ )
    {
        c++;
        return c;
    }
}
void caesar(int key, char *plain, char *cipher)
{
    int i;
    char c;
    for (i = 0; plain[i]; i++) {
        c = plain[i];
        if (c >= 'a' && c <= 'z')
            c = 'A' + c - 'a';

        if (c >= 'A' && c <= 'Z')
            cipher[i] = caesar_char(key, c);
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
    caesar(key, plain, cipher);
    puts(cipher);
    exit(EXIT_SUCCESS);
}
