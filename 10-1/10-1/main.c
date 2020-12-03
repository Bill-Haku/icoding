//
//  main.c
//  10-1
//
//  Created by HakuBill on 2020/9/29.
//

#include <stdbool.h>   /* C99 only */
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 700

/* external variables */
char contents[STACK_SIZE];
int top = 0;

void stack_overflow(void) {
  printf("Stack overflow\n");
  exit(EXIT_FAILURE);
}

void stack_underflow(void) {
  printf("Stack underflow\n");
  exit(EXIT_FAILURE);
}


void make_empty(void) {
  top = 0;
}

bool is_empty(void) {
  return top == 0;
}

bool is_full(void) {
  return top == STACK_SIZE;
}

void push(char ch) {
  if (is_full())
    stack_overflow();
  else
    contents[top++] = ch;
}

char pop(void) {
  if (is_empty())
    stack_underflow();
  else {
      contents[top-1]='\0';
      top--;
//      return contents[--top];
  }
  return '\0'; /* prevents compiler warning due to stack_underflow() call */
}

int judge(char ch) {
    if(ch==')') {
        if(contents[top-1]=='(') {
            pop();
        }
        else
            return -1;
    }
    else if(ch=='}') {
        if(contents[top-1]=='{') {
            pop();
        }
        else
            return -1;
    }
}

int main(void) {
    char c;
    make_empty();
    while(scanf("%c",&c)!=EOF) {
        if(c=='('||c=='{')
            push(c);
        else
            if(judge(c)==-1) {
                printf("Parentheses/braces are NOT nested properly\n");
                return 0;
            }
    }
    printf("Parentheses/braces are nested properly\n");
    return 0;
}
