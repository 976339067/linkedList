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
 * list head type
 */
typedef struct listHead{
	int listLength;			/*list length*/
	listNode_t headNode;	/*headNode.next :list 1st node pointer; headNode.previous :list last node pointer*/
}listHead_t;

/*
 * boolean type
 */
typedef enum
{
	FALSE = 0,
	TRUE = 1,
}bool;

/*
 * list function return type
 */
typedef enum{
	LIST_OPER_SUCCESS = 0,		/*success*/
	LIST_OPER_WRONG_PARAM = 1,	/*wrong parameter*/
	LIST_OPER_FAILURE = 2,		/*failure*/
}listOperStatus_t;

typedef void pFreeFunc_t(void *);

listOperStatus_t initList(listHead_t *pListHead);

listOperStatus_t clearList(listHead_t *pListHead, pFreeFunc_t pFreeFunc);

listOperStatus_t listAppendNode(listHead_t *pListHead, listNode_t *pAppendNode);

bool listEmpty(listHead_t listHead);

#endif /* PROJECTDIR_H_LINKEDLIST_H_ */
