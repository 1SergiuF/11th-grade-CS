#include <fstream>
using namespace std;

ifstream fin("bst.in");
ofstream fout("bst.out");

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key {k}, left {nullptr}, right {nullptr}
    {}
};

class BST {
public:
    BST() : root {nullptr}
    {}

    void Insert(int key)
    {
        if (root == nullptr)
        {
            root = new Node(key);
            return;
        }

        Node* curr = root;
        while (true)
        {
            if (key < curr->key)
                if (curr->left == nullptr)
                {
                    curr->left = new Node(key);
                    break;
                }
                else
                    curr = curr->left;

            else if (key >= curr->key)
                if (curr->right == nullptr)
                {
                    curr->right = new Node(key);
                    break;
                }
                else
                    curr = curr->right;

            else
                return;
        }
    }

    void InOrdine(Node* ptr)
    {
        if (!ptr) return;

        InOrdine(ptr->left);
        fout << ptr->key << ' ';
        InOrdine(ptr->right);
    }

    void AfiseazaInOrdine()
    {
        InOrdine(root);
    }

    void DezalocaBST(Node* ptr)
    {
        if (!ptr) return;

        DezalocaBST(ptr->left);
        DezalocaBST(ptr->right);
        delete ptr;
    }

    ~BST()
    {
        DezalocaBST(root);
    }

private:
    Node* root;
};

int main()
{
    int n, val;
    BST bst;

    fin >> n;
    while (n--)
    {
        fin >> val;
        bst.Insert(val);
    }

    bst.AfiseazaInOrdine();

    return 0;
}