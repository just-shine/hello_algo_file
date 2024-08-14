/* for loop*/
#include <stdio.h>


int forloop(int n){
    int res = 0;
    //循环求和 
    for (int i = 0;i<= n;++i){
        res += i;
    }
    return res;
}
/* while 循环 */
int whileLoop(int n) {
    int res = 0;
    int i = 1; // 初始化条件变量
    // 循环求和 1, 2, ..., n-1, n
    while (i <= n) {
        res += i;
        i++; // 更新条件变量
    }
    return res;
}
/* while 循环（两次更新） */
int whileLoopII(int n) {
    int res = 0;
    int i = 1; // 初始化条件变量
    // 循环求和 1, 4, 10, ...
    while (i <= n) {
        res += i;
        // 更新条件变量
        i++;
        i *= 2;
    }
    return res;
}
/* 双层 for 循环 */
char *nestedForLoop(int n) {
    // n * n 为对应点数量，"(i, j), " 对应字符串长最大为 6+10*2，加上最后一个空字符 \0 的额外空间
    int size = n * n * 26 + 1;
    char *res = malloc(size * sizeof(char));
    // 循环 i = 1, 2, ..., n-1, n
    for (int i = 1; i <= n; i++) {
        // 循环 j = 1, 2, ..., n-1, n
        for (int j = 1; j <= n; j++) {
            char tmp[26];
            snprintf(tmp, sizeof(tmp), "(%d, %d), ", i, j);
            strncat(res, tmp, size - strlen(res) - 1);
        }
        //printf("\n");
    }
    return res;
}
/* 递归 */
int recur(int n) {
    // 终止条件
    if (n == 1)
        return 1;
    // 递：递归调用
    int res = recur(n - 1);
    // 归：返回结果
    return n + res;
}
/* 尾递归 */
int tailRecur(int n, int res) {
    // 终止条件
    if (n == 0)
        return res;
    // 尾递归调用
    return tailRecur(n - 1, res + n);
}
/* 斐波那契数列：递归 */
int fib(int n) {
    // 终止条件 f(1) = 0, f(2) = 1
    if (n == 1 || n == 2)
        return n - 1;
    // 递归调用 f(n) = f(n-1) + f(n-2)
    int res = fib(n - 1) + fib(n - 2);
    // 返回结果 f(n)
    return res;
}
/* 使用迭代模拟递归 */
int forLoopRecur(int n) {
    int stack[1000]; // 借助一个大数组来模拟栈
    int top = -1;    // 栈顶索引
    int res = 0;
    // 递：递归调用
    for (int i = n; i > 0; i--) {
        // 通过“入栈操作”模拟“递”
        stack[1 + top++] = i;
    }
    // 归：返回结果
    while (top >= 0) {
        // 通过“出栈操作”模拟“归”
        res += stack[top--];
    }
    // res = 1+2+3+...+n
    return res;
}
int main(){

    //int result = forloop(10);
    //int result1 = whileLoop(10);
    printf("%s\n",nestedForLoop(5));
    //printf("result = %d \n",result);
    //printf("result1 = %d \n",result1);

    return 0;
}