#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 根据数组构造二叉树
TreeNode* construct_binary_tree(const vector<int>& vec) {
    vector<TreeNode*> vecTree(vec.size(), NULL);
    TreeNode* root = NULL;
    for (int i = 0; i < vec.size(); i++) {
        TreeNode* node = NULL;
        if (vec[i] != -1) node = new TreeNode(vec[i]);
        vecTree[i] = node;
        if (i == 0) root = node;
    }
    for (int i = 0; i * 2 + 2 < vec.size(); i++) {
        if (vecTree[i] != NULL) {
            vecTree[i]->left = vecTree[i * 2 + 1];
            vecTree[i]->right = vecTree[i * 2 + 2];
        }
    }
    return root;
}

// 层序打印打印二叉树
void print_binary_tree(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != NULL) que.push(root);
    vector<vector<int>> result;
    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            if (node != NULL) {
                vec.push_back(node->val);
                que.push(node->left);
                que.push(node->right);
            }
            // 这里的处理逻辑是为了把null节点打印出来，用-1 表示null
            else vec.push_back(-1);
        }
        result.push_back(vec);
    }
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        deque<TreeNode*> dque;
        vector<vector<int>> vec;
        dque.push_back(pRoot);
        if(pRoot==NULL)return vec;
        int count=0;
        
        while(!dque.empty())
        {
            int size=dque.size();
            vector<int> veci;
            if(count%2==1)
            {
                for(int i=0;i<size;i++)
             {
                TreeNode* node=dque.front();
                dque.pop_front();
                veci.push_back(node->val);
                if(node->left)dque.push_back(node->left);
                if(node->right)dque.push_back(node->right);                                                
              }
            }
            else{
                for(int i=0;i<size;i++)
             {
                TreeNode* node=dque.back();
                dque.pop_back();
                veci.push_back(node->val);
                if(node->left)dque.push_front(node->left);
                if(node->right)dque.push_front(node->right);                                                
              }
            vec.push_back(veci);
                                              
                                              
            }
            return vec;
            
            
            
        }
    }
    
};



// class Solution {
// public:
//     int count=0;
//     vector<vector<int> > Print(TreeNode* pRoot) {
        
//         queue<TreeNode*> que;
//         que.push(pRoot);
//         vector<vector<int>> vec;
//         if(pRoot==NULL) return vec;        
        
//         while(!que.empty())
//         {
//             count+=1;
//             int size=que.size();
//             vector<int> veci;
//             if(count%2==1)
//             {
//                 for(int i=0;i<size;i++)
//                 {
//                     TreeNode* node=que.front();
//                     que.pop();
//                     veci.push_back(node->val);
//                     if(node->left)que.push(node->left);
//                     if(node->right)que.push(node->right);
//                 }
//             }
//             else{
//                 for(int i=size-1;i>=0;i--)
//                 {
//                     TreeNode* node=que.front();
//                     que.pop();
//                     veci.push_back(node->val);    
                    
//                     if(node->left)que.push(node->left);
//                     if(node->right)que.push(node->right);
//                 }
//                 reverse(begin(veci), end(veci));                
//             }
//              vec.push_back(veci);
            
//         }
//         return vec;     
        
//     }
    
// };


int main() {
    // 注意本代码没有考虑输入异常数据的情况
    // 用 -1 来表示null
    vector<int> vec = {1,2,3,-1,-1,4,5};
    TreeNode* root = construct_binary_tree(vec);
    //print_binary_tree(root);

    Solution s1;
    //s1.Print(root);
     reverse(begin(vec), end(vec));
     int a=0;

    system("pause");
    return 0;
}