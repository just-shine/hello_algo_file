#include<iostream>
#include<vector>
#include<unordered_map>
//#include<hash_map>

using namespace std;
int main(){
    //初始化哈希表
    unordered_map<int,string> map;
    //添加操作
    //在哈希表中添加键值对
    map[12836] = "小哈";
    map[15937] = "小喽";
    map[16750] = "小算";
    map[13276] = "小法";
    map[10583] = "小鸭";
    
    //查询操作
    //向哈希表中输入键 key 得到值value
    string name = map[13276];
    cout << name << endl;
    //删除操作
    //在哈希表中删除键值对(key,value)
    //map.erase(10583);
    //遍历哈希表
    //遍历键值对 key - value
    for(auto kv:map){
        cout<<kv.first<<" -> "<<kv.second<<endl;
    }
    //使用迭代器遍历key -> value
    for(auto iter = map.begin();iter != map.end();iter++){
        cout<<iter->first << " -> "<< iter->second <<endl;
    }




    return 0;
}