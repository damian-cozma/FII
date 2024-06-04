#include <iostream>
#include "Tree.h"

using namespace std;

int main() {
    Tree<int> tree;

    tree.addNode(nullptr, 5);
    tree.addNode(tree.getRoot(), 6);
    tree.addNode(tree.getRoot(), 3);
    tree.addNode(tree.getRoot(), 8);

    tree.addNode(tree.find(8), 4);
    tree.addNode(tree.find(8), 1);
    tree.addNode(tree.find(8), -2);

    cout << "Count: " << tree.countNodes(tree.getRoot()) << "\n";

    auto* ten = tree.find(8); // changed from eight to ten
    cout << "Copii 10:" << endl; // changed from 8 to 10
    for (size_t i = 0; i < ten->getChildrenCount(); ++i) { // changed from eight to ten
        cout << ten->getChild(i)->getData() << " "; // changed from eight to ten
    }
    cout << endl;
    cout << "Sortat:" << endl;
    ten->sortChildren();
    for (size_t i = 0; i < ten->getChildrenCount(); ++i) { // changed from eight to ten
        cout << ten->getChild(i)->getData() << " "; // changed from eight to ten
    }

    return 0;
}
