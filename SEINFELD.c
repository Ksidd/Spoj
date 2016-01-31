/************************************************************************
Author         :- Siddharth Rajendra Kawar
Program        :- SPOJ classical problem
Problem Code   :- ANARC09A
Submitted      :- 2016-01-21
SPOJ user name :- Ksidd 
************************************************************************/
#include<stdio.h>
Push(char ch);
char Pop();
char stack[2050];
int top;

int main(){

    char str[2050];

    int Min_Op = 0;
    int TC = 1;
    while(scanf("%s",str)){
        top = -1;
        Min_Op = 0;
        if(str[0] == '-')
            break;
        int i=0;
        for(i=0;str[i]!='\0';i++){

            if(str[i] == '}'){
                if(top == -1){
                    Push('{');
                    Min_Op++;
                }
                else{
                    while(Pop()!='{');

                }
            }
            else{
                Push('{');
            }
        }
        if(top!=-1){
            while(top!=-1){
                Pop();
                Min_Op++;
                while(Pop()!='{');
            }
        }
        printf("%d. %d\n",TC,Min_Op);
        TC++;
    }

    return 0;
}
Push(char ch){
    top = top + 1;
    stack[top] = ch;
}

char Pop(){
    char t = stack[top];
    top = top - 1;
    return t;
}
