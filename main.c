#include "useful.h"

//extern int evaluate1(char *);
//extern int evaluate2(char *);
extern int evaluate3(char *);

int main(){
    char buff[MAXLENGTH];
    printf(">>>");
    while (mygetline(buff,MAXLENGTH))
    {
        printf("%d\n", evaluate3(buff));
        printf("\n>>>");
    }
    
}