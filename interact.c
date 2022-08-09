
#define SIZE 10
#define MAP_LIMIT 6
#define MONSTER_NAME 20
typedef struct monster_data
{
   char monster_name[SIZE];
   char weakness[SIZE];
}monster;

monster mons[6];
char op;
void generate_monster()
{
    int random , i;
    char temp[6][MONSTER_NAME] ,temp2[6][MONSTER_NAME];
    srand(time(0));

    //insert names of moster
    strcpy(temp[0],"Fire ");
    strcpy(temp[1],"Grass");
    strcpy(temp[2],"Witch");
    strcpy(temp2[0],"Water");
    strcpy(temp2[1],"Fire");
    strcpy(temp2[2],"Sword");

    //generate random numbers
    for(i=0;i<MAP_LIMIT;++i)
    {
        random =rand();     //this will generate a number between 0 and 2
        random =random%3;

        //give the monster name and a weakness
        strcpy(mons[i].monster_name ,temp[random]);
        strcpy(mons[i].weakness,temp2[random]);
    }
    
}

int interact(int pos , int flag , int life)
{
    int check;
    char op, attack[6];
    if(flag == 0)
    {
        //if there is a persons
        printf("There seems to be a person around ya\nDo you wanna talk to him ? [y/n] : !!!\n");
        scanf(" %c",&op);
        if(op == 'Y' || op == 'y')
        {
            if(pos/2)
            {
                printf("\n+--------------------------------------------------------+");
                printf("\n|\"There are sometimes wild moster herr look out for them\"|\n");
                printf("+----------------------------------------------------------|\n");
                
                //ask user to press any key then you can clear screen
                printf("\nPress any key to continue \n");
                //getch();
            }
            else
            {
                printf("\n+------------------------------------------+");
                printf("\n|\"The weather seem nice today is'nt  it ?\"|");
                printf("\n+------------------------------------------+");
                
                printf("\nPress any key to continue \n");
                //getch();
            }

        } 
         
        return life;   
    }

     //the battle mode
     if(flag == 1)
     {
         printf("\"There is a wild monster here !!!!\"\n");
         printf("\n +----------------+\n");
         printf("\n |  BATTLE TIME   |\n");
         printf("\n +----------------+\n");
         printf("\n\"A  %s monster has appererd !!!\"\n",mons[pos].monster_name);
         printf("\nPress any key to engage  !!!!\n");
         //getc();
     
     do{ 
         system("clear");
         //system("color c");
         printf("\n+---------------------------+\n");
         printf("|   FIGHTING %s MONSTER     |",mons[pos].monster_name);
         printf("\n+---------------------------+\n");
         printf("\nWhat power you wanna user : ");
         printf("\n+--------+---------+----------+");
         printf("\n| [Fire] | [Water] | [Sword]  |\n");
         printf("+--------+---------+----------+\n");
         printf("\nEnter same as given option!!!\n");
         printf("\nChoose your attack  :  ");
         scanf("%s",attack);
         
         system("clear");
         check = strcmp(attack ,mons[pos].weakness);
         if(check == 0)
         {
            printf("\nUsing %s !!!! \"ATTACK !!!!\"",attack);
            printf("\nYOU DEFATED THE MONSTER!!!!\n");
            //system("color f");
            return life;
         }
        else
        { 
         // system("color c");   
          printf("\nUsing %s !!!! ATTACK !!!!\n",attack);
          printf("\n+------------------------+");
          printf("\n|\"DARN that didnt work\"|");
          printf("\n+------------------------+");
          printf("\nYOU GOT ATTACKED !!!\n");
          life--;
          
          system("clear");
          printf("\n+------------------+\n");
          printf("\n|Remaing Life  : %d|\n",life);
          printf("\n+------------------+\n");
          printf("\nPress any key to attack again\n");
         // getc();
         // system("color f");
        }

       }while(life != 0); 

        printf("\n-------------------\n");   
        printf("\n/////YOU DIED\\\\\\ \n");
        printf("\n*****-+-*****GAME OVER*****-+-*****\n");
        exit(0);
    }
 return life;
}


void homepage()
{
   printf("\n                   ░░                                                  ░░    ");
   printf("\n                   ████                                              ████    ");
   printf("\n                   ██▓▓██                                          ██  ██   ");
   printf("\n                   ██▓▓▓▓██                                      ██    ██    ");
   printf("\n               ██████▓▓▓▓▓▓██████████████████████████████████████      ██████");
   printf("\n               ██░░░░░░▓▓▓▓▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░      ░░░░░░██");
   printf("\n               ██▓▓▒▒▒▒▒▒▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒      ▒▒▒▒▒▒  ██");
   printf("\n               ██▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒      ░░▒▒▒▒    ██");
   printf("\n               ██░░▓▓▓▓▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒    ▒▒▒▒▒▒    ░░██");
   printf("\n               ██░░▓▓▓▓▓▓▓▓▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒        ░░██");
   printf("\n               ██░░▒▒▓▓▓▓▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒        ▒▒░░██");
   printf("\n               ██▒▒▒▒▒▒▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒░░▒▒▒▒▒▒    ▒▒▒▒        ▒▒▒▒  ██");
   printf("\n               ██▓▓▓▓▓▓▒▒▒▒▓▓▓▓▒▒▒▒▒▒▓▓▓▓▒▒▒▒░░▒▒▒▒    ▒▒▒▒▒▒    ▒▒▒▒      ██");
   printf("\n               ██░░▓▓▓▓▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▓▓▒▒▒▒░░▒▒    ░░▒▒  ▒▒  ░░▒▒      ░░██");
   printf("\n               ██▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▓▓    ▒▒  ▒▒▒▒    ▒▒▒▒▒▒      ▒▒  ██");
   printf("\n               ██▓▓▓▓▒▒▓▓▓▓▓▓▒▒▒▒▓▓▓▓▓▓▒▒      ▒▒▒▒▒▒      ▒▒▒▒      ▒▒    ██");
   printf("\n               ██░░▓▓▓▓▒▒▒▒▓▓▒▒▓▓▒▒▒▒▓▓        ▒▒▒▒    ▒▒▒▒  ▒▒  ▒▒▒▒    ░░██");
   printf("\n               ██░░▓▓▓▓▓▓▓▓▒▒▒▒▓▓▒▒▒▒      ░░░░▒▒▒▒  ░░▒▒    ▒▒▒▒        ░░██");
   printf("\n               ██░░▒▒▓▓▓▓▓▓▓▓▒▒▒▒▓▓▓▓    ▒▒▒▒░░  ▒▒▒▒▒▒    ▒▒▒▒        ▒▒░░██");
   printf("\n               ██░░░░░░▓▓▓▓▓▓░░░░░░▓▓  ░░░░      ░░      ░░░░░░      ░░░░░░██");
   printf("\n               ██░░▒▒▒▒▒▒▓▓▓▓░░▒▒▒▒▒▒▒▒▒▒      ░░▒▒    ░░    ▒▒    ░░▒▒▒▒░░██");
   printf("\n               ██░░▓▓▓▓▒▒▒▒▓▓▒▒▓▓▓▓▓▓▒▒    ▒▒░░  ▒▒▒▒▒▒      ▒▒  ▒▒▒▒    ░░██");
   printf("\n               ██░░▒▒▓▓▓▓▓▓▒▒▒▒▒▒▓▓▓▓    ▒▒      ▒▒▒▒      ▒▒▒▒▒▒      ▒▒░░██");
   printf("\n               ██░░▒▒▓▓▓▓▓▓▓▓▒▒▓▓▒▒▓▓  ▒▒      ▒▒▒▒      ▒▒  ▒▒        ▒▒░░██");
   printf("\n               ██░░▒▒▒▒▒▒▓▓▓▓▒▒▓▓▓▓▒▒▒▒    ▒▒░░  ▒▒    ▒▒    ▒▒    ▒▒▒▒▒▒░░██");
   printf("\n               ██░░▒▒▓▓▒▒▒▒▒▒▒▒▓▓▓▓▓▓▒▒  ▒▒      ▒▒▒▒▒▒      ▒▒▒▒▒▒▒▒  ▒▒░░██");
   printf("\n               ██░░▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒▓▓  ▒▒      ▒▒▒▒      ▒▒▒▒▒▒        ▒▒░░██");
   printf("\n               ██░░▒▒▒▒▓▓▓▓▓▓▒▒▒▒▒▒▒▒░░    ▒▒░░▒▒▒▒    ░░▒▒  ▒▒      ▒▒▒▒░░██");
   printf("\n               ██░░▒▒▒▒▒▒▒▒▓▓▒▒▓▓▓▓▓▓▒▒  ▒▒      ▒▒▒▒▒▒      ▒▒  ▒▒▒▒▒▒▒▒░░██");
   printf("\n               ██░░▒▒▒▒▓▓▓▓▒▒▒▒▒▒▓▓▓▓  ▒▒      ▒▒▒▒        ▒▒▒▒▒▒    ▒▒▒▒░░██");
   printf("\n               ██░░▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒▒▒░░  ▒▒▒▒░░▒▒▒▒    ░░▒▒▒▒      ░░▒▒▒▒░░██");
   printf("\n               ██░░▒▒▒▒▒▒▒▒▓▓▓▓▒▒▓▓▓▓  ▒▒▒▒      ▒▒▒▒▒▒    ▒▒    ▒▒▒▒▒▒▒▒░░██");
   printf("\n               ██░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒  ▒▒░░▒▒        ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░██");
   printf("\n               ██░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒    ▒▒    ░░▒▒▒▒      ▒▒▒▒▒▒▒▒░░██");
   printf("\n               ██░░░░▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒      ░░▒▒▒▒      ▒▒    ▒▒▒▒▒▒▒▒░░░░██");
   printf("\n               ██░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒    ▒▒    ░░▒▒▒▒      ▒▒▒▒▒▒▒▒░░██");
   printf("\n               ██░░░░▒▒▒▒▒▒▒▒▓▓▓▓▒▒▒▒▒▒      ░░▒▒▒▒      ▒▒    ▒▒▒▒▒▒▒▒░░░░██");
   printf("\n               ██████░░░░▒▒▒▒▒▒▓▓▒▒▒▒    ▒▒▒▒░░        ▒▒▒▒  ▒▒▒▒▒▒░░░░██████");
   printf("\n                     ████░░░░▒▒▒▒▒▒    ░░          ▒▒░░▒▒▒▒▒▒▒▒░░░░████      ");
   printf("\n                         ████░░░░▒▒      ▒▒    ▒▒▒▒▓▓▓▓▓▓▒▒░░░░████          ");
   printf("\n                             ██      ▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒▒▒▓▓▓▓▓▓██              ");
   printf("\n                           ██    ████░░░░▒▒▒▒░░▒▒▒▒░░░░████▓▓▓▓██            ");
   printf("\n                         ██    ██    ████░░░░░░░░░░████    ██▓▓▓▓██          ");
   printf("\n                       ████████          ████░░████          ████████        ");
   printf("\n                                             ██                              ");
   printf("\n\n\n");
   printf("\n  /$$$$$$   /$$$$$$  /$$        /$$$$$$        /$$       /$$$$$$$$ /$$    /$$ /$$$$$$$$ /$$       /$$$$$$ /$$   /$$  /$$$$$$ ");
   printf("\n /$$__  $$ /$$__  $$| $$       /$$__  $$      | $$      | $$_____/| $$   | $$| $$_____/| $$      |_  $$_/| $$$ | $$ /$$__  $$");
   printf("\n| $$  \\__/| $$  \\ $$| $$      | $$  \\ $$      | $$      | $$      | $$   | $$| $$      | $$        | $$  | $$$$| $$| $$  \\__/");
   printf("\n|  $$$$$$  | $$  | $$| $$      | $$  | $$      | $$      | $$$$$   |  $$ / $$/| $$$$$   | $$         | $$  | $$ $$ $$| $$ /$$$$");
   printf("\n\\____   $$| $$  | $$| $$      | $$  | $$      | $$      | $$__/    \\  $$ $$/ | $$__/   | $$        | $$  | $$  $$$$| $$|_  $$");
   printf("\n /$$  \\ $$| $$  | $$| $$      | $$  | $$      | $$      | $$        \\  $$$/  | $$      | $$        | $$  | $$\\  $$$| $$  \\ $$");
   printf("\n|  $$$$$$/|  $$$$$$/| $$$$$$$$|  $$$$$$/      | $$$$$$$$| $$$$$$$$   \\  $/   | $$$$$$$$| $$$$$$$$ /$$$$$$| $$ \\  $$|  $$$$$$/");
   printf("\n \\______/  \\______/ |________/ \\______/       |________/|________/    \\_/    |________/|________/|______/|__/  \\__/ \\______/ ");

   
   char op;
   printf("\nWELCOME TO SOLO LEVELING THE ADVENTURE GAME!!!!!!\n");
   printf("\nUSE LOGIC TO DEFEAT MONSTERS!!!!");
   printf("\nTRAVEL THE GIVEN MAP TO COMPLETE THE GAME!!!");
   printf("\nDONT FORGET TO TALK TO PEOPLE");

   printf("\nPRESS ANY KEY TO START YOUR ADVENTURE\n");
   scanf(" %c",&op);
}   
