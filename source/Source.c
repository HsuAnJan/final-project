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
	printf("\n	規則說明:互猜對方心中的一個(不會重複!)的四位數字。\n\n");
	printf("	A代表你猜的的數字中有n個在答案裡並且在相同的位置，\n\n	B則是代表你猜的的數字中有n個在答案中，但是位置有錯。\n\n	如果不懂等等會有示範~		");
	system("pause");
	system("cls");
	printf("	\n請輸入四位數:(你要猜電腦的數字)\n\n");
	printf("	輸入後電腦會回應你有幾A幾B 並且說\n\n");
	printf("					請問XXXX 幾A幾B\n\n");
	printf("	注意!!	*XXXX*代表電腦猜你的數字，假如有1A1B的話就打:	1(空格)1(enter)\n\n");
	printf("	了解規則後，就可以開使猜數字了!\n\n");

	system("pause");
	system("cls");
	printf("\n");
	aptr = &a[0];
	A = 0; B = 0;

	do//選擇是否再一局//
	{
		for (a1 = 0; a1 < 10; a1++)//把四位數字的組合
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
		change(&a);      //打亂a[10]裡的數，之後取前五個為答案//
		do
		{
			A = 0; B = 0;
			printf("請輸入四位數:  ");
			while (out == 0)   //判斷是否有數字重複//
			{
				scanf_s("%d", &total);
				while (total / 1000 > 9)  //檢查是否為四位數//
				{
					printf("'四位數'拉~~\n再來一次       ");
					total = 0;
					scanf_s("%d", &total);
				}
				b[0] = total / 1000;
				b[1] = (total / 100) % 10;
				b[2] = (total / 10) % 10;
				b[3] = total % 10;
				if (b[0] != b[1] && b[0] != b[2] && b[0] != b[3] && b[1] != b[2] && b[1] != b[3] && b[2] != b[3]) //判斷是否有數字重複//
					out = 1;
				else
				{
					printf("輸入不可重複!!!!\n");
					printf("請輸入四位數:  ");
				}
			}
			for (i = 0; i < 4; i++)     //計算有幾個A幾個B//
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
				printf("\n恭喜你獲勝!\n");
			else
			{
				totalo = 0;
				srand(time(NULL));
				do {
					o = rand() % 5040;
				} while (kk[0][o] == -1);
				printf("\t\t\t\t\t\t換我囉!\n\t\t\t\t\t\t請問");
				for (i = 0; i < 4; i++)
				{
					printf("%d", kk[i][o]);
				}
				printf(" 幾A幾B:");
				do{
					scanf_s("%d%d", &a1, &b1);
					if ((a1 + b1) > 4) printf("A+B>4 %dA%dB怎麼可能?!\n想騙~\t\t\t\t\t\t     老實說多少:", a1, b1);
				}while (a1 + b1 > 4);
				if (a1 != 4)
				{
					for (i = 0; i < 5040; i++)
					{
						if (i == o)continue;
						if (kk[0][i] == -1)continue;
						na = 0;
						nb = 0;
						for (j = 0; j < 4; j++)for (c = 0; c < 4; c++)if (kk[j][i] == kk[c][o]) j == c ? na++ : nb++;//計算有幾個A幾個B//
						if (na != a1 || nb != b1)for (c = 0; c < 4; c++) kk[c][i] = -1;
					}
					for (c = 0; c < 4; c++) kk[c][o] = -1;
				}
				for (i = 0; i < 5040; i++)if (kk[0][i] == -1)totalo++;
				printf("\n");
			}
		} while (A < 4 && totalo != 5040 && a1 != 4);     //猜中A有四個的話就獲勝或者電腦猜到四個A或電腦發現你作弊//
		if (A == 4)printf("答案是:%d%d%d%d\n", a[0], a[1], a[2], a[3]);
		else a1 == 4 ? printf("\t\t\t\tYes! 我猜中了~~\n答案是:%d%d%d%d\n", a[0], a[1], a[2], a[3]) : printf("Woo 你作弊TAT\n");
		A = 0; B = 0;
		printf("請問還要再一局嗎?\n");
		printf("按 1 繼續遊戲，按 0 離開遊戲\n\n");
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