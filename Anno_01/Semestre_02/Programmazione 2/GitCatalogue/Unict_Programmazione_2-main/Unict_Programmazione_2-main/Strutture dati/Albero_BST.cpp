#include <iostream>

using namespace std;

class BST_Node
{
public:
    BST_Node(int d) : data(d), left(nullptr), right(nullptr), parent(nullptr) {}

    int getData() const { return data; }
    BST_Node* getLeft() const { return left; }
    BST_Node* getRight() const { return right; }
    BST_Node* getParent() const { return parent; }

    void setLeft(BST_Node* l) { left = l; }
    void setRight(BST_Node* r) { right = r; }
    void setParent(BST_Node* p) { parent = p; }

private:
    int data;
    BST_Node* left;
    BST_Node* right;
    BST_Node* parent;
};

class BST
{
public:
    BST() : root(nullptr) {}

    ~BST()
    {
        clear(root);
        root = nullptr;
    }

    void insert(int val)
    {
        BST_Node* x = root;
        BST_Node* y = nullptr;

        while (x != nullptr)
        {
            y = x;
            if (val == x->getData())
                return;
            else if (val < x->getData())
                x = x->getLeft();
            else
                x = x->getRight();
        }

        BST_Node* newnode = new BST_Node(val);
        newnode->setParent(y);

        if (root == nullptr)
            root = newnode;
        else if (val < y->getData())
            y->setLeft(newnode);
        else
            y->setRight(newnode);
    }

    BST_Node* search(int val)
    {
        return search(root, val);
    }

    BST_Node* min()
    {
        return min(root);
    }

    BST_Node* successivo(int val)
    {
        BST_Node* node = search(val);
        if (!node) return nullptr;

        if (node->getRight())
            return min(node->getRight());

        BST_Node* p = node->getParent();
        while (p != nullptr && node == p->getRight())
        {
            node = p;
            p = p->getParent();
        }
        return p;
    }

    bool remove(int val)
    {
        BST_Node* node = search(val);
        if (!node) return false;

        if (node->getLeft() == nullptr)
        {
            trapianta(node, node->getRight());
        }
        else if (node->getRight() == nullptr)
        {
            trapianta(node, node->getLeft());
        }
        else
        {
            BST_Node* next = min(node->getRight());

            if (next->getParent() != node)
            {
                trapianta(next, next->getRight());
                next->setRight(node->getRight());
                next->getRight()->setParent(next);
            }

            trapianta(node, next);
            next->setLeft(node->getLeft());
            next->getLeft()->setParent(next);
        }

        delete node;
        return true;
    }

    void print(ostream& os) const
    {
        os << "=== PRE ORDER ===" << endl;
        pre_order_print(root,os);
        os << "\n=== IN ORDER ===" << endl;
        in_order_print(root,os);
        os << "\n=== POST ORDER ===" << endl;
        post_order_print(root,os);
        os << endl;
    }

private:
    BST_Node* root;

    void trapianta(BST_Node* u, BST_Node* v)
    {
        if (u->getParent() == nullptr)
            root = v;
        else if (u == u->getParent()->getLeft())
            u->getParent()->setLeft(v);
        else
            u->getParent()->setRight(v);

        if (v != nullptr)
            v->setParent(u->getParent());
    }

    BST_Node* search(BST_Node* node, int val)
    {
        while (node != nullptr)
        {
            if (node->getData() == val)
                return node;
            else if (val < node->getData())
                node = node->getLeft();
            else
                node = node->getRight();
        }
        return nullptr;
    }

    BST_Node* min(BST_Node* node)
    {
        if (!node) return nullptr;
        while (node->getLeft() != nullptr)
        {
            node = node->getLeft();
        }
        return node;
    }

    void pre_order_print(BST_Node* x, ostream& os) const
    {
        if (!x) return;
        os << x->getData() << " ";
        pre_order_print(x->getLeft(),os);
        pre_order_print(x->getRight(),os);
    }

    void in_order_print(BST_Node* x, ostream& os) const
    {
        if (!x) return;
        in_order_print(x->getLeft(), os);
        os << x->getData() << " ";
        in_order_print(x->getRight(), os);
    }

    void post_order_print(BST_Node* x,ostream& os) const
    {
        if (!x) return;
        post_order_print(x->getLeft(), os);
        post_order_print(x->getRight(), os);
        os << x->getData() << " ";
    }

    void clear(BST_Node* x)
    {
        if (!x) return;
        clear(x->getLeft());
        clear(x->getRight());
        delete x;
    }
};

ostream& operator << (ostream& os, const BST& b) 
{
    b.print(os);
    return os;
}

int main()
{
    BST albero;

    albero.insert(50);
    albero.insert(30);
    albero.insert(10);
    albero.insert(40);
    albero.insert(70);
    albero.insert(20);
    albero.insert(60);
    albero.insert(80);

    cout << "=== PRE ALBERO ===" << endl;
    cout << albero;

    albero.remove(50);
    
    cout << "\n=== POST ALBERO ===" << endl;
    cout << albero;

    return 0;
}
