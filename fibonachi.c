#include <stdio.h>
int main(){
    long long int x = 0, y1 = 1;
    int counter = 0;
    printf("Cuantos terminos de la serie quiere ver? ");
    scanf("%d", &counter);

    if (counter > 93) {
        counter = 93;
    }

    if (counter < 1) {
        counter = 0;
    }

    switch (counter) {
        case 0:
            return;
        case 1:
            printf("\n%lld", x);
            return 0;
            break;
        case 2:
            printf("\n%lld", x);
            printf(", %lld", y1);
            return 0;
            break;
        default:
            printf("\n%lld", x);
            printf(", %lld", y1);
            while (counter > 2) {
                y1 = x + y1;
                x = y1 - x;
                printf(", %lld", y1);
                counter --;
            }
            return y1;
    }
}
