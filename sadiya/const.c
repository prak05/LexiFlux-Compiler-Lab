#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void input();
void output();
void change(int p,char *res);
void constant();

struct expr{
    char op[2],op1[5],op2[5],res[5];
    int flag;
}arr[10];

int n;

int main(){
    input();
    constant();
    output();
    return 0;
}

void input(){
    int i;
    printf("\n\n enter the number of expressions:");
    scanf("%d",&n);
    printf("\n enter the input (op op1 op2 res): \n");
    for(i=0;i<n;i++){
        scanf("%s",arr[i].op);
        scanf("%s",arr[i].op1);
        scanf("%s",arr[i].op2);
        scanf("%s",arr[i].res);
        arr[i].flag=0;
    }
}

void constant(){
    int i;
    int op1,op2,eval_result;
    char res_str[5];

    for(i=0;i<n;i++){
        if((isdigit(arr[i].op1[0]) && isdigit(arr[i].op2[0])) ||
           (strcmp(arr[i].op,"=")==0 && isdigit(arr[i].op1[0])))
        {
            op1=atoi(arr[i].op1);
            op2=atoi(arr[i].op2);

            char op = arr[i].op[0];

            switch(op){
                case '+':
                    eval_result=op1+op2;
                    break;

                case '-':
                    eval_result=op1-op2;
                    break;

                case '*':
                    eval_result=op1*op2;
                    break;

                case '/':
                    eval_result=(op2!=0)? op1/op2:0;
                    break;

                case '=':
                    eval_result=op1;
                    break;

                default:
                    continue;
            }

            sprintf(res_str,"%d",eval_result);
            arr[i].flag=1;
            change(i,res_str);
        }
    }
}

void output(){
    int i;
    printf("\n optimized code is:\n");
    for(i=0;i<n;i++){
        if(!arr[i].flag){
            printf("%s %s %s %s\n",arr[i].op,arr[i].op1,arr[i].op2,arr[i].res);
        }
    }
}

void change(int p,char *res){
    int i;
    for(i=p+1;i<n;i++){
        if(strcmp(arr[p].res,arr[i].op1)==0){
            strcpy(arr[i].op1,res);
        }

        if(strcmp(arr[p].res,arr[i].op2)==0){
            strcpy(arr[i].op2,res);
        }
    }
}

