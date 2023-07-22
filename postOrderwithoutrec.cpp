class Solution {
public:
    int find1(vector<TreeNode* > v,TreeNode* root)
    {
        auto it=find(v.begin(),v.end(),root);
        if(it!=v.end())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        
    vector<TreeNode* > v1;
    vector<TreeNode* > vis;
    vector<int> vis_val;
    TreeNode* temp;
    if(root==NULL)
    {
        return vis_val;
    }
    v1.push_back(root);
    while(v1.empty()!=true)
    {
        temp=v1.back();
        if(temp->left==nullptr and temp->right==nullptr)
        {
            v1.pop_back();
            vis.push_back(temp);
        }
        else if(temp->left!=nullptr and temp->right!=nullptr)
        {
            if(find1(vis,temp->left)==1 and find1(vis,temp->right)==1)
            {
                v1.pop_back();
                vis.push_back(temp);
            }
            else
            {
                v1.push_back(temp->right);
                v1.push_back(temp->left);
            }
        }
        else if(temp->left!=nullptr)
        {
            if(find1(vis,temp->left)==1)
            {
                v1.pop_back();
                vis.push_back(temp);
            }
            else
            {
                v1.push_back(temp->left);
            }
        
        }
        else if(temp->right!=temp)
        {
            if(find1(vis,temp->right)==1)
            {
                v1.pop_back();
                vis.push_back(temp); 
            }
            else
            {
              v1.push_back(temp->right);  
            }
        }
    }
    for(int i=0;i<vis.size();i++)
    {
        vis_val.push_back(vis.at(i)->val);
    }
    return vis_val;
   
        
        
    }

};