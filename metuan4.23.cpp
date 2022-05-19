#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>


using namespace std;

int main()
{
	int N;
    cin>>N;
    string str;
    cin>>str;
    char a='C',b='J';
    unordered_map<char,int> map;
    for(int i=0;i<str.size();i++)
        {
            map[str[i]]++;
        }
    
    int k=150,count=0;
    if(N==1)cout<<0;
    else if(N==2&&str[0]!=str[1])cout<<0;
    else if(N==2&&str[0]==str[1])cout<<-1;
    else
        {            
        while(k--)
        {
            
            for(int i=0;i<N-2;i++)
                {
                    if(str[i]==str[i+1]&&str[i+1]!=str[i+2]) {
                        swap(str[i+1],str[i+2]);  
                        count++;
                    }                 
                } 
        }
        if(abs(map[a]-map[b])>1)
            {
                cout<<-1;
                
            }
            else{
                cout<<count;
            }
    
        }

    system("pause");
	return 0;
}


// #include<iostream>
// //#include<string>  
// #include<queue>
// #include<vector>
// #include<unordered_map>
// #include<stack>
// using namespace std;


// int main()
// {
//     string str;
//     stack<string> stk;
//     unordered_map<string,int> map={ {"true",1}, {"false",0} };

//     while(cin>>str)
//     {
//         if(str=="and")
//         {
//             string a=stk.top();
//             stk.pop();
//             cin>>str;
//             if(map[a]&&map[str]==1)
//             {
//                 stk.push("true");
//             }
//             else{
//                 stk.push("false");
//             }            
//         }
//         else if(str!="or")
//         {
//             stk.push(str);
//         }
        
//     }
//     bool bo=map[stk.top()];
//     stk.pop();
//     while(!stk.empty())
//     {
//         bo=map[stk.top()]||bo;
//     }
//     if(bo==true)
//     {
//         cout<<"true";
//     }
//     else if(bo==false)
//     {
//         cout<<"false";
//     }
//     else{
//         cout<<"error";
//     }
     
// 	system("pause");
//     return 0;
// }




















//.......................................................1111
// #include<iostream>
// #include<string>
// #include<vector>

// using namespace std;

// class Solution
// {
// public:
//     vector<int> partitionLabels(string S)
//     {
//         int hash[27]={0};
//         for(int i=0;i<S.size();i++){
//             hash[S[i]-'a']=i;
//         } 
                                    
//     vector<int> result;
//         int left=0;
//         int right=0;
//         for(int i=0;i<S.size();i++)
//         {
//             right=max(right,hash[S[i]-'a']);
//             if(i==right){
//                 result.push_back(right-left+1);
//                 left=i+1;
//             }
//         }
//         return result;        
//     }
    
    
// };

// int main()
// {    
//     string S;
//     cin>>S;
//     Solution s1;
//     vector<int> aaa;
//     aaa=s1.partitionLabels(S);
//     for(int i=0;i<aaa.size();i++)
//     {
//         cout<<aaa[i];
//     }
//     return 0;
// }