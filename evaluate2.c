#include "useful.h"

int evaluate2(char* exp){
    DealWithExp(exp);
    int queqe[MAXLENGTH];
    int queqe_ptr = -1;

    char buff[MAXLENGTH];

    int tokentype;
    while ((tokentype = getToken(buff,MAXLENGTH)) != -1)
    {
        if(tokentype == OP_MUL){
            if(queqe_ptr < 0){
                printf("error: there's no number before *.\n");
                return -1;
            }else{
                if(getToken(buff,MAXLENGTH) == NUM){
                    queqe[queqe_ptr] *= str2i(buff);
                }else{
                    printf("error: %s is not a number.\n", buff);
                }
            }
        }else if(tokentype == OP_DIV){
            if(queqe_ptr < 0){
                printf("error: there's no number before /.\n");
                return -1;
            }else{
                if(getToken(buff,MAXLENGTH) == NUM){
                    queqe[queqe_ptr] /= str2i(buff);
                }else{
                    printf("error: %s is not a number.\n", buff);
                }
            }
        }else{
            printf("buff:%s\n",buff);
            if(queqe_ptr < MAXLENGTH - 1)
                queqe[++queqe_ptr] = (tokentype == NUM) ? str2i(buff) : (unsigned int)buff[0];
        }
    }
    //以上循环就是把优先级高的乘除法先做了，然后放到栈中，只对栈做加减法就好了
    if(queqe_ptr < 0 ){
        return 0;
    }
    int sum = queqe[0];
    char operator;
    for (int i = 1; i <= queqe_ptr; i++){
        operator= queqe[i++];
        switch (operator)
        {
        case '+':
            sum = sum + queqe[i];
            break;
        case '-':
            sum = sum - queqe[i];
            break;
        default:
            break;
        }
    }
    return sum;
}