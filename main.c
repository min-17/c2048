//a simple and basic 2048 game programmed in C.
//You might not appreciate it much cuz bad(wait, zero) graphics,duh.
//merges two numbers of the same value, exclude zero.
//replaces one of em with a zero.
//the game ends if:
//1. there are no zeroes left in the matrix.
//2. you wish to exit the game,then send in -1 as i/p then.
//3. you complete the game, i.e., 2048.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//movs include merging of same numbers and shift in a direction
void leftOp(int[4][4]);
void rightOp(int[4][4]);
void upOp(int[4][4]);
void downOp(int[4][4]);
void play(int[4][4]);
//on the prompt
void message();
void display(int[4][4]);
void spacing(int);
//to generate 2 randomly
void prandom(int[4][4]);
int random_num(int,int);
//shift functions enable numbers to move towards vacant positions
void shLeft(int[4][4]);
void shRight(int[4][4]);
void shUp(int[4][4]);
void shDown(int[4][4]);
int flag=0;
/////////
int main(void) {
  int s;
  int a[4][4]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  prandom(a); //to randomly generate a 2
  prandom(a);
  display(a);
  message(a);
  play(a);
  return 0;
}
//similar to a flag variable?. 
int x=0;
/////////
//deciding which operation to perform
void play(int a[4][4]){
  int c,s;
  while(1){
    //wanna call it quits, send a -1.
    scanf("%d", &c);
    x=0;
    if(c==-1)
      break;
    switch(c){
      case 1: leftOp(a);
              //display(a);
              break;
      case 4: rightOp(a);
              //display(a);
              break;
      case 2: upOp(a);
              //display(a);
              break;
      case 3: downOp(a);
              //display(a);
              break;
      default:printf("invalid");
    } 
    
    prandom(a);
    message();
    display(a);
    if(x==-1)
      break;
    //no more zeroes in the matrix, then GAME OVER!
  }
}

///////////
//display the matrix
void display(int a[4][4]){
  int i,j;
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      //printf("%d   ",a[i][j]);
      spacing(a[i][j]);
    
    }
    printf("\n");
    //printf("\n");
  }
  printf("\n");
}

/////////
void leftOp(int a[4][4]){
  int i,j,k;
  shLeft(a);
  for(i=0;i<4;i++){
    for(j=0;j<3;j++){
      if(a[i][j]==a[i][j+1]){
        a[i][j]+=a[i][j+1];
        a[i][j+1]=0;
      }
    }
  }
  shLeft(a);

}
void upOp(int a[4][4]){
  int i,j,k;
  shUp(a);
  for(i=0;i<4;i++){
    for(j=0;j<3;j++){
      if(a[j][i]==a[j+1][i]){
        a[j][i]+=a[j+1][i];
        a[j+1][i]=0;
      }
    }
  }
  shUp(a);

}

void rightOp(int a[4][4]){
  int i,j,k;
  shRight(a);
  for(i=0;i<4;i++){
    for(j=0;j<3;j++){
      if(a[i][j]==a[i][j+1]){
        a[i][j+1]+=a[i][j];
        a[i][j]=0;
      }
    }
  }
  shRight(a);

}
void downOp(int a[4][4]){
  int i,j,k;
  shDown(a);
  for(i=0;i<4;i++){
    for(j=0;j<3;j++){
      if(a[j][i]==a[j+1][i]){
        a[j+1][i]+=a[j][i];
        a[j][i]=0;
      }
    }
  }
  shDown(a);

}

////////
void prandom(int a[4][4]){
  int i,j,n=0,c[16],h=0,s;
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      n++;
      if(a[i][j]==0){
        c[h]=n;
        h++;    //counts number of 0s
      }
    }
  }
  s=random_num(0,h);
  n=0;
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      n++;
      if(n==c[s])
        a[i][j]=2;
        
    }
  }
  //display(a);
  if(h==0)
    x=-1;
  else
    x=0;

}

int random_num(int min, int max){
  srand(time(NULL));
  return min=rand() % max;
}

/////////
void message(){
  printf("1-Left\n2-Up\n3-Down\n4-Right\n-1 to exit:)\n");
  printf("Enter op\n");
}
/////////
void shLeft(int a[4][4]){
  int i,j,k;
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      for(k=0;k<3;k++){
        if(a[i][k]==0){
          a[i][k]+=a[i][k+1];
          a[i][k+1]=0;
        }
      }
    }
  }
}

void shUp(int a[4][4]){
  int i,j,k;
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      for(k=0;k<3;k++){
        if(a[k][i]==0){
          a[k][i]+=a[k+1][i];
          a[k+1][i]=0;
        }
      }
    }
  }
}

void shRight(int a[4][4]){
  int i,j,k;
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      for(k=0;k<3;k++){
        if(a[i][k+1]==0){
          a[i][k+1]+=a[i][k];
          a[i][k]=0;
        }
      }
    }
  }
}

void shDown(int a[4][4]){
  int i,j,k;
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      for(k=0;k<3;k++){
        if(a[k+1][i]==0){
          a[k+1][i]+=a[k][i];
          a[k][i]=0;
        }
      }
    }
  }
}

void spacing(int n){
  int c=0,g;
  g=n;
  while(g>0){
    c++;
    g/=10;
  }

  if(n==0)
    c=1;

  switch(c){
    case 1: printf("%d     ",n);
            break;
    case 2: printf("%2d    ",n);
            break;
    case 3: printf("%3d   ",n);
            break;
    case 4: printf("%4d  ",n);
            break;
    
  }  
}

