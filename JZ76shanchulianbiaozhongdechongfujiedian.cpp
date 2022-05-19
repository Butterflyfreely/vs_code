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
    ListNode* deleteDuplication(ListNode* pHead) {
        if(pHead==NULL||pHead->next==NULL)return pHead;
        //if(pHead==pHead->next)return NULL;
        ListNode* dummy=new ListNode(0);
        ListNode* pre=dummy;
        ListNode* front=pHead;
        ListNode* rear=pHead->next;
        dummy->next=pHead;             
        
        while(rear!=NULL)
        {
            if(front->val==rear->val)
            {
                while(front->val==rear->val)
                {
                    rear=rear->next;
                }
                front=rear;
                pre->next=front;
                rear=rear->next;
            }
            else{
                front=front->next;
                 rear=rear->next;
                pre=pre->next;
            }
            
        }
        return dummy->next;        
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



int main() {
    Solution s1;

    //新建一个链表
    vector<int> vec={1,1}; 
    ListNode* head=NewNodeList(vec);    

    ListNode* aaa=s1.deleteDuplication(head);

    //打印链表
    while(aaa!=NULL)
    {
        cout<<aaa->val<<" ";
        aaa=aaa->next;
    }

    system("pause");
    return 0;
}
