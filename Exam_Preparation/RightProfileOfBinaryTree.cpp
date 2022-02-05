#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

struct Node{
    Node* left;
    Node* right;
    int value;
    Node(int value){
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST{
public:
    BST(){
        root = NULL;
    }

    void insert(int value){
        root = insert(root , value);
    }

    void printRightProfile(){
        int max_level = 0;
        rightViewUtil(root , 1 , &max_level);
    }

    void rightViewUtil(struct Node* root , int level , int* max_level){
        if(root == NULL){
            return;
        }

        if(*max_level < level){
            cout << root->value << " ";
            *max_level = level;
        }

        rightViewUtil(root -> right , level + 1 , max_level);
        rightViewUtil(root -> left , level + 1 , max_level);
    }
private:

    Node* root;

    Node* insert(Node* curNode , int value){
        if(curNode == NULL){
            curNode = new Node(value);
        }else if ( curNode -> value < value){
            curNode->right = insert(curNode->right , value);
        }else if( curNode -> value > value){
            curNode->left = insert(curNode->left , value);
        }else{}

        return curNode;
    }
};

int main(){
    int n ;
    cin >> n;
    int value;
    BST tree;
    for(int i = 0 ;i < n ; i++){
        cin >> value;
        tree.insert(value);
    }
    tree.printRightProfile();
    return 0;
}
