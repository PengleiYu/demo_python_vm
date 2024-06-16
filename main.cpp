#include <cstdio>

#define INIT 0
#define NUM 1

int state, num = 0;

void checkNumState();

int main() {
    FILE *fp = fopen("test_token.txt", "r");
    int ch;

    while ((ch = getc(fp)) != EOF) {
//        printf("%c\n", ch);
        if (ch == ' ' || ch == '\n') {
            checkNumState();
        } else if ('0' <= ch && ch <= '9') {
            state = NUM;
            num = num * 10 + ch - '0';
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            checkNumState();
            printf("token操作符: %c\n", ch);
            state = INIT;
        }
    }
    // 数字可能处于文件尾部
    checkNumState();

    fclose(fp);

    return 0;
}

void checkNumState() {
    if (state == NUM) {
        printf("token数字: %d\n", num);
        state = INIT;
        num = 0;
    }
}
