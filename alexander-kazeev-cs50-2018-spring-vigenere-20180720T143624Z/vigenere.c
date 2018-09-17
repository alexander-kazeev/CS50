#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //Проверка входящего параметра
    if (argc != 2)
    {
        printf("Должен быть один и только один входной текстовый параметр\n");
        return 1;
    }

    //Получаем слово-коэффициент смещения
    string s = (argv[1]);
    int keyLength = strlen(s);
    int key[keyLength];
    printf("Кодовое слово до: %s\n", s);
    for (int i = 0; i < keyLength; i++)
    {
        //Проверяем на текст
        if (s[i] >= 65 && s[i] <= 90)
        {
            key[i] = s[i] - 65;
        }
        else if (s[i] >= 97 && s[i] <= 122)
        {
            key[i] = s[i] - 97;
        }
        else
        {
            printf("Должен быть один и только один входной текстовый параметр\n");
            return 1;
        }
    }

    //получаем текст для кодирования
    printf("plaintext: ");
    string before = get_string();
    //printf("%s\n", before);

    //Кодируем
    printf("ciphertext: ");
    int currKeyPos = 0;
    for (int i = 0, n = strlen(before); i < n; i++)
    {
        //Если буква
        if ((before[i] >= 65 && before[i] <= 90) || (before[i] >= 97 && before[i] <= 122))
        {
            if (before[i] >= 65 && before[i] <= 90)
            {
                printf("%c", ((before[i] - 65 + key[currKeyPos]) % 26) + 65);
            }
            else if (before[i] >= 97 && before[i] <= 122)
            {
                printf("%c", ((before[i] - 97 + key[currKeyPos]) % 26) + 97);
            }
            //Идем на следующую букву ключа
            currKeyPos = (currKeyPos + 1) % keyLength;
        }
        else
        {
            printf("%c", before[i]);
        }
    }

    printf("\n");
}