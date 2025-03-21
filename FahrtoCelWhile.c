#include <stdio.h>

/* print Farenheit-Celcius table
    for fahr = 0, 20, ..., 300 */

fahrToCelWhile()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;          /* lower limit of temperature table */
    upper = 300;        /* upper limit*/
    step = 20;          /* step size*/

    printf("Farenheit-Celcius table\n\n");
    printf("Farenheit Celcius\n\n");

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%6.0f %9.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
