//
// Created by Carla Onate on 16/04/21.
//

// https://www.geeksforgeeks.org/print-ancestors-of-a-given-node-in-binary-tree/
//https://www.geeksforgeeks.org/insert-a-node-in-binary-search-tree-iteratively/
//https://medium.com/@sakshis.ug18.ec/level-order-tree-traversal-f2c4eccb1780
//https://replit.com/@ertello/BinarySearchTree#NodeTree.h

#ifndef BST_ACT_BST_H
#define BST_ACT_BST_H

#include "../../../../../../../CLionProjects/BST_Act/Node.h"
#include <queue>


template <class T>
class BST{
private:
    Node<T> *root;
    void inOrder(Node<T>*);
    void preOrder(Node<T>*);
    void postOrder(Node<T>*);
    void levelByLevel(Node<T>*);
    Node<T>* deleteNode(Node<T>*, T);
    Node<T>* recursiveInsert(Node<T>*, T);
    int height(Node<T>*);
    void iterativeInsert(T);  //Todo: No funciona
    bool ancestors(Node<T>*, T);
    Node<T>* minValueNode(Node<T>*);


public:
    BST();
    void menu();
    void insert(T value);
    bool find(T);
    void deleteVal(T);
    void print(int);
    int whatLevelAmI(T);

};

#endif //BST_ACT_BST_H


template <class T> BST<T>::BST() {
    root = nullptr;
}


template <class T> void  BST<T>::menu(){
    int menuOption = 0;
    int val;

    while(menuOption != -1){
        std::cout << "1- Insertar valores \n";
        std::cout << "2- Borrar valor\n";
        std::cout << "3- Imprimir valor preorder\n";
        std::cout << "4- Imprimir valor inorder\n";
        std::cout << "5- Imprimir valor postoder\n";
        std::cout << "6- Imprimir valor por nivel\n";
        std::cout << "7- Altura arbol\n";
        std::cout << "8- Ancestros valor\n";
        std::cout << "9- Nivel del valor\n";
        std::cout << "Ingrese -1 para temrinar\n";
        std::cin >> menuOption;

        if(menuOption == 1){
            while(val != -1){
                std::cout << "Valor: (-1 para terminar)";
                std::cin >> val;
                if(val > 0) insert(val);
            }
        } else if(menuOption == 2){
            std::cout << "Valor: ";
            std::cin >> val;
            deleteVal(val);
        } else if(menuOption == 3){
            print(menuOption);
        } else if(menuOption == 4){
            print(menuOption);
        } else if(menuOption == 5){
            print(menuOption);
        } else if(menuOption == 6){
            print(menuOption);
        } else if(menuOption == 7){
            std::cout << height(root) << "\n";
        } else if(menuOption == 8){
            std::cout << "Valor: ";
            std::cin >> val;
            ancestors(root, val);
            std::cout << "\n";
        } else if(menuOption == 9){
            std::cout << "Valor: ";
            std::cin >> val;
            std::cout << whatLevelAmI(val) << "\n";
        }
    }

}


template <class T> void BST<T>::iterativeInsert(T value) {
    Node<T>* newValue = new Node<T>(value);
    Node<T>* current = root;

    Node<T>* trail = nullptr;

    while (current != nullptr){
        trail = current;
        if(value > current->data){
            current = current->right;
        } else {
            current = current->left;
        }
    }

    if(trail == nullptr){
        root = newValue;
    } else if(value > trail->data){
        trail->right = newValue;
    } else {
        trail->left = newValue;
    }
}


template <class T> Node<T>* BST<T>::recursiveInsert(Node<T>* p, T value){
    if (p == nullptr) {
        p = new Node<T>(value);
    } else if (value < p->data){
        p->left = recursiveInsert(p->left, value);
    } else if (value > p->data){
        p->right = recursiveInsert(p->right, value);
    } else{
        std::cout << "El elemento " << value << " ya existe en el arbol" << std::endl;
    }
    return p;
}


template <class T> void BST<T>::insert(T value) {
    root = recursiveInsert(root, value);
}

template <class T> void BST<T>::deleteVal(T value) {
    deleteNode(root, value);
}


template<class T> Node<T>* BST<T>::minValueNode(Node<T>* node) {
    Node<T> *curr = node;
    while (curr && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}


template <class T> Node<T>* BST<T>::deleteNode(Node<T>* node, T value) {
    Node<T> *curr = node;
    // base case
    if (node == nullptr){
        return node;
    }
    if (value < node->data){
        node->left = deleteNode(node->left, value);
        return node;
    } else if (value > node->data){
        node->right = deleteNode(node->right, value);
        return node;
    } else {
        if (node->left==nullptr && node->right==nullptr){
            delete(node);
            return nullptr;
        } else if (node->left == nullptr) {
            curr= node->right;
            delete(node);
            return curr;
        } else if (node->right == nullptr) {
            curr = node->left;
            delete(node);
            return curr;
        }

        curr = minValueNode(root->right);

        node->data = curr->data;

        node->right = deleteNode(node->right, curr->data);
    }
    return node;

}


template <class T> bool BST<T>::find(T value) {
    Node<T> *p = root;
    while(p != nullptr) {
        if (p->data == value) {
            return true;
        } else {
            p = (value < p->data ? p->left : p->right);
        }
    }
    return false;
}


template <class T> int BST<T>::height(Node<T>* node) {
    if (node == NULL){
        return 0;
    } else {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        /* use the larger one */
        if (lheight > rheight){
            return(lheight + 1);
        } else{
            return(rheight + 1);
        }
    }
}


template <class T> bool BST<T>::ancestors(Node<T>* node, T value) {
    if (node == NULL){
        return false;
    }

    if (node->data == value){
        return true;
    }

    /* If target is present in either left or right subtree of this node,
       then print this node */
    if (ancestors(node->left, value) || ancestors(node->right, value)) {
        std::cout << node->data << " ";
        return true;
    }

    return false;

}


template <class T> int BST<T>::whatLevelAmI(T value) {
    Node<T> *p = root;
    int counter = 0;
    while(p != nullptr) {
        if (p->data == value) {
            return true;
        } else {
            p = (value < p->data ? p->left : p->right);
            counter++;
        }
    }
    return counter+1;
}


template <class T> void BST<T>::print(int type) {
    if(type == 3){
        preOrder(root);
    } else if (type == 4){
        inOrder(root);
    } else if (type == 5){
        postOrder(root);
    } else {
        levelByLevel(root);
    }
    std::cout << "\n";
}


template <class T> void BST<T>::inOrder(Node<T>* node){
    if (node != nullptr){
        inOrder(node->left);
        std::cout << node->data << " ";
        inOrder(node->right);
    }
}


template <class T> void BST<T>::preOrder(Node<T>* node){
    if(node != nullptr){
        std::cout << node->data << " "; // node
        preOrder(node->left); // left
        preOrder(node->right); // right
    }
}


template<class T> void BST<T>::postOrder(Node<T>* node){
    if(node != nullptr){
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->data << " ";
    }
}


template <class T> void BST<T>::levelByLevel(Node<T>* node) {
        if (root == NULL){
            return;
        }

        std::queue<Node<T>*> q;
        q.push(root);

        while (!q.empty()){
            int nodes = q.size();
            /*Dequeue all nodes of current level and
              Enqueue all nodes of next level */
            while (nodes > 0){
                Node<T>* current= q.front();
                std::cout << current->data << " ";
                q.pop();
                if (current->left != NULL)
                    q.push(current->left);
                if (current->right != NULL)
                    q.push(current->right);
                nodes--;
            }
            std::cout << " | ";
        }

}
