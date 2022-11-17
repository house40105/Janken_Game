#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int ComAction(void);
int GameSet(int player1a,int player2a);
int ComWord(void);
int ComFingerCount(void);
int Determin(int worda, int computera, int playera);

int main(void)
{
	int player1,player2,result,word,player,player1left,player1right,computer,back;
	int choosegame=1;
	int whowin=0;

	srand(time(NULL));

	while(choosegame!=3)
	{
		printf("1)數字拳, 2)划酒拳, 3)結束:");
		scanf("%d",&choosegame);
		if(choosegame<1||choosegame>3)
		{
			printf("輸入錯誤！");
			continue;
		}
		else if(choosegame==1)
		{
			player2=ComAction();
			while(whowin!=1)
			{
				printf("請出拳：1)剪刀 2)石頭 3)布：");
				scanf("%d",&player1);

				if(player1<1||player1>3)
				{
					printf("輸入錯誤！");
					continue;
				}

				result=GameSet(player1,player2);

				printf("玩家出");
				if(player1==1)
					printf("剪刀，電腦出");
				else if(player1==2)
					printf("石頭，電腦出");
				else if(player1==3)
					printf("布，電腦出");
				if(player2==1)
					printf("剪刀，");
				else if(player2==2)
					printf("石頭，");
				else if(player2==3)
					printf("布，");
				if(result==1)
					printf("玩家獲勝！\n玩家先。");
				else if(result==-1)
					printf("電腦獲勝！\n電腦先。");
				else if(result==0)
				{
					printf("平手！\n");
					continue;
				}
				/*遊戲開始*/
				printf("\n======遊戲開始======\n");
				while(whowin!=1)
				{
					if(result==1)
					{
						printf("拳語：");
						scanf("%d",&word);
						if(word!=0&&word!=5&&word!=10&&word!=15&&word!=20)
						{
							printf("輸入錯誤！");
							continue;
						}
					}
					else if(result==-1)
						word=ComWord();

					printf("出拳（左手/右手）：");
					scanf("%d %d",&player1left,&player1right);
					if((player1left!=0&&player1left!=5)||(player1right!=0&&player1right!=5))
						{
							printf("輸入錯誤！");
							continue;
						}

					printf("玩家（左手/右手）：%d %d\n",player1left,player1right);

					player=player1left+player1right;
					computer=ComFingerCount();	

					printf("電腦（左手/右手）：");
					if(computer==0)
						printf("0 0");
					else if(computer==5)
						printf("5 0");
					 else if(computer==10)
						printf("5 5");

					printf("\n總數:%d",player+computer);
					if(result==1)
						printf("(玩家喊%d)\n",word);
					else if(result==-1)
						printf("(電腦喊%d)\n",word);

					back=Determin(word,computer,player);

					if(back==0)
					{
						printf("下一回合\n");
						result=result*-1;
						continue;
					}
					else if(back==1&&result==1)
					{
						printf("玩家聽牌！\n");
						while(1)
						{
							if(result==1)
							{
								printf("拳語：");
								scanf("%d",&word);
								if(word!=0&&word!=5&&word!=10&&word!=15&&word!=20)
								{
									printf("輸入錯誤！\n");
									continue;
								}
							}
							else if(result==-1)
								word=ComWord();

							printf("出拳（左手/右手）：");
							scanf("%d %d",&player1left,&player1right);
							if((player1left!=0&&player1left!=5)||(player1right!=0&&player1right!=5))
							{
								printf("輸入錯誤！");
								continue;
							}

							printf("玩家（左手/右手）：%d %d\n",player1left,player1right);

							player=player1left+player1right;
							computer=ComFingerCount();	

							printf("電腦（左手/右手）：");
							if(computer==0)
								printf("0 0");
							else if(computer==5)
								printf("5 0");
							else if(computer==10)
								printf("5 5");

							printf("\n總數:%d",player+computer);
							if(result==1)
								printf("(玩家喊%d)\n",word);
							else if(result==-1)
								printf("(電腦喊%d)\n",word);

							back=Determin(word,computer,player);

							if(back==1)
							{
								printf("玩家獲勝！\n");
								whowin=1;
								break;
							}
							else
							{
								printf("遊戲重新開始！\n");
								result=result*-1;
								break;
							}
						}
					}
					else if(back==1&&result==-1)
					{
						printf("電腦聽牌！\n");
						while(1)
						{
							if(result==1)
							{
								printf("拳語：");
								scanf("%d",&word);
								if(word!=0&&word!=5&&word!=10&&word!=15&&word!=20)
								{
									printf("輸入錯誤！\n");
									continue;
								}
							}
							else if(result==-1)
								word=ComWord();

							printf("出拳（左手/右手）：");
							scanf("%d %d",&player1left,&player1right);
							if((player1left!=0&&player1left!=5)||(player1right!=0&&player1right!=5))
							{
								printf("輸入錯誤！\n");
								continue;
							}

							printf("玩家（左手/右手）：%d %d",player1left,player1right);

							player=player1left+player1right;
							computer=ComFingerCount();	

							printf("\n電腦（左手/右手）：");
							if(computer==0)
								printf("0 0");
							else if(computer==5)
								printf("5 0");
							else if(computer==10)
								printf("5 5");

							printf("\n總數:%d",player+computer);
							if(result==1)
								printf("(玩家喊%d)",word);
							else if(result==-1)
								printf("(電腦喊%d)",word);

							back=Determin(word,computer,player);

							if(back==1)
							{
								printf("\n電腦獲勝！");
								whowin=1;
								break;
							}
							else
							{
								printf("\n遊戲重新開始！");
								result=result*-1;
								break;
							}
						}
					}
				}
			}
		}
		else if(choosegame==2)
		{
		}
	}
	
	return 0;
}
int ComAction(void)
{
	int player2input;

	player2input=1+(rand()%3);
	return player2input;
}
int GameSet(int player1a,int player2a)
{
	int final;

	if((player1a==1&&player2a==3)||(player1a==2&&player2a==1)||(player1a==3&&player2a==2))
		final=1;
	else if((player1a==3&&player2a==1)||(player1a==1&&player2a==2)||(player1a==2&&player2a==3))
		final=-1;
	else
		final=0;

	return final;
}
int ComWord(void)
{
	int player2say;

	player2say=(rand()%5)*5;

	return player2say;
}
int ComFingerCount(void)
{
	int player2aleftright;

	player2aleftright=(rand()%3)*5;

	return player2aleftright; 
}
int Determin(int worda, int computera, int playera)
{
	int backa;

	if(computera+playera==worda)
		backa=1;
	else
		backa=0;

	return backa;
}