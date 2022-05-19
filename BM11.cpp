#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val):val(val), next(nullptr){}
};


//核心算法
class Solution {
public:
    
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        if(head==NULL)return head;
        ListNode* left=head;
        ListNode* right=head->next;
        
        while(right!=NULL)
        {
            if(right->next!=NULL&&left->val==right->val)
            {
                right=right->next;
            }
            else
            {
                left->next=right;
                left=right;
                right=right->next;
            }
        }
        return head;
    }
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



int main()
 {
    Solution s1;

    //新建一个链表
    vector<int> vec1={1,2,2}; 
    vector<int> vec2={1,3,2,5,0,6,0,2,1,4,3,9,3,0,9,9,0,3,1,6,5,7,8,6,2,3,8,5,0,9,7,9,4,5,9,9,4,9,3,6}; 
    ListNode* head1=NewNodeList(vec1);    
    ListNode* head2=NewNodeList(vec2);  
    ListNode* aaa=s1.deleteDuplicates(head1);

    // //打印链表
    // for(int i=0;i<vec.size();i++)
    // {
    //     cout<<head->val<<" ";
    //     head=head->next;
    // }

    system("pause");
    return 0;
}
