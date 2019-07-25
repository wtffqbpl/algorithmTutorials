#include <iostream>


template<typename T>
struct binaryTreeNode {
    T element;
    binaryTreeNode<T>* leftChild;
    binaryTreeNode<T>* rightChild;

    binaryTreeNode() : element(0), leftChild(nullptr), rightChild(nullptr) {}
    binaryTreeNode(const T& theElement)
            : element(theElement)
            , leftChild(nullptr)
            , rightChild(nullptr) {}
    binaryTreeNode(const T& theElement, binaryTreeNode* theLeftChild, binaryTreeNode* theRightChild)
                            : element(theElement)
                            , leftChild(theLeftChild)
                            , rightChild(theRightChild) {}
}

template<typename T>
class binaryTree {
public:
    virtual ~binaryTree() {};
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual void preOrder(void (*) (T*)) = 0;
    virtual void inOrder(void (*) (T*)) = 0;
    virtual void postOrder(void (*) (T*)) = 0;
    virtual void postOrder(void(*) T(*)) = 0;
    virtual void levelOrder(void (*) T(*)) = 0;
}

template<typename E>
class linkedBinaryTree : public binaryTree<binaryTreeNode<E>>
{
public:
    linkedBinaryTree() 
        : root(nullptr)
        , treeSize(0) {}
    ~linkedBinaryTree() {ereas();}
    bool empty() const {return treeSize == 0;}
    int size() const {return treeSize;}
    void preOrder(void(*theVisit)(binaryTreeNode<E>*)) {
        visit = the
    }

private:
    binaryTreeNode<E>* root;
    int treeSize;
    static void (*visit)(binaryTreeNode<E>*);
    static void preOrder(binaryTreeNode<E>* t);
    static void inOrder(binaryTreeNode<E>* t);
    static void postOrder(binaryTreeNode<E>* t);
    static void dispose(binaryTreeNode<E>* t) {delete t;};

};

template<typename K, typename E>
pair<const K, E>* binarySearchTree<K, E>::find(const K& theKey) const
{
    

}