/*
Author : @wuan
Link :
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define endl '\n'
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    queue<TreeNode *> qe;
    qe.push(root);
    while (!qe.empty())
    {
        int n = qe.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *temp = qe.front();
            qe.pop();
            if (temp == p)
            {
                return temp;
            }
            else if (temp->left == p || temp->left == q)
            {
                return temp;
            }
            else if (temp->right == p || temp->right == q)
            {
                return temp;
            }
            if (temp->left)
            {
                qe.push(temp->left);
            }
            if (temp->right)
            {
                qe.push(temp->right);
            }
        }
    }
    return root;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}