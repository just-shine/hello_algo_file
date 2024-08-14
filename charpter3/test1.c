#include<stdio.h>

int main(){
    float toobig = 3.4E38*100.0f;
    printf("%e\n",toobig);//值过大 输出inf
    


    return 0;
}