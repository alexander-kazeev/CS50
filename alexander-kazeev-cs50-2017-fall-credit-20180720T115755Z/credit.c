#include <stdio.h>
#include <cs50.h>
#include <math.h>

void errFunction(void); //Прототип функции errFunction

int main(void)
{
    //Запрашиваем номер карты
    long cardNumber = 0;
    do
    {
        printf("Number: ");
        cardNumber = get_long_long();
    }
    while (cardNumber <= 0);

    //Определяем количество знаков
    int digitCount = 0;
    int digitArray[20];
    {
        long tempCardNumber = cardNumber;
        while (tempCardNumber != 0)
        {
            digitArray[digitCount] = tempCardNumber % 10;
            tempCardNumber = tempCardNumber / 10;
            digitCount++;
        }
    }

    //Проверяем количество знаков
    if (digitCount != 13 && digitCount != 15 && digitCount != 16)
    {
        //printf("Неверное количество знаков %d\n", digitCount);
        errFunction();
        return 0;
    }

    //Считаем контрольную сумму
    int even = digitCount % 2;
    int crc = 0;
    for (int i = digitCount - 1; i >= 0; i--)
    {
        //Четное число цифр - умножаем нечетные позиции, нечетное цисло цифр - умножаем четные позиции. Берем остаток от деления на 9.
        if ((even = 0 && (i + 1) % 2 != 0) || (even = 1 && (i + 1) % 2 == 0))
        {
            if (digitArray[i] * 2 > 9)
            {
                crc += (digitArray[i] * 2) - 9;
            }
            else
            {
                crc += digitArray[i] * 2;
            }
        }
        //Складываем как есть
        else
        {
            crc += digitArray[i];
        }
    }

    //Проверяем контрольную сумму
    //printf("Контрольная сумма %i\n", crc);
    if (crc % 10 != 0)
    {
        errFunction();
        return 0;
    }

    //Определяем эквайра
    //Visa
    if (digitArray[digitCount - 1] == 4)
    {
        printf("VISA\n");
    }
    //AMEX
    else if (digitArray[digitCount - 1] == 3 && (digitArray[digitCount - 2] == 4 || digitArray[digitCount - 2] == 7))
    {
        printf("AMEX\n");
    }
    else if (digitArray[digitCount - 1] == 5 && (digitArray[digitCount - 2] >= 1 && digitArray[digitCount - 2] <= 5))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        errFunction();
    }
}

//Сообщение об ошибке
void errFunction(void)
{
    printf("INVALID\n");
}
