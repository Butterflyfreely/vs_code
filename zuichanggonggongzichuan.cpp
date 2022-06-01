#include<iostream>
#include<string>
#include<vector>


using namespace std;

class Solution {
public:
    
    string LCS(string str1, string str2) {
        // write code here
        
        int maxlenth=0;//记录最长公共子串长度
        int maxlastIndex=0;
        
        vector<vector<int>> dp(str1.size()+1,vector<int>(str2.size()+1));
        
        for(int i=0;i<str1.size();i++)
        {
            for(int j=0;j<str2.size();j++)
            {
                if(str1[i]==str2[j])
                {
                    dp[i+1][j+1]=dp[i][j]+1;
                    if(dp[i+1][j+1]>maxlenth)
                    {
                        maxlenth=dp[i+1][j+1];
                        maxlastIndex=i;
                    }
                }               
                 else{
                        dp[i+1][j+1]=0;
                    }
            }            
        }
        return str1.substr(maxlastIndex-maxlenth+1,maxlenth);
        
    }
};



int main()
{
    string str1="1AB2345CD";
    string str2="12345EF";
    Solution s1;
    cout<<s1.LCS(str1,str2);


    system("pause");
}