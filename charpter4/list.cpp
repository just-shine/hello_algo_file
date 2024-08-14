#include<iostream>
#include<vector>

using namespace std;
int main(){
    vector<int> nums1;
    nums1.clear();
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.insert(nums1.begin()+2,6);
    for (size_t i = 0; i < nums1.size(); i++)
    {
        cout<<nums1[i]<<endl;
    }
 
    return 0;
}
