#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
void swap(int*,int*);
// random value for arr...........
void randomValue(int tempArr[15]){
	int temp;
	int i,j;
	srand(time(NULL));	
	for(i=0;i<15;i++){
	 temp = rand()%15+1;
	 for(j=0;j<=i-1;j++){
	 	if(temp==tempArr[j]){
	 		break;
		 }
	 }
	 if(i==j){
	 	tempArr[i] = temp;
	 }else{
	 	i--;
	 }
	}
}
void randomMatrix(int arr[][4],int tempArr[15]){
	int i,j;
	 int m = 0;
	printf("\n\n");
	for( i=0;i<4;i++){
	for( j=0;j<4;j++){
		arr[i][j]=tempArr[m];
		m++;
	}
	printf("\n");
 }
 arr[i-1][j-1] =0;
}
int shiftUp(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }
    if (i == 3) // shifting not possible
        return 0;

    // Successfully swapped two numbers !
    swap(&arr[i][j], &arr[i + 1][j]);
    return 1; // Success
}


int shiftDown(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }
    if (i == 0) // shifting not possible
        return 0;
    swap(&arr[i][j], &arr[i - 1][j]); // swap numbers

    return 1; // shift up success
}
int shiftRight(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }
    if (j == 0) // shifting not possible
        return 0;

    swap(&arr[i][j], &arr[i][j - 1]);

    return 1; // shift up success
}

int shiftLeft(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }

    if (j == 3) // shifting not possible
        return 0;

    swap(&arr[i][j], &arr[i][j + 1]);
    return 1; // shift up success
}

void swap(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
    printf("");
}

int win(int arr[][4]){
	int i,j,m=1;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(!(m==arr[i][j])){
				return 0;
			}
		if(m!=15){
			m++;
		}else
		{
			m = 0;
		}
		}
	}
	return 1;		
}
void showMatrix(int arr[4][4],char str[20]){
	printf("\n                                           NUMBER SHIFTING GAME \n");
	printf("\n                                      .................................\n\n"); 
	printf("PLAYER-%s\n\n\n",str);
	int i,j;
	    printf(" ______________________\n");
	for(i=0;i<4;i++){
		printf(" | ");	
			for(j=0;j<4;j++)
			{
				printf("%3d |",arr[i][j]);
			}
			printf("\n");
		    printf(" ______________________\n");
	}
}
void gameRule(char str[20]){
	int arr[4][4];
	
	printf("\n                                           NUMBER SHIFTING GAME  \n");
	printf("                                        .................................");
	printf("\n\nENTER YOUR NAME ............   ");
	gets(str);
	system("cls");   
	printf("\n                                           NUMBER SHIFTING GAME \n");
	printf("\n                                      .................................\n\n"); 
	printf("PLAYER-%s",str);
	printf("\n\n.................................................WIN SITUTION .............................\n\n");
	int i,j,m=1;
    printf(" ______________________\n");
	for(i=0;i<4;i++){
		printf(" | ");	
			for(j=0;j<4;j++)
			{
				if(m==16){
			     	m=0;
				}
				arr[i][j] = m;
				printf("%3d |",arr[i][j]);
				
				
				m++;
				
			}
			printf("\n");
		    printf(" ______________________\n");
	}


	printf("\n");
	printf("\n GAME RULES :\n");
	printf("\n1. You can move only 1 step at a time with the arrow key\n");
	printf("\n           Move Up     : by Up arrow key ");
	printf("\n           Move Down   : by Down arrow key ");
	printf("\n           Move Right  : by Up Right key ");
	printf("\n           Move Left   : by Up Left key ");
	printf("\n\n2. You can move numbers at an empty position only. ");
	printf("\n\n3. For each valid move : your total number of moves will decrease by 1.");
	printf("\n\n\n");
	printf("please Enter any key.... ");
	getch();
	system("cls");

}
int readEnteredKey()
{
    char c;
    c = getch();
    if (c == -32)
        c = getch();

    return c;
}
int main(){
	char str[20];
	int x;
	int flag = 0;
	int maxTry = 4;
	int tempArr[15];
	int arr[4][4];

	while(1){
		gameRule(str);
	  	randomValue(tempArr);
    	randomMatrix(arr,tempArr);
    	printf("\n                                           NUMBER SHIFTING GAME \n");
    	printf("\n                                      .................................\n\n"); 
     	printf("PLAYER-%s\n\n",str);
    	showMatrix(arr,str); // show matrix
		while(maxTry){
			system("cls");
			showMatrix(arr,str); // show matrix
	       int key = readEnteredKey();
		   switch(key) // maping
            {
            	 case 101: // ascii of E

                 case 69: // ascii of e
                printf("\a\a\a\a\a\a\n     Thanks for Playing ! \n\a");
                printf("\n Press any Any exit the game \n");
                key = readEnteredKey();
                return 0;
            case 72: // arrow up
                if (shiftUp(arr))
                    maxTry--;
                break;
            case 80: // arrow down
                if (shiftDown(arr))
                    maxTry--;
                break;
            case 77: // arrow  right
                if (shiftRight(arr))
                    maxTry--;
                break;
            case 75: // arrow left
                if (shiftLeft(arr))
                    maxTry--;
                break;
            default:
            	printf(" ");
                
            }
          if(maxTry==0){
          	if(win(arr)){
          		flag = 1;
          		break; }
		  }
		  
        }
        if(flag == 1 ){
        	printf(".................................................YOU ARE WIN ....\n\n\n");
        	printf("\nExit Press Enter 0 ");
        	scanf("%d",x);
        	if(x==0){
        	   break;}}
		else{
			printf("..........................................................You are lose.........\n\n");
			printf("Play Again press 1 ");
			printf(" and press 0 for exit ");
			scanf("%d",&x); 
			if(x==0){
				return 0;
			}else{
			system("cls");
			fflush(stdin);
			maxTry = 4;
			} }
		
	
	
	}
        	
		}
	
