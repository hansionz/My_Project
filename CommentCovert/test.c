#include"CommentCovert.h"

void CommentCovert(FILE *pfIn, FILE *pfOut)
{
	enum status status = NUL_STATUS;
	while (status != END_STATUS)
	{
		switch (status)
		{
		case NUL_STATUS:
			DoNulStaus(pfIn, pfOut, &status);
			break;
		case C_STATUS:
			DoCStaus(pfIn, pfOut, &status);
			break;
		case CPP_STAUS:
			DoCppStaus(pfIn, pfOut, &status);
			break;
		default:
			break;
		}
	}
}
int main()
{
	FILE *pfIn = NULL;
	FILE *pfOut = NULL;
	pfIn = fopen("input.c", "r");
	if (pfIn == NULL)
	{
		perror("use file to read");
		exit(EXIT_FAILURE);
	}
	pfOut = fopen("output.c", "w");
	if (pfOut == NULL)
	{
		perror("use file to write");
		fclose(pfIn);
		pfIn = NULL;
		exit(EXIT_FAILURE);
	}
	//×¢ÊÍ×ª»»
	CommentCovert(pfIn, pfOut);

	fclose(pfIn);
	pfIn = NULL;
	fclose(pfOut);
	pfOut = NULL;

	return 0;
}