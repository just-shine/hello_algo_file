// Created by think on 2024/8/15.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 假设 val 最大长度为 100
#define MAX_SIZE 100
//键值对 int -> string
typedef struct {
    int key;
	char val[MAX_SIZE];
}Pair;
//链表节点
typedef struct Node{
    Pair *pair;
    struct Node *next;
}Node;
//链式地址哈希表
typedef struct {
    int size;       //键值对数量
    int capacity;   //哈希表容量
    double loadThres;//触发扩容的负载因子阈值
    int extendRatio;//扩容倍数
    Node **buckets; //桶数组
}HashMapChaining;
void extend(HashMapChaining *HashMap);
//构造函数
HashMapChaining *newHashMapChaining(){
    HashMapChaining *hashMap = (HashMapChaining*) malloc(sizeof(HashMapChaining));
    hashMap->size = 0;
    hashMap->capacity = 4;
    hashMap->loadThres = 2.0/3.0;
    hashMap->extendRatio = 2;
    hashMap->buckets = (Node **)malloc(hashMap->capacity*sizeof(Node*));
    for(int i = 0;i<hashMap->capacity;i++){
        hashMap->buckets[i] = NULL;
    }
    return hashMap;
}
//析构函数
void delHashMapChaining(HashMapChaining *HashMap){
    for(int i=0;i<HashMap->capacity;i++){
        Node *cur = HashMap->buckets[i];
        while(cur){
            Node *tmp = cur;
            cur = cur->next;
            free(tmp->pair);
            free(tmp);
        }
    }
    free(HashMap->buckets);
    free(HashMap);
}
//哈希函数
int hashFunc(HashMapChaining *HashMap,int key){
    return key % HashMap->capacity;
}
//负载因子
double loadFactor(HashMapChaining *HashMap){
    return (double)HashMap->size/(double)HashMap->capacity;
}
//查询操作
char *get(HashMapChaining *HashMap,int key){
    printf("开始查询操作\n");
    int index = hashFunc(HashMap,key);
    //遍历桶,若找到key,则返回对应val
    Node *cur = HashMap->buckets[index];
    while (cur){
        if(cur->pair->key == key) {
            return cur->pair->val;
        }
        cur = cur->next;
    }
    return "";//若未找到key,则返回空字符串
}
//添加操作
void put(HashMapChaining *HashMap,int key,const char* val){
    printf("开始插入数据:%d -> %s\n",key,val);
    //当负载因子超过阈值时,执行扩容操作
    if(loadFactor(HashMap) > HashMap->loadThres){
        extend(HashMap);
    }
    int index = hashFunc(HashMap,key);//
    //遍历桶,若遇到指定key,则更新对应val 并返回
    Node *cur = HashMap->buckets[index];
    while (cur){
        if(cur->pair->key == key){
            strcpy(cur->pair->val,val);
            return;
        }
        cur = cur->next;
    }
    //若无该key,则将键值对添加至链表头部
    Pair *newPair = (Pair*) malloc(sizeof(Pair));
    newPair->key = key;
    strcpy(newPair->val,val);

    Node *newNode = (Node*) malloc(sizeof (Node));
    newNode->pair = newPair;
    newNode->next = HashMap->buckets[index];

    HashMap->buckets[index] = newNode;
    HashMap->size++;
}

//扩容哈希表
void extend(HashMapChaining *HashMap){
    printf("触发扩容机制\n");
    //暂存原哈希表
    int oldCapacity = HashMap->capacity;
    Node **oldBuckets = HashMap->buckets;
    //初始化扩容后的新哈希表
    HashMap->capacity *= HashMap->extendRatio;
    HashMap->buckets = (Node**) malloc(HashMap->capacity*sizeof (Node*));
    for(int i = 0;i<HashMap->capacity;i++){
        HashMap->buckets[i] = NULL;
    }
    HashMap->size = 0;
    //将键值对从原哈希表搬运至新哈希表
    for(int i = 0;i< oldCapacity;i++){
        Node *cur = oldBuckets[i];
        while (cur){
            //将原数据插入
            put(HashMap,cur->pair->key,cur->pair->val);
            //指向该桶的下一个地址
            Node *temp = cur;
            cur = cur->next;
            //释放内存
            free(temp->pair);
            free(temp);
        }
    }
    free(oldBuckets);
}
//删除操作
void removeItem(HashMapChaining *HashMap,int key){
    int index = hashFunc(HashMap,key);
    Node *cur = HashMap->buckets[index];
    Node *pre = NULL;
    while (cur){
        if(cur->pair->key == key){
            //从中删除键值对
            if(pre){
                pre->next = cur->next;
            }else{
                HashMap->buckets[index] = cur->next;
            }
            //释放内存
            free(cur->pair);
            free(cur);
            HashMap->size--;
            return;
        }
        pre = cur;
        cur = cur->next;
    }
}
//打印哈希表
void print(HashMapChaining *HashMap){
    for(int i = 0;i<HashMap->capacity;i++){
        Node *cur = HashMap->buckets[i];
        printf("[ ");
        while (cur){
            printf("%d -> %s, ",cur->pair->key,cur->pair->val);
            cur = cur->next;
        }
        printf(" ]\n");
    }
}

int main(){

    HashMapChaining *hashmap = newHashMapChaining();
    put(hashmap,2,"hello");
    put(hashmap,4,"world");
    put(hashmap,6,"im");
    put(hashmap,8,"so");
    put(hashmap,10,"good");
    print(hashmap);
    char *s = get(hashmap,10);
    char *s1 = get(hashmap,20);
    printf("s ->%s\n",s);
    printf("s1 -> %s\n",s1);
    removeItem(hashmap,6);
    print(hashmap);

    delHashMapChaining(hashmap);
    return 0;
}






















