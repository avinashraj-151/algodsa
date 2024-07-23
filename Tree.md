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
# center of a tree
All dimeter having same center.center can't be more than 2
ALL dimeter passes through all center.

# approach 
 1. we need to find the diameter of tree (we solve earlier)
 2. find the path between to need and find the mid of path if odd then one center node if even then 2 center.

Not exact similar but this is similar question [ find the path between the two node ]( https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another)

# code for above problem 
```
class Solution {
    //need to find the parent 
    vector<TreeNode*>par;
    string ans;
    TreeNode*y=nullptr;
public:
    void parent(TreeNode*root,TreeNode*previous,int startvalue){
        if(!root)return;
        if(startvalue==root->val)y=root;
        par[root->val]=previous;
        parent(root->right,root,startvalue);
        parent(root->left,root,startvalue);
    }
    int dfs(TreeNode*root,TreeNode*previous,int destvalue){
        if(!root)return 0;
        if(root->val == destvalue)return 1;
        if(previous!=par[root->val] && par[root->val]!=nullptr){
            ans.push_back('U'); 
            if(!dfs(par[root->val],root,destvalue)){
                ans.pop_back();
            }else{
                return 1;
            }
        }
         if(previous!=root->right){
              ans.push_back('R');
            if(!dfs(root->right,root,destvalue)){
            
                ans.pop_back();
            }else{
                return 1;
            }
        }
        if(previous!=root->left){
            ans.push_back('L');
            if(!dfs(root->left,root,destvalue)){
                ans.pop_back();
            }else{
                return 1;
            }

        }
        return 0;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        par.resize(1000001, nullptr); 
        parent(root,nullptr,startValue);
        dfs(y,nullptr,destValue);
        return ans;
    }
};
```
#centorid 
Centroid means that if we select a node then all subtree is less than equal to n/2 .
 





























