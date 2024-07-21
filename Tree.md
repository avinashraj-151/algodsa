# 1. [Diameter of a tree](https://leetcode.com/problems/diameter-of-binary-tree/description ).
it is longest path between two node (u,v).

# Algorithm for this
choose random node (x)->find the farthest node from that node(y) -> find the farthest node from that node (z).
claim that y and z are the one of the diameter of tree. so it require two dfs.

# my code is 
```
class Solution {
    unordered_map<TreeNode*,int>dep;
    unordered_map<TreeNode*,TreeNode*>parent;
public:
    void dfs(TreeNode* root,int depth,TreeNode* previous){
        if(!root)return;
        dep[root]=depth;
        parent[root]=previous;
        dfs(root->right,depth+1,root);
        dfs(root->left,depth+1,root);
    }
    void dfs1(TreeNode* root,int depth,TreeNode* previous){
        if(!root)return;
        dep[root]=depth;
        if(previous!=parent[root])dfs1(parent[root],depth+1,root);
        if(previous!=root->right)dfs1(root->right,depth+1,root);
        if(previous!=root->left)dfs1(root->left,depth+1,root);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        TreeNode* previous = new TreeNode(-200);
        dfs(root,0,previous);
        TreeNode*y=nullptr;
        int second=-200;
        for(auto&x:dep){
            // cout<<x.first->val<<" "<<x.second<<endl;
            if(second<x.second){
                second=x.second;
                y=x.first;
            }
        }
        dfs1(y,0,previous);
         second=-200;
         for(auto&x:dep){
            // cout<<x.first->val<<" "<<x.second<<endl;
            if(second<x.second && x.first->val!= (-200)){
                second=x.second;
                // y=x.first;
            }
        }
        return second;
    }
};
```
my approach choose a random node and find the depth of node and get that node from that node find the farthest node from that node .
we get the distance of dimaeter of node.

# nice approach  could be 
maintain a maximumdimeter and find the max length of right and max length of left and compare with maximumdimeter.
```
class Solution {
public:
    int dfs(TreeNode* root,int &maxd){
        if(!root)return 0;
        int r=dfs(root->right,maxd);
        int l=dfs(root->left,mxd);
        maxd=max(maxd,r+l);
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
       int maxd=0;
       dfs(root,maxd);
       return maxd;
    }
};
```
