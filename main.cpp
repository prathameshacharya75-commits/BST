
#include <iostream>
#include "BST.hpp"

using namespace std;

int main() {
    BST<int> tree;

    cout << "===== BINARY SEARCH TREE =====" << endl;

    // Insert elements
    cout << "\nInserting elements: 50 30 70 20 40 60 80" << endl;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Display traversals
    cout << "\nIn-Order Traversal: ";
    tree.inOrderTraversal();

    cout << "Pre-Order Traversal: ";
    tree.preOrderTraversal();

    cout << "Post-Order Traversal: ";
    tree.postOrderTraversal();

    // Search operation
    cout << "\nSearching for 40: ";
    cout << (tree.search(40) ? "Found" : "Not Found") << endl;

    cout << "Searching for 100: ";
    cout << (tree.search(100) ? "Found" : "Not Found") << endl;

    // Delete operation
    cout << "\nDeleting node 30..." << endl;
    tree.remove(30);

    cout << "In-Order Traversal after deletion: ";
    tree.inOrderTraversal();

    cout << "\nProgram completed successfully." << endl;

    return 0;
}

