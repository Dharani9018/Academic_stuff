#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

#define MAX 50

typedef struct stack
{
    int data[MAX];
    int top;
} stack;

void init(stack *s)
{
    s->top=-1;
}

void push(stack *s, char x)
{
    if(s->top==MAX-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++(s->top)] = x;
    return;
}
char pop(stack *s)
{
    if(s->top==-1)
    {
        return '\0';
    }
    return s->data[(s->top)--];
}
int full(stack *s)
{
    return s->top==MAX-1;
}

int empty(stack *s)
{
    return s->top==-1;
}

char peek(stack *s)
{
    if(s->top==-1)
    {
        return '\0';
    }
    return s->data[s->top];
}

int precedence(char x)
{
    if(x=='(')
        return 0;
    if(x=='+' || x=='-')
        return 1;
    if(x=='*' || x=='/' || x=='%')
        return 2;
    
    return 3;
}
    
void infix_to_postfix(char infix[], char postfix[])
{
    stack s;
    init(&s);
    int i=0,j=0;//i for infix,j for postfix
    char x,token;
    while(infix[i]!='\0')
    {
        token=infix[i];
        if(isalnum(token))
        {
            postfix[j++]=token;
        }
        else if(token=='(')
        {
            push(&s,token);
        }
        else if(token==')')
        {
            while((x=pop(&s))!='(')
            {
                postfix[j++]=x;
            }
        }
        else
        {
            while(!empty(&s) && precedence(token)<=precedence(peek(&s)))
            {
                postfix[j++]=pop(&s);
            }
            push(&s,token);
        }
        i++;
    }
    while(!empty(&s))
    {
        postfix[j++]=pop(&s);
    }
    postfix[j]='\0';
}

void reverse(char str[])
{
    int len = strlen(str);
    int i = 0, j = len - 1;
    char temp;
    while(i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

void infix_to_prefix(char infix[], char prefix[])
{
    char rev_infix[MAX], rev_postfix[MAX];
    int len = strlen(infix), i;

    // Step 1: Reverse infix expression and swap '(' and ')'
    for(i = 0; i < len; i++)
    {
        if(infix[i] == '(')
            rev_infix[len - i - 1] = ')';
        else if(infix[i] == ')')
            rev_infix[len - i - 1] = '(';
        else
            rev_infix[len - i - 1] = infix[i];
    }
    rev_infix[len] = '\0';

    // Step 2: Get postfix of the reversed+swapped infix
    infix_to_postfix(rev_infix, rev_postfix);

    // Step 3: Reverse postfix to get prefix
    reverse(rev_postfix);
    strcpy(prefix, rev_postfix);
}
int main()
{
    char infix[30],postfix[30],prefix[30];
    printf("Enter an infix expression(no spaces): ");
    scanf("%s",infix);
    infix_to_postfix(infix,postfix);
    //infix_to_prefix(infix,prefix);
    printf("\nPostfix: %s\n",postfix);
    //printf("Prefix: %s\n",prefix);
    return 0;
}
