#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Запрашиваем положительное целое число до 23 включительно
    float amount = -3;
    do
    {
        printf("Change owed: ");
        amount = get_float();
    }
    while (amount < 0);

    //Приводим к целому числу
    amount = roundf(amount * 100);

    //Определяем количество монет
    int coinsCount = 0;
    int coinsValues[] = {25, 10, 5, 1};
    for (int i = 0, n = sizeof(coinsValues) / sizeof(coinsValues[0]); i < n; i++)
    {
        int d = amount / coinsValues[i];
        if (d > 0)
        {
            amount -= coinsValues[i] * d;
            coinsCount += d;
        }
    }

    //Выводим результат
    printf("%i\n", coinsCount);
}