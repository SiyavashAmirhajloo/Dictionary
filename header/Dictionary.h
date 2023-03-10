#ifndef DS_TA_DICTIONARY_H
#define DS_TA_DICTIONARY_H

#include "AVL.h"

class Dictionary {
private:
    AVL dict;
public:
    Node *getDictRoot() { return dict.getRoot(); }

    bool add(string word, string def);

    bool Delete(string word);

    void wordsWithChar(char begin);

    Node *search(Node *root, string word, int &compNum);

    void showDict();
};

#endif