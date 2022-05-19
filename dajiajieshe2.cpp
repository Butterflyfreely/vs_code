#include<iostream>
//#include<string>  
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)return 0;
        if(nums.size()==1)return nums[0];
        return max(dajiajieshe(nums,0,nums.size()-2),dajiajieshe(nums,1,nums.size()-1));
    }

    int dajiajieshe(vector<int>& nums,int start,int end)
    {
        if(start==end)return nums[start];
        vector<int> dp(nums.size(),0);
        dp[start]=nums[start];
        dp[start+1]=max(nums[start],nums[start+1]);
        for(int i=start+2;i<=end;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[end];
    }
};


int main()
{
    Solution s1;
    
    int a[5] = { 9,3, 15, 20, 7 };
    


	system("pause");
    return 0;
}



