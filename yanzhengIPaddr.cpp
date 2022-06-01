#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;


class Solution {
public:
    bool is_corr_IPv4(string& str)
    {
        int id=0;
        for(int i=0;i<3;i++)
        {
            int j=id;
            string single;
            while(str[id]!='.')
            {
                id++;                             
            }
            single=str.substr(j,id-j);
            if(single.size()>=2&&single[0]=='0')return false;
            if(single<"0"||single>"255")return  false; 
            id++;
        }
        string finnal=str.substr(id);
        if(finnal<"0"||finnal>"255"||id<str.size()-1)return false;
        else return true;        
    }
    
    bool is_corr_IPv6(string& str)
    {
        //转为小写
        for(int i=0;i<str.size();i++)
        {
            str[i]=tolower(str[i]);
        }

        //判断
        int id=0;
        for(int i=0;i<7;i++)
        {
            int j=id;
            string single;
            while(str[id]!=':')
            {
                id++;                             
            }
            single=str.substr(j,id-j);            
            if(single<"0"||single>"ffff")return  false; 
            id++;
        }
        string finnal=str.substr(id);
        if(finnal<"0"||finnal>"ffff")return false;
        else return true;  
    }

    string solve(string IP) {
        // write code here
        //判断是IPv4还是IPv6
        int i=0;
        bool isIPv4=false,isIPv6=false;
        while(IP[i]!='.'&&IP[i]!=':')
        {
            i++;
        }
        if(IP[i]=='.')isIPv4=is_corr_IPv4(IP);
        else isIPv6=is_corr_IPv6(IP);   
        if(isIPv4==true)return "IPv4";
        else if(isIPv6==true)return "IPv6";
        else return "Neither";        
    }
};

int main() {
    string str="2001:0db8:85a3:0:0:8A2E:0370:7334";//"2001:0db8:85a3:0:0:8A2E:0370:7334"   "172.01.254.1"
    Solution s1;
    cout<<s1.solve(str);

    //system("pause"); 
    return 0;
}




