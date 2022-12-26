#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>

// The prize array
int prize[] = {0, 1000, 2000, 5000, 10000, 50000, 100000, 500000, 100000};
int indx = 0;

// lifelines
bool fifty50 = true, phn_frnd = true, flip_qsn = true;

// The Question
int serial = 1;
struct Question
{
    bool visited;           // check if the question is alreasy asked
    char name[100];     
    char options[4][25];
    int key;                // index of the answer
};

void result();
void menu();
void fiftyfifty(struct Question temp);
void phone_frnd();

// initializing the questions
struct Question quest[] = { {false, "How many consonants are there in the English alphabet? \n", {"21", "26", "9", "12"}, 0},
                            {false, "Which animal is known as the ship of desert ? \n", {"Desert Lizard", "Camel", "Scorpion", "Horse"}, 1},
                            {false, "What is the National song of India ? \n", {"Gypsy", "Vande mataram", "Jana Gana Mana", "Jingle bells"}, 1},
                            {false, "What is the biggest continent in the world ? \n", {"South America", "Antarctica", "Europe", "Asia"}, 3},
                            {false, "Which colour symbolises peace? \n", {"Black", "Pink", "Yellow", "White"}, 3},
                            {false, "Which is the largest planet of our Solar System ? \n", {"Neptune", "Sun", "Jupiter", "Mars"}, 2},
                            {false, "How many years are there in one Millenium? \n", {"100", "500", "1,000", "10,000"}, 2},
                            {false, "Which is the National Aquatic Animal of India? \n", {"River Dolphin", "Shark", "SeaHorse", "Fish"}, 0}
                            };

int main()
{
    system("cls");
    while(true) menu();
}

// Result
void result()
{
    system("cls");
    for(int i=0; i<50; i++) printf("__");    // aesthetics
    if(indx != 8)   printf("\nSorry, Wrong Answer !!!\n");
    else            printf("\nCongratulations !!!. You won !!!! \n");
    printf("You solved %d questions. \n", indx);  //  info
    printf("You earned %d rupees. \n", prize[indx]);  //  info
    for(int i=0; i<50; i++) printf("__");    // aesthetics

    exit(0);
}

// lifeline function
void fiftyfifty(struct Question temp)
{
    int prev = 5;   // stores the prev option deleted
    int cross = 2;  // stores the number of options to be deleted
    while(cross)
    {
        int random_option = (rand()%3)+1;
        while(random_option-1 == (temp.key) && random_option == prev)    random_option = (rand()%3)+1;
        cross--;
        prev = random_option;
        printf("%d is false !!!\n", random_option);
    }
    fifty50 = false;
}

// lifeline function
void phone_frnd()
{
    printf("Call Connected ... ");
    for(int i=30; i>=0; i--)
    {
        printf("%d seconds left \n", i);
        Sleep(1000);
    }
    phn_frnd = false;
}

// The main menu
void menu()
{
    // clearing screen  
    system("cls");  srand(time(0));

    if(indx == 0)
    {
        printf("Welcome to KBC !! press any key to start playing !");
        int temp;   scanf("%d", &temp);
        system("cls");
    }

    else if(indx == 8)  result(); 

    // generating a random number between 0 and (max ques array size)
    int max_bound = *(&quest + 1) - quest; 
    
    finding_question:
        int rand_question  = rand()%max_bound;  // the random number

    while(quest[rand_question].visited == true)
    {
        rand_question  = rand()%max_bound;          // Doubt :  can a program run into infinite loop in this condition 
    }    

    // Asking the question
    printf("Question %d]%s", (indx+1), quest[rand_question].name);
    printf("Prize : %d \n\n", prize[indx+1]);
    printf("Option A)   %s \n", quest[rand_question].options[0]);
    printf("Option B)   %s \n", quest[rand_question].options[1]);
    printf("Option C)   %s \n", quest[rand_question].options[2]);
    printf("Option D)   %s \n", quest[rand_question].options[3]);
    
    // checking for lifelines
    if(fifty50) printf("\nType e for 50-50, ");
    if(flip_qsn) printf("\nType f to flip the question, ");
    if(fifty50) printf("\nType g to pnone a friend ");
    printf("\n");

    // Checking the answer
    printf("\nEnter the correct option : ");
    fflush(stdin);
    char ans;   scanf("%c", &ans);

    // lifeline functions
    if(ans == 'e' && fifty50 == true)  fiftyfifty(quest[rand_question]);
    else if(ans == 'f' && flip_qsn == true) {flip_qsn = false; system("cls");   goto finding_question;}
    else if(ans == 'g' && phn_frnd == true) phone_frnd(); 


    if(ans == 'e' || ans == 'f' || ans == 'g')
    {
        printf("\nEnter the correct option : ");
        fflush(stdin);
        ans;   scanf("%c", &ans);
    }

    ans = toupper(ans);
    ans = ans-65;   // subtracting the ascii value to make the options as 0, 1, 2, 3
    
    if(ans == quest[rand_question].key)
    {
        indx++;
        quest[rand_question].visited = true;
    }

    else
    {
        result();
    }
}
