#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    string trans(string s, int n) {
        // write code here
        for(int i=0;i<n;i++)
        {
            if(s[i]-'a'>=0&&s[i]!=' ')
            {
                s[i]=toupper(s[i]);
            }
            else if(s[i]-'a'<0&&s[i]!=' ')
            {
                s[i]=tolower(s[i]);
            }
        }
        string res="";
        
        for(int i=n-1;i>=0;i--)
        {
            int k=i;
            while(s[i]!=' '&&i>=0)
            {
                i--;
            }
            string a=s.substr(i+1,k-i); 
            res+=a;
            res+=' ';
        }
        return res.substr(0,n);      
        
    }
};

int main() {
    string str="This is a sample";
    int target=16;
    Solution s1;
     s1.trans(str,target);
    //cout<<str[0]-'a'<<endl;

    //system("pause"); 
    return 0;
}










