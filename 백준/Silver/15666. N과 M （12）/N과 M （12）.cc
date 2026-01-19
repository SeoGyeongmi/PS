#include <stdio.h>
#include <stdlib.h>

int N, M;
int a[8], arr[8];

void dfs(int depth, int start) {
    if (depth == M) {
        for (int i = 0; i < M; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }

    int last = -1;
    for (int i = start; i < N; i++) {
        if (a[i] == last) continue;
        arr[depth] = a[i];
        last = a[i];
        dfs(depth + 1, i);
    }
}

int cmp(const void *x, const void *y) {
    return *(int *)x - *(int *)y;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);

    qsort(a, N, sizeof(int), cmp);
    dfs(0, 0);
    return 0;
}
