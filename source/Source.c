#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<time.h>
void change(int *const array);
void swap(int *x, int *y);
int main()
{

	int kk[4][5040] = { 0 }, i = 0, j, o;
	int a1, b1, c, d, e, totalo = 0, fr = 0;
	int na, nb, nc;
	int choose = 1;
	int out = 0;
	int A = 0, B = 0;
	int total;
	int b[4];
	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int *aptr;
	printf("\n	�W�h����:���q���ߤ����@��(���|����!)���|��Ʀr�C\n\n");
	printf("	A�N��A�q�����Ʀr����n�Ӧb���׸̨åB�b�ۦP����m�A\n\n	B�h�O�N��A�q�����Ʀr����n�Ӧb���פ��A���O��m�����C\n\n	�p�G���������|���ܽd~		");
	system("pause");
	system("cls");
	printf("	\n�п�J�|���:(�A�n�q�q�����Ʀr)\n\n");
	printf("	��J��q���|�^���A���XA�XB �åB��\n\n");
	printf("					�а�XXXX �XA�XB\n\n");
	printf("	�`�N!!	*XXXX*�N��q���q�A���Ʀr�A���p��1A1B���ܴN��:	1(�Ů�)1(enter)\n\n");
	printf("	�F�ѳW�h��A�N�i�H�}�ϲq�Ʀr�F!\n\n");

	system("pause");
	system("cls");
	printf("\n");
	aptr = &a[0];
	A = 0; B = 0;

	do//��ܬO�_�A�@��//
	{
		for (a1 = 0; a1 < 10; a1++)//��|��Ʀr���զX
		{
			for (b1 = 0; b1 < 10; b1++)
			{
				if (a1 == b1)continue;
				for (c = 0; c < 10; c++)
				{
					if (a1 == c || b1 == c)continue;
					for (d = 0; d < 10; d++)
					{
						if (a1 == d || b1 == d || c == d)continue;
						kk[0][i] = a1;
						kk[1][i] = b1;
						kk[2][i] = c;
						kk[3][i] = d;
						i++;
					}
				}
			}
		}
		change(&a);      //����a[10]�̪��ơA������e���Ӭ�����//
		do
		{
			A = 0; B = 0;
			printf("�п�J�|���:  ");
			while (out == 0)   //�P�_�O�_���Ʀr����//
			{
				scanf_s("%d", &total);
				while (total / 1000 > 9)  //�ˬd�O�_���|���//
				{
					printf("'�|���'��~~\n�A�Ӥ@��       ");
					total = 0;
					scanf_s("%d", &total);
				}
				b[0] = total / 1000;
				b[1] = (total / 100) % 10;
				b[2] = (total / 10) % 10;
				b[3] = total % 10;
				if (b[0] != b[1] && b[0] != b[2] && b[0] != b[3] && b[1] != b[2] && b[1] != b[3] && b[2] != b[3]) //�P�_�O�_���Ʀr����//
					out = 1;
				else
				{
					printf("��J���i����!!!!\n");
					printf("�п�J�|���:  ");
				}
			}
			for (i = 0; i < 4; i++)     //�p�⦳�X��A�X��B//
			{
				if (a[i] == b[0] || a[i] == b[1] || a[i] == b[2] || a[i] == b[3])
				{
					B++;
					if (a[i] == b[i])
					{
						A++;
						B--;
					}
				}
			}
			out = 0;
			printf("%22dA %dB\n", A, B);
			if (A == 4)
				printf("\n���ߧA���!\n");
			else
			{
				totalo = 0;
				srand(time(NULL));
				do {
					o = rand() % 5040;
				} while (kk[0][o] == -1);
				printf("\t\t\t\t\t\t�����o!\n\t\t\t\t\t\t�а�");
				for (i = 0; i < 4; i++)
				{
					printf("%d", kk[i][o]);
				}
				printf(" �XA�XB:");
				do{
					scanf_s("%d%d", &a1, &b1);
					if ((a1 + b1) > 4) printf("A+B>4 %dA%dB���i��?!\n�Q�F~\t\t\t\t\t\t     �ѹ껡�h��:", a1, b1);
				}while (a1 + b1 > 4);
				if (a1 != 4)
				{
					for (i = 0; i < 5040; i++)
					{
						if (i == o)continue;
						if (kk[0][i] == -1)continue;
						na = 0;
						nb = 0;
						for (j = 0; j < 4; j++)for (c = 0; c < 4; c++)if (kk[j][i] == kk[c][o]) j == c ? na++ : nb++;//�p�⦳�X��A�X��B//
						if (na != a1 || nb != b1)for (c = 0; c < 4; c++) kk[c][i] = -1;
					}
					for (c = 0; c < 4; c++) kk[c][o] = -1;
				}
				for (i = 0; i < 5040; i++)if (kk[0][i] == -1)totalo++;
				printf("\n");
			}
		} while (A < 4 && totalo != 5040 && a1 != 4);     //�q��A���|�Ӫ��ܴN��өΪ̹q���q��|��A�ιq���o�{�A�@��//
		if (A == 4)printf("���׬O:%d%d%d%d\n", a[0], a[1], a[2], a[3]);
		else a1 == 4 ? printf("\t\t\t\tYes! �ڲq���F~~\n���׬O:%d%d%d%d\n", a[0], a[1], a[2], a[3]) : printf("Woo �A�@��TAT\n");
		A = 0; B = 0;
		printf("�а��٭n�A�@����?\n");
		printf("�� 1 �~��C���A�� 0 ���}�C��\n\n");
		scanf_s("%d", &choose);
	} while (choose == 1);

}

void change(int *const a)
{
	int i, y, x;
	srand(time(NULL));
	for (i = 0; i < 5; i++)
	{
		for (x = 0; x < 10; x++)
		{
			y = rand() % 10;
			swap(&a[x], &a[y]);
		}
	}
}

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}