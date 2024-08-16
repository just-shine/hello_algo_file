//
// Created by think on 2024/8/16.
//
#include<iostream>
#include<vector>
using namespace std;

struct Pair{
public:
    int key;
    string val;
    Pair(int key,string val){
        this->key = key;
        this->val = val;
    }
    ~Pair(){}
};
//链式地址哈希表
class HashMpaChaining{
private:
    int size;                       //键值对数量
    int capacity;                   //哈希表容量
    double loadThres;               //触发扩容的负载因子阈值
    int extendRatio;                //扩容倍数
    vector<vector<Pair *>> buckets; //桶数组
public:
    //构造函数
    HashMpaChaining():size(0),capacity(4),loadThres(2.0/3.0),extendRatio(2){
        buckets.resize(capacity);
    }
    //析构方法
    ~HashMpaChaining(){
        for(auto &bucket:buckets){
            for(Pair *pair : bucket){
                //释放内存
                delete pair;
            }
        }
    }
    //哈希函数
    int hashFunc(int key){
        return key % capacity;
    }
    //负载因子
    double loadFactor(){
        return (double)size / (double )capacity;
    }
    //查询操作
    string get(int key){
        int index = hashFunc(key);
        //遍历桶,若找到key,则返回对应val
        for(Pair *pair :buckets[index]){
            if(pair->key == key){
                return pair->val;
            }
        }
        //若未找到key,则返回空字符
        return "";
    }
    //添加操作
    void put(int key,string val){
        //当负载因子超过阈值时,执行扩容
        if(loadFactor() > loadThres){
            extend();
        }
        int index = hashFunc(key);
        //遍历桶,若遇到指定key,则更新对应val并返回
        for(Pair *pair : buckets[index]){
            if(pair->key == key){
                pair->val = val;
                return;
            }
        }
        //若无该key,则将键值对添加至尾部
        buckets[index].push_back(new Pair(key,val));
        size++;
    }
    //删除操作
    void remove(int key){
        int index = hashFunc(key);
        auto &bucket = buckets[index];
        //遍历桶,从中删除键值对
        for(int i = 0;i<bucket.size();i++){
            if(bucket[i]->key == key){
                Pair *tmp = bucket[i];
                bucket.erase(bucket.begin() + i);
                delete tmp;
                size--;
                return;
            }
        }
    }

    //扩容哈希表
    void extend(){
        //暂存原哈希表
        vector<vector<Pair *>> bucketsTmp = buckets;
        //初始化扩容后的新哈希表
        capacity *= extendRatio;
        buckets.clear();
        buckets.resize(capacity);
        size = 0;
        //将原键值对从原哈希表搬运至新哈希表
        for(auto &bucket :bucketsTmp){
            for(Pair *pair : bucket){
                put(pair->key,pair->val);
                //释放内存
                delete pair;
            }
        }
    }
    //打印哈希表
    void print(){
        for(auto &bucket :buckets){
            cout<<"[ ";
            for(Pair *pair : bucket){
                cout<<pair->key << " -> " << pair->val<<", ";
            }
            cout << "]\n";
        }
    }
};



























