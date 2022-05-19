#include<iostream>
//#include<string>  
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;


class solution
{
public:
    int findMaxForm(vector<string>& strs,int m,int n)
    {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(string str:strs)
        {
            int zeroNum=0,oneNum=0;
            for(char c:str)
            {
                if(c=='1')oneNum++;
                else zeroNum++;
            }            
        for(int i=m;i>=zeroNum;i--)
        {
            for(int j=n;j>=oneNum;j--)
            {
                dp[i][j]=max(dp[i][j],dp[i-zeroNum][j-oneNum]+1);
            }
        }
        }
        return dp[m][n];
        
    }
};


int main()
{
    solution s1;
    vector<string> strs={"10", "0001", "111001", "1", "0"};
    int m=5,n=3;
    cout<<s1.findMaxForm(strs,m,n)<<endl;


	system("pause");
    return 0;
}

