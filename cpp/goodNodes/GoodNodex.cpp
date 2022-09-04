//
// Created by Mattia Lunardi on 01/09/22.
//
#include <iostream>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};


class Solution{
public:
    int goodNodes(TreeNode *);
};

int Solution::goodNodes(TreeNode *root){

}

int main(int argc, char **argv){

}