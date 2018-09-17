#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Запрашиваем положительное целое число до 23 включительно
    int height = -3;
    do
    {
        printf("Введите целое положительное число до 23: ");
        height = get_int();
    }
    while (height < 0 || height > 23);

    //Рисуем пирамиду
    for (int i = 0; i < height; i++)
    {
        //Вставляем символы
        for (int j = 0; j <= height; j++)
        {
            //Пробелы
            if ((height - i - 1) > j)
            {
                printf(" ");
            }
            //Решетки
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}