#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char words[20000][51];

int cmp(const void *a, const void *b) {
    char *s1 = (char *)a;
    char *s2 = (char *)b;

    int l1 = strlen(s1);
    int l2 = strlen(s2);

    if (l1 != l2) return l1 - l2;
    return strcmp(s1, s2);
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", words[i]);
    }

    qsort(words, N, sizeof(words[0]), cmp);

    printf("%s\n", words[0]);
    for (int i = 1; i < N; i++) {
        if (strcmp(words[i], words[i - 1]) != 0) {
            printf("%s\n", words[i]);
        }
    }

    return 0;
}
