#include<stdio.h>
#include"Horizontalmoves.h"
#include"Verticalmoves.h"
int main()
{
	//declaring our variables
	int a,b,c,i,j,k,m,n;
	int counta=0;
	int countb=0;
	int moves=0;
	int turn=0;
	//make our basemap
	char map[11][11][3]=
	{
		{"*","  ","*","  ","*","  ","*","  ","*","  ","*"},
		{" ","  "," ","  "," ","  "," ","  "," ","  "," "},
		{"*","  ","*","  ","*","  ","*","  ","*","  ","*"},
		{" ","  "," ","  "," ","  "," ","  "," ","  "," "},
		{"*","  ","*","  ","*","  ","*","  ","*","  ","*"},
		{" ","  "," ","  "," ","  "," ","  "," ","  "," "},
		{"*","  ","*","  ","*","  ","*","  ","*","  ","*"},
		{" ","  "," ","  "," ","  "," ","  "," ","  "," "},
		{"*","  ","*","  ","*","  ","*","  ","*","  ","*"},
		{" ","  "," ","  "," ","  "," ","  "," ","  "," "},
		{"*","  ","*","  ","*","  ","*","  ","*","  ","*"}
	};
	//this for knowing about which horizontal line is used(using 1 and 0)
	int horiztest[7][6]=
	{
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0}
	};
	//this for knowing about which vertical line is used(using 1 and 0)
	int vertest[6][7]=
	{
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
	};
	//making an infinite loop
	while(1)
	{
		//use a condition about playerA
		if(turn==0)
		{
			//show it's playerA's turn and getting parameteres 
			printf("It's PlayerA turn:");
			scanf("%d %d %d",&a,&b,&c);
			//using a condition to get horizontal line
			if(a==0)
			{
				//using a condition for getting valid parameters
				if(b>0 && b<7 && c>0 && c<6)
				{
					m=b;
					n=c;
					//using a condition to get a line that is new
					if(horiztest[m][n]==0)
					{
						//this line is for changing the turn
						turn=1-turn;
						horiztest[m][n]=1;
						b=b*2-1;
						c=c*2-1;
						//put horizontal line in related home in map array
						horizontalmoves(map,b,c);
						moves++;
						//these two conditons are for checking there is a square or not and also count it and write player name in that square
						if(horiztest[m+1][n]&vertest[m][n]&vertest[m][n+1])
						{
							//write name of player in sqare
							map[b][c][0]='A';
							map[b][c][1]=' ';
							//to give a bonus
							turn=1-turn;
							counta++;
						}
						if (horiztest[m-1][n]&vertest[m-1][n]&vertest[m-1][n+1])
						{
							map[b-2][c][0]='A';
							map[b-2][c][1]=' ';
							turn=1-turn;
							counta++;
							if(horiztest[m][n-1]&vertest[m-1][n-1]&vertest[m-1][n])
							{
								turn=1-turn;
							}
						}
					}
					//this will be showed when we get iterative parameters 
					else
					{
						printf("You should give us a new one.\n");
					}
				}
				//this will be showed when we get invalid parameters
				else
				{
					printf("Invalid.Trt again!\n");
				}
			}
			//here is for vertical lines
			else if(a==1)
			{
				//make a condition for getting valid parameters
				if(b>0 && b<6 && c>0 && c<7)
				{
						m=b;
						n=c;
						if(vertest[m][n]==0)
						{
							//this for changing turn
							turn=1-turn;
							vertest[m][n]=1;
							b=b*2;
							c=c*2-1;
							verticalmoves(map,b,c);
							moves++;
							//these two conditons are for checking there is a square or not and also count it and write player name in that square
							if(horiztest[m][n]&horiztest[m+1][n]&vertest[m][n+1])
							{
								//write name of player in square
								map[b-1][c][0]='A';
								map[b-1][c][1]=' ';
								//here we are gonna to give a bonus
								turn=1-turn;
								counta++;
							}
							if(horiztest[m][n-1]&horiztest[m+1][n-1]&vertest[m][n-1])
							{
								map[b-1][c-2][0]='A';
								map[b-1][c-2][1]=' ';
								turn=1-turn;
								counta++;
								if(horiztest[m][n]&horiztest[m+1][n]&vertest[m][n+1])
								{
									turn=1-turn;
								}
							}
						}
						//show it when we get iterative parameters
						else
						{
							printf("You should give us a new one.\n");
						}
				}
				//show it when we get invalid parameters
				else
				{
					printf("Invalid.Try again!\n");
				}
			}
			//here we are gonna check we get 0 or 1 as first parameter
			else
			{
				printf("Firs parameter should be 0 or 1.\n");
			}
			//here we are gonna show map
			for(i=0;i<11;i++)
			{
				for(j=0;j<11;j++)
				{
					printf("%s",map[i][j]);
				}
				printf("\n");
			}
		}
		//this is like before but for playerB
		if(turn==1)
		{
			printf("It's PlayerB turn:");
			scanf("%d %d %d",&a,&b,&c);
			//for horizontal lines
			if(a==0)
			{
				//make a condition for getting valid parameters 
				if(b>0 && b<7 && c>0 && c<6)
				{
					m=b;
					n=c;
					//check that we have this line or not
					if(horiztest[m][n]==0)
					{
						turn=1-turn;
						horiztest[m][n]=1;
						b=b*2-1;
						c=c*2-1;
						horizontalmoves(map,b,c);
						moves++;
						//check that we made square or not and give him a bonus and write name of player in squares
						if(horiztest[m+1][n]&vertest[m][n]&vertest[m][n+1])
						{
							map[b][c][0]='B';
							map[b][c][1]=' ';
							turn=1-turn;
							countb++;
						}
						if (horiztest[m-1][n]&vertest[m-1][n]&vertest[m-1][n+1])
						{
							map[b-2][c][0]='B';
							map[b-2][c][1]=' ';
							turn=1-turn;
							countb++;
							if(horiztest[m+1][n]&vertest[m][n]&vertest[m][n+1])
							{
								turn=1-turn;
							}
						}
					}
					//this will be shown we get iterative parameters
					else
					{
						printf("You should give us a new one.\n");
					}
				}
				//this will be shown we get invalid parameters
				else
				{
					printf("Invalid.Try again!\n");
				}
			}
			//this is for vertical line
			else if(a==1)
			{
				//check that parameters are valid or not
				if(b>0 && b<6 && c>0 && c<7)
				{
					m=b;
					n=c;
					//check we had that line or not
					if(vertest[m][n]==0)
					{
						turn=1-turn;
						vertest[m][n]=1;
						b=b*2;
						c=c*2-1;
						verticalmoves(map,b,c);
						moves++;
						//check that we made square or not and give him a bonus and write name of player in squares
						if(horiztest[m][n]&horiztest[m+1][n]&vertest[m][n+1])
						{
							map[b-1][c][0]='B';
							map[b-1][c][1]=' ';
							turn=1-turn;
							countb++;
						}
						if(horiztest[m][n-1]&horiztest[m+1][n-1]&vertest[m][n-1])
						{
							map[b-1][c-2][0]='B';
							map[b-1][c-2][1]=' ';
							turn=1-turn;
							countb++;
							if(horiztest[m][n]&horiztest[m+1][n]&vertest[m][n+1])
								{
									turn=1-turn;
								}
						}
					}
					//this will be shown when we get iterative items
					else
					{
						printf("You should give us a new one.\n");
					}
				}
				//this will be show when we get invalid items
				else
				{
					printf("Invalid.Try again!\n");
				}
			}
			//this will be shown when firstparameter is nor 1 or 0
			else
			{
				printf("First parameter should be 0 or 1.\n");
			}
			//this is for showing map
			for(i=0;i<11;i++)
			{
				for(j=0;j<11;j++)
				{
					printf("%s",map[i][j]);
				}
				printf("\n");
			}
		}
		//this is end condition 
		if(moves==60)
		{
			//showing playerA and playerB scores
			printf("PlayerA:%d\n",counta);
			printf("PlayerB:%d\n",countb);
			//show who won the game
			if(counta>countb)
			{
				printf("PlayerA won the game.");
				break;
			}
			else if(counta<countb)
			{
				printf("PlayerB won the game.");
				break;
			}
			else
			{
				printf("Tie!");
				break;
			}
		}
	}
}