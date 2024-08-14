#include<iostream>
#include<stack>
using namespace std;


int main(){
    //初始化栈
    stack<int> stack;
    //元素入栈
    stack.push(1);
    stack.push(13);
    stack.push(6);
    stack.push(8);
    stack.push(2);
    stack.push(5);
    //访问栈顶元素
    int top = stack.top();
    cout<<top<<endl;
    //元素出栈
    stack.pop();
    //获取栈的长度
    int size = stack.size();
    //判断是否为空
    bool empty = stack.empty();

    return 0;
}