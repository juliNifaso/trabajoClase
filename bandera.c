#include <stdio.h>
int main() {
    int x = 1;
    float foo = 0, bar = 0, num = 0;
    printf("dime un numero: ");
    scanf("%f", &num);

    while (x <= num) {
        if (x%2!=0) {
            foo = (float) 1/x;
            printf("1/%d - ",x);
            x++;
            bar += foo;
        } else {
            foo = (float) 1/x;
            printf("1/%d + ",x);
            x++;
            bar -= foo;
        }
    }
    printf("\b\b= %f", bar);
    return 0;
}
