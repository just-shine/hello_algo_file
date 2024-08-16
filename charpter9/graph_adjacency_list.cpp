//
// Created by think on 2024/8/16.
//
#include<iostream>
#include<vector>
#include"../utils/cpp/common.hpp"
using namespace std;
//基于邻接表实现的无向图类
class GraphAdjList{
public:
    //邻接表,key :顶点,vlaue:该顶点的所有邻接顶点
    unordered_map<Vertex *,vector<Vertex *>> adjList;
    //在vector中删除指定节点
    void remove(vector<Vertex *> &vec,Vertex *vet){
        for(int i = 0; i<vec.size();i++){
            if(vec[i] == vet){
                vec.erase(vec.begin() + i);
                break;
            }
        }
    }
    //构造方法
    GraphAdjList(const vector<vector<Vertex *>> &edges){
        //添加所有的顶点和边
        for(const vector<Vertex *> &edge :edges) {
            addVertex(edge[0]);
            addVertex(edge[1]);
            addEdge(edge[0],edge[1]);
        }
    }
    //获取顶点数量
    int size(){
        return adjList.size();
    }
    //添加边
    void addEdge(Vertex *vet1,Vertex *vet2){
        if(!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2){
            throw invalid_argument("不存在顶点");
        }
        //添加vet1 - vet2
        adjList[vet1].push_back(vet2);
        adjList[vet2].push_back(vet1);
    }
    //删除边
    void removeEdge(Vertex *vet1,Vertex *vet2){
        if(!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2){
            throw invalid_argument("不存在顶点");
            //删除边
            remove(adjList[vet1],vet2);
            remove(adjList[vet2],vet1);
        }
    }
    //添加顶点
    void addVertex(Vertex *vet){
        if(adjList.count(vet)){
            return;
        }
        //在邻接表中添加一个新链表
        adjList[vet] = vector<Vertex *>();
    }
    //删除顶点
    void removeVertex(Vertex *vet){
        if(!adjList.count(vet))
            throw invalid_argument("不存在顶点");
        //在邻接表中删除顶点vet对应的链表
        adjList.erase(vet);
        //遍历其他顶点的链表,删除所有包含vet的边
        for(auto &adj :adjList){
            remove(adj.second,vet);
        }
    }
    void print(){
        cout<<"邻接表 = "<<endl;
        for(auto &adj : adjList){
            const auto &key = adj.first;
            const auto &vec = adj.second;
            cout<<key ->val <<" : ";
            printVector(vetsToVals(vec));
        }
    }
};
































