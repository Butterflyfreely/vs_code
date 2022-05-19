#include<iostream>
//#include<string>  
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;


void test()
{
    vector<int> weight={1,2,3};
    vector<int> value={15,20,30};
    int bagSize=4;
    vector<int> dp(bagSize+1,0);

    for(int i=0;i<weight.size();i++)//先遍历物品
    {
        for(int j=weight[i];j<=bagSize;j++)//再遍历背包容量
        {
            dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }
    cout<<dp[bagSize]<<endl;
}

int main()
{    
    //int a[5] = { 9,3, 15, 20, 7 };
    test();
	system("pause");
    return 0;
}

