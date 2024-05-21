#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) {
        this->val = val;
        left = right = nullptr;
    }
};

#endif
