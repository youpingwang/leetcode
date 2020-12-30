//
// Created by CC on 12/23/20.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int value;
    struct ListNode *next;
}ListNode;

ListNode* createList(int n);
void travelList(ListNode *pHead);
//result store in array
int* reverseList(ListNode *pHead, int* returnSize);
iteratively or recursively
struct ListNode* reverseList(struct ListNode* head);


int main()
{
    ListNode *pList;
    int *listArray;
    int n = 5, i, listNumber;

    printf("Please input the number of the 1-linklist: ");
    scanf("%d", &n);
    printf("\n");
    pList = createList(n);

    printf("The travelList is:  ");
    travelList(pList);

    printf("The reverseList is: ");
    listArray = reverseList(pList, &listNumber);

    for (i = 0; i <= listNumber - 1; ++i)
        printf("%d\t", listArray[i]);
    printf("\n");
    free(listArray);

    return 0;
}


//create n nodes of 1-linklist
ListNode* createList(int n)
{
    ListNode *pHead, *pNode, *pCurr;
    int i = 0;

    if (n < 1)
    {
        printf("createList FAILURE: n < 1");
        exit(EXIT_FAILURE);
    }
//  create the head of the 1-linklist,
//  and the head node store the length of the 1-linklist
    pHead = (ListNode*)malloc(sizeof(ListNode));
    pCurr = pHead;

    while (i <= n - 1)
    {
        pNode = (ListNode*)malloc(sizeof(ListNode));
        printf("Please input the %dth of %d node: ", i, n);
        scanf("%d", &pNode->value);
        pCurr->next = pNode;
        pCurr = pCurr->next;
        i++;
    }
    pCurr->next = NULL;
    pHead->value = n;

    return pHead;
}

void travelList(ListNode *pHead)
{
    ListNode *pCurr;

    if (pHead == NULL)
    {
        printf("travelList FAILURE: pHead is NULL");
        exit(EXIT_FAILURE);
    }

    pCurr = pHead -> next;
    while (pCurr != NULL)
    {
        printf("%d\t", pCurr->value);
        pCurr = pCurr->next;
    }
    printf("\n");
}

int* reverseList(ListNode *pHead, int* returnSize)
{
    ListNode *pCurr;
    int number = 0, i;

    if (pHead == NULL )
    {
        printf("reverseList FAILURE: pHead is NULL");
        exit(EXIT_FAILURE);
    }
    if (returnSize == NULL)
    {
        printf("reverseList FAILURE: returnSize is NULL");
        exit(EXIT_FAILURE);
    }

    pCurr = pHead->next;
    //First walk all nodes in order to get the number of the 1-linklist
    while (pCurr != NULL)
    {
        number++;
        pCurr = pCurr -> next;
    }
    int *returnArray = (int *)malloc(sizeof(int) * number);

    pCurr = pHead->next;
    // walk all nodes in order and reversely store in the array returnArray
    for (i = number - 1; pCurr != NULL; i--)
    {
        returnArray[i] = pCurr->value;
        pCurr = pCurr->next;
    }
    *returnSize = number;

    return returnArray;
}
