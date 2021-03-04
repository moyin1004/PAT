#include <bits/stdc++.h>

using namespace std;

struct TNode {
    int val;
    TNode *left;
    TNode *right;
    TNode(int x):val(x), left(nullptr), right(nullptr) {}
};

vector<int> post;
vector<int> in;

TNode *creat(int inl, int inr, int &postr) {
    assert(postr >= 0);
    if (inl == inr) {
        ++postr;
        return nullptr;
    }
    int val = post[postr-1];
    TNode *root = new TNode(val);

    int i = inl;
    while (i < inr && in[i] != val) ++i;
    // 后续遍历 反着来，先右子树的根，再左子树
    root->right = creat(i+1, inr, --postr);
    root->left = creat(inl, i, --postr);
    return root;
}

void levelOrder(TNode *tree) {
    queue<TNode*> q;
    q.push(tree);
    while (!q.empty()) {
        TNode *temp = q.front();
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
        cout << temp->val;
        q.pop();
        if (!q.empty()) cout << " ";
    }
}

void destroy(TNode *tree) {
    if (!tree) return ;
    destroy(tree->left);
    destroy(tree->right);
    delete tree;
}

int main() {
    int n;
    cin >> n;
    int temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        post.push_back(temp);
    }
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        in.push_back(temp);
    }
    int postr = post.size();
    TNode *tree = creat(0, in.size(), postr);
    levelOrder(tree);
    cout << endl;
    destroy(tree);
    return 0;
}