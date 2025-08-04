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
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *invertTree(TreeNode *root)
{
    if (!root || (root->left == nullptr && root->right == nullptr))
    {
        return root;
    }
    TreeNode *temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);
    return root;
}
void show(TreeNode *root)
{
    if (!root)
    {
        cout << "null";
        return;
    }
    cout << root->val << " ";
    show(root->left);
    show(root->right);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // Tạo các node lá
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node9 = new TreeNode(9);

    // Tạo các node trung gian
    TreeNode *node2 = new TreeNode(2);
    node2->left = node1;
    node2->right = node3;

    TreeNode *node7 = new TreeNode(7);
    node7->left = node6;
    node7->right = node9;

    // Root node
    TreeNode *root = new TreeNode(4);
    root->left = node2;
    root->right = node7;

    TreeNode *invertedRoot = invertTree(root);
    show(invertedRoot);
    return 0;
}