#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val):val(val), next(nullptr){}
};


//核心算法
class Solution 
{
public:



};


//根据数组新建一个链表
ListNode* NewNodeList(vector<int> vec)
{
    if(vec.size()==0)
    {
        cout<<"链表不存在"<<endl;
        return nullptr;
    }
    ListNode* dummy=new ListNode(0);  
    ListNode* head=new ListNode(vec[0]); 
    dummy->next=head; 
    for(int i=0;i<vec.size()-1;i++)
    {
        head->next=new ListNode(vec[i+1]);
        head=head->next;
    } 
    return dummy->next;
}



int main() {
    Solution s1;

    //新建一个链表
    vector<int> vec={1,2,3,4,5}; 
    ListNode* head=NewNodeList(vec);    

    //打印链表
    for(int i=0;i<vec.size();i++)
    {
        cout<<head->val<<" ";
        head=head->next;
    }

    system("pause");
    return 0;
}
