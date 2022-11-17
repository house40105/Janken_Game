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
		printf("1)�Ʀr��, 2)�E�s��, 3)����:");
		scanf("%d",&choosegame);
		if(choosegame<1||choosegame>3)
		{
			printf("��J���~�I");
			continue;
		}
		else if(choosegame==1)
		{
			player2=ComAction();
			while(whowin!=1)
			{
				printf("�ХX���G1)�ŤM 2)���Y 3)���G");
				scanf("%d",&player1);

				if(player1<1||player1>3)
				{
					printf("��J���~�I");
					continue;
				}

				result=GameSet(player1,player2);

				printf("���a�X");
				if(player1==1)
					printf("�ŤM�A�q���X");
				else if(player1==2)
					printf("���Y�A�q���X");
				else if(player1==3)
					printf("���A�q���X");
				if(player2==1)
					printf("�ŤM�A");
				else if(player2==2)
					printf("���Y�A");
				else if(player2==3)
					printf("���A");
				if(result==1)
					printf("���a��ӡI\n���a���C");
				else if(result==-1)
					printf("�q����ӡI\n�q�����C");
				else if(result==0)
				{
					printf("����I\n");
					continue;
				}
				/*�C���}�l*/
				printf("\n======�C���}�l======\n");
				while(whowin!=1)
				{
					if(result==1)
					{
						printf("���y�G");
						scanf("%d",&word);
						if(word!=0&&word!=5&&word!=10&&word!=15&&word!=20)
						{
							printf("��J���~�I");
							continue;
						}
					}
					else if(result==-1)
						word=ComWord();

					printf("�X���]����/�k��^�G");
					scanf("%d %d",&player1left,&player1right);
					if((player1left!=0&&player1left!=5)||(player1right!=0&&player1right!=5))
						{
							printf("��J���~�I");
							continue;
						}

					printf("���a�]����/�k��^�G%d %d\n",player1left,player1right);

					player=player1left+player1right;
					computer=ComFingerCount();	

					printf("�q���]����/�k��^�G");
					if(computer==0)
						printf("0 0");
					else if(computer==5)
						printf("5 0");
					 else if(computer==10)
						printf("5 5");

					printf("\n�`��:%d",player+computer);
					if(result==1)
						printf("(���a��%d)\n",word);
					else if(result==-1)
						printf("(�q����%d)\n",word);

					back=Determin(word,computer,player);

					if(back==0)
					{
						printf("�U�@�^�X\n");
						result=result*-1;
						continue;
					}
					else if(back==1&&result==1)
					{
						printf("���ať�P�I\n");
						while(1)
						{
							if(result==1)
							{
								printf("���y�G");
								scanf("%d",&word);
								if(word!=0&&word!=5&&word!=10&&word!=15&&word!=20)
								{
									printf("��J���~�I\n");
									continue;
								}
							}
							else if(result==-1)
								word=ComWord();

							printf("�X���]����/�k��^�G");
							scanf("%d %d",&player1left,&player1right);
							if((player1left!=0&&player1left!=5)||(player1right!=0&&player1right!=5))
							{
								printf("��J���~�I");
								continue;
							}

							printf("���a�]����/�k��^�G%d %d\n",player1left,player1right);

							player=player1left+player1right;
							computer=ComFingerCount();	

							printf("�q���]����/�k��^�G");
							if(computer==0)
								printf("0 0");
							else if(computer==5)
								printf("5 0");
							else if(computer==10)
								printf("5 5");

							printf("\n�`��:%d",player+computer);
							if(result==1)
								printf("(���a��%d)\n",word);
							else if(result==-1)
								printf("(�q����%d)\n",word);

							back=Determin(word,computer,player);

							if(back==1)
							{
								printf("���a��ӡI\n");
								whowin=1;
								break;
							}
							else
							{
								printf("�C�����s�}�l�I\n");
								result=result*-1;
								break;
							}
						}
					}
					else if(back==1&&result==-1)
					{
						printf("�q��ť�P�I\n");
						while(1)
						{
							if(result==1)
							{
								printf("���y�G");
								scanf("%d",&word);
								if(word!=0&&word!=5&&word!=10&&word!=15&&word!=20)
								{
									printf("��J���~�I\n");
									continue;
								}
							}
							else if(result==-1)
								word=ComWord();

							printf("�X���]����/�k��^�G");
							scanf("%d %d",&player1left,&player1right);
							if((player1left!=0&&player1left!=5)||(player1right!=0&&player1right!=5))
							{
								printf("��J���~�I\n");
								continue;
							}

							printf("���a�]����/�k��^�G%d %d",player1left,player1right);

							player=player1left+player1right;
							computer=ComFingerCount();	

							printf("\n�q���]����/�k��^�G");
							if(computer==0)
								printf("0 0");
							else if(computer==5)
								printf("5 0");
							else if(computer==10)
								printf("5 5");

							printf("\n�`��:%d",player+computer);
							if(result==1)
								printf("(���a��%d)",word);
							else if(result==-1)
								printf("(�q����%d)",word);

							back=Determin(word,computer,player);

							if(back==1)
							{
								printf("\n�q����ӡI");
								whowin=1;
								break;
							}
							else
							{
								printf("\n�C�����s�}�l�I");
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