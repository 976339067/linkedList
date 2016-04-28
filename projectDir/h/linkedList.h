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
	int len;			/*list length*/
	listNode_t node;	/*node.next :list head node pointer; node.previous :list tail node pointer*/
}listHead_t;

/*
 * list function return type
 */
typedef enum{
	LIST_OPER_SUCCESS = 0,		/*success*/
	LIST_OPER_WRONG_PARAM = 1,	/*wrong parameter*/
	LIST_OPER_FAILURE = 2,		/*failure*/
}listOperStatus_t;

listOperStatus_t initList(listHead_t *listHead);

#endif /* PROJECTDIR_H_LINKEDLIST_H_ */
