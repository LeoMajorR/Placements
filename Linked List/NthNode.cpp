#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

int nthNodeFromEnd(Node *head, int n){
    Node *temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    if(count < n)
        return -1;
    temp = head;
    for(int i = 1; i < count - n + 1; i++)
        temp = temp->next;
    return temp->data;
}