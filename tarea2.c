#include <stdio.h>
#include <math.h>

int numeros[9];

void numeros10();
float promedioPositivo();
float promedioNegativo();
int factorial(n);
int potencias();
int fibonacci();
int serieE();
void fun();

int main(){
    int foo;
    printf("Que ejercicio quieres hacer:\n");
    printf("El de 10 numeros (1)\n");
    printf("El factorial (2)\n");
    printf("La primeras 10 potencias (3)\n");
    printf("La serie fibonacci (4)\n");
    printf("La serie E (5)\n");
    scanf("%d",&foo);

    switch (foo) {
    case 1:
        numeros10();
        break;
    case 2:
        fun();
        break;
    case 3:
        potencias();
        break;
    case 4:
        fibonacci();
        break;
    case 5:
        serieE();
        break;
    default:
        printf("No escogiste una opcion");
    }
}


void numeros10() {
    int i;
    for (i=0;i<10;i++) {
        printf("Dame el numero %d: ", i+1);
        scanf("%d", &numeros[i]);
    }
    printf("La suma de los numeros es: %d",suma());
    printf("\nEl promedio de los numeros positivos es: %f",promedioPositivo());
    printf("\nEl promedio de los numeros negativos es: %f",promedioNegativo());
}

int suma() {
    int sum = 0, i;

    for (i=0;i<10;i++) {
        sum += numeros[i];
    }
    return sum;
}

float promedioPositivo() {
    int sum = 0, i, r=0;
    for (i=0;i<10;i++) {
        if (numeros[i]>1) {
            sum += numeros[i];
            r++;
        }
    }
    float resulatado = (float) sum/r;
    return resulatado;
}

float promedioNegativo() {
    int sum = 0, i, r=0;
    for (i=0;i<10;i++) {
        if (numeros[i]<0) {
            sum += numeros[i];
            r++;
        }
    }
    float resulatado = (float) sum/r;
    return resulatado;
}

void fun() {
    int num;
    printf("dime un numero: ");
    scanf("%d", &num);
    printf("El factorial de %d es %d",num,factorial(num));
}

int factorial(n) {
    int sum = 1;
    while (n > 0) {
        sum *= n;
        n--;
    }
    return sum;

}

int potencias() {
    int i, q;
    printf("Dame un numero: ");
    scanf("%d", &q);
    for (i=1;i<10;i++) {
        printf("%d al poder de %d es:  %.2lf \n",q,i,pow(q,i));
    }
    printf("%d al poder de %d es: %.2lf \n",q,10,pow(q,10));

}

int fibonacci() {
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

int serieE() {
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
