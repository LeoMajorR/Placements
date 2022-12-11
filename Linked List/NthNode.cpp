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
//nth Node from end of linked list
//Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.
//Algorithm:
//1. Traverse the linked list from head to end and count the number of nodes. Let the count be n.
//2. Now traverse the list from head to (n – k + 1)th node and return the node at (n – k + 1)th node.
int nthNodeFromEnd(Node *head, int n){
    Node *temp = head;
    int len = 0;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    if(len < n)
        return -1;
    temp = head;
    for(int i=1; i<len-n+1; i++)
        temp = temp->next;
    return temp->data;
}