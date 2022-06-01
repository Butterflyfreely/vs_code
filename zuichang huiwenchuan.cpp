#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    int getLongestPalindrome(string A) {
        // write code here
        int max1=1;
        vector<int> dp(A.size()+1,1);
        
        for(int i=0;i<A.size();i++)
        {
            int left=i,right=i;
            while(left>=0&&right<A.size())
            {
                if(A[left]==A[right])
                {
                    max1=max(max1,right-left+1); 
                    left--;right++;                   
                }
                else{
                    break;                  
                }
            }
            
        }
        return max1;
    }
};

int main() {

    string A="abbba";
    Solution s1;
    cout<<s1.getLongestPalindrome(A)<<endl;

    system("pause"); 
    return 0;
}


