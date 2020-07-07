/*
E2B.h   -library for change english to braille
Created by WeSeokHwan (llaayy@naver.com) , 2020.6.30

U can use or upgrade this library for free.
I wanna add more function like korean to braille
anyway THX for using.
CuringInnos

이거 보고 만든 거임 : https://github.com/hyonzin/hangul-braille-converter.git
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

            //특수기호
            {0, 1, 0, 0, 0, 0}, //value[26][]]
            {0, 1, 0, 0, 1, 1},
            {0, 1, 0, 0, 1, 0},
            {0, 1, 1, 0, 0, 1},
            {0, 0, 1, 0, 0, 1},
            {0, 1, 1, 0, 1, 0},
            {0, 0, 0, 0, 0, 0}, //value[32][]

            //순서대로 대문자 숫자
            {0, 0, 0, 0, 0, 1}, //value[33][]
            {0, 0, 1, 1, 1, 1}  //value[34][]
    };

    char key[69];

    //영어를 점자로 문자열 반환
    char *E_B(char x);

    //점자를 영어로 char 반환
    char B_E(int x[]);
    int find(int x[]);

    //쓰고 싶은 핀번호 설정 시작핀만 (4입력시 4번핀~9번핀 사용)
    void E_BSET();

    //알파벳에 따라 key value 값 초기화
    void m_init();

private:
    int _pin[6];
};

#endif