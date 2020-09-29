#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include <iostream>

int isUpper(char letter);
int isLower(char letter);
char encryption(char letter, int key);
char disencryption(char letter, int key);

using namespace std;

int main()
{
    int c;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char string[100];
    int key;
    printf("������� ������: ");
    gets(string);
    printf("������� ����� ������� ���� (���� ����� ����������, ������� 0): ");
    scanf("%d", &key);

    if (key == 0)
    {
        for (int i=0; i<32; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                string[j] = encryption(string[j], 1);
            }
            printf("%d. ", i);
            puts(string);
        }
    }
    else {
    int i;
    for (i = 0; i < 100; i++)
    {
        string[i] = encryption(string[i], key);
    }
    printf("\n����������� ������: ");
    puts(string);
    printf("\n���������� ������������? ������� Enter\n");
    c = _getch();
    if(c==13)
    {
        for (i = 0; i < 100; i++)
    {
        string[i] = disencryption(string[i], key);
    }
        printf("\n������������� ������: ");
        puts(string);
    }
    else
        exit (0);
    }
    getch();
    return 0;
}

int isUpper(char letter)
{
    int result = 0;
    if (letter >= '�' && letter <= '�')
        result = 1;

    return result;
}

int isLower(char letter)
{
    int result = 0;
    if (letter >= '�' && letter <= '�')
        result = 1;

    return result;
}

char encryption(char letter, int key)
{
    if (isUpper(letter))
    {
        letter += key;
        if (letter > '�')
        {
            letter-=32;
        }
    }
    if (isLower(letter))
    {
        letter += key;
        if (letter > '�')
        {
            letter-=32;
        }
    }
    return letter;
}

char disencryption(char letter, int key)
{
    if (isUpper(letter))
    {
        letter -= key;
        if (letter < 'A')
        {
            letter +=32;
        }
    }
    if (isLower(letter))
    {
        letter -= key;
        if (letter > '�')
        {
            letter +=32;
        }
    }
    return letter;
}
