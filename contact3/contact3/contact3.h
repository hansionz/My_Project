#ifndef __CONTACT3_H__  
#define __CONTACT3_H__  

#include<stdio.h>  
#include<assert.h>  
#include<string.h>  
#include<stdlib.h>  
#pragma warning(disable:4996)  

#define MAX 2  
#define FILENAME peoinfo.dat
enum SLECT
{
	EXIT,
	ADD,
	DELE,
	SEARCH,
	ALERT,
	SHOW,
	EMPTY,
	SORT
};
typedef struct People
{
	char name[20];
	char sex[10];
	int  age;
	char tele[20];
	char addr[30];
}people;

typedef struct Contact
{
	people *data;
	int count;
	int capacity;
}contact, *pcontact;

void Add_people(contact *book);
void Search_people(contact *book);
void Dele_people(contact *book);
void Alert_people(contact *book);
void Show_people(contact *book);
void Sort_people(contact *book);
void Empty_people(contact *book);
void Init_contact(contact *book);
void check_capacity(contact *book);
void Save_contact(contact *book);
void Load_people(contact *book);

#endif //__CONTACT3_H__