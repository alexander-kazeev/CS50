#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    //Проверка входящего параметра
    if (argc != 2)
    {
        printf("Должен быть один и только один входной параметр\n");
        return 1;
    }

    //Получаем коэффициент смещения
    int k = atoi(argv[1]);

    //получаем текст для кодирования
    printf("plaintext: ");
    string before = get_string();

    //Кодируем
    printf("ciphertext: ");
    for (int i = 0, n = strlen(before); i < n; i++)
    {
        if (before[i] >= 65 && before[i] <= 90)
        {
            printf("%c", ((before[i] - 65 + k) % 26) + 65);
        }
        else if (before[i] >= 97 && before[i] <= 122)
        {
            printf("%c", ((before[i] - 97 + k) % 26) + 97);
        }
        else
        {
            printf("%c", before[i]);
        }
    }
    printf("\n");
}