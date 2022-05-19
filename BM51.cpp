#include <iostream>
#include <vector>
#include <queue>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        unordered_map<int,int> map;
        for(int i=0;i<numbers.size();i++)
        {
            map[numbers[i]]++;
        }
        int res=0;
        for(auto it:map)
        {
            if(it.second>numbers.size()/2)res=it.first;
        }
       return res;
    }
};


int main() {
    vector<int> a={1,2,3,2,2,2,5,4,2};
    Solution s1;
    cout<<s1.MoreThanHalfNum_Solution(a)<<endl;

    system("pause");
    return 0;
}