#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
//the typing game makes you type words 5-12 characters in length, letters only
//next up: try to add more customizable parameters
//next up: add a scoring system

#define MIN_WORD_LEN 5
#define MAX_WORD_LEN 12

int getRandomWordLen() {
    struct timeval tm;
    mingw_gettimeofday(&tm, NULL);
    srand(tm.tv_sec + tm.tv_usec * 1000000ul);
    return rand() % (MAX_WORD_LEN - MIN_WORD_LEN + 1) + MIN_WORD_LEN;
}

void getRandomWord(char* word) {
    int n = getRandomWordLen();
    for (int i = 0; i < n; i++) {
        char c = rand() % ('z' - 'a' + 1) + 'a';
        word[i] = c;
    }
    word[n]='\0';
}

int main() {
    printf("Time to play a typing game! Press Enter to play!\n");
    getchar();

    while (1) {
        char word[13];
        getRandomWord(word);

        printf("%s\n", word);
        char buf[13];
        scanf("%12s", buf);

        if (strcmp(word, buf) == 0) {
            printf("Correct!\n");
        } else {
            printf("Wrong!\n");
        }

        getchar();
    }

    return 0;
}
