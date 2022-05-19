//#include <bits/stdc++.h>
#include<unordered_map>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
//#include<>

using namespace std;


unordered_map<int,vector<int>> map={
          //{1,{1,2,3,4,5,6,7}},
            {1,{0,0,1,0,0,1,0}},
            {2,{1,0,1,1,1,0,1}},
            {3,{1,0,1,1,0,1,1}},
            {4,{0,1,1,1,0,1,0}},
            {5,{1,1,0,1,0,1,1}},
            {6,{1,1,0,1,1,1,1}},
            {7,{1,0,1,0,0,1,0}},
            {8,{1,1,1,1,1,1,1}},
            {9,{1,1,1,1,0,1,1}},
            {0,{0,0,0,0,0,0,0}}
        }; 

int result(string str)
{
     vector<int> vec={0,0,0,0,0,0,0,0};
    int count=0;
    
    for(int i=0;i<str.size();i++)
    {
        int num=stoi(str.substr(i,1));
        vector<int> vec1=map[num];
        int liang=0;
        int mie=0;
        for(int j=0;j<7;j++)
        {
            if(vec[j]==0&&vec1[j]==1)
            {
                liang++;
                vec[j]=1;                
            }
        }

        for(int k=0;k<7;k++)
        {
            if(vec[k]==1&&vec1[k]==0)
            {
                mie++;
                vec[k]=0;
            }
        }
        count=count+liang+mie;
    }
    return count;

}

int main()
{  
    string str;
    cin>>str;

    int kk=result(str); 

    cout<<kk;
    
    system("pause");
    return 0;
}