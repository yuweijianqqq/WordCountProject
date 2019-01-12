#include<stdafx.h>

int CheckFlieName(char filename[])
{
	if (_access(filename, 0) != 0) { return -1; }	// �ļ������� 
	if (_access(filename, 4) != 0) { return -2; }	// �ļ��޷���Ȩ��
	return 1;
}

void CommandProcessing(char order[], char filename[])
{
	switch (order[1])
	{
	case 'c':
		printf("�ַ���:  %d\n", CountCharacter(filename));
		break;
	case 'w':
		printf("������:  %d\n", CountWord(filename));
		break;
	case 'l':
		printf("����:  %d\n", CountLine(filename));
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
		// ���ô���ͼ�ν���ĳ���
	}
	else 
	{
		// �����ļ�
		char filename[100];
		memset(filename, 0, sizeof(filename));
		strcpy_s(filename, argv[2]);
		int flag = CheckFlieName(filename);

		// ����ļ�
		if (flag == -1)
		{
			printf("�ļ������ڣ����������룡");
			return 0;
		}
		if (flag == -2)
		{
			printf("�ļ��޷���Ȩ�ޣ������ļ�Ȩ�ޣ�");
			return 0;
		}

		// ����ͳ��
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


