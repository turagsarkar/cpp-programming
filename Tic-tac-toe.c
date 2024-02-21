#include <stdio.h>
#include <stdlib.h>

void clear()
{
	system("pause");
    system("cls");
}


int main ()

{
	FILE *fp1,*fp2;

	fp1 = fopen("playerone.txt","r");
	fp2 = fopen("playertwo.txt","r");

    int p=0;
    int q=0;
    int winner=0;
    char board[3][3];
    int playerone=0,playertwo=0;
    int z;
    for(p=0;p<3;p++)
    {
    int player = 0,choice = 0,row = 0,column = 0,line = 0;
    char board [3][3] = {
                 { '1','2' ,'3' },

                 {'4' ,'5' ,'6' },

                 {'7','8' ,'9' }
                        };
      int i;
    for ( i = 0; winner==0 && i<9 ; i++)

    {
        printf("\n\n");

        printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);

        printf("---|---|---\n");

        printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);

        printf("---|---|---\n");

        printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);

       player = i%2 + 1;
        if(player==1)
        {
           do

        {

            printf("\nPlayer %d, please enter the number of the square"

                "where you want to place your %c: ",

                player,(player==1)?'X':'O');
            scanf("%d", &choice);
            row = --choice/3;

            column = choice%3;

        }while(choice<0 || choice>9 || board [row][column]>'9');

        board[row][column] = (player == 1) ? 'X' : 'O';

        }
        else if(player==2)
        {
          do

        {

            printf("\nPlayer %d, please enter the number of the square"

                "where you want to place your %c: ",

            player,(player==1)?'X':'O');
            choice= 1 + ( rand() % 9 );
            printf("%d\n",choice);
            row = --choice/3;

            column = choice%3;

        }while(choice<0 || choice>9 || board [row][column]>'9');

        board[row][column] = (player == 1) ? 'X' : 'O';

        }

        if((board[0][0]==board[1][1] && board[0][0]==board[2][2]) ||

           (board[0][2]==board[1][1] && board[0][2]==board[2][0]))

           winner = player;

        else

            for(line = 0; line <=2; line++)

                if((board[line][0]==board[line][1] && board[line][0]==board[line][2])||

                    (board[0][line]==board[1][line] && board[0][line]==board[2][line]))

                    winner = player;

        clear();
    }

        printf("\n\n");

        printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);

        printf("---|---|---\n");

        printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);

        printf("---|---|---\n");

        printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);




        if(winner==0)
        {
            printf("The game is a draw\n");
            q++;
        }


        else if((board[0][0]==board[1][1] && board[0][0]==board[2][2]))
        {
            printf("\n\n");
        printf(" %c |   |  \n", board[0][0]);

        printf("---|---|---\n");

        printf("   | %c |  \n", board[1][1]);

        printf("---|---|---\n");

        printf("   |   | %c\n",board[2][2]);

        printf("Player %d has won\n", winner);
            break;
        }

        else if((board[0][2]==board[1][1] && board[0][2]==board[2][0]))
        {
            printf("\n\n");
         printf("   |   | %c \n", board[0][2]);

        printf("---|---|---\n");

        printf("   | %c |  \n", board[1][1]);

        printf("---|---|---\n");

        printf(" %c |   |  \n",board[2][0]);

            printf("Player %d has won\n", winner);
            break;
        }
        else if((board[0][0]==board[0][1] && board[0][0]==board[0][2]))
        {
            printf("\n\n");
         printf(" %c | %c | %c \n", board[0][0],board[0][1],board[0][2]);

        printf("---|---|---\n");

        printf("   |   |  \n");

        printf("---|---|---\n");

        printf("   |   |  \n");

            printf("Player %d has won\n", winner);
            break;
        }
        else if((board[1][0]==board[1][1] && board[1][0]==board[1][2]))
        {
            printf("\n\n");
         printf("   |   |  \n");

        printf("---|---|---\n");

        printf(" %c | %c | %c \n", board[1][0],board[1][1],board[1][2]);

        printf("---|---|---\n");

        printf("   |   |  \n");

            printf("Player %d has won\n", winner);
            break;
        }
        else if((board[2][0]==board[2][1] && board[2][0]==board[2][2]))
        {
            printf("\n\n");
         printf("   |   |  \n");

        printf("---|---|---\n");

        printf("   |   |  \n");

        printf("---|---|---\n");

        printf(" %c | %c | %c \n",board[2][0],board[2][1],board[2][2]);

            printf("Player %d has won\n", winner);
            break;
        }
        else if((board[0][0]==board[1][0] && board[0][0]==board[2][0]))
        {
            printf("\n\n");
         printf(" %c |   |  \n", board[0][0]);

        printf("---|---|---\n");

        printf(" %c |   |  \n", board[1][0]);

        printf("---|---|---\n");

        printf(" %c |   |  \n",board[2][0]);

            printf("Player %d has won\n", winner);
            break;
        }
        else if((board[0][1]==board[1][1] && board[0][1]==board[2][1]))
        {
            printf("\n\n");
         printf("   | %c |  \n", board[0][1]);

        printf("---|---|---\n");

        printf("   | %c |  \n", board[1][1]);

        printf("---|---|---\n");

        printf("   | %c |  \n",board[2][1]);

            printf("Player %d has won\n", winner);
            break;
        }
        else if((board[0][2]==board[1][2] && board[0][2]==board[2][2]))
        {
            printf("\n\n");
         printf("   |   | %c \n", board[0][2]);

        printf("---|---|---\n");

        printf("   |   | %c \n", board[1][2]);

        printf("---|---|---\n");

        printf("   |   | %c \n",board[2][2]);

            printf("Player %d has won\n", winner);
            break;
        }
    }
    if(q==3)
    {

        printf("Player 1 has got 1 and Player 2 has got 1\n");

        fscanf(fp1,"%d",&playerone);
    	playerone += 1;
    	fclose(fp1);

    	fscanf(fp2,"%d",&playertwo);
    	playertwo += 1;
    	fclose(fp2);

    	printf("total point of Player 1 is = %d & Player 2 is = %d",playerone,playertwo);

    	fp1 = fopen("playerone.txt","w");
    	fprintf(fp1,"%d",playerone);
    	fclose(fp1);

    	fp2 = fopen("playertwo.txt","w");
    	fprintf(fp2,"%d",playertwo);
    	fclose(fp2);
    }
    else
    {
    	printf("Player has got is 3\n",winner);
    	if(winner == 1)
    	{
    		fscanf(fp1,"%d",&playerone);
    		playerone += 3;
    		fclose(fp1);

    		fp1 = fopen("playerone.txt","w");
    		fprintf(fp1,"%d",playerone);
    		fclose(fp1);

    		fscanf(fp1,"%d",&playerone);
    		fclose(fp1);
    		printf("Player %d total point is = %d",winner,playerone);

		}
		else
		{
			fscanf(fp2,"%d",&playertwo);
    		playertwo += 3;
    		fclose(fp2);

    		fp2 = fopen("playertwo.txt","w");
    		fprintf(fp2,"%d",playertwo);
    		fclose(fp2);

    		fscanf(fp2,"%d",&playertwo);
    		fclose(fp2);
    		printf("Player %d total point is = %d",winner,playertwo);
		}
    }

    return 0;

}

