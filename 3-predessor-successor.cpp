// finding predesoor and successor of key element
/*
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    //find key
    BinaryTreeNode<int>* temp = root;
    
    int pre = -1;
    int suc = -1;
    while(temp->data != key)
    {
        if(temp->data>key)
        {
            suc = temp->data;
            temp  = temp->left;
        }
        else
        {
             pre = temp->data;
            temp = temp->right;
        }
    }
    
    //pre and suc
    
    //pre
    BinaryTreeNode<int>* l = temp->left;
    while(l!=NULL)
    {
        pre = l->data;
        l = l->right;
    }
    
     //suc
    BinaryTreeNode<int>* r = temp->right;
    while(r!=NULL)
    {
        suc = r->data;
        r = r->left;
    }
    
    pair<int,int> ans = make_pair(pre,suc);
    
    return ans;
    
     
}
*/