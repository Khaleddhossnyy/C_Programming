// Linked list
// 1 way linked list
// 2 way linked list
#include <stdio.h>
#include "STD_Types.h"
#include <stdlib.h>

#define Null ((void*)0)

typedef struct Node Node;

struct Node{
	u32 data;
	Node *Prev;
	Node *Next;
};

Node *first = Null;
Node *last = Null;

Node *create(u32 value);
void add(Node *ptr);
void DisaplyAll(void);
Node *Search(u32 value);
void InsertAfter(Node *Pafter, Node *Pnew);
void Delete(Node *Pdelete);

void main(void){
	u32 option=0; 
	while (option != 6)
	{   printf("for Adding: press 1\n");
		printf("for Display all: press 2\n");
		printf("for Searching: press 3\n");
		printf("for Inserting: press 4\n");
		printf("for Exit: press 6\n");
		printf("for Deleting: press 7\n");
		scanf("%d",&option);
		
		if(1 == option)
		{
			Node * pointer_to_Node=Null;
			u32 Value;
			printf("Enter the value to be put inside the node: ");
			scanf("%d",&Value);
			pointer_to_Node=create(Value);
			add(pointer_to_Node);
		}
		else if(2 == option)
		{
			printf("All the elements in the list are: \n");
			DisaplyAll();
		}
		else if(6== option)
		{
			printf("See youu <3");
			break;
		}
		else if(3==option)
		{
			Node *Searching_pointer=Null;
			int Searching_Value;
			printf("Enter the value you want to search for : \n");
			scanf("%d",&Searching_Value);
			Searching_pointer= Search(Searching_Value);
			if (Searching_pointer == Null)
			{
				printf("This node doesn't exist\n");
			}
			else
			{
				printf("The value of this node is : %d \n",Searching_pointer->data);
			}
		}
		else if(4==option)
		{
			u32 After_this_Value;
			u32 Value;
			Node *search;
			Node * Adding;
			printf("Please enter the value to put the new value after it :  \n");
			scanf("%d",&After_this_Value);
			search = Search(After_this_Value);
			
			printf("Enter the value you want to add in this new node : \n");
			scanf("%d",&Value);
			Adding = create(Value);
			InsertAfter(search,Adding);
			printf("New node inserted successfuly\n");
			
		}
		else if(5==option)
		{
			u32 value;
			Node * search=Null;
			printf("Enter the value of the node to search for : \n");
			scanf("%d",&value);
			search = Search(value);
			if (search != Null)
			{
				Delete(search);
				printf("Deleted");
			}
			else
			{
				printf("Not found");
			}
		}
	}
}

Node *create(u32 value){
	Node *New = (Node*)malloc(sizeof(Node));
	New->data = value; 
	New->Prev = Null;
	New->Next = Null;
	return New;
} 

void add(Node *ptr){
	if(first==Null){
		first = last = ptr;
	}else{
		ptr->Prev = last;
		last->Next = ptr;
		last = ptr;
	} 
}

void DisaplyAll(void){
	u8 count=0;
	
	Node *display = first;
	
	while(display!=Null){
		count++;
	printf("%d\n", display->data);
	display=display->Next;
	}
	
	printf("number of elemets = %d\n", count);
	
	if(count==0){
		printf("Linked list empty");
	}
	/*if(first==Null){
		printf("Linked list empty");
	}*/
}

Node *Search(u32 value)
{
    Node *Psearch = first;
    while(Psearch != Null)
    {
        if(Psearch->data == value)
        {
            return Psearch;
        }
        else
        {
            Psearch = Psearch->Next;
        }
    }
    return Null;
}

void InsertAfter(Node *Pafter, Node *Pnew)
{
        Pnew->Prev=Pafter;
        Pnew->Next=Pafter->Next;
        Pafter->Next->Prev=Pnew;
        Pafter->Next=Pnew;
}

void Delete(Node *Pdelete)
{
    if(Pdelete==first)
    {
        if(Pdelete==last)
        {
            first=last=Null;
        }
        else
        {
            first=first->Next;
            first->Prev=Null;
        }
    }
    else if(Pdelete==last)
    {
        last=last->Prev;
        last->Next=Null;
    }
    else
    {
        Pdelete->Prev->Next=Pdelete->Next;
        Pdelete->Next->Prev=Pdelete->Prev;
    }
    free(Pdelete);
}
