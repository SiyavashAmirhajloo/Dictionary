#include <stdlib.h>
#include "Dictionary.h"

int menu();
void order(int o, Dictionary& myDict);

int main() {
    Dictionary myDict;
    int o = menu();
    while (o != 0) {
        order(o, myDict);
        o = menu();
    }
    return 0;
}

int menu() {
    cout << "__________\tMENU\t__________\n\n";
    cout << "'Search a word'\t\t\tEnter 1\n";
    cout << "'Search by first letter'\tEnter 2\n";
    cout << "'Add a word to dictionary'\tEnter 3\n";
    cout << "'Delete a word from dictionary'\tEnter 4\n";
    cout << "'Show the dictionary'\t\tEnter 5\n";
    cout << "'Exit'\t\t\t\tEnter 0\n";
    cout << "Your order: ";
    int n;
    cin >> n;
    return n;
}

void order(int o, Dictionary& myDict) {
    system("cls");
    string w, d;
    int num = 1;
    Node *node;
    switch (o) {
        case 0:
            exit(1);
            break;
        case 1:
            cout << "__________\tSEARCH\t__________\n\n";
            cout << "Enter your Word: ";
            cin >> w;
            node = myDict.search(myDict.getDictRoot(), w, num);
            if (node != NULL) {
                cout << node->word.key << ": " << node->word.definition << endl;
                cout << "Left child=> ";
                if (node->left != NULL)
                    cout << node->left->word.key << ": " << node->left->word.definition << endl;
                else
                    cout << endl;
                cout << "Right child=> ";
                if (node->right != NULL)
                    cout << node->right->word.key << ": " << node->right->word.definition << endl;
                else
                    cout << endl;
            }
            break;
        case 2:
            cout << "__________\tSEARCH BY LETTER\t__________\n\n";
            char c;
            cout << "Enter your leter: ";
            cin >> c;
            myDict.wordsWithChar(c);
            break;
        case 3:
            cout << "__________\tADD\t__________\n\n";
            cout << "Enter your Word: ";
            cin >> w;
            cout << "Enter the Word's definition: ";
            cin >> d;
            if (myDict.add(w, d))
                cout << "Your word added successfully.\n";
            else
                cout << "Your word is already existed.\n";
            break;
        case 4:
            cout << "__________\tDELETE\t__________\n\n";
            cout << "Enter your Word: ";
            cin >> w;
            if (myDict.Delete(w))
                cout << "Your word deleted successfully.\n";
            else
                cout << "Your word is not exist in dictionary.\n";
            break;
        case 5:
            cout << "__________\tDICTIONARY\t__________\n\n";
            myDict.showDict();
            break;
        default:
            break;
    }
    cout << "For back to Menu Enter a key: ";
    char b;
    cin >> b;
    system("CLS");
}