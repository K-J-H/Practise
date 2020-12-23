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
 * 使用前先使用DealWithExp函数
 * 没调用一次gettoken，都有一个token取出存放在buff中
 * 返回token的类型,失败返回-1
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

        if(tokentype != NUM && isNum(c)){//开始读数字
            tokentype = NUM;
            buff[i++] = c;
            exp_ptr++;
            continue;
        }else if(tokentype == NUM && isNum(c)){//正在读数字
            buff[i++] = c;
            exp_ptr++;
            continue;
        }else if(tokentype == NUM && !isNum(c)){//刚好读完数字,return是exp_ptr指向的就是下个一非数字字符。
            buff[i] = '\0';
            return NUM;
        }else{//正在读的不是数字
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
