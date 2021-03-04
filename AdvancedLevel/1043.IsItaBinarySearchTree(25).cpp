#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int num) : data(num), left(nullptr), right(nullptr) {}
};

vector<int> pre, mirror, post, revpost;

void insert(Node *&tree, int data) {
    if (!tree) {
        tree = new Node(data);
        return ;
    }
    if (data >= tree->data) {
        insert(tree->right, data);
    } else {
        insert(tree->left, data);
    }
}

void preOrder(Node *tree) {
    if (!tree) {
        return ;
    }
    pre.push_back(tree->data);
    preOrder(tree->left);
    preOrder(tree->right);
}

void mirrorOeder(Node *tree) {
    if (!tree) {
        return ;
    }
    mirror.push_back(tree->data);
    mirrorOeder(tree->right);
    mirrorOeder(tree->left);
}

void postOrder(Node *tree) {
    if (!tree) {
        return ;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    post.push_back(tree->data);
}

void reversePostOrder(Node *tree) {
    if (!tree) {
        return ;
    }
    reversePostOrder(tree->right);
    reversePostOrder(tree->left);
    revpost.push_back(tree->data);
}

void print(vector<int> &a) {
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i];
        if (i != a.size()-1) cout << " ";
    }
    cout << endl;
}

void destroy(Node *tree) {
    if (!tree) return;
    destroy(tree->left);
    destroy(tree->right);
    delete tree;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> arr;
    arr.resize(n);
    Node *tree = nullptr;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        insert(tree, arr[i]);
    }
    preOrder(tree);
    mirrorOeder(tree);
    int pos = 0;
    if (arr == pre) {
        cout << "YES" << endl;
        postOrder(tree);
        print(post);
    }
    else if (arr == mirror) {
        cout << "YES" << endl;
        reversePostOrder(tree);
        print(revpost);
    }
    else {
        cout << "NO" << endl;
    }
    destroy(tree);
    return 0;
}