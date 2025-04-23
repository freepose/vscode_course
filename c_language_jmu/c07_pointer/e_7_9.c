#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
void DisplayDice(int numOfDice);
void DisplayResult(int *pointOfDice); // 指针变量作为形参
int maxOfCount(int pOfDice[6]);		  // 数组名作为形参
int main()
{
	int pointOfDices[100][6], numberOfDice, numberOfParticipants, indexOfParticipants;
	printf("请输入参与博饼活动的人数：");
	scanf("%d", &numberOfParticipants);
	srand((unsigned)time(NULL));
	for (indexOfParticipants = 0; indexOfParticipants < numberOfParticipants; indexOfParticipants++)
	{
		getch();
		printf("\n第%d个人博：\n", indexOfParticipants + 1);
		for (numberOfDice = 0; numberOfDice < 6; numberOfDice++)
		{
			pointOfDices[indexOfParticipants][numberOfDice] = rand() % 6 + 1;
			DisplayDice(pointOfDices[indexOfParticipants][numberOfDice]);
		}
		DisplayResult(pointOfDices[indexOfParticipants]); // 数组名（只带一个下标的二维数组）作为实参
	}
	return 0;
}
void DisplayDice(int numOfDice)
{
	SetConsoleOutputCP(437);													 // 设置控制台属性，可以显示扩展ASCII码符号
	printf("%c%c%c%c%c%c%c%c%c\n", 218, 196, 196, 196, 196, 196, 196, 196, 191); // 画上边框
	switch (numOfDice)															 // 画点
	{
	case 1:
		printf("%c       %c\n", 179, 179);
		printf("%c   %c  %c\n", 179, 250, 179);
		printf("%c       %c\n", 179, 179);
		break;
	case 2:
		printf("%c       %c\n", 179, 179);
		printf("%c  %c%c %c\n", 179, 250, 250, 179);
		printf("%c       %c\n", 179, 179);
		break;
	case 3:
		printf("%c %c    %c\n", 179, 250, 179);
		printf("%c  %c   %c\n", 179, 250, 179);
		printf("%c    %c %c\n", 179, 250, 179);
		break;
	case 4:
		printf("%c  %c%c %c\n", 179, 250, 250, 179);
		printf("%c  %c%c %c\n", 179, 250, 250, 179);
		break;
	case 5:
		printf("%c  %c%c %c\n", 179, 250, 250, 179);
		printf("%c   %c  %c\n", 179, 250, 179);
		printf("%c  %c%c %c\n", 179, 250, 250, 179);
		break;
	case 6:
		printf("%c  %c%c %c\n", 179, 250, 250, 179);
		printf("%c  %c%c %c\n", 179, 250, 250, 179);
		printf("%c  %c%c %c\n", 179, 250, 250, 179);
		break;
	}
	printf("%c%c%c%c%c%c%c%c%c\n", 192, 196, 196, 196, 196, 196, 196, 196, 217); // 画下边框
}
void DisplayResult(int *pointOfDice)
{
	int indexOfDice, numberOfFour, maxOfOther;
	int countOfDIcePoint[6] = {0}, indexOfCount;
	int *dicePointCount = countOfDIcePoint;
	SetConsoleOutputCP(936); // 设置控制台属性，可以显示汉字
	for (indexOfDice = 0; indexOfDice < 6; indexOfDice++)
		countOfDIcePoint[*(pointOfDice + indexOfDice) - 1]++;
	numberOfFour = countOfDIcePoint[3]; // 4出现的次数
	maxOfOther = maxOfCount(dicePointCount);
	// 求其余点数出现的最大次数，指针变量作为实参
	if (maxOfOther == 6)
		if (countOfDIcePoint[0] == 6)
			printf("恭喜您，博到了状元（遍地锦）");
		else
			printf("恭喜您，博到了状元（六杯黑/灯下黑）");
	else if (maxOfOther == 5)
		if (numberOfFour == 1)
			printf("恭喜您，博到了状元（五子登科）+一秀");
		else
			printf("恭喜您，博到了状元（五子登科）");
	else if (maxOfOther == 4)
		if (numberOfFour == 1)
			printf("恭喜您，博到了四进+一秀");
		else if (numberOfFour == 2)
			printf("恭喜您，博到了四进+二举");
		else
			printf("恭喜您，博到了四进");
	else if (countOfDIcePoint[0] == 2 && numberOfFour == 4)
		printf("恭喜您，博到了状元插金花");
	else if (numberOfFour == 6)
		printf("恭喜您，博到了状元（六杯红/满堂红）");
	else if (numberOfFour == 5)
		printf("恭喜您，博到了状元（五红）");
	else if (numberOfFour == 4)
		printf("恭喜您，博到了状元（四点红）");
	else if (numberOfFour == 3)
		printf("恭喜您，博到了三红");
	else if (numberOfFour == 2)
		printf("恭喜您，博到了二举");
	else if (numberOfFour == 1 && maxOfOther != 1)
		printf("恭喜您，博到了一秀");
	else if (maxOfOther == 1)
		printf("恭喜您，博到了对堂");
	else
		printf("很抱歉，您的手气不好，什么都没博到");
}
int maxOfCount(int pOfDice[6])
{
	int i, max = pOfDice[0];
	for (i = 0; i < 6; i++)
	{
		if (i != 3)
			if (max < pOfDice[i])
				max = pOfDice[i];
	}
	return max;
}
