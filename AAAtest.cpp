#include <iostream>
#include<vector>
#include<unordered_map>
#include <algorithm>

using namespace std;

int main() {
	int N=0;
	cin>>N;
	vector<vector<int>> vec(N+1,vector<int>(N+1,0));
	for(int i=0;i<N;i++)
	{
		int a=0,b=0,c=0;
		cin>>a;
		cin>>b;
		cin>>c;
		vec[a][b]=c;
	}
    int result=0;

//1、dp[i][j]表示在此处能获得的最大法力值
//2、递推公式dp[i][j]=max(dp[i][j-1]+vec[i][j],dp[i-1][j]+vec[i][j])
//3、遍历顺序
//4、初始化
//5、举例试试
	vector<vector<int>> dp(N+1,vector<int>(N+1,0));

	unordered_map<int,pair<int,int>> map;
	//dp[0][0]=vec[0][0];
	for(int i=1;i<N+1;i++)
	{
		for(int j=1;j<N+1;j++)
		{
			dp[i][j]=max(dp[i][j-1]+vec[i][j],dp[i-1][j]+vec[i][j]);
			if(map.count(dp[i][j]))
			{

			}
			else
			{
				map[dp[i][j]].first=i;
				map[dp[i][j]].second=j;
			}

		}
	}

	result+=dp[N][N];
	
	vector<int> find;
	for(auto it:map)
	{
		find.push_back(it.first);
	}

	sort(find.begin(),find.end());

	vec[map[find[find.size()-1]].first][map[find[find.size()-1]].second]=0;
	int k=find.size()-1,p=find.size()-1;

	for(int oo=find.size()-2;oo>=0;oo--)
	{
		if(map[find[oo]].first<k&&map[find[oo]].first<p)
		{
			vec[map[find[oo]].first][map[find[oo]].first<p]=0;
			k=map[find[oo]].first;
			p=map[find[oo]].first;
		}
	}



	vector<vector<int>> dp1(N+1,vector<int>(N+1,0));
		for(int i=1;i<N+1;i++)
	{
		for(int j=1;j<N+1;j++)
		{
			dp1[i][j]=max(dp[i][j-1]+vec[i][j],dp[i-1][j]+vec[i][j]);
		}
	}

 result+=dp1[N][N];
	


// 5
// 1 1 5
// 1 3 6
// 2 5 6
// 4 2 13
// 5 1 5
// 0 0 0
//30



// 7
// 2 1 12
// 2 5 8
// 2 6 6
// 3 3 5
// 4 3 13
// 6 6 5
// 7 2 1
// 0 0 0
// 49


    

	//int k=49;
	cout<<result<<endl;

   system("pause");
}