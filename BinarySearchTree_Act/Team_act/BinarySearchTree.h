#ifndef _BST_H_
#define _BST_H_

  #include<iostream>
  #include <queue>
  #include "NodeTree.h"
  using namespace std;

  template <class T>
  class BinarySearchTree { 
  private:
    NodeTree<T> *root;
    void preorder(NodeTree<T>* nodo);
    void postorder(NodeTree<T>* nodo);
    void inorder(NodeTree<T>* nodo);
  public: 
      BinarySearchTree();
      bool search(T valor);
      void insert(T valor);
      NodeTree<T> *insertRecursive(NodeTree<T> *r, T valor);
      void detete(T valor);
      NodeTree<T> *deleteRecursive(NodeTree<T> *r, T valor);
      NodeTree<T> *reemplazar(NodeTree<T> *r);
      void verarbol();
      void verarbolRecursivo(NodeTree<T> *r, int target); 
      int height(NodeTree<T> *r);
      void printLevelOrder(NodeTree<T> *r);
      void menu();
      bool printAncestors(NodeTree<T> *r, T n);
      int getLevel(NodeTree<T>* r, T data);
      int getLevelUtil(NodeTree<T>* r, T data, int level);
      void printGivenLevel(NodeTree<T>* r, int level);
  }; 

  template<class T>
  BinarySearchTree<T>::BinarySearchTree() {
    root = nullptr;
  }

  template<class T>
  void BinarySearchTree<T>::menu(){
    int op;
    int x = 0;
    while (x < 4){
      cout<<"\n\tMENU"<<endl;
      cout<<"1. inserta un dato nuevo en el BST"<<endl;
      cout<<"2. Elimina un dato del BST."<<endl;
      cout<<"3. Imprime todos los nodos del BST."<<endl;
      cout<<"4. Busquedade un dato dado"<<endl;
      cout<<"5. Imprimir en Preorder."<<endl;
      cout<<"6. Imprimir en Inorder"<<endl;
      cout<<"7. Imprimir en Postorder"<<endl;
      cout<<"8. Imprimir por Level by level"<<endl;
      cout<<"9. Regresa la altura del BST."<<endl;
      cout<<"10. Desplegará los ancestros de un dato."<<endl;
      cout<<"11. Indica el nivel en que se encuentra un dato"<<endl;
      cout<<"0. Salir"<<endl;
      cout<<"Ingrese la opcion: ";cin>>op;
      cout<<"\n"<<endl;
      if (op <12){
        if (op == 1){
          cout<<"inserta un dato nuevo en el BST"<<endl;
          int n;
          int dato;
          cout<<"Numero de datos: ";cin>>n;
          for (int i = 0; i <n; i++){
            cout<<"Ingrese el dato: ";cin>>dato;
            insert(dato);
          }
        }if (op == 2){
          cout<<"Elimina un dato del BST."<<endl;
          int dato;
          cout<<"Dato a eliminar: ";cin>>dato;
          detete(dato);
        }if (op == 3){
          cout<<"Imprime todos los nodos del BST."<<endl;
          cout<<"Arbol: ";
          verarbol();
          cout << endl; 
        }if (op == 4){
          cout<<"Busquedade un dato dado"<<endl;
          int dato;
          cout<<"Dato abuscar: ";cin>>dato;
          cout <<search(dato) <<endl;
        }if (op == 5){
          cout<<"Imprimir en Preorder."<<endl;
          preorder(root);
          cout << endl;
        }if (op == 6){
          cout<<"Imprimir en Inorder"<<endl;
          inorder(root);
          cout << endl;
        }if (op == 7){
          cout<<"Imprimir en Postorder"<<endl;
          postorder(root);;
          cout << endl;
        }if (op == 8){
          cout<<"Imprimir por Level by level"<<endl;
          printLevelOrder(root);
          cout << endl;
        }if(op == 9){
          cout<<"Regresa la altura del BST."<<endl;
          cout<<"Altura: "<<height(root)<<endl;
        }if (op == 10){
          cout<<"Desplegará los ancestros de un dato."<<endl;
          int target;
          cout<<"Ingresa el valor a buscar: ";cin>>target;
          cout<<"Los ancestros son: ";
          printAncestors(root, target);
          cout << endl;
        }if (op == 11){
          cout<<"Indica el nivel en que se encuentra un dato"<<endl;
          int x;
          cout<<"Dato a buscar: ";cin>>x;
          int level = getLevel(root, x);
          if (level)
            cout << x << " esta en el nivel: "<< getLevel(root, x) << endl;
          else
            cout <<"-1"<< endl;

        }if (op == 0){
          x=5;
        }
      }else {
        cout<<"Digite una opcion correcta"<<endl;
     }
    } 
  }

  template<class T>
  bool BinarySearchTree<T>::search(T valor) {
    NodeTree<T> *p = root;
    while(p != nullptr) {
      if (p->data == valor) {
        return true;
      }
      else { 
        p = (valor < p->data ? p->left : p->right);
      }
    }
    return false;
  }

  template<class T>
  void BinarySearchTree<T>::insert(T valor) {
    root = insertRecursive(root, valor);  
  }
  template<class T>
  NodeTree<T> *BinarySearchTree<T>::insertRecursive(NodeTree<T> *p, T valor) {
    if (p == nullptr) 
      p = new NodeTree(valor);
    else if (valor < p->data)
      p->left = insertRecursive(p->left, valor);
    else if (valor > p->data)
      p->right = insertRecursive(p->right, valor);
    else
      std::cout << "El elemento " << valor << " ya existe en el arbol" << std::endl;
    return p;
  }

  template<class T>
  void BinarySearchTree<T>::detete(T valor){
    root = deleteRecursive(root, valor);
  }

  template<class T>
  NodeTree<T> *BinarySearchTree<T>::deleteRecursive(NodeTree<T> *p, T valor){
    if (p == nullptr)
    cout<<endl;
    else if (valor < p->data){
      p->left = deleteRecursive(p->left, valor);
    }else if (valor > p->data ){
      p->right = deleteRecursive(p->left, valor);
    }else{
      NodeTree<T> *q = p;
      if (q->left == nullptr)
        p = q->right;
      else if (q->right == nullptr)
        p = q->left;
      else
        q = reemplazar(q);
      delete(q);
      
    }
    return p;
  }

  template<class T>
  NodeTree<T> *BinarySearchTree<T>::reemplazar(NodeTree<T> *act){
    NodeTree<T> *a, *p;
    p = act;
    a = act->left;
    while (a->right != nullptr){
      p = a;
      a = a->right;
    }
    act -> data = a-> data;
    if (p == act)
      p->left = a->left;
    else
      p->right = a->left;
    return a;
  }

  template<class T>
  void BinarySearchTree<T>::verarbol(){
    verarbolRecursivo(root, 0);
  }

  template<class T>
  void BinarySearchTree<T>::verarbolRecursivo(NodeTree<T> *arb, int n){
    if (!arb) // si no hay arbol a mostrar
        return;
    else { // si hay arbol por mostrar
      verarbolRecursivo(arb->right, n+1); // mostrar su lado derecho
      for (int i=0; i<n; i++); // correr los espacios
      cout<<arb->data<<" ";
      //printf("%d\n", arbol->valor); // mostrar valor de la arbol 
      verarbolRecursivo(arb->left, n+1); // mostrar su lado izquierdo
    }
  }

  template<class T>
void BinarySearchTree<T>::preorder(NodeTree<T>* nodo){
    if(nodo != nullptr){
      std::cout<<nodo->data<<std::endl; // nodo
      preorder(nodo->left); // left
      preorder(nodo->right); // right
    }
}
    

template<class T>
void BinarySearchTree<T>::inorder(NodeTree<T>* nodo){
    if(nodo != nullptr){
    inorder(nodo->left);
    std::cout<<nodo->data<<std::endl;
    inorder(nodo->right);
    }
}

template<class T>
void BinarySearchTree<T>::postorder(NodeTree<T>* nodo){
    if(nodo != nullptr){
    postorder(nodo->left);
    postorder(nodo->right);
    std::cout<<nodo->data<<std::endl;
    }
}

template<class T>
int BinarySearchTree<T>::height(NodeTree<T>* node){
  if (node == nullptr)
    return 0;
  else{
    /* compute the depth of each subtree */
    int lDepth = height(node->left);
    int rDepth = height(node->right);
     
    /* use the larger one */
    if (lDepth > rDepth){
      return(lDepth + 1);

    }else 
    return(rDepth + 1);
  }
}

template<class T>
void BinarySearchTree<T>::printLevelOrder(NodeTree<T>* root){
  int h = height(root);
  int i;
  for (i=1; i<=h; i++){
    cout<<"Nivel "<<i<<" : ";printGivenLevel(root, i);
    cout<<"\n";
    }
}
template<class T>
void BinarySearchTree<T>::printGivenLevel(NodeTree<T>* root, int level){
   if (root == nullptr)
        return;
    if (level == 1)
        cout<<root->data<<" ";
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}
/*
  if (root == nullptr)  return;
  queue<NodeTree<T>*> q;
  q.push(root);
  while (q.empty() == false){
    NodeTree<T>* node = q.front();
    cout << node->data << " ";
    q.pop();
    if (node->left != nullptr)
    q.push(node->left);
    
    if (node->right != nullptr)
      q.push(node->right);
  }
*/


template<class T>
bool BinarySearchTree<T>::printAncestors(NodeTree<T>* root, T target){
  if (root == nullptr)
    return false;
  
  if (root->data == target)
     return true;

  if ( printAncestors(root->left, target) ||
       printAncestors(root->right, target) )
  {
    cout << root->data << " ";
    return true;
  }
  return false;
} 

template<class T>
int BinarySearchTree<T>::getLevelUtil(NodeTree<T>* node, T data, int level){
  if (node == nullptr)
    return 0;

  if (node -> data == data)
    return level;
 
  int downlevel = getLevelUtil(node -> left, data, level + 1);
  if (downlevel != 0)
    return downlevel;
 
  downlevel = getLevelUtil(node->right, data, level + 1);
    return downlevel;
} 

template<class T>
int BinarySearchTree<T>::getLevel(NodeTree<T>* node, T data){
  return getLevelUtil(node, data, 1);
}

#endif // _BST_H_