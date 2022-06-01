#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

struct Interval {
      int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
  };
 
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
       
        static bool cmp(Interval& a,Interval& b)
        {
            return a.start<b.start;
        }
    vector<Interval> merge(vector<Interval> &intervals) {
        
        vector<Interval> res;
        int i=0;     
        if(intervals.size()==0)return res;
        
         //先将区间排序
        sort(intervals.begin(),intervals.end(),cmp);
        
        int size=intervals.size();
        bool index=false;

        for(int i=1;i<size;i++)
        {
            int start=intervals[i-1].start;
            int end=intervals[i-1].end;
            while(i<size&&intervals[i].start<end)//不断更新区间
            {
                end=max(end,intervals[i].end);
                if(i==size-1)index=true;//是否合并了最后一个区间
                i++;
            }
            res.push_back(Interval(start,end));
        }
        
        if(index==false)res.push_back(intervals[size-1]);        
        
        return res;
        //res.push_back();
    }
};

int main() {

    vector<Interval> aaa={{10,20},{0,10}};
    Solution s1;
    vector<Interval> kkk=s1.merge(aaa);

    system("pause"); 
    return 0;
}