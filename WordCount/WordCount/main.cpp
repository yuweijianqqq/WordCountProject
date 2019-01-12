#include<stdafx.h>

int CheckFlieName(char filename[])
{
	if (_access(filename, 0) != 0) { return -1; }	// 文件不存在 
	if (_access(filename, 4) != 0) { return -2; }	// 文件无访问权限
	return 1;
}

void CommandProcessing(char order[], char filename[])
{
	switch (order[1])
	{
	case 'c':
		printf("字符数:  %d\n", CountCharacter(filename));
		break;
	case 'w':
		printf("单词数:  %d\n", CountWord(filename));
		break;
	case 'l':
		printf("行数:  %d\n", CountLine(filename));
		break;
	case 'a':
		// CountComplex(filename);
		break;
	}
}
int main(int argc, char* argv[])
{
	if (strcmp(argv[1], "-x") == 0)
	{
		// 调用带有图形界面的程序
	}
	else 
	{
		// 调用文件
		char filename[100];
		memset(filename, 0, sizeof(filename));
		strcpy_s(filename, argv[2]);
		int flag = CheckFlieName(filename);

		// 检查文件
		if (flag == -1)
		{
			printf("文件不存在！请重新输入！");
			return 0;
		}
		if (flag == -2)
		{
			printf("文件无访问权限，请检查文件权限！");
			return 0;
		}

		// 处理统计
		if (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "-w") == 0
			|| strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "-a") == 0)
		{
			CommandProcessing(argv[1], filename);
		}
	}
	
	printf("Prease any key to continue...\n");
	system("pause");
	return 0;
}


