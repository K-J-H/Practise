#include "useful.h"

int mystack[MAXLENGTH];
int stack_tpr = 0;//总是指向空的位置

static int mypush(int a){
    if(stack_tpr > MAXLENGTH - 1){
        printf("error[evaluate3.c]:stack overflow.\n");
        return -1;
    }else{
        mystack[stack_tpr++] = a;
    }
    return a;
}

static int mypop(){
    if(stack_tpr <= 0){
        printf("error[evaluate3.c]:stack empty.\n");
        return -1;
    }else{
        return mystack[--stack_tpr];
    }
}

int evaluate_stack(){//计算只有加减法的栈
    if(stack_tpr <= 0){
        printf("evaluate: stack empty.\n");
        return -1;
    }
    int sum = mystack[0];
    for (int i = 1; i < stack_tpr; i++){
        char c = (unsigned int)mystack[i];
        switch (c)
        {
        case '+':
            sum = sum + mystack[++i];
            break;
        case '-':
            sum = sum - mystack[++i];
        default:
            break;
        }
    }
    stack_tpr = 0;
    return sum;
}
int evaluate3_();
int evaluate3(char* exp){
    DealWithExp(exp);
    evaluate3_();
}

//打印栈，在每一次调用gettoken是调用本函数，测试用
void printfstack(){
    if(stack_tpr <= 0){
        printf("count:%d", stack_tpr);
    }
    for (int i = 0; i < stack_tpr; i++){
        printf("%d-->", mystack[i]);
    }
    printf("\n");
}

int evaluate3_(){
    int tokentype;
    char buff[MAXLENGTH];
    while((tokentype = getToken(buff,MAXLENGTH)) != -1){//读到的都是已知的
        if(tokentype == LEFT_PARA){//如果是括号，那么一直计算直到遇到右括号（在下面处理）
            int tmp = evaluate3_();
            mypush(tmp);            //然后将括号内的值放到栈中

        }else if(tokentype == RIGHT_PARA){//接回上面，遇到右括号代表已经计算完括号的值了，计算并返回栈的值。
            return evaluate_stack();

        }else if(tokentype == OP_MUL || tokentype == OP_DIV){//如果计算时遇到了乘除法，那么先判断下一个是数字还是括号
            int mul_div = tokentype;

            if((tokentype = getToken(buff, MAXLENGTH)) == NUM){
                int lefttmp = mypop();
                int righttmp = str2i(buff);
                mypush( (mul_div == OP_MUL) ? lefttmp * righttmp : lefttmp / righttmp );

            }else if(tokentype == LEFT_PARA){
                int lefttmp = mypop();
                int nextvalue = evaluate3_();
                mypush((mul_div == OP_MUL) ? lefttmp * nextvalue : lefttmp / nextvalue);

            }else{
                printf("error: undefine expression.\n");
            }

        }else{//剩下都是数字和加减法了
                if(tokentype == NUM){
                    mypush(str2i(buff));
                }else{
                    mypush((unsigned int)buff[0]);
                }
        }
    }//处理完后只剩下只有加减法的栈了

    return evaluate_stack();
}