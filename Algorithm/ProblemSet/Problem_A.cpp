#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
#define ESP 1e-10

struct list {
    double num;
    char c;
    int ded;
    list* next;
};
typedef struct list* Stack;

double fuction(char a[]);
int Tranfer(char a[], int i);
double top(Stack s);
void push(double x, Stack s, int d);
void pop(Stack s);
void calculate(Stack s1, Stack s2, char c, int x);
void fuc(Stack s1, Stack s2, char c, int x);

int main() {
    char a[200];
    cin >> a;
    double ans = fuction(a);
    if(fabs(ans) < ESP) ans = 0;
    cout << ans << endl;

    return 0;
}

double fuction(char a[]) {
    Stack s1, s2;
    s1 = (Stack)malloc(sizeof(struct list));
    s2 = (Stack)malloc(sizeof(struct list));
    s1->ded = 0;
    s2->ded = 1;
    s1->next = NULL;
    s2->next = NULL;
    char str[20] = "\n";
    int cnt = 0;
    int len = strlen(a);
    for (int i = 0; i < len; i++) {
        if ((a[i] >= '0' && a[i] <= '9') || a[i] == '.')
            str[cnt++] = a[i];
        else {
            double m;
            if (cnt > 0) {
                m = atof(str);
                push(m, s1, 0);
                strncpy_s(str, "\n", 1);
                cnt = 0;
            }
            int x = Tranfer(a, i);
            if (x > 0) calculate(s1, s2, a[i], x);
        }
    }
    return s1->next->num;
}

double top(Stack s) {
    if (s->next != NULL) {
        if (s->ded == 0)
            return s->next->num;
        else
            return s->next->c;
    } else
        return 0;
}

void push(double x, Stack s, int d) {
    Stack temp;
    temp = (Stack)malloc(sizeof(struct list));
    if (s->ded == 0) {
        temp->num = x;
        temp->ded = d;
        temp->next = s->next;
        s->next = temp;
    } else {
        temp->ded = d;
        temp->c = (char)x;
        temp->next = s->next;
        s->next = temp;
    }
}

void pop(Stack s) {
    Stack temp;
    if (s->next != NULL) {
        temp = s->next;
        s->next = s->next->next;
        free(temp);
    }
}

int Tranfer(char a[], int i) {
    if (a[i] == '+' || a[i] == '-')
        return 1;
    else if (a[i] == '*' || a[i] == '/')
        return 2;
    else if (a[i] == '^')
        return 3;
    else if (a[i] == 's' && a[i + 1] == 'i' && a[i + 2] == 'n')
        return 4;
    else if (a[i] == 'c' && a[i + 1] == 'o' && a[i + 2] == 's')
        return 4;
    else if (a[i] == 'g' && a[i - 1] == 'o' && a[i - 2] == 'l')
        return 4;
    else if (a[i] == 'n' && a[i - 1] == 'l')
        return 4;
    else if (a[i] == '(')
        return 5;
    else if (a[i] == ')')
        return 6;
    else if (a[i] == '=')
        return 1;
    return 0;
}

void calculate(Stack s1, Stack s2, char c, int x) {
    if (s2->next == NULL) {
        push(c, s2, x);
    } else if (c != '=' && c != ')') {
        while (s2->next != NULL && s2->next->ded >= x && s2->next->ded != 5) {
            fuc(s1, s2, c, x);
        }
        push(c, s2, x);
    } else if (c == ')') {
        while (s2->next->ded != 5 && s2->next != NULL) {
            fuc(s1, s2, c, x);
        }
        pop(s2);
    } else if (c == '=') {
        while (s2->next != NULL) {
            fuc(s1, s2, c, x);
        }
    }
}

void fuc(Stack s1, Stack s2, char c, int x) {
    char op;
    op = (char)top(s2);
    pop(s2);
    double y, z;
    switch (op) {
        case '+':
            y = top(s1);
            pop(s1);
            z = top(s1);
            pop(s1);
            push(z + y, s1, 0);
            break;
        case '-':
            y = top(s1);
            pop(s1);
            z = top(s1);
            pop(s1);
            push(z - y, s1, 0);
            break;
        case '*':
            y = top(s1);
            pop(s1);
            z = top(s1);
            pop(s1);
            push(z * y, s1, 0);
            break;
        case '/':
            y = top(s1);
            pop(s1);
            z = top(s1);
            pop(s1);
            push(z / y, s1, 0);
            break;
        case '^':
            y = top(s1);
            pop(s1);
            z = top(s1);
            pop(s1);
            push(pow(z, y), s1, 0);
            break;
        case 's':
            y = top(s1);
            pop(s1);
            push(sin(y * 3.14159 / 180), s1, 0);
            break;
        case 'c':
            y = top(s1);
            pop(s1);
            push(cos(y * 3.14159 / 180), s1, 0);
            break;
        case 'g':
            y = top(s1);
            pop(s1);
            push(log2(y), s1, 0);
            break;
        case 'n':
            y = top(s1);
            pop(s1);
            push(log(y), s1, 0);
            break;
    }
}
