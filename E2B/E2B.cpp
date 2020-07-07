#include <Arduino.h>
#include "E2B.h"
#include <stdio.h>
#include <string.h>
char key[69];

bool NUM = false;
bool CAP = false;

void E2B::m_init()
{
    //key �ʱ�ȭ
    //�ҹ���
    for (int i = 0; i < 26; i++)
    {
        key[i] = 97 + i;
    }
    //�빮��
    for (int i = 0; i < 26; i++)
    {
        key[26 + i] = 65 + i;
    }
    //����
    key[52] = '1';
    key[53] = '2';
    key[54] = '3';
    key[55] = '4';
    key[56] = '5';
    key[57] = '6';
    key[58] = '7';
    key[59] = '8';
    key[60] = '9';
    key[61] = '0';
    //Ư����ȣ
    key[62] = ',';
    key[63] = '.';
    key[64] = '-';
    key[65] = '?';
    key[66] = '_';
    key[67] = '!';
    key[68] = ' ';
}

char *E2B::E_B(char x)
{
    int answer = -1;
    static char TO_return[50];

    //to return 0���� �ʱ�ȭ
    for (int i = 0; i < 50; i++)
    {
        TO_return[i] = 0;
    }

    //key���� �Է¹��� x���� ���� ���� ã��
    char temp[7] = "";
    for (int i = 0; i < 69; i++)
    {
        if (x == key[i])
        {
            answer = i;
            break;
        }
    }

    //�ҹ��� ��ȯ
    if (answer < 26)
    {
        for (int i = 0; i < 6; i++)
        {
            sprintf(temp, "%d", value[answer][i]);
            strcat(TO_return, temp);
        }
        return TO_return;
    }

    //�빮��
    else if (answer < 52)
    {
        //�պκ�
        for (int i = 0; i < 6; i++)
        {
            sprintf(temp, "%d", value[33][i]);
            strcat(TO_return, temp);
        }
        //�޺κ�
        for (int i = 0; i < 6; i++)
        {
            sprintf(temp, "%d", value[answer - 26][i]);
            strcat(TO_return, temp);
        }
    }

    //���� ��ȯ
    else if (answer < 62)
    {
        //�պκ�
        for (int i = 0; i < 6; i++)
        {
            sprintf(temp, "%d", value[34][i]);
            strcat(TO_return, temp);
        }
        //�޺κ�
        for (int i = 0; i < 6; i++)
        {
            sprintf(temp, "%d", value[answer - 52][i]);
            strcat(TO_return, temp);
        }
    }
    else if (answer == -1)
    {
        for (int i = 0; i < 6; i++)
        {
            sprintf(temp, "%d", value[32][i]);
            strcat(TO_return, temp);
        }
        return TO_return;
    }
    //Ư������
    else
    {
        for (int i = 0; i < 6; i++)
        {
            sprintf(temp, "%d", value[answer - 36][i]);
            strcat(TO_return, temp);
        }
    }
    return TO_return;
}

char E2B::B_E(int x[])
{
    int idx = find(x);

    //���� ���� �Է½� ��ĭ ���
    if (idx == -1)
    {
        return ' ';
    }

    //�빮�� �ε����� cap�� true�� �ٲٰ� ��ĭ ���
    if (idx == 33)
    {
        CAP = !CAP;
        return ' ';
    }
    //���� �ε����� num�� true�� �ٲٰ� ��ĭ ���
    else if (idx == 34)
    {
        NUM = !NUM;
        return ' ';
    }

    //Ư������
    if (idx > 25 && idx < 33)
    {
        return key[idx + 36];
    }

    //�빮��
    if (CAP)
    {
        CAP = !CAP;
        return key[idx + 26];
    }

    //����
    else if (NUM)
    {
        NUM = !NUM;
        return key[idx + 52];
    }

    //�ҹ���
    else
    {
        return key[idx];
    }
}

//�迭�� value�� �ε����� ��ȯ
int E2B::find(int x[])
{
    for (int i = 0; i < 45; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (x[j] == value[i][j])
            {
                if (j == 5)
                {
                    return i;
                }
            }
            else
            {
                break;
            }
        }
    }
    return -1;
}