//
// Created by think on 2024/8/15.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100
//键值对 int -> string
typedef struct {
    int key;
    char *val;
}Pair;
//MapSet
typedef struct {
    void *set;
    int len;
}MapSet;
//基于数组实现的哈希表
typedef struct{
    Pair *buckets[MAX_SIZE];
}ArrayHashMap;
//构造函数
ArrayHashMap *newArrayHashMap(){
    ArrayHashMap *hmap = malloc(sizeof(ArrayHashMap));
    for(int i = 0;i<MAX_SIZE;i++){
        hmap->buckets[i] = NULL;
    }
}
//析构函数
void delArrayHashMap(ArrayHashMap *hmap){
    for(int i = 0;i < MAX_SIZE;i++){
        if(hmap->buckets[i] != NULL){
            free(hmap->buckets[i]->val);
            free(hmap->buckets[i]);
        }
    }
    free(hmap);
}
//计算index 哈希函数
int hashFunc(int key){
    int index = key % MAX_SIZE;
    return index;
}
//查询操作
const char *get(const ArrayHashMap *hmap,const int key){
    int index = hashFunc(key);
    const Pair *pair = hmap->buckets[index];
    if(pair == NULL){
        return NULL;
    }
    return pair->val;

}
//添加操作
void put(ArrayHashMap *hmap,const int key,const char* val){
    Pair *pair = malloc(sizeof(Pair));
    pair->key = key;
    pair->val = malloc(strlen(val)+1);
    strcpy(pair->val,val);

    int index = hashFunc(key);
    hmap->buckets[index] = pair;
}
//删除操作
void removeItem(ArrayHashMap *hmap,const int key){
    int index = hashFunc(key);
    free(hmap->buckets[index]->val);
    free(hmap->buckets[index]);
    hmap->buckets[index] = NULL;
}
//获取所有键值对
void pairSet(ArrayHashMap *hmap,MapSet *set){
    Pair *entries;
    int i = 0,index = 0;
    int total = 0;
    //统计有效键值对数量
    for(i=0;i<MAX_SIZE;i++){
        if(hmap->buckets[i] != NULL){
            total++;
        }
    }
    entries = malloc(sizeof(Pair)*total);
    for (int i = 0; i < MAX_SIZE; ++i) {
        if(hmap->buckets[i] != NULL){
            entries[index].key = hmap->buckets[i]->key;
            entries[index].val = malloc(strlen(hmap->buckets[i]->val) +1);
            entries[index].val = hmap->buckets[i]->val;
            index++;
        }
    }
    set->set = entries;
    set->len = total;
}
//获取所有键
void keySet(ArrayHashMap *hmap,MapSet* set){
    int *keys;
    int i = 0,index = 0;
    int total = 0;
    //统计有效键值对数量
    for(i = 0;i<MAX_SIZE;i++){
        if(hmap->buckets[i] != NULL){
            total++;
        }
    }
    keys= malloc(sizeof(int)*total);
    for(i=0;i<MAX_SIZE;i++){
        if(hmap->buckets[i] != NULL){
            keys[index] = hmap->buckets[i]->key;
            index++;
        }
    }
    set->set = keys;
    set->len = total;
}
//获取所有值
void valueSet(ArrayHashMap *hmap,MapSet *set){
    char** vals;
    int i = 0,index = 0;
    int total = 0;
    //统计有效键值对数量
    for(i=0;i<MAX_SIZE;i++){
        if(hmap->buckets[i] != NULL){
            total++;
        }
    }
    vals = malloc(total*sizeof (char*));
    for(i = 0;i<MAX_SIZE;i++){
        if(hmap->buckets[i] != NULL){
            vals[index] = hmap->buckets[i]->val;
            index++;
        }
    }
    set->set = vals;
    set->len = total;
}
//打印哈希表
void print(ArrayHashMap *hmap){
    int i;
    MapSet set;
    pairSet(hmap,&set);
    Pair *entries = (Pair*)set.set;
    for(i = 0;i<set.len;i++){
        printf("%d -> %s\n",entries[i].key,entries[i].val);
    }
    free(set.set);
}

int main(){
    ArrayHashMap *hmap = newArrayHashMap();
    put(hmap,123,"hello");
    put(hmap,124,"world");
    put(hmap,125,"somuch");
    MapSet keys;
    keySet(hmap,&keys);
    int *a = (int*)keys.set ;
    for(int i = 0;i<keys.len;i++){
        printf("%d\n",a[i]);
    }
    print(hmap);
    delArrayHashMap(hmap);




    return 0;
}














