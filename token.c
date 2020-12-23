#include "useful.h"

static char *exp_ptr;

void DealWithExp(char* exp){
    exp_ptr = exp;
}

char* getExpPtr(){
    return exp_ptr;
}

extern void printfstack();
/**
 * ʹ��ǰ��ʹ��DealWithExp����
 * û����һ��gettoken������һ��tokenȡ�������buff��
 * ����token������,ʧ�ܷ���-1
*/
int getToken(char* buff, int length){
    printfstack();
    int i = 0, tokentype = -1;
    char c;
    while( (c = *exp_ptr)){
        if(myisblank(c)){
            exp_ptr++;
            continue;
        }

        if(tokentype != NUM && isNum(c)){//��ʼ������
            tokentype = NUM;
            buff[i++] = c;
            exp_ptr++;
            continue;
        }else if(tokentype == NUM && isNum(c)){//���ڶ�����
            buff[i++] = c;
            exp_ptr++;
            continue;
        }else if(tokentype == NUM && !isNum(c)){//�պö�������,return��exp_ptrָ��ľ����¸�һ�������ַ���
            buff[i] = '\0';
            return NUM;
        }else{//���ڶ��Ĳ�������
            switch (c)
            {
            case '(':
                tokentype = LEFT_PARA;
                break;
            case ')':
                tokentype = RIGHT_PARA;
                break;
            case '+':
                tokentype = OP_ADD;
                break;
            case '-':
                tokentype = OP_SUB;
                break;
            case '*':
                tokentype = OP_MUL;
                break;
            case '/':
                tokentype = OP_DIV;
                break;
            default:
                printf("unknow char:%c\n", c);
                return -1;
                break;
            }
            buff[i++] = c;
            buff[i++] = '\0';
            exp_ptr++;
            return tokentype;
        }
    }
    buff[i] = '\0';
    return tokentype;
}
