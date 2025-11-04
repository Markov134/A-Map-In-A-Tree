//
// Created by Steph on 11/3/2025.
//

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>

template<typename T>
class Node {
public:
    T key;
    Node * left;
    Node * right;

    Node(T k) : key(k), left(nullptr), right(nullptr) {}
};

template<typename T>
class SplayTree {
private:
    Node<T>* root;

    Node<T>* rightRotation(Node<T>* x) {
        Node<T>* y = x->left;
        x->left = y->right;
        y->right = x;

        return y;
    }

    Node<T>* leftRotation(Node<T>* x) {
        Node<T>* y = x->right;
        x->right = y->left;
        y->left = x;

        return y;
    }

    Node<T>* splay(Node<T>* root, T key) {
        if (root == nullptr || root->key == key)
            return root;

        // key lies in left subtree
        if (root->key > key)
        {
            // Key is not in tree, we are done
            if (root->left == nullptr)
                return root;

            // Zig-Zig (Left Left)
            if (root->left->key > key)
            {
                // First recursively bring the
                // key as root of left-left
                root->left->left = splay(root->left->left, key);

                // Do first rotation for root,
                // second rotation is done after else
                root = rightRotation(root);
            }
            else if (root->left->key < key) // Zig-Zag (Left Right)
            {
                // First recursively bring
                // the key as root of left-right
                root->left->right = splay(root->left->right, key);

                // Do first rotation for root->left
                if (root->left->right != nullptr)
                    root->left = leftRotation(root->left);
            }

            // Do second rotation for root
            return (root->left == nullptr) ? root : rightRotation(root);
        }
        else // Key lies in right subtree
        {
            // Key is not in tree, we are done
            if (root->right == nullptr)
                return root;

            // Zig-Zag (Right Left)
            if (root->right->key > key)
            {
                // Bring the key as root of right-left
                root->right->left = splay(root->right->left, key);

                // Do first rotation for root->right
                if (root->right->left != nullptr)
                    root->right = rightRotation(root->right);
            }
            else if (root->right->key < key)// Zag-Zag (Right Right)
            {
                // Bring the key as root of
                // right-right and do first rotation
                root->right->right = splay(root->right->right, key);
                root = leftRotation(root);
            }

            // Do second rotation for root
            return (root->right == nullptr) ? root : leftRotation(root);
        }
    }

    Node<T>* insert(Node<T>* root, T key) {
        if (root == nullptr)
            return new Node<T>(key);

        root = splay(root, key);

        if (root->key == key)
            return root;

        Node<T>* node = new Node<T>(key);
        if (root->key > key) {
            node->right = root;
            node->left = root->left;
            root->left = nullptr;
        }
        else {
            node->left = root;
            node->right = root->right;
            root->right = nullptr;
        }

        return node;
    }

    Node<T>* deleteNode(Node<T>* root, T key) {
        Node<T>* temp;
        if (!root)
            return nullptr;

        root = splay(root, key);

        if (key != root->key)
            return root;

        if (!root->left) {
            temp = root;
            root = root->right;
        } else {
            temp = root;

            root = splay(root->left, key);

            root->right = temp->right;
        }

        delete temp;

        return root;
    }

    void preOrder(Node<T>* root) {
        if (root != nullptr) {
            std::cout << root->key << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    Node<T>* search(Node<T>* root, T key) {
        if (root == nullptr)
            return nullptr;

        root = splay(root, key);
        return root;
    }

    void deleteAllNodes(Node<T>* root) {
        if (root == nullptr)
            return;

        deleteAllNodes(root->left);
        deleteAllNodes(root->right);
        delete root;
    }

public:
    SplayTree() : root(nullptr) {}
    ~SplayTree() {
        deleteAllNodes(root);
    }

    void insert(T k) { root = insert(root, k); }
    void remove(const T k) { root = deleteNode(root, k); }
    void search(T k) { root = search(root, k); }
    Node<T>* getRoot() const { return root; }

    void printpreOrder() {
        preOrder(root);
        std::cout << std::endl;
    }
};

#endif //BINARYSEARCHTREE_H
