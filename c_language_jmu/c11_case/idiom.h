#define LEN 500
#define SCORE 5
typedef struct
{
	char idiom[20];		   // 成语名字
	char illustation[500]; // 成语解释
} IDIOM;
typedef struct
{
	int ranking;		// 排名
	char user[100];		// 用户名
	int score[3];		// 分数、正确数量、错误数量
	char datetime[100]; // 日期
} RANKING;

void GotoSystemMenu();	   // 1.进入系统菜单
void MainMenu(char *user); // 2.游戏菜单
void OperateGameMenu();	   // 3.选择游戏操作界面
void GuessBeginMenu();	   // 猜游戏界面开头界面
void FillIdiomMenu();	   // 补充成语界面
void ShowRanking();		   // 查排名
void FileException();	   // 文件读取异常处理

// 成语数据相关操作函数
int GetIdiomData(IDIOM *idioms); // 读取成语文件
void BeginGuessGame(IDIOM *idioms, RANKING *ranks, int idiomLen);
void GotoMainMenu(int rightNumber, int wrongNumber);					  // 返回主界面函数
void BeginFillGame(IDIOM *idioms, RANKING *userLocPtr, int idiomLen);	  // 补充成语游戏
void SplitIdiom(char *idiomstr, char characters[][4], int *characterNum); // 分割成语
void CreateBlanks(char characters[][4], int characterNum, int loc[]);	  // 造填空
void getScore(RANKING *userLocPtr, char *rightAnswer, int rightflag);	  // 根据用户回答结果评分，更新排名成绩

// 排名数据的相关函数
int GetRankData(RANKING *ranks);								// 读取排名文件数据。
int ExistUser(char *user, RANKING *ranks, int *rankLen);		// 读取排名文件，查找用户是否存在
RANKING *SetUserInfo(RANKING *ranks, int *rankLen, char *user); // 设置用户的排名初始信息
void WriteToRanking(RANKING *ranks, int rankLen);				// 分数写入排名文件。
void SortRanking(RANKING *ranks, int rankLen);					// 对排名排序
void PrintRanking(RANKING *ranks, int rankLen);					// 展示排名内容