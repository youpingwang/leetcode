//
// Created by CC on 12/28/20.
//

/*
 Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.


Example 1:

Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3


Constraints:

0 <= index, val <= 1000
Please do not use the built-in LinkedList library.
At most 2000 calls will be made to get, addAtHead, addAtTail,  addAtIndex and deleteAtIndex.

 */
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode{
    int value;
    struct listNode *next;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *pHead = (MyLinkedList *)malloc(sizeof(MyLinkedList));

    pHead->next = NULL;
    pHead->value = 0;

    return pHead;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    int counter = 0;
    MyLinkedList *pCurr;

    if (index < 0 || index > 1000)
        return -1;

    pCurr = obj;
    while (counter < index)
    {
        pCurr = pCurr->next;
        counter++;
    }
    if (pCurr == NULL)
        return -1;

    return pCurr->value;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList *pNode = (MyLinkedList *)malloc(sizeof(MyLinkedList));

//Switch the value of obj with the new pNode, rather than switch the nodes itself.
    if (obj->value != 0)
    {
        pNode->value = obj->value;
        pNode->next = obj->next;
        obj->next = pNode;
    }
    obj->value = val;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList *pCurr;
    MyLinkedList *pNode = (MyLinkedList *)malloc(sizeof(MyLinkedList));

    pNode->value = val;
    pNode->next = NULL;
    pCurr = obj;
    while (pCurr->next != NULL)
        pCurr = pCurr->next;
    pCurr->next = pNode;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    int listNumber = 0;
    MyLinkedList *pCurr;
    MyLinkedList *pNode = (MyLinkedList *)malloc(sizeof(MyLinkedList));

    pCurr = obj;
//    To get the length of 1-linklist
    while (pCurr != NULL)
    {
        pCurr = pCurr->next;
        listNumber++;
    }

    if (index == 0)
    {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    else if (index == listNumber)
    {
        myLinkedListAddAtTail(obj, val);
        return;
    }
    else if (index > listNumber)
    {
        printf("FUNCTION myLinkedListAddAtIndex: The index is greater than the length of 1-linklist\n");
        return;
    }

    pNode->value = val;
    listNumber = 0;
    pCurr = obj;
    while (listNumber < index - 1)
    {
        pCurr = pCurr->next;
        listNumber++;
    }
    pNode->next = pCurr->next;
    pCurr->next = pNode;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    MyLinkedList *pCurr;
    int counter = 0;

    pCurr = obj;
//    To get the length of the list
    while (pCurr != NULL)
    {
        pCurr = pCurr->next;
        counter++;
    }

    if (index > counter - 1)
    {
        printf("FUNCTION myLinkedListDeleteAtIndex: The index is invalid!");
        return;
    }

    pCurr = obj;
    if (index == 0)
    {//Delete the node in head
        pCurr->value = pCurr->next->value;

    }
    else if (index == counter - 1)
    {//Delete the node in tail

    }
    //Delete the node within list

}

void myLinkedListFree(MyLinkedList* obj) {

}

void myLinkedListGetAll(MyLinkedList *obj)
{
    MyLinkedList *pCurr;

    pCurr = obj;
    while (pCurr != NULL)
    {
        printf("%d\t", pCurr->value);
        pCurr = pCurr->next;
    }
    printf("\n");

}
/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/

int main()
{
    MyLinkedList *pList;

    pList = myLinkedListCreate();
    myLinkedListGetAll(pList);
    myLinkedListAddAtHead(pList, 1);
    myLinkedListGetAll(pList);
    myLinkedListAddAtHead(pList, 2);
    myLinkedListGetAll(pList);
    myLinkedListAddAtTail(pList, 3);
    myLinkedListGetAll(pList);
    myLinkedListAddAtTail(pList, 4);
    myLinkedListGetAll(pList);
    myLinkedListAddAtHead(pList, 5);
    myLinkedListGetAll(pList);
    myLinkedListAddAtIndex(pList, 6, 10);
    myLinkedListGetAll(pList);

}
