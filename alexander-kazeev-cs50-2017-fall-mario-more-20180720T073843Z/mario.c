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
        for (int j = 0; j < (height * 2) + 2; j++)
        {
            //Пробелы
            if ((height - i - 1) > j || (j >= height && j < height + 2))
            {
                printf(" ");
            }
            //Решетки
            else if (j <= height + i + 2)
            {
                printf("#");
            }
        }
        printf("\n");
    }
}