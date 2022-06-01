#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    /**
     * 解码
     * @param nums string字符串 数字串
     * @return int整型
     */
    int solve(string nums) {
        // write code here
        if(nums=="0")return 0;
        if(nums=="10"||nums=="20")return 1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]=='0'&&nums[i-1]>'2')return 0;

        }
        
        vector<int> dp(nums.size()+1,1);
        dp[0]=0;
        
        for(int i=2;i<nums.size();i++)
        {
            if(nums[i]!='0'&&nums[i-1]=='1'||nums[i-1]=='2'&&nums[i]<'7')
            {
                dp[i]=dp[i-1]+dp[i-2];
            }
            else
            {
                dp[i]=dp[i-1];
            }

        }
        return dp[nums.size()];
    }
};
int main() {

    string nums="101";
    
    Solution s1;
    cout<<s1.solve(nums)<<endl;


    system("pause"); 
    return 0;
}




