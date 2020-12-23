#include "useful.h"



int evaluate1(char *exp){
    DealWithExp(exp);
    char value[MAXLENGTH];
    if(getToken(value,MAXLENGTH) != NUM){
        printf("error: %s not define.\n",value);
    }else
    {
        char op[MAXLENGTH];
        int val = str2i(value);

        int tmp1, tmp2;
        while (((tmp1 = getToken(op, MAXLENGTH)) == OP_ADD || tmp1 == OP_SUB) && (tmp2 = getToken(value, MAXLENGTH)) == NUM)
        {
            switch (tmp1)
            {
            case OP_ADD:
                val = val + str2i(value);
                break;
            case OP_SUB:
                val = val - str2i(value);
                break;
            default:
                break;
            }
        }
        return val;
    }
    
}

