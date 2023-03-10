#include "Dictionary.h"

bool Dictionary::add(string word, string def) {
    int temp = dict.Size();
    dict.insert(dict.getRoot(), word, def);
    if (temp == dict.Size())
        return false;
    return true;
}

bool Dictionary::Delete(string word) {
    int temp = dict.Size();
    dict.deletion(dict.getRoot(), word);
    if (temp == dict.Size())
        return false;
    return true;
}

void Dictionary::wordsWithChar(char begin) {
    vector<Word> words;
    dict.inorder(dict.getRoot(), words);
    cout << "Words with '" << begin << "' are here.\n\n";
    for (int i = 0; i < words.size(); i++) {
        if (words[i].key[0] == begin)
            cout << words[i].key << ": " << words[i].definition << endl;
    }
}

Node* Dictionary::search(Node* root, string word, int & compareNum) {
    if (root == NULL) {
        cout << "The word does not exist in this Dictionary.\n";
        return NULL;
    }
    if (word < root->word.key) {
        cout << "Compare number " << compareNum << ": " << word << " < " << root->word.key << endl;
        return search(root->left, word, compareNum);
    }
    if (word > root->word.key) {
        cout << "Compare number " << compareNum << ": " << word << " > " << root->word.key << endl;
        return search(root->right, word, compareNum);
    }
    cout << "Compare number " << compareNum << ": " << word << " is found.\n";
    return root;
}

void Dictionary::showDict() {
    vector<Word> words;
    dict.inorder(dict.getRoot(), words);
    char letter = 'A';
    while (letter <= 'Z') {
        cout << endl << "* " << letter << " *" << endl;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].key[0] == letter - ('A' - 'a'))
                cout << words[i].key << ": " << words[i].definition << endl;
        }
        letter++;
    }
}