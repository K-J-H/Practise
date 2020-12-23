#ifndef USEFUL
#define USEFUL
#include<stdio.h>
#define MAXLENGTH 1024

enum
{
    NUM = 0,
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    LEFT_PARA,
    RIGHT_PARA
};

void DealWithExp(char *exp);

char *getExpPtr();

int getToken(char *buff, int length);

int mygetline(char *buff, int length);

int myisblank(char c);

int isNum(char c);

int str2i(char *str);
#endif