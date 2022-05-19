#include <iostream>
#include <vector>
#include<stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val):val(val), next(nullptr){}
};


//核心算法
class Solution {
  public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head==NULL||k<=1)return head;
        stack<ListNode*> stk;

        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* dummy1=new ListNode(0);
        dummy1->next=dummy;
        
        int num=0;
        while(head!=NULL)
        {
            num++;
            head=head->next;
        }

        
        for(int i=0;i<k;i++)
        {
            stk.push(head);
            head=head->next;
        }
        
        for(int i=0;i<k;i++)
        {
            dummy->next=stk.top();
            stk.pop();
            dummy=dummy->next;
        }
      
        return dummy1->next->next;
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
    
    //新建一个链表
    vector<int> vec={1,2}; 
    ListNode* head=NewNodeList(vec);    

    //求解
    Solution s1;
    ListNode* aa=s1.reverseKGroup(head,2);


    //打印链表
    for(int i=0;i<vec.size();i++)
    {
        cout<<aa->val<<" ";
        aa=aa->next;
    }

    system("pause");
    return 0;
}



// //核心算法
// class Solution {
//   public:
//     /**
//      *
//      * @param head ListNode类
//      * @param k int整型
//      * @return ListNode类
//      */
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         // write code here

//         if(k <= 1) return head;
//         if(head == NULL) return head;
//         //寻找左指针
//         ListNode* dummy=new ListNode(0);
//         dummy->next=head;
        
//         int num=0;
//         while(head!=NULL)
//         {
//             num++;
//             head=head->next;            
//         }
        
//         int N=num/k;
        
//         ListNode* pre=dummy;
//         for(int i=0;i<N;i++)
//         {
//             ListNode* left=pre->next;
//             int j=k-1;
//             ListNode* right=left;
//             while(j--)
//             {
//                 right=right->next;
//             }
//             ListNode* cur=right->next;
//             pre->next=NULL;
//             right->next=NULL;
//             reverseNodeList(left);
//             //连接
//             pre->next=right;
//             left->next=cur;
//             pre=left;
//         }
//        return dummy->next;

//     }
    
// private:
//     void reverseNodeList(ListNode* head)
//     {
//         ListNode* pre=NULL;
//         ListNode* cur=head;
//         while(cur!=NULL)
//         {
//             ListNode* cur_next=cur->next;
//             cur->next=pre;
//             pre=cur;
//             cur=cur_next;
//         }        
//     }
// };