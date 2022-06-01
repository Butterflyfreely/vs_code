#include <iostream>
#include <vector>
#include <queue>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& arr) {
        // write code here
        unordered_map<int,int> map;
        int max1=0;        
        
        for(int i=0;i<arr.size();i++)
        {
            for(int j=i;j<arr.size();j++)
            {
                map[arr[j]]++;
                if(map[arr[j]]>1)
                {
                    max1=max(max1,j-i);
                    map.clear();
                    break;
                }
                if(j==arr.size()-1)max1=max(max1,j-i);

            }        
        }
           
        return max1;
    }
};

int main() {

    vector<int> vec={2,3,4,5};
    int target=8;
    Solution s1;
    s1.maxLength(vec);

    system("pause"); 
    return 0;
}









