#include<iostream>
//#include<string>  
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;


class solution
{
public:

int wordBreak() {
    vector<int> weight={1,3,4};
    vector<int> val={15,20,30};
    vector<int> num={2,3,2};
    int bagSize=10;

    vector<int> dp(bagSize+1,0);

    //展开物品
    for (int k=0;k<weight.size();k++)
    {
        while(num[k]>1)
        {
            weight.push_back(weight[k]);
            val.push_back(val[k]);
            num[k]--;
        }
    }

    for(int i=0;i<weight.size();i++)
    {
        for(int j=bagSize;j>=weight[i];j--)
        {
            dp[j]=max(dp[j],dp[j-weight[i]]+val[i]);
        }
        for (int j = 0; j <= bagSize; j++) {
            cout << dp[j] << " ";
        }
        cout << endl;
    }
    return dp[bagSize];
}
};


int main()
{
    solution s1;
    cout<<s1.wordBreak()<<endl;
    


	system("pause");
    return 0;
}

