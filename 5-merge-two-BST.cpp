#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };
    void inorder(TreeNode<int> *root,vector<int> &in)
{
    if(root==NULL)
    {
       return ; 
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
vector<int> mergeArrays(vector<int> a,vector<int> b)
{
    vector<int> ans(a.size() + b.size());
    
    int i=0,j=0,k=0;
    
    while(i<a.size() && j<b.size())
    {
        if(a[i]<b[j])
        {
            ans[k++] = a[i++];
        }
        else
        {
            ans[k++] = b[j++];
        }
    }
    while(i<a.size())
    {
        ans[k++] = a[i++];
    }
    while(j<b.size())
    {
        ans[k++] = b[j++];
    }
   return ans; 
}
TreeNode<int>* inorderTOBST(int s,int e,vector<int>& in)
{
    // base case
    if(s>e)
    {
        return NULL;
    }
    int mid = s+(e-s)/2;
    TreeNode <int>* root = new TreeNode<int>(in[mid]);
    root->left = inorderTOBST(s,mid-1,in);
    root->right = inorderTOBST(mid+1,e,in);
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // step 1: store inorder 
    vector <int> bst1,bst2; 
    inorder(root1,bst1);
    inorder(root2,bst2);
    
    //step 2: MERGE BOTH SORTED arrays
    vector<int> mergedArray = mergeArrays(bst1,bst2);
    
    // step 3: USE MERGED INORDER ARRAY TO BUILD BST
    int s=0,e=mergedArray.size()-1;
    
    return inorderTOBST(s,e,mergedArray);
}
int main()
{

    return 0;
}
// 2nd approach


