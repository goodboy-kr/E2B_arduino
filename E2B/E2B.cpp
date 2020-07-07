#include <Arduino.h>
#include "E2B.h"
#include <stdio.h>
#include <string.h>
char key[69];

bool NUM = false;
bool CAP = false;

void E2B::m_init()
{
    //key 초기화
    //소문자
    for (int i = 0; i < 26; i++)
    {
        key[i] = 97 + i;
    }
    //대문자
    for (int i = 0; i < 26; i++)
    {
        key[26 + i] = 65 + i;
    }
    //숫자
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
    //특수기호
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

    //to return 0으로 초기화
    for (int i = 0; i < 50; i++)
    {
        TO_return[i] = 0;
    }

    //key에서 입력받은 x값과 같은 문자 찾기
    char temp[7] = "";
    for (int i = 0; i < 69; i++)
    {
        if (x == key[i])
        {
            answer = i;
            break;
        }
    }

    //소문자 변환
    if (answer < 26)
    {
        for (int i = 0; i < 6; i++)
        {
            sprintf(temp, "%d", value[answer][i]);
            strcat(TO_return, temp);
        }
        return TO_return;
    }

    //대문자
    else if (answer < 52)
    {
        //앞부분
        for (int i = 0; i < 6; i++)
        {
            sprintf(temp, "%d", value[33][i]);
            strcat(TO_return, temp);
        }
        //뒷부분
        for (int i = 0; i < 6; i++)
        {
            sprintf(temp, "%d", value[answer - 26][i]);
            strcat(TO_return, temp);
        }
    }

    //숫자 변환
    else if (answer < 62)
    {
        //앞부분
        for (int i = 0; i < 6; i++)
        {
            sprintf(temp, "%d", value[34][i]);
            strcat(TO_return, temp);
        }
        //뒷부분
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
    //특수문자
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

    //예외 문자 입력시 빈칸 출력
    if (idx == -1)
    {
        return ' ';
    }

    //대문자 인덱스시 cap을 true로 바꾸고 빈칸 출력
    if (idx == 33)
    {
        CAP = !CAP;
        return ' ';
    }
    //숫자 인덱스시 num을 true로 바꾸고 빈칸 출력
    else if (idx == 34)
    {
        NUM = !NUM;
        return ' ';
    }

    //특수문자
    if (idx > 25 && idx < 33)
    {
        return key[idx + 36];
    }

    //대문자
    if (CAP)
    {
        CAP = !CAP;
        return key[idx + 26];
    }

    //숫자
    else if (NUM)
    {
        NUM = !NUM;
        return key[idx + 52];
    }

    //소문자
    else
    {
        return key[idx];
    }
}

//배열을 value의 인덱스로 변환
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