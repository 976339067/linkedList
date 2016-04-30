/*
 * linkedList.c
 *
 *  Created on: Apr 28, 2016
 *      Author: hui
 */
#include <stdio.h>
#include "../h/linkedList.h"

#define	__LIST_TEST__

listOperStatus_t initList(listHead_t *listHead)
{
	/*check parameter*/
	if(NULL == listHead)
	{
		return LIST_OPER_WRONG_PARAM;
	}

	/*set list length 0*/
	listHead->len = 0;

	/*set list head node next pointer point head node itself*/
	listHead->headNode.next = &(listHead->headNode);

	/*set list head node previous pointer point head node itself*/
	listHead->headNode.previous = &(listHead->headNode);

	/*return success*/
	return LIST_OPER_SUCCESS;
}

listOperStatus_t clearList(listHead_t *listHead, pFreeFunc_t pFreeFunc)
{
	listNode_t *pHeadNode = NULL;
	listNode_t *pCurrentNode = NULL;
	listNode_t *pNectNode = NULL;
	/*check parameter*/
	if(NULL == listHead)
	{
		return LIST_OPER_WRONG_PARAM;
	}

	if(NULL == pFreeFunc)
	{
		return LIST_OPER_WRONG_PARAM;
	}

	pHeadNode = &(listHead->headNode);
	/*delete list 1st node until only the head node left.free all the list node,but not free list head*/
	for(pCurrentNode = pHeadNode->next; pCurrentNode != pHeadNode; pCurrentNode = pHeadNode->next)
	{
		pNectNode = pCurrentNode->next;

		/*head node member next point the delete node's next node*/
		pHeadNode->next = pNectNode;

		/*the delete node's next node member previous point head node*/
		pNectNode->previous = pHeadNode;

		/*free current node*/
		pFreeFunc(pCurrentNode);
		pCurrentNode = NULL;

		/*update head node length*/
		listHead->len--;
	}

	/*set list length 0*/
	listHead->len = 0;

	/*return success*/
	return LIST_OPER_SUCCESS;
}

listOperStatus_t listAppendNode(listHead_t *listHead, listNode_t *pAppendNode)
{
	listNode_t *pHeadNode = NULL;
	listNode_t *pLastNode = NULL;
	/*check parameter*/
	if(NULL == listHead)
	{
		return LIST_OPER_WRONG_PARAM;
	}
	if(NULL == pAppendNode)
	{
		return LIST_OPER_WRONG_PARAM;
	}

	pHeadNode = &(listHead->headNode);
	pLastNode = pHeadNode->previous;
	/*configure the node append to the list: member next point to head node, previous point to last node*/
	pAppendNode->next = pHeadNode;
	pAppendNode->previous = pLastNode;

	/*configure the original list last node: member next point the append node,previous keep original value*/
	pLastNode->next = pAppendNode;

	/*configure the list head node: member previous point the append node*/
	pHeadNode->previous = pAppendNode;

	/*update list length*/
	listHead->len++;

	/*return success*/
	return LIST_OPER_SUCCESS;
}

#ifdef __LIST_TEST__
int main(int argc, char *argv[])
{
	printf("in %s, line :%d\n", __func__, __LINE__);

	return 0;
}
#endif
