#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val (x),left(NULL),right(NULL){}
};

TreeNode* construct(const vector<int>& vec)
{
    vector<TreeNode*> vectree(vec.size(),NULL);
    TreeNode* root=NULL;
    for(int i=0;i<vec.size();i++)
    {
        TreeNode* node=NULL;
        if(vec[i]!=-1)node=new TreeNode(vec[i]);
        vectree[i]=node;
        if(i==0)root=node;
    }

    for(int i=0;i*2+2<vec.size();i++)
    {
        if(vectree[i]!=NULL)
        {
            vectree[i]->left=vectree[i*2+1];
            vectree[i]->right=vectree[i*2+2];
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

int main()
{
    vector<int> vec={1,2,3,4,5,-1,6};
    TreeNode* root=construct(vec);
    print_binary_tree(root);


   // int a=0;
    system("pause");
    return 0;
}