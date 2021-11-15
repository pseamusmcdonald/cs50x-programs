#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

/* Functions */

string encrypt (string plain, string key);
bool val (string cipher);

int main (int argc, string cipherkey[]) {
    if (val(cipherkey[1]) == true) {
        string message = get_string("Plaintext: ");
        printf("Ciphertext: %s\n", encrypt(message, cipherkey[1]));
    }
    else {
        printf("INVALID KEY\n");
    }
}

string encrypt (string plain, string key) {
    char * encrypted;
    encrypted = malloc(strlen(plain) * sizeof(char));
    int relate[26];
    
/* Relate Key */

    for (int i = 0; i < 26; i++) {
        if ((key[i] >= 'a') && (key[i] <= 'z')) {
            relate[i] = (key[i] - ('a' + i));
        }
        else if ((key[i] >= 'A') && (key[i] <= 'Z')) {
            relate[i] = (key[i] - ('A' + i));
        }
    }
        
/*Encrypt*/
        
        for (int n = 0; n < strlen(plain); n++) {
            if ((plain[n] >= 'a') && (plain[n] <= 'z')) {
                int k = 0;
                while (plain[n] != (k + 'a' - 1)) {
                    encrypted[n] = (plain[n] + relate[k]);
                    k++;
                }
            }
            else if ((plain[n] >= 'A') && (plain[n] <= 'Z')) {
                int k = 0;
                while (plain[n] != (k + 'A' - 1)) {
                    encrypted[n] = (plain[n] + relate[k]);
                    k++;
                }
            }
            else encrypted[n] = plain[n];
        }
    return encrypted;
}

bool val (string cipher) {
    bool val;
    if (strlen(cipher) != 26) {
        val = false;
        return val;
    }
    for (int i = 0; i < strlen(cipher); i++) {
        if (((cipher[i] >= 'a') && (cipher[i] <= 'z')) || ((cipher[i] >= 'A') && (cipher[i] <= 'Z'))) val = true;
        else {
            val = false;
            break;
        }
    }
    return val;
}