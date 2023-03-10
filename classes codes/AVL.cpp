#include "AVL.h"

AVL::AVL() {
    root = nullptr;
    size = 0;
}

void AVL::setSize(int s) {
    size = s;
}

Node* AVL::newNode(string key, string def) {
    Node *node = new Node(key, def, nullptr, nullptr);
    node->height = 1;
    return node;
}

Node* AVL::rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    int a = (y->left == nullptr) ? 0 : y->left->height;
    int b = (y->right == nullptr) ? 0 : y->right->height;
    y->height = ((a >= b) ? a : b) + 1;
    a = (x->left == nullptr) ? 0 : x->left->height;
    b = (x->right == nullptr) ? 0 : x->right->height;
    x->height = ((a >= b) ? a : b) + 1;
    return x;
}

Node* AVL::leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    if (x == root)
        root = y;
    x->right = T2;

    int a = (y->left == nullptr) ? 0 : y->left->height;
    int b = (y->right == nullptr) ? 0 : y->right->height;
    y->height = ((a >= b) ? a : b) + 1;
    a = (x->left == nullptr) ? 0 : x->left->height;
    b = (x->right == nullptr) ? 0 : x->right->height;
    x->height = ((a >= b) ? a : b) + 1;
    return y;
}

int AVL::getBalance(Node *N) {
    if (N == NULL)
        return 0;
    int a = (N->left == nullptr) ? 0 : N->left->height;
    int b = (N->right == nullptr) ? 0 : N->right->height;
    return a - b;
}

Node* AVL::insert(Node* node, string key, string def) {
    if (node == nullptr) {
        Node *n = newNode(key, def);
        if (size == 0)
            root = n;
        size++;
        return n;
    }

    if (key < node->word.key)
        node->left = insert(node->left, key, def);
    else if (key > node->word.key)
        node->right = insert(node->right, key, def);
    else
        return node;

    int a = (node->left == nullptr) ? 0 : node->left->height;
    int b = (node->right == nullptr) ? 0 : node->right->height;
    node->height = 1 + ((a >= b) ? a : b);

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->word.key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->word.key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->word.key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->word.key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* AVL::deletion(Node* root, string key) {
    if (root == NULL)
        return NULL;

    if (key < root->word.key)
        root->left = deletion(root->left, key);
    else if (key > root->word.key)
        root->right = deletion(root->right, key);
    else {
        size--;
        if (root->left == NULL || root->right == NULL) {
            Node *tmp = (root->left != nullptr) ? root->left : root->right;
            if (tmp == NULL) {
                tmp = root;
                root = nullptr;
            } else
                *root = *tmp;
            if (tmp == this->root) {
                free(tmp);
                this->root = nullptr;
            }
        } else {
            Node *tmp = min(root->right);
            root->word.key = tmp->word.key;
            root->right = deletion(root->right, tmp->word.key);
        }
    }
    if (root == NULL)
        return root;

    int a = (root->left == nullptr) ? 0 : root->left->height;
    int b = (root->right == nullptr) ? 0 : root->right->height;
    root->height = ((a >= b) ? a : b) + 1;

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* AVL::min(Node* r) {
    if (r == nullptr)
        return r;
    Node *node = r;
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

void AVL::inorder(Node *root, vector<Word>& temp) {
    if (root != NULL) {
        inorder(root->left, temp);
        temp.push_back(root->word);
        inorder(root->right, temp);
    }
}