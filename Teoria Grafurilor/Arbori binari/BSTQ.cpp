#include <fstream>
#include <vector>
using namespace std;
vector<int> noduri;
ifstream fin("bstq.in");
ofstream fout("bstq.out");

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int key) : 
        key {key}, 
        left {nullptr}, 
        right {nullptr}
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

    void PushInOrdine(Node* ptr)
    {
        if (!ptr) return;

        PushInOrdine(ptr->left);
        noduri.push_back(ptr->key);
        PushInOrdine(ptr->right);
    }

    void AfiseazaVal(int k)
    {
        PushInOrdine(root);
        fout << noduri[k - 1] << '\n';
    }

    void DezalocaArbore(Node* ptr)
    {
        if (!ptr) return;

        DezalocaArbore(ptr->left);
        DezalocaArbore(ptr->right);
        delete ptr;
    }

    ~BST()
    {
        DezalocaArbore(root);
    }

private:
    Node* root;
};

int main()
{
    int n;
    BST A;
    fin >> n;
    int x, y;

    for (int i = 1; i <= n; ++i)
    {
        fin >> x >> y;
        if (x == 1)
            A.Insert(y);
        else
        {
            A.AfiseazaVal(y);
            noduri.clear();
        }
    }
}