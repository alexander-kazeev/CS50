// Implements a dictionary's functionality

#include <stdbool.h>
#include "dictionary.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int dictWords = 0; //Число слов, загруженных в словарь

typedef struct tryNode
{
    bool isWord; //Является словом (конец слова)
    struct tryNode *child[27]; //Указатель на детей
} tryNode;

tryNode *dictFirstNode; //указатель на первый нод словаря

//Индекс текущего символа в массиве
int getCharIndex(char c)
{
    if (c == '\'')
    {
        return 26;
    }
    else
    {
        int currIndex = tolower(c) - 'a';
        return currIndex;
    }
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    tryNode *wordCurrNode = dictFirstNode;
    //strlen не включает '\0', поэтому + 1
    for (int i = 0, wordLength = strlen(word) + 1; i < wordLength; i++)
    {
        //Если слово кончилось, проверяем, в словаре оно кончилось или нет
        if (word[i] == '\0')
        {
            return (wordCurrNode->isWord == true);
        }

        //Проверяем текущий символ
        int currIndex = getCharIndex(word[i]);
        if (currIndex < 0 || currIndex > 26)
        {
            return false;
        }
        if (wordCurrNode->child[currIndex] == NULL)
        {
            return false;
        }

        //Перемещаемся в словаре на текущий символ
        wordCurrNode = wordCurrNode->child[currIndex];
    }
    return false;
}

//Создание пустого нода
tryNode *createNode()
{
    tryNode *newTryNode = malloc(sizeof(tryNode));
    newTryNode->isWord = false;
    for (int i = 0; i < 27; i++)
    {
        newTryNode->child[i] = NULL;
    }
    return newTryNode;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *dictFile = fopen(dictionary, "r");
    if (dictFile == NULL)
    {
        return false;
    }

    dictFirstNode = createNode(); //Создаем первый нод для словаря

    if (dictFirstNode == NULL)
    {
        return false;
    }
    tryNode *dictCurrNode = dictFirstNode; //Текущий нод. Сначала он смотрит на первый нод

    for (char c = fgetc(dictFile); c != EOF; c = fgetc(dictFile))
    {
        //Обрабатываем текущий символ слова
        if (c != '\n')
        {
            int currIndex = getCharIndex(c);
            if (dictCurrNode->child[currIndex] == NULL)
            {
                dictCurrNode->child[currIndex] = createNode();
                if (dictCurrNode->child[currIndex] == NULL)
                {
                    return false;
                }
            }
            dictCurrNode = dictCurrNode->child[currIndex]; //Перемещаемся на созданный нод
        }
        //Обрабатываем конец слова
        else
        {
            dictCurrNode->isWord = true; //Записали полное слово
            dictWords++; //Увеличиваем счетчик записанных в словарь слов
            dictCurrNode = dictFirstNode; //Перемещаемся в первый нод словаря
        }
    }
    fclose(dictFile);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return dictWords;
}

//Рекурсивно удаляем все вложения
void unloadCurrNode(tryNode *currNode)
{
    for (int i = 0; i < 27; i++)
    {
        if (currNode->child[i] != NULL)
        {
            unloadCurrNode(currNode->child[i]);
        }
    }
    free(currNode);
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    if (dictFirstNode != NULL)
    {
        unloadCurrNode(dictFirstNode);
    }
    return true;
}
