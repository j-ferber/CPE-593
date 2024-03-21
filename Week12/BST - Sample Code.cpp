#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int bookId;
    string title;
    Node* left;
    Node* right;
};

// Function to create a new Node
Node* newNode(int id, string title) {
    Node* temp = new Node;
    temp->bookId = id;
    temp->title = title;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new node
Node* insert(Node* root, int bookId, string title) {
    if (root == NULL) {
        return newNode(bookId, title);
    } else if (bookId < root->bookId) {
        root->left = insert(root->left, bookId, title);
    } else {
        root->right = insert(root->right, bookId, title);
    }
    return root; 
}

// Function for pre-order traversal
void preOrder(Node* root) {
    if (root == NULL) {
        return;
    } else {
        cout << "Book ID: " << root->bookId << ", Title: " << root->title << endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function for in-order traversal
void inOrder(Node* root) {
    if (root == NULL) {
        return;
    } else {
        inOrder(root->left);
        cout << "Book ID: " << root->bookId << ", Title: " << root->title << endl;
        inOrder(root->right);
    }
}

// Function for post-order traversal
void postOrder(Node* root) {
    if (root == NULL) {
        return;
    } else {
        postOrder(root->left);
        postOrder(root->right);
        cout << "Book ID: " << root->bookId << ", Title: " << root->title << endl;
    }
}

// Function for level order traversal
void levelOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << "Book ID: " << current->bookId << ", Title: " << current->title << endl;
        if (current->left) {
            q.push(current->left);
        }
        if (current->right) {
            q.push(current->right);
        }
    }
}

// Function to calculate the height of the tree
int height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    if (leftHeight >= rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

// Function to find the minimum value (book ID) in the tree
int findMin(Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node->bookId;
}

// Function to find the maximum value (book ID) in the tree
int findMax(Node* node) {
    while (node->right != NULL) {
        node = node->right;
    }
    return node->bookId;
}

// Main function
int main() {
    Node* root = NULL;
    root = insert(root, 4, "The Great Gatsby");
    root = insert(root, 2, "1984");
    root = insert(root, 1, "To Kill a Mockingbird");
    root = insert(root, 3, "The Catcher in the Rye");
    root = insert(root, 6, "Brave New World");
    root = insert(root, 5, "The Hobbit");
    root = insert(root, 7, "Green Mile");

    // WRITE CODE HERE
    cout << "\nPreorder Traversal:\n-------------------------------" << endl;
    preOrder(root);
    cout << "\nInorder Traversal:\n-------------------------------" << endl;
    inOrder(root);
    cout << "\nPostorder Traversal:\n-------------------------------" << endl;
    postOrder(root);
    cout << "\nLevel-order Traversal:\n-------------------------------" << endl;
    levelOrder(root);
    cout << "\nHeight: " << height(root) << endl;
    cout << "\nMinimum Value: " << findMin(root) << endl;
    cout << "\nMaximum Value: " << findMax(root) << endl;


    return 0;
}
