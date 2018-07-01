//为了方便理解，下面的代码存在向原状态装换的过程，这是不必要的，已经注释掉。
#include"CommentCovert.h"

//正常代码处理
void DoNulStaus(FILE *pfIn, FILE *pfOut, enum status *ps)
{
	int first = fgetc(pfIn);
	switch (first)
	{
	case '/':
	{
				int second = fgetc(pfIn);
				switch (second)
				{
				case'*':
				{
						   fputc('/', pfOut);
						   fputc('/', pfOut);
						   *ps = C_STATUS;
				}
					break;
				case'/':
				{
						   fputc(first, pfOut);
						   fputc(second, pfOut);
						   *ps = CPP_STAUS;
				}
					break;
				default:
				{
						   fputc(first, pfOut);
						   fputc(second, pfOut);
						   /**ps = NUL_STATUS;*/
				}
					break;
				}
	}
		break;
	case EOF:
	{
				fputc(first, pfIn);
				*ps = END_STATUS;
	}
		break;
	default:
	{
			   fputc(first, pfOut);
			   /**ps = NUL_STATUS;*/
	}
		break;
	}
}
//c风格代码注释区处理
void DoCStaus(FILE *pfIn, FILE *pfOut, enum status *ps)
{
	int first = fgetc(pfIn);
	switch (first)
	{
	case'*':
	{
			   int second = fgetc(pfIn);
			   switch (second)
			   {
			   case'/':
			   {
						  int third = fgetc(pfIn);
						  if (third != '\n')
						  {
							  fseek(pfIn, -1, SEEK_CUR);
							  //如果third不是'\n'，那个字符已经被读走，应该把那个字符还回去在放一个'\n'
							  fputc('\n', pfOut);
						  }
						  else
						  {
							  fputc(third, pfOut);
						  }
						  *ps = NUL_STATUS;
			   }
				   break;
			   case'*':
			   {
						  fputc(first, pfOut);
						  fseek(pfIn, -1, SEEK_CUR);
						  /**ps = C_STATUS;*/
						  //把fp指针移动到离文件当前位置-1字节处,回退1个字符
						  //因为第二个字符如果是*要和/一起判断是否是C语言注释风格结束
			   }
				   break;
			   default:
			   {
						  fputc(first, pfOut);
						  fputc(second, pfOut);
						  /**ps = C_STATUS;*/
			   }
				   break;
			   }
	}
		break;
	case'\n':
	{
				fputc(first, pfOut);
				fputc('/', pfOut);
				fputc('/', pfOut);
				/**ps = C_STATUS;*/
	}
		break;
	default:
	{
			   fputc(first, pfOut);
			   /**ps = C_STATUS;*/
	}
		break;
	}
}
//c++风格代码注释区处理
void DoCppStaus(FILE *pfIn, FILE *pfOut, enum status *ps)
{
	int first = fgetc(pfIn);
	switch (first)
	{
	case'\n':
	{
				fputc(first, pfOut);
				*ps = NUL_STATUS;
	}
		break;
	case EOF:
		fputc(first, pfOut);
		*ps = END_STATUS;
		break;
	default:
		fputc(first,pfOut);
		/**ps = CPP_STAUS;*/
		break;
	}
}