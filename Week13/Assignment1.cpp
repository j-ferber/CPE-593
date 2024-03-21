#include <iostream>
#include <queue>

using namespace std;

struct Employee {
    int employeeID;
    string name;
    double salary;
    string department;
    Employee* left;
    Employee* right;
};

// Function to create a new Employee node
Employee* newEmployee(int id, string name, double salary, string department) {
    Employee* temp = new Employee;
    temp->employeeID = id;
    temp->name = name;
    temp->salary = salary;
    temp->department = department;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to insert a new employee record
Employee* insert(Employee* root, int employeeID, string name, double salary, string department) {
    if (root == NULL) {
        return newEmployee(employeeID, name, salary, department);
    } else if (employeeID < root->employeeID) {
        root->left = insert(root->left, employeeID, name, salary, department);
    } else {
        root->right = insert(root->right, employeeID, name, salary, department);
    }
    return root;
}

// Function for pre-order traversal
void preOrder(Employee* root) {
    if (root == NULL) {
        return;
    } else {
        cout << "Employee ID: " << root->employeeID << ", Name: " << root->name << ", Salary: " << root->salary << ", Department: " << root->department << endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function for in-order traversal
void inOrder(Employee* root) {
    if (root == NULL) {
        return;
    } else {
        inOrder(root->left);
        cout << "Employee ID: " << root->employeeID << ", Name: " << root->name << ", Salary: " << root->salary << ", Department: " << root->department << endl;
        inOrder(root->right);
    }
}

// Function for post-order traversal
void postOrder(Employee* root) {
    if (root == NULL) {
        return;
    } else {
        postOrder(root->left);
        postOrder(root->right);
        cout << "Employee ID: " << root->employeeID << ", Name: " << root->name << ", Salary: " << root->salary << ", Department: " << root->department << endl;
    }
}

// Function for level order traversal
void levelOrder(Employee* root) {
    if (root == NULL) {
        return;
    } else {
        queue<Employee*> q;
        q.push(root);
        while (!q.empty()) {
            Employee* current = q.front();
            cout << "Employee ID: " << current->employeeID << ", Name: " << current->name << ", Salary: " << current->salary << ", Department: " << current->department << endl;
            if (current->left != NULL) {
                q.push(current->left);
            }
            if (current->right != NULL) {
                q.push(current->right);
            }
            q.pop();
        }
    }
}

// Function to calculate the height of the tree
int height(Employee* node) {
    if (node == NULL) {
        return 0;
    } else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        } else {
            return rightHeight + 1;
        }
    }
}

// Function to find the minimum value (employee ID) in the tree
int findMin(Employee* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node->employeeID;
}

// Function to find the maximum value (employee ID) in the tree

int findMax(Employee* node) {
    while (node->right != NULL) {
        node = node->right;
    }
    return node->employeeID;
}

// Main function
int main() {
    Employee* root = NULL;
    root = insert(root, 101, "Alice", 50000.0, "HR");
    root = insert(root, 102, "Bob", 60000.0, "IT");
    root = insert(root, 103, "Charlie", 55000.0, "Finance");
    root = insert(root, 104, "David", 62000.0, "Marketing");
    root = insert(root, 201, "Eve", 51000.0, "HR");
    root = insert(root, 202, "Frank", 59000.0, "IT");
    root = insert(root, 203, "Grace", 60000.0, "Finance");
    cout << "Level Order Traversal:" << endl;
    levelOrder(root);
    cout << endl;
    cout << "Pre-Order Traversal:" << endl;
    preOrder(root);
    cout << endl;
    cout << "In-Order Traversal:" << endl;
    inOrder(root);
    cout << endl;
    cout << "Post-Order Traversal:" << endl;
    postOrder(root);
    cout << endl;
    cout << "Height of the tree: " << height(root) << endl;
    cout << "Minimum value (employee ID) in the tree: " << findMin(root) << endl;
    cout << "Maximum value (employee ID) in the tree: " << findMax(root) << endl;
}