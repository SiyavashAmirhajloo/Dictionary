#include "Node.h"

Node::Node(string k, string def) {
    word.key = k;
    word.definition = def;
}

Node::Node(string k, string def, Node* l, Node* r) {
    word.key = k;
    word.definition = def;
    left = l;
    right = r;
}

