# Cproj2022_KBC
C project, 2022, KBC program, Semester 1

# Includes
**#include < stdio.h>** : is used for standard input and output functions  
**#include < stdbool.h>** : is used for boolean values   
**#include < stdlib.h>** : is used for clear screen and random function   
**#include < ctype.h>** : is used for toupper() function   
**#include < time.h>** : is used for seed in srand  
**#include < windows.h>** : is used for sleep function to pause the execution of program  

# Global Variables
> Prize array is used to store cost won by the user  
> indx stores the current money won  
> fifty50, phn_frnd, flip_qsn are used to check if the user has exhausted lifelines or not  

# Struct Question
> visited checks if the current question is already asked
> name stores the question 
> options array stores the 4 options  
> key stores the index of correct option

## Functions 
> Result() : Displays the final result and exits the program.   
> menu() : Asks and checks the question. The main body of the KBC proram.   
>fiftyfifty() and phone_frnd() : lifeline functions  

# P.S
This is a random question asking KBD program. More questions can be added manually without altering the internal working of the program. There are 3 lifelines for the user to use and 8 questions are asked. 
