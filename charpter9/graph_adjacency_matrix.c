// Created by think on 2024/8/16.
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

//基于邻接矩阵实现的无向图结构体
typedef struct{
    int vertices[MAX_SIZE];
    int adjMat[MAX_SIZE][MAX_SIZE];
    int size;
}GraphAdjMat;
//构造函数
GraphAdjMat *newGraphAdjMat(){
    GraphAdjMat *graph = (GraphAdjMat*) malloc(sizeof(GraphAdjMat));
    graph->size = 0;
    for (int i = 0; i < MAX_SIZE; ++i) {
        for(int j = 0;j<MAX_SIZE;j++){
            graph->adjMat[i][j] = 0;
        }
    }
    for(int j= 0;j<MAX_SIZE;j++){
        graph->vertices[j] = 0;
    }
    return graph;
}
//析构函数
void delGraphAdjMat(GraphAdjMat *graph){
    free(graph);
}
//查找顶点索引值
int findIndex(GraphAdjMat *graph,int k){
    for(int i = 0;i<graph->size;i++){
        if (graph->vertices[i] == k){
            return i;
        }
    }
    return -1;
}
//添加顶点
void addVertex(GraphAdjMat *graph,int val){
    if(graph->size == MAX_SIZE){
        fprintf(stderr,"图的顶点数量已达最大值\n");
        return;
    }
    //添加第n个顶点,并将第n行n列置零
    int n = graph->size;
    graph->vertices[n] = val;
    for(int i = 0;i<=n;i++){
        //行列置0
        graph->adjMat[n][i] = graph->adjMat[i][n] = 0;
    }
    graph->size++;
}
//删除顶点
void removeVertex(GraphAdjMat *graph,int index){
    if(index<0 || index >= graph->size){
        fprintf(stderr,"顶点索引越界\n");
        return;
    }
    //在顶点列表中移除索引index的顶点
    for(int i = index;i<graph->size -1;i++){
        graph->vertices[i] = graph->vertices[i+1];
    }
    //在邻接矩阵中删除索引index的行
    for(int i = index;i<graph->size-1;i++){
        for(int j = 0;j<graph->size;j++){
            graph->adjMat[i][j] = graph->adjMat[i+1][j];
        }
    }
    //在邻接矩阵中删除索引index的列
    for(int i = 0;i<graph->size;i++){
        for(int j = 0;j<graph->size -1;j++){
            graph->adjMat[i][j] = graph->adjMat[i][j+1];
        }
    }
    graph->size--;
}
//添加边
//参数i,j对应vertices元素索引
void addEdge(GraphAdjMat *graph,int i,int j){
    if(i<0||j<0||i>= graph->size || j>= graph->size||i== j){
        fprintf(stderr,"边索引越界或相等\n");
        return;
    }
    graph->adjMat[i][j] = 1;
    graph->adjMat[j][i] = 1;
}
//删除边
//参数i ,j对应vertices元素索引
void removeEdge(GraphAdjMat *graph,int i,int j){
    if(i<0||j<0||i>= graph->size || j>= graph->size||i== j){
        fprintf(stderr,"边索引越界或相等\n");
        return;
    }
    graph->adjMat[i][j] = 0;
    graph->adjMat[j][i] = 0;
}
//打印数组
void printfArray(int *arr,int size){
    for(int i = 0;i<size;i++){
        printf("\t%d ",arr[i]);
    }
    printf("\n");
}
//打印邻接矩阵
void printGraphAdjMat(GraphAdjMat *graph){
    //printf("顶点列表 = ");
    printfArray(graph->vertices,graph->size);
    //printf("邻接矩阵 = \n");
    for(int i = 0;i<graph->size;i++){
        printfArray(graph->adjMat[i],graph->size);
    }
}
int main(){
    GraphAdjMat *graph = newGraphAdjMat();
    addVertex(graph,3);
    addVertex(graph,5);
    addVertex(graph,6);
    addEdge(graph, findIndex(graph,3), findIndex(graph,6));
    addEdge(graph, findIndex(graph,5), findIndex(graph,6));
    printGraphAdjMat(graph);

    delGraphAdjMat(graph);
    return 0;

}




























