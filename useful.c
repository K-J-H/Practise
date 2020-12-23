#include "useful.h"
/**
 * �Ӽ��̶�ȡһ���ַ������浽buff��
 * ���룺��ŵ�buff�ַ����飬���鳤��
 * �������ȡ�����ַ�����
*/
int mygetline(char* buff, int length){
    int i = 0;
    char c;
    while((c = getchar()) != EOF && c != '\n' && i < length - 1){
        buff[i++] = c;
    }
    buff[i] = '\0';
    return i;
}

int myisblank(char c){
    return c == ' ' || c == '\n' || c == '\t';
}

int isNum(char c){
    return c >= '0' && c <= '9';
}

int myatoi(char c){
    if(isNum(c)){
        return c - '0';
    }else
    {
        printf("error: not a number.\n");
        return -1;
    }
}

int str2i(char *str){
    char c;
    int sum = 0;
    while ((c = *str))
    {
        if(isNum(c)){
            sum = sum * 10 + myatoi(c);
        }else{
            printf("error: %c is not a number.\n", c);
            return -1;
        }
        str++;
    }
    return sum;
}

