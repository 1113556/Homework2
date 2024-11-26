//蔡宗修
//1113556
//11/22
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree from level-order input
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Left child
        if (nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        // Right child
        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Helper function to calculate the diameter of the binary tree
int calculateDiameter(TreeNode* root, int& diameter) {
    if (!root) return 0;

    int leftHeight = calculateDiameter(root->left, diameter);
    int rightHeight = calculateDiameter(root->right, diameter);

    // Update the diameter if the path through root is larger
    diameter = max(diameter, leftHeight + rightHeight);

    // Return the height of the current node
    return max(leftHeight, rightHeight) + 1;
}

// Function to calculate the diameter of the binary tree
int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    calculateDiameter(root, diameter);
    return diameter;
}

// Utility function to split a string by a delimiter
vector<int> parseInput(const string& input) {
    vector<int> result;
    stringstream ss(input);
    string token;

    while (getline(ss, token, ',')) {
        result.push_back(stoi(token));
    }

    return result;
}

int main() {
    string input;
    cout << "Enter level-order traversal (comma-separated, -1 for null nodes): ";
    getline(cin, input);

    vector<int> nodes = parseInput(input);

    TreeNode* root = buildTree(nodes);

    int diameter = diameterOfBinaryTree(root);

    cout << "The diameter of the binary tree is: " << diameter << endl;

    return 0;
}

