#include <iostream>
#include <vector>
#include <queue>
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


// class Solution {
// public:
//     int rob(TreeNode* root) {
//         if(root==NULL)return 0;
//         vector<int> vec;
//         queue<TreeNode*> que;
//         que.push(root);

//         while(!que.empty())
//         {            
//             int size=que.size();
//             int row=0;            
//             for(int i=0;i<size;i++)
//             {
//                 TreeNode* node=que.front();
//                 que.pop();
//                 if(node->val!=-1)row+=node->val;                
//                 if(i==size-1)vec.push_back(row);
//                 if(node->left)que.push(node->left);
//                 if(node->right)que.push(node->right);
//             }            
//         }
//         if(vec.size()==1)return vec[0];
//         vector<int> dp(vec.size(),0);
//         dp[0]=vec[0];
//         dp[1]=max(vec[0],vec[1]);
//         for(int i=2;i<vec.size();i++)
//         {
//             dp[i]=max(dp[i-1],dp[i-2]+vec[i]);
//         }
//         return dp[vec.size()-1];
//     }
// };

class Solution {
public:
    int rob(TreeNode* root) {
        if(root==NULL)return 0;
        if(root->left==NULL&&root->right==NULL)return root->val;

        //抢孙子节点
        int x1=root->val;
        if(root->left) x1+=rob(root->left->left)+rob(root->left->right);
        if(root->left) x1+=rob(root->right->left)+rob(root->right->right);

        //抢子节点
        int x2=rob(root->left)+rob(root->right);

        return max(x1,x2);
    }
};


int main() {
    // 注意本代码没有考虑输入异常数据的情况
    // 用 -1 来表示null
    vector<int> vec = { 2,1,3,-1,4 };
    TreeNode* root = construct_binary_tree(vec);
    print_binary_tree(root);
    cout<<endl;
    cout<<endl;
    cout<<endl;

    Solution s1;    
    cout<<s1.rob(root)<<endl;    
    system("pause");
    return 0;
}



