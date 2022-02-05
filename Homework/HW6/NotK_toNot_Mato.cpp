#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>

using namespace std;

struct node{
    int key;
    struct node *left , *right;
};

struct node* newNode(int item){
    struct node* temp = new node;
    temp ->key = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
};

void printLineByLine( struct node* root){
    if(root != NULL){
        queue<node*>q;
        q.push(root);
        while(!q.empty()){
            int nodeCount = q.size();
            while( nodeCount > 0){
                node* node = q.front();
                cout << node->key << " ";
                q.pop();
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
                nodeCount--;
            }
        }
    }else{
        return;
    }
}

struct node* myInsert(struct node* node, int key){
    if (node == NULL){
        return newNode(key);
    }
    if(key < node->key){
        node->left = myInsert(node->left , key);
    }else if(node-> key < key){
        node->right = myInsert(node->right , key);
    }
    return node;
};

struct node* minValuenode(struct node* node){
    struct node* current = node;
    while(current && current->left != NULL){
        current = current->left;
    }
    return current;
};

struct node* deleteNode(struct node* root , int key){
    if(root == NULL){
        return root;
    }
    if(key < root->key){
        root->left = deleteNode(root->left , key);
    }else if( key > root->key){
        root->right = deleteNode(root->right , key);
    }else{
        if( root->left == NULL && root->right == NULL){
            return NULL;
        }
        else if( root->left == NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if( root->right == NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValuenode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right , temp->key);
    }
    return root;
};

int main(){
    int N = 0 , K = 0 , variable = 0;
    cin >> N >> K;
    vector<int>numbers;
    struct node* root = NULL;
    for(int i = 0 ; i < N ; i++){
        cin >> variable;
        root = myInsert(root , variable);
        numbers.push_back(variable);
    }
    int max_K = 0;
    sort(numbers.begin() , numbers.end() ,
    [](auto& a, auto &b){
            return a > b;
    });
    max_K = numbers[K - 1];
    root = deleteNode(root , max_K);
    printLineByLine(root);
    return 0;
}
