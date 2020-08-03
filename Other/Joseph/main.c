#include <stdio.h>

int joseph(int index) {

    int ret = 1;

    for(;;) {
        int wrong = 0;
        long long sum = 0;

        int i;
        for (i = 0; i < index; i++) {
            sum += ret - 1;
            sum %= (2 * index - i);
            if (sum < index) wrong = 1;
        }

        if (wrong) {
            ret++;
        } else {
            return ret;
        }
    }
}

int main() {
    int tomb[15];

/*
    int i;
    for (i = 1; i < 15; i++) {
        printf("tomb[%d] = %d;\n", i, joseph(i));
    }
*/

    tomb[1] = 2;
    tomb[2] = 7;
    tomb[3] = 5;
    tomb[4] = 30;
    tomb[5] = 169;
    tomb[6] = 441;
    tomb[7] = 1872;
    tomb[8] = 7632;
    tomb[9] = 1740;
    tomb[10] = 93313;
    tomb[11] = 459901;
    tomb[12] = 1358657;
    tomb[13] = 2504881;
    tomb[14] = 13482720;

    int n;
    while(scanf("%d", &n) == 1 && n != 0) {
        printf("%d\n", tomb[n]);
    }

    return 0;
}