// check whether given tree is BST
/*bool solution(BinaryTreeNode<int> *root,int min,int max)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->data>=min && root->data<=max)
    {
        bool left = solution(root->left,min,root->data);
        bool right = solution(root->right,root->data,max);
        
        return left && right;
    }
    else
    {
        return false;
    }
}
bool validateBST(BinaryTreeNode<int> *root) {
   return solution(root,INT_MIN,INT_MAX); 
}*/