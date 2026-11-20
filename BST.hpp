
#ifndef BST_HPP
#define BST_HPP

#include <iostream>
using namespace std;

template <typename T>
class BST {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insertNode(Node* node, T value);
    bool searchNode(Node* node, T value) const;
    Node* deleteNode(Node* node, T value);
    Node* findMin(Node* node) const;

    void inOrder(Node* node) const;
    void preOrder(Node* node) const;
    void postOrder(Node* node) const;
    void destroyTree(Node* node);

public:
    BST();
    ~BST();

    void insert(T value);
    bool search(T value) const;
    void remove(T value);

    void inOrderTraversal() const;
    void preOrderTraversal() const;
    void postOrderTraversal() const;
};

template <typename T>
BST<T>::BST() {
    root = nullptr;
}

template <typename T>
BST<T>::~BST() {
    destroyTree(root);
}

template <typename T>
void BST<T>::destroyTree(Node* node) {
    if (node == nullptr)
        return;

    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}

template <typename T>
typename BST<T>::Node* BST<T>::insertNode(Node* node, T value) {
    if (node == nullptr)
        return new Node(value);

    if (value < node->data)
        node->left = insertNode(node->left, value);
    else if (value > node->data)
        node->right = insertNode(node->right, value);

    return node;
}

template <typename T>
void BST<T>::insert(T value) {
    root = insertNode(root, value);
}

template <typename T>
bool BST<T>::searchNode(Node* node, T value) const {
    if (node == nullptr)
        return false;

    if (node->data == value)
        return true;

    if (value < node->data)
        return searchNode(node->left, value);

    return searchNode(node->right, value);
}

template <typename T>
bool BST<T>::search(T value) const {
    return searchNode(root, value);
}

template <typename T>
typename BST<T>::Node* BST<T>::findMin(Node* node) const {
    while (node && node->left != nullptr)
        node = node->left;

    return node;
}

template <typename T>
typename BST<T>::Node* BST<T>::deleteNode(Node* node, T value) {
    if (node == nullptr)
        return nullptr;

    if (value < node->data) {
        node->left = deleteNode(node->left, value);
    }
    else if (value > node->data) {
        node->right = deleteNode(node->right, value);
    }
    else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = findMin(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }

    return node;
}

template <typename T>
void BST<T>::remove(T value) {
    root = deleteNode(root, value);
}

template <typename T>
void BST<T>::inOrder(Node* node) const {
    if (node == nullptr) return;

    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

template <typename T>
void BST<T>::preOrder(Node* node) const {
    if (node == nullptr) return;

    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

template <typename T>
void BST<T>::postOrder(Node* node) const {
    if (node == nullptr) return;

    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}

template <typename T>
void BST<T>::inOrderTraversal() const {
    inOrder(root);
    cout << endl;
}

template <typename T>
void BST<T>::preOrderTraversal() const {
    preOrder(root);
    cout << endl;
}

template <typename T>
void BST<T>::postOrderTraversal() const {
    postOrder(root);
    cout << endl;
}

#endif

