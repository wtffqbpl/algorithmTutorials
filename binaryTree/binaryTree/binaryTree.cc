#include <iostream>


#define BinNodePosi(T) BinNode<T>*


template<typename T> struct BinNode {
    BinNodePosi(T) parent, lChild, rChild;
    T data;
    int height;
    int size();

    BinNodePosi(T) insertAsLC(T const &);
    BinNodePosi(T) insertAsRC(T const &);
    BinNodePosi(T) succ();   // in-order tranverse the successive node for current node.
    template <typename VST> void travLevel(VST &);   // tranverse tree in level order.
    template <typename VST> void travPre(VST &);        // pre-order
    template <typename VST> void travIn(VST &);           //  in-order
    template <typename VST> void travPost(VST &);       // post-order
    /* data */
};

template <typename T> BinNodePosi(T) BinNode<T>::insertAsLC(T const & e)
{
    return lChild = new BinNode(e, this);
}

template <typename T> BinNodePosi(T) BinNode<T>::insertAsRC(T const & e)
{
    return rChild = new BinNode(e, this);
}

template <typename T> int BinNode<T>::size()
{
    int s = 1;
    if (lChild) s += lChild->size();
    if (rChild) s += rChild->size();

    return s;
}  // O(n = |size| )


template <typename T> class BinTree
{
protected:
    int _size;
    BinNodePosi(T) _root;
    virtual int updateHeight(BinNodePosi(T) x);
    void updateHeightAbove(BinNodePosi(T) x);

public:
    int size() const {return _size; }
    bool empty() const {return !_root; }
    BinNodePosi(T) root() const {return _root; }
};

#define stature(p) ( (p) ? (p)->height : -1)

template <typename T> int BinTree<T>::updateHeight(BinNodePosi(T) x)
{
    return x->height = 1 + max(stature(x->lChild), stature(x->rChild));
} // O(1)

template<typename T> void BinTree<T>::updateHeightAbove(BinNodePosi(T) x)
{
    while (x)
        { updateHeight(x); x = x->parent; }
} // O(n = depth(x))