#include "Sample_BST2.h"

int main()
{
    BST<int> bst;
    vector<int> v;
    // int x;
    // cin >> x;
    // while (x != -1)
    // {
    //     bool b = bst.insert(x);
    //     if (!b)
    //         v.push_back(x);
    //     cin >> x;
    // }

    vector<int> arr = {3, 5, 1, 6, 2, 4, 9, 7};
    for (int i = 0; i < arr.size(); i++)
    {
        bool b = false;
        b = bst.insert(arr[i]);
        if (!b)
            v.push_back(arr[i]);
    }

    cout << "Rejected Keys are: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    cout << "Total rejected keys " << v.size() << endl;

    return 0;
}