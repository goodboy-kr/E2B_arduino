/*
E2B.h   -library for change english to braille
Created by WeSeokHwan (llaayy@naver.com) , 2020.6.30

U can use or upgrade this library for free.
I wanna add more function like korean to braille
anyway THX for using.
CuringInnos

�̰� ���� ���� ���� : https://github.com/hyonzin/hangul-braille-converter.git
*/
#ifndef E2B_h
#define E2B_h
#include <Arduino.h>
#include <stdio.h>


class E2B
{
public:
    int value[45][6] =
        {
            //A~Z
            {1, 0, 0, 0, 0, 0}, //value[0][]
            {1, 1, 0, 0, 0, 0},
            {1, 0, 0, 1, 0, 0},
            {1, 0, 0, 1, 1, 0},
            {1, 0, 0, 0, 1, 0},
            {1, 1, 0, 1, 0, 0},
            {1, 1, 0, 1, 1, 0},
            {1, 1, 0, 0, 1, 0},
            {0, 1, 0, 1, 0, 0},
            {0, 1, 0, 1, 1, 0},
            {1, 0, 1, 0, 0, 0},
            {1, 1, 1, 0, 0, 0},
            {1, 0, 1, 1, 0, 0},
            {1, 0, 1, 1, 1, 0},
            {1, 0, 1, 0, 1, 0},
            {1, 1, 1, 1, 0, 0},
            {1, 1, 1, 1, 1, 0},
            {1, 1, 1, 0, 1, 0},
            {0, 1, 1, 1, 0, 0}, //s value[18][]
            {0, 1, 1, 1, 1, 0},
            {1, 0, 1, 0, 0, 1},
            {1, 1, 1, 0, 0, 1},
            {0, 1, 1, 1, 1, 1},
            {1, 0, 1, 1, 0, 1},
            {1, 0, 1, 1, 1, 1},
            {1, 0, 1, 0, 1, 1}, //value[25][]

            //Ư����ȣ
            {0, 1, 0, 0, 0, 0}, //value[26][]]
            {0, 1, 0, 0, 1, 1},
            {0, 1, 0, 0, 1, 0},
            {0, 1, 1, 0, 0, 1},
            {0, 0, 1, 0, 0, 1},
            {0, 1, 1, 0, 1, 0},
            {0, 0, 0, 0, 0, 0}, //value[32][]

            //������� �빮�� ����
            {0, 0, 0, 0, 0, 1}, //value[33][]
            {0, 0, 1, 1, 1, 1}  //value[34][]
    };

    char key[69];

    //��� ���ڷ� ���ڿ� ��ȯ
    char *E_B(char x);

    //���ڸ� ����� char ��ȯ
    char B_E(int x[]);
    int find(int x[]);

    //���� ���� �ɹ�ȣ ���� �����ɸ� (4�Է½� 4����~9���� ���)
    void E_BSET();

    //���ĺ��� ���� key value �� �ʱ�ȭ
    void m_init();

private:
    int _pin[6];
};

#endif