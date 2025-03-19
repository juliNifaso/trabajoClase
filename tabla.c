#include <stdio.h>
int main() {
    int num = 0, x, count=10;
    for (num=1; num<=count; num++) {
        for (x=1; x<count; x++) {
            printf("%d x %d  = %d\n",num,x,num * x);
        }
        printf("%d x %d = %d\n\n",num,x,num * x);
    }
    return 0;
}
