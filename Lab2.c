#include<stdio.h>
#include<stdlib.h>  
#define smax 5

void push();
void pop();
void palin();
void display();

int top = -1, stk[smax];

void main() {
    int ch;
    while (1) {
        printf("\nSTACK MENU\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PALINDROME CHECK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: palin(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("INVALID CHOICE\n");
        }
    }
}

void push() {
    int item;
    if (top == smax - 1)
        printf("\nSTACK FULL (Overflow)\n");
    else {
        printf("Enter the item to be inserted: ");
        scanf("%d", &item);
        stk[++top] = item;
    }
}

void pop() {
    int d;
    if (top == -1)
        printf("\nSTACK EMPTY (Underflow)\n");
    else {
        d = stk[top--];
        printf("The deleted element is %d\n", d);
    }
}

void display() {
    if (top == -1)
        printf("\nSTACK EMPTY\n");
    else {
        printf("\nCONTENTS OF STACK ARE:\n");
        for (int i = top; i >= 0; i--)
            printf("%d\n", stk[i]);
    }
}

void palin() {
    int i, j = 0, flag = 1;
    int rev[smax];

    if (top == -1 || top == 0) {
        printf("\nPALINDROME CANNOT BE CHECKED\n");
        return;
    }

    // Reverse the stack
    for (i = top; i >= 0; i--, j++)
        rev[j] = stk[i];

    // Compare original stack and reversed stack
    for (i = 0; i <= top; i++) {
        if (rev[i] != stk[i]) {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("\nIT IS A PALINDROME\n");
    else
        printf("\nIT IS NOT A PALINDROME\n");
}
