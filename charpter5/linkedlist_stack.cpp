#include<iostream>
#include<vector>
#include<stdbool.h>
using namespace std;
struct ListNode{
    int val;
    struct ListNode *next;  
};

/* 基于链表实现的栈 */
class LinkedListStack {
  private:
    ListNode *stackTop; // 将头节点作为栈顶
    int stkSize;        // 栈的长度

  public:
    LinkedListStack() {
        stackTop = nullptr;
        stkSize = 0;
    }

    ~LinkedListStack() {
        // 遍历链表删除节点，释放内存
        freeMemoryLinkedList(stackTop);
    }

    /* 获取栈的长度 */
    int size() {
        return stkSize;
    }

    /* 判断栈是否为空 */
    bool isEmpty() {
        return size() == 0;
    }

    /* 入栈 */
    void push(int num) {
        ListNode *node = new struct ListNode(num);
        node->next = stackTop;
        stackTop = node;
        stkSize++;
    }

    /* 出栈 */
    int pop() {
        int num = top();
        ListNode *tmp = stackTop;
        stackTop = stackTop->next;
        // 释放内存
        delete tmp;
        stkSize--;
        return num;
    }

    /* 访问栈顶元素 */
    int top() {
        if (isEmpty())
            throw out_of_range("栈为空");
        return stackTop->val;
    }

    /* 将 List 转化为 Array 并返回 */
    vector<int> toVector() {
        ListNode *node = stackTop;
        vector<int> res(size());
        for (int i = res.size() - 1; i >= 0; i--) {
            res[i] = node->val;
            node = node->next;
        }
        return res;
    }
};
/* 基于数组实现的栈 */
class ArrayStack {
  private:
    vector<int> stack;

  public:
    /* 获取栈的长度 */
    int size() {
        return stack.size();
    }

    /* 判断栈是否为空 */
    bool isEmpty() {
        return stack.size() == 0;
    }

    /* 入栈 */
    void push(int num) {
        stack.push_back(num);
    }

    /* 出栈 */
    int pop() {
        int num = top();
        stack.pop_back();
        return num;
    }

    /* 访问栈顶元素 */
    int top() {
        if (isEmpty())
            throw out_of_range("栈为空");
        return stack.back();
    }

    /* 返回 Vector */
    vector<int> toVector() {
        return stack;
    }
};

int main(){
    return 0;
}