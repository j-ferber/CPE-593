#ifndef BSTCHECKER_H
#define BSTCHECKER_H

// Your code here (include additional header files, if needed)
#include "Node.h"

class BSTChecker {
public:

    static Node* valid(Node* node, int left, int right) {
        if (!node) {
            return nullptr;
        }
        if (!(node->key < right && node->key > left)) {
            return node;
        }
        Node* leftNext = valid(node->left, left, node->key);
        if (leftNext != nullptr) {
            return leftNext;
        }
        Node* rightNext = valid(node->right, node->key, right);
        if (rightNext != nullptr) {
            return rightNext;
        }
        return nullptr;
    }

    static Node* CheckBSTValidity(Node* rootNode) {
        return valid(rootNode, INT_MIN, INT_MAX);
    }
};

#endif