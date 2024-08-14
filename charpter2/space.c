#include<stdio.h>


/* 线性阶（递归实现） */
void linearRecur(int n) {
    printf("递归 n = %d\r\n", n);
    if (n == 1)
        return;
    linearRecur(n - 1);
    printf("退出递归 n = %d\r\n", n);
}

int main(){

    linearRecur(5);


    return 0;
}