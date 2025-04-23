#include <stdio.h>
int main()
{
	int option, index;
	char article[10][100] = {"知史力行，初心历久弥坚",
							 "江苏：让红色资源鲜活呈现深入人心",
							 "高站位高标准高质量推进党史学习教育",
							 "部署开展\"我为群众办实事\"实践活动",
							 "弘扬英雄精神 坚定理想信念",
							 "缅怀革命先烈 传承红色基因",
							 "话剧《香山之夜》：舞台上的一堂鲜活党课",
							 "“迎解古樟”树下听党史",
							 "山西阳泉：社区减负“轻装上阵”",
							 "砥砺初心牢记使命 务求实效办好实事"};
	printf("****************** 阅读文章 ******************\n");
	printf("*               1:选择文章编号               *\n");
	printf("*               2:输入关键词                 *\n");
	printf("*               0:返回到主菜单               *\n");
	printf("**********************************************\n");

	printf("请输入您的选择:");
	scanf("%d", &option);

	switch (option)
	{
	case 1:
		printf("请输入文章编号：");
		scanf("%d", &index);
		puts(article[index - 1]);
		break;
	case 2:
		printf("您的选择是：输入关键词\n");
		break;
	case 0:
		printf("您的选择是：返回到主菜单\n");
		break;
	default:
		printf("输入有误，输入数字只能是0,1,2！\n");
	}
	return 0;
}
