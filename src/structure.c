#include <stdio.h>
#include <stdlib.h>
#include "../headers/structure.h"

/* 
@requires nothing
@assigns storage for a stack 
@ensures create an empty stack */
stack* empty_stack(){
	stack* p;
	p=malloc(sizeof(stack));
	p->content=malloc(N*sizeof(studentCard));
	p->top=-1;
	return p;
}

/* 
@requires stack p
@assigns nothing
@ensures return 1 if stack p is empty else, return 0 */ 
int is_empty_stack(stack* p){
	return (p->top < 0);
}
 
/*
@requires stack p and a correctly formated studentCard x
@assigns nothing
@ensures add a studentCard x on the top of the stack */
void push(studentCard x, stack* p){
	p->top=p->top + 1;
	p->content[p->top]=x;
}

/*
@requires stack p not empty 
@assigns nothing 
@ensures return the studentCard on top of the stack */ 
studentCard pop(stack* p){
	if (is_empty_stack(p)==1)
		return 0;
	studentCard n;
	n=p->content[p->top];
	p->top=p->top - 1;
	return n;
}

/*
@requires stack p not empty
@assigns nothing
@ensures double the top studentCard of the stack */ 
void double_top(stack* p){
	studentCard n=p->content[p->top];
	push(n,p);
}
