/*
 * linkedList.h
 *
 *  Created on: Apr 28, 2016
 *      Author: hui
 */

#ifndef PROJECTDIR_H_LINKEDLIST_H_
#define PROJECTDIR_H_LINKEDLIST_H_

/*
 * list node type
 */
typedef struct listNode{
	struct listNode *previous;	/*previous node pointer*/
	struct listNode *next;		/*next node pointer*/
}listNode_t;

/*
 * list length type
 */
typedef	int	listLength_t;

/*
 * list head type
 */
typedef struct listHead{
	listLength_t	listLength;	/*list length*/
	listNode_t		headNode;	/*headNode.next :list 1st node pointer; headNode.previous :list last node pointer*/
}listHead_t;

/*
 * boolean type
 */
typedef enum
{
	FALSE = 0,
	TRUE = 1,
}BOOL_t;

/*
 * list function return type
 */
typedef enum{
	LIST_OPER_SUCCESS = 0,		/*success*/
	LIST_OPER_WRONG_PARAM = 1,	/*wrong parameter*/
	LIST_OPER_FAILURE = 2,		/*failure*/
}listOperStatus_t;

typedef void pFreeFunc_t(void *);

/*
 * initial the list
 */
listOperStatus_t initList(listHead_t *pListHead);

/*
 * clear the list, not free list head, free all the node,so the list can be continue used
 */
listOperStatus_t clearList(listHead_t *pListHead, pFreeFunc_t pFreeFunc);

/*
 * destroy the list, free list head, free all the node, so the list cannot be continue used
 */
listOperStatus_t destroyList(listHead_t **pListHead, pFreeFunc_t pFreeFunc);

/*
 * append node to the list tail
 */
listOperStatus_t listAppendNode(listHead_t *pListHead, listNode_t *pAppendNode);

/*
 * judge whether the list is empty
 */
BOOL_t listEmpty(listHead_t listHead);

/*
 * get the list length
 */
listLength_t listLengthGet(listHead_t listHead);

#endif /* PROJECTDIR_H_LINKEDLIST_H_ */
