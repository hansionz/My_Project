#ifndef __COMMENTCOVERT_H__
#define __COMMENTCOVERT_H__

enum status
{
	END_STATUS,
	NUL_STATUS,
	C_STATUS,
	CPP_STAUS
};
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

void CommentCovert(FILE *pfIn, FILE *pfOut);
void DoNulStaus(FILE *pfIn, FILE *pfOut, enum status *ps);
void DoCStaus(FILE *pfIn, FILE *pfOut, enum status *ps);
void DoCppStaus(FILE *pfIn, FILE *pfOut, enum status *ps);



#endif //__COMMENTCOVERT_H__