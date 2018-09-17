#define _XOPEN_SOURCE

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

void changeIndex(int *charIndex, int charQuantity, int charIndexQuantity, int level); //Прототип

/*
anushree:50xcIMJ0y.RXo  YES     (   123343 try)
brian:50mjprEcqC/ts     CA      (     1433 try)
bjbrown:50GApilQSG3E2   UPenn   (104346887 try)
lloyd:50n0AAUD.pL8g     lloyd   ( 32802860 try)
malan:50CcfIk1QrPr6     maybe   ( 36906961 try)
maria:509nVI8B9VfuA     TF      (     1710 try)
natmelo:50JIIyhDORqMU   nope    (   747098 try)
rob:50JGnXUgaafgc       ROFL    (  5431808 try)
stelios:51u8F0dkeDSbY   NO      (     2172 try)
zamyla:50cI2vYkF0YU2    LOL     (   104922 try)
*/

int main(int argc, string argv[])
{
    //Проверка входящего параметра
    if (argc != 2)
    {
        printf("Должен быть один и только один входной текстовый параметр\n");
        return 1;
    }
    int maxPassLength = 5;

    //Получаем хеш пароля и запоминаем "соль"
    string hashCode = (argv[1]);
    char salt[2];
    strncpy(salt, hashCode, 2);

    //Строка со всеми символами
    char allChars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int charQuantity = sizeof(allChars) / sizeof(allChars[0]) - 1;

    //Последний символ в charIndex для '\0'.
    int charIndex[maxPassLength + 1];
    int charIndexQuantity = sizeof(charIndex) / sizeof(charIndex[0]) - 2;
    //Последний символ в myPass для '\0'. Обязательно! Иначе пароль с длиной, равной maxPassLength, не найдется.
    char myPass[(maxPassLength + 1)];
    //Заполняем начальными значениями
    for (int i = 0; i <= maxPassLength; i++)
    {
        if (i < maxPassLength)
        {
            charIndex[i] = -1;
        }
        else
        {
            charIndex[i] = '\0';
        }
        myPass[i] = '\0';
    }

    //Создаем новый пароль и проверяем его хеш
    while (true)
    {
        //Увеличиваем счетчик и индекс на 1
        changeIndex(charIndex, charQuantity, charIndexQuantity, 0);

        //Выходим, если все перебрали и не нашли
        if (charIndex[charIndexQuantity] >= charQuantity)
        {
            printf("INVALID\n");
            return 0;
        }

        //Заполняем новый пароль по новым индексам
        for (int i = 0; i <= charIndexQuantity; i++)
        {
            if (charIndex[i] >= 0)
            {
                myPass[i] = allChars[charIndex[i]];
            }
        }

        //Определяем хеш пароля
        string result = crypt(myPass, salt);

        //Проверяем получившийся хеш с введенным при запуске
        if (strcmp(result, hashCode) == 0)
        {
            printf("%s\n", myPass);
            return 0;
        }
    }
}

void changeIndex(int *charIndex, int charQuantity, int charIndexQuantity, int level)
{
    if (level <= charIndexQuantity)
    {
        charIndex[level]++;
        if (charIndex[level] >= charQuantity && level < charIndexQuantity)
        {
            charIndex[level] -= charQuantity;
            changeIndex(charIndex, charQuantity, charIndexQuantity, level + 1);
        }
    }
}
