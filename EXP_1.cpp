#include <bits/stdc++.h>

#pragma GCC optimize "trapv"
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define MOD 1000000007LL
#define LL long long
#define ULL unsigned long long
#define LD long double
#define pb push_back
#define vli vector<LL int>
#define vi vector<int>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define REP(i, n) for (long long int i = 0; i < (n); i++)
#define FOR(i, a, b) for (long long int i = (a); i < (b); i++)
#define FORR(i, n) for (long long int i = (n); i >= 0; i--)
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int i = 0;
    TreeNode *trimBST(TreeNode *root, int L, int R)
    {
        if (root == NULL)
            return NULL;
        if (root->val > R)
            return trimBST(root->left, L, R);
        if (root->val < L)
            return trimBST(root->right, L, R);
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }

    TreeNode *bstFromPreorder(vector<int> &A, int bound = INT_MAX)
    {
        if (i == A.size() || A[i] > bound)
            return NULL;
        TreeNode *root = new TreeNode(A[i++]);
        root->left = bstFromPreorder(A, root->val);
        root->right = bstFromPreorder(A, bound);
        return root;
    }

    void bfs(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *cur = q.front();
            cout << cur->val << " ";
            q.pop();
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    int temp, l, h, n;
    cout << "Enter Number of tree nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        nums.push_back(temp);
    }
    cin >> l >> h;
    TreeNode *root = s.bstFromPreorder(nums);
    TreeNode *trimmed_root = s.trimBST(root, l, h);
    s.bfs(trimmed_root);
    return 0;
}
