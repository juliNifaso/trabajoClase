#include <stdio.h>

/* print Farenheit-Celcius table
    for fahr = 0, 20, ..., 300 */

fahrToCelFor()
{
    int fahr;

    printf("Farenheit-Celcius table\n\n");
    printf("Farenheit Celcius\n\n");

    for (fahr = 300; fahr >= 0; fahr -= 20)
        printf("%6d %9.1f\n", fahr, (5.0/9.0)*(fahr-32));
}

