#include "Sample_BST.h"

int main()
{
    BST<int> bst;
    int x;
    cin >> x;
    while (x != -1)
    {
        bst.insert(x);
        cin >> x;
    }

    // height of BST
    cout << "Height of BST: " << bst.height() << endl;

    // leaf count
    cout << "No. of Leaf Nodes: " << bst.leafCount() << endl;

    return 0;
}