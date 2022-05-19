#include<iostream>
//#include<string>  
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

void test()
{
    vector<int> val = { 15,20,35 };
    vector<int> weight = { 1,3,4 };
    int bagweight = 4;


    //初始化
    vector<int> dp(bagweight + 1, 0);

    for (int i = 0; i < weight.size(); i++)
    {
        for (int j = bagweight; j >= weight[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - weight[i]] + val[i]);
        }
    }

    cout << dp[bagweight-1] <<endl;
}



int main()
{
    test();
    //cout<<"hello world"<<endl;
    system("pause");
    return 0;
}

