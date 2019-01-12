// 实现基本功能

#include<stdafx.h>

int CountCharacter(char file[])
{
	int character_num = 0;
	char ch;
	freopen(file, "r", stdin);
	while ((ch = getchar()) != EOF)
	{
		if (ch != ' ' && ch != '\n' &&ch != '\t')
		{
			character_num++;
		}
	}
	fclose(stdin);
	return character_num;
}

int CountWord(char file[])
{
	int word_num = 0;
	int word = 0;
	char ch;
	freopen(file, "r", stdin);
	while ((ch = getchar()) != EOF)
	{
		if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || ch == '_')
		{
			word = 1;
		}
		else
		{
			if (word == 1)
			{
				word_num++;
				word = 0;
			}
		}
	}
	fclose(stdin);
	return word_num;
}

int CountLine(char file[])
{
	int line_num = 0;
	char ch;
	freopen(file, "r", stdin);
	while ((ch = getchar()) != EOF)
	{
		if (ch == '\n')
		{
			line_num++;
		}
	}
	fclose(stdin);
	return line_num;
}

