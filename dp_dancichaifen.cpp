
#include<iostream>
//#include<string>  
#include<queue>
#include<vector>
#include<unordered_set>

using namespace std;

class solution
{
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(),wordDict.end());
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;

        for(int i=1;i<=s.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                string str=s.substr(j,i-j);
                if(set.find(str)!=set.end()&&dp[j])
                {
                    dp[i]=true;
                }
            }
        }
        return dp[s.size()];
    }
};

int main()
{
    solution s1;
    string s="leetcode";
    vector<string> wordDict={"leet","code"};    
    cout<<s1.wordBreak(s,wordDict)<<endl;

	system("pause");
    return 0;
}




