#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//基于链表实现的栈
 typedef struct ListNode{
    int val;
    struct ListNode *next;
}ListNode_t;
typedef struct{
    ListNode_t *top;//将头节点作为栈顶
    int size;     //栈的长度
}LinkedListStack;
//构造函数
LinkedListStack *LinkedListStackInit(){
    LinkedListStack *s = malloc(sizeof(LinkedListStack));
    s->top = NULL;
    s->size = 0;
    return s;
}
//析构函数
void delLinkedListStack(LinkedListStack *s){
    while(s->top){
        ListNode_t *n = s->top->next;
        free(s->top);
        s->top = n;
    }
    free(s);
}
//获取栈的长度
int size(LinkedListStack *s){
    return s->size;
}
//判断栈是否为空
bool isEmpty(LinkedListStack *s){
    return size(s) == 0;
}
//入栈
void push(LinkedListStack *s,int num){
    ListNode_t *node = (ListNode_t*)malloc(sizeof(ListNode_t));
    node->next = s->top;//更新新节点的指针域
    node->val = num;//更新新节点的数据域
    s->top = node;//更新栈顶
    s->size ++;//更新栈大小
}
//访问栈顶元素
int peek(LinkedListStack *s){
    if(s->size == 0){
        printf("栈为空\n");
        return INT_MAX;
    }
    return s->top->val;
}
int pop(LinkedListStack *s){
    int val = peek(s);
    ListNode_t *tmp = s->top;
    s->top = s->top->next;
    //释放内存
    free(tmp);
    s->size--;
    return val;
}

int main(){
    LinkedListStack *s = LinkedListStackInit() ;
    push(s,5);
    push(s,8);
    printf("size %d\n",size(s));
    printf("top %d\n",peek(s));
    pop(s);
    printf("top %d\n",peek(s));
    
    



    return 0;
}