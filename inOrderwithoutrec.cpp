class Solution {
public:
    int find_val(vector<TreeNode* > v,TreeNode* value)
    {
        auto it=find(v.begin(),v.end(),value);
        if(it!=v.end())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode* > v2;
        vector<TreeNode* >v1;
        vector<int> v3;
        v1.push_back(root);
        TreeNode* temp;
        if(root==NULL)
        {
            return v3;
        }
        while(v1.empty()!=true)
        {
            temp=v1.back();
            if(temp->left==nullptr and temp->right==nullptr)
            {
                v2.push_back(temp);
                v1.pop_back();
            }
            if(temp->left!=nullptr and temp->right!=nullptr)
            {
                if(find_val(v2,temp->left)==1)
                {
                    v1.pop_back();
                    v2.push_back(temp);
                    v1.push_back(temp->right);
                }
                else
                {
                    v1.push_back(temp->left);
                }
            }
            else if(temp->left!=nullptr)
            {
                if(find_val(v2,temp->left)==1)
                {
                    v1.pop_back();
                    v2.push_back(temp);
                }
                else
                {
                    v1.push_back(temp->left);
                }
            }
            else if(temp->right!=nullptr)
            {
                v1.pop_back();
                v2.push_back(temp);
                v1.push_back(temp->right);
            }
            
        }
        for(int i=0;i<v2.size();i++)
        {
            v3.push_back(v2.at(i)->val);
        }
        return v3;

        
    }
};