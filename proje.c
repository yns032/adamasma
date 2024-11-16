#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void displayProgress(char word[], char guessed[]);
int checkWin(char word[], char guessed[]);

int main() {
    char word[] = "PROGRAM"; // Gizli kelime
    char guessed[strlen(word) + 1]; 
    int attempts = 6; // Başlangıç deneme hakkı
    char letter;
    int i;

    // guessed dizisini başlat
    for (i = 0; i < strlen(word); i++) {
        guessed[i] = '_';
    }
    guessed[i] = '\0';

    printf("Adam Asmaca Oyununa Hoşgeldiniz!\n");

    while (attempts > 0) {
        displayProgress(word, guessed);
        printf("Bir harf tahmin edin: ");
        scanf(" %c", &letter);
        letter = toupper(letter); // Harfi büyük yap

        // Doğru tahmin kontrolü
        int correctGuess = 0;
        for (i = 0; i < strlen(word); i++) {
            if (word[i] == letter) {
                guessed[i] = letter;
                correctGuess = 1;
            }
        }

        // Yanlış tahmin için deneme hakkını azalt
        if (!correctGuess) {
            attempts--;
            printf("Yanlış tahmin! Kalan deneme hakkı: %d\n", attempts);
        }

        // Kazanma durumu kontrolü
        if (checkWin(word, guessed)) {
            printf("Tebrikler! Kelimeyi doğru tahmin ettiniz: %s\n", word);
            break;
        }
    }

    if (attempts == 0) {
        printf("Üzgünüm, kaybettiniz! Kelime: %s\n", word);
    }

    return 0;
}

// Kelimenin mevcut durumunu göster
void displayProgress(char word[], char guessed[]) {
    printf("Kelime: ");
    for (int i = 0; i < strlen(word); i++) {
        printf("%c ", guessed[i]);
    }
    printf("\n");
}

// Oyuncunun kazandığını kontrol et
int checkWin(char word[], char guessed[]) {
    return strcmp(word, guessed) == 0;
}
