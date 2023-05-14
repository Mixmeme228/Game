#include"list.h"
#include<iostream>
list1 globallist;
list1::list1()
{
	Begin = NULL;
}
void list1::addNode()
{
		list* g = new list;
		list* yk = g;
		Begin = yk;
		g->x = 100;
		g->prev = NULL;
		g->next = NULL;
		list* g1 = new list;
		g1->x = 250;
		g1->prev = yk;
		g1->next = NULL;
		g->next = g1;
		list* g2 = new list;
		g2->x = 400;
		g2->prev = yk->next;
		g2->next = NULL;
		g1->next = g2;
		list* g3 = new list;
		g3->x = 550;
		g3->prev = (yk->next)->next;
		g3->next = NULL;
		g2->next = g3;
		list* g4 = new list;
		g4->x = 700;
		g4->prev = ((yk->next)->next)->next;
		g4->next = NULL;
		g3->next = g4;
		list* g5 = new list;
		g5->x = 850;
		g5->prev = (((yk->next)->next)->next)->next;
		g5->next = NULL;
		g4->next = g5;
		list* g6 = new list;
		g6->x = 1000;
		g6->prev = ((((yk->next)->next)->next)->next)->next;
		g6->next = NULL;
		g5->next = g6;
}