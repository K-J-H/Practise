#include "useful.h"

int mystack[MAXLENGTH];
int stack_tpr = 0;//����ָ��յ�λ��

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

int evaluate_stack(){//����ֻ�мӼ�����ջ
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

//��ӡջ����ÿһ�ε���gettoken�ǵ��ñ�������������
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
    while((tokentype = getToken(buff,MAXLENGTH)) != -1){//�����Ķ�����֪��
        if(tokentype == LEFT_PARA){//��������ţ���ôһֱ����ֱ�����������ţ������洦��
            int tmp = evaluate3_();
            mypush(tmp);            //Ȼ�������ڵ�ֵ�ŵ�ջ��

        }else if(tokentype == RIGHT_PARA){//�ӻ����棬���������Ŵ����Ѿ����������ŵ�ֵ�ˣ����㲢����ջ��ֵ��
            return evaluate_stack();

        }else if(tokentype == OP_MUL || tokentype == OP_DIV){//�������ʱ�����˳˳�������ô���ж���һ�������ֻ�������
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

        }else{//ʣ�¶������ֺͼӼ�����
                if(tokentype == NUM){
                    mypush(str2i(buff));
                }else{
                    mypush((unsigned int)buff[0]);
                }
        }
    }//�������ֻʣ��ֻ�мӼ�����ջ��

    return evaluate_stack();
}