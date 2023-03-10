#ifndef DS_TA_AVL_H
#define DS_TA_AVL_H

#include <vector>
#include "Node.h"

class AVL {
private:
    Node *root;
    int size;
public:
    AVL();

    Node *getRoot() { return root; }

    int Size() { return size; }

    void setSize(int s);

    Node *newNode(string key, string def);

    Node *rightRotate(Node *y);

    Node *leftRotate(Node *x);

    int getBalance(Node *N);

    Node *insert(Node *node, string key, string def);

    Node *deletion(Node *root, string key);

    Node *min(Node *r);

    void inorder(Node *r, vector<Word> &words);
};

#endif