#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val):val(val), next(nullptr){}
};


class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write code here
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        
        ListNode* pre=dummy;
        for(int i=0;i<m-1;i++)
        {
            pre=pre->next;
        }
        ListNode* left=pre->next;
        
         ListNode* right=pre;      
        for(int j=0;j<n-m+1;j++)
        {
            right=right->next;
        }
        ListNode* cur= right->next;
        
        //切断链接
        pre->next=NULL;
        right->next=NULL;
        
        //反转链表
        reverseLinkedList(left);
        
        //连接链表
        left->next=cur;
        pre->next=right;
        
        
        return dummy->next;       
        
    }
private:  
    void reverseLinkedList(ListNode* head)
        {
            ListNode* pre=NULL;
            ListNode* cur=head;
            while(cur!=NULL)
            {
                ListNode* cur_next=cur->next;
                cur->next=pre;
                pre=cur;
                cur=cur_next;                
            }
            
        }
};


int main() {
    Solution s1;

    //新建一个链表
    vector<int> vec={1,2,3,4,5};       
    ListNode* dummy=new ListNode(0);  
    ListNode* head=new ListNode(vec[0]); 
    dummy->next=head; 
    for(int i=0;i<vec.size()-1;i++)
    {
        head->next=new ListNode(vec[i+1]);
        head=head->next;
    } 


    // head->next=new ListNode(2);
    // head=head->next;
    // head->next=new ListNode(3);
    // head=head->next;
    // head->next=new ListNode(4);
    // head=head->next;
    // head->next=new ListNode(5);  

    s1.reverseBetween(dummy->next,2,4);

    //输出链表
    for(int i=0;i<vec.size();i++)
    {
        cout<<dummy->next->val<<" ";
        dummy=dummy->next;
    }

    system("pause");
    return 0;
}
