#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
        return root;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node= q.front();
            q.pop();
            swap(node->left,node->right);
            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);
        }
        return root;
    }
};
int main(){
    cout<<"Hello World"<<endl;
    int n;
    cin>>n;
    cout<<n;
    return 0;
}