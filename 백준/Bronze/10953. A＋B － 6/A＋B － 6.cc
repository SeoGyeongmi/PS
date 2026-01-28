#include <stdio.h>


int main() {

	int a, b;
    char commma;

    int n;
    scanf("%d", &n);
	while (n--) {
        scanf("%d,%d", &a,&b);
		printf("%d \n", a + b);
	}

	return 0;
}