#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int size=nums.size();
        vector<int> result;
        if(size==0)
        {
            result={-1,-1};
            return result;
        }

        int  first=findfirst(nums,target);
        if(first==-1)
        {
            result={-1,-1};
            return result;
        }

        int last=findlast(nums,target);
        result={first,last};
        return result;      

    }

    int findfirst(vector<int>& vec,int target)
        {
            int left=0,right=vec.size()-1;
            
            while(left<right)
            {
                int mid=(left+right)/2;
                if(vec[mid]<target)
                {
                    right=mid-1;
                }
                else if(vec[mid]==target)
                {
                    right=mid;
                }
                else{
                    //vec[mid]>target
                    left=mid+1;
                }
            }
            if(vec[left]==target)return left;
            return -1;
        }

    int findlast(vector<int>& vec,int target)
        {
            int left=0,right=vec.size()-1;
            
            while(left<right)
            {
                int mid=(left+right+1)/2;
                if(vec[mid]<target)
                {
                    right=mid-1;
                }
                else if(vec[mid]==target)
                {
                    left=mid;
                }
                else{
                    //vec[mid]>target
                    left=mid+1;
                }
            }
            return left;
        }

};

int main() {

    vector<int> vec={5,7,7,8,8,10};
    int target=8;
    Solution s1;
    vector<int> ret=s1.searchRange(vec,target);
    for(int i=0;i<ret.size();i++)
    {
        cout<<ret[i]<<" ";
    }
    cout<<endl;

    system("pause");
    return 0;
}