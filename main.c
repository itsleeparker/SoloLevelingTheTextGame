////////////////////////////
//HEADER FILES
///////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "interact.c"
#define SIZE 10
#define MAP_LIMIT 6
#define MAP_SIZE 6
#define VIEW 25

////////////////////////////
///STRUCTURE DECLARATION
///////////////////////////

char map_dir[MAP_LIMIT][MAP_SIZE];

typedef struct status_data
{  
  char position[MAP_SIZE];                   // its a pointer this will tell where our charachter is
  int status;               //a flag will tell is monster is there or not
}status;            


/////////////////////////
////MAIN FUNCTION
////////////////////////


int main()
{
    status stat[MAP_LIMIT];
    int i = 0 , life=3,compass=3 ,j,check; 
    char dir[MAP_SIZE];
    int check_string(char *,int);   //function prototype;
    void generate_map(status *);    //function prototype;

    //function calls
    homepage();                     //will display homepage 
    generate_map(stat);             //this will generate a map at random 
    generate_monster();             //this will generate monsters
    printf("\n-----------GAME---------------\n");
   do
    {
        //display map
        
        
        printf("\nMap : ");             
        for(j=i;j<MAP_LIMIT;++j)        //map of the game
        {
            printf("\t%s",map_dir[j]);
        }
         
        //display perons view;
        printf("\nView : ");
        life = interact(i,stat[i].status, life);      //this will handle batteles and npcs
        system("clear");
        
        map:
        //display map again since the map will be cleared out
        printf("\nMap : ");
        for(j=i;j<MAP_LIMIT;++j)        //map of the game
        {
            printf("\t%s",map_dir[j]);
        }

        //for taking in directions from user
        printf("\n[1]East  \t[2]West\n[3]North\t[4]South");        
        printf("\nEnter Direction you wanna go to ? \t\t[LIFE : %d] \t\t[Remaining Magic Compass :  %d] \n",life , compass);     //compass will count the number of off tracks , lifr will count health
        printf("\nEnter direction [Enter same as shown] : ");
        scanf("%s",dir);
        
        //This will check if the user is on given map track
        check=strcmp(dir,map_dir[i]);
        if(check != 0)
        {
            printf("\nYou got off the track !!! pls follow the map\n");
            compass--;
            if(compass == 0)
            {
                break;      //this will exit the game;
            }
            printf("\nUsing Magic compass to get back on track!!!! \t\t[Remaining magic compass : %d]\n",compass);
            goto map;
        }

        strcpy(stat[i].position,map_dir[j]);
        system("clear");
        i++;        //heart of incrementaion makes charachter mover forward
    }while(i<MAP_LIMIT);
    if(compass == 0)
    {
        printf("\nYou got lost in the woods !!!!\n");
    }
    if(life != 0 && compass != 0)
    {
        printf("\n!!!!!!CONRAGTULATION YOU FINISHED THE QUEST AND FOUND SECRET TREASURE!!!!!!!\n");
    }

    printf("\n*****-+-*****GAME OVER*****-+-*****\n");
    printf("\n-----!!!THANK YOU FOR PLAYING!!!----\n");

}

void generate_map(status *stat)
{
    int i,j=1,random_num;
    char   directions[4][MAP_SIZE];
    strcpy(directions[0],"East");
    strcpy(directions[1],"West");
    strcpy(directions[2],"North");
    strcpy(directions[3],"South");

    srand(time(0));
    for(i=0;i<=MAP_LIMIT;++i)
    {
       random_num = rand();
       random_num = random_num%4;      //this will genarte a random number between 0 adn 3
        

        //allocate places for each location;
        strcpy(map_dir[i],directions[random_num]);      //this will generate a map
        
        //place ncps at random points
        random_num=random_num/2;
        stat[j].status = random_num;
        j++;     
    }
    
}

