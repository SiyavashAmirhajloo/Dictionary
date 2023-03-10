#ifndef DS_TA_NODE_H
#define DS_TA_NODE_H

#include<iostream>

using namespace std;

struct Word {
    string key;
    string definition;
};

class Node {
public:
    Word word;
    Node *left;
    Node *right;
    int height;

    Node(string k, string def);

    Node(string k, string def, Node *l, Node *r);

    Node() {}
};

#endif