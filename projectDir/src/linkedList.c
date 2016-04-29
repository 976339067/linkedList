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

#ifdef __LIST_TEST__
int main(int argc, char *argv[])
{
	printf("in %s, line :%d\n", __func__, __LINE__);

	return 0;
}
#endif
