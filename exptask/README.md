# The Student Achievement Management System for Middle Schools

_Written by Bill Haku. Thanks for understanding all the mistakes in this file._

## Project Introduction

This is the final term project for C language course of SISE of UESTC. The group members are __Jiajun Bai__, Chengchen Dian, Junwen Duan, Jie Li, Zhenyu Liu, and Zhe Peng (in alphabat order of the last names).

This project is a system of student achievement management for middle schools.  The whole project mainly includes 5 parts, and each part will be specificly explained below.

## Main Moudles' Introduction

### Global variables and precompiling parts

#### Header files

The following header files were included in this program:

- `<stdio.h>`
- `<string.h>`
- `<stdlib.h>`
- `<unisted.h> `
- `<time.h>`

__Attention: `<unisted.h>` should be replaced into `<windows.h>` in Windows environment.__

#### Global variables

The following are the the global variables:

```C
const int MAXN=2e6;
 
struct student {
    struct score {
        int choice_question;
        int completion;
        int answer_question;
        int tot;
        char grade;
    } sc[10][105];   
    int tot_score[105];  
    char name[20];
}stu[MAXN];
int all_stu_num;    
char user_name[MAXN];
int user_name_length=1;
int class_number;
int allTestTime;
int hr_type;
int currentHour, currentMin;
```

Here are the explainations.

The structural morphology array `stu[MAXN]`includes another structural morphology array `sc[10][105]`, an integer array `tot_score` and a character array `name`. The specific introduction to `sc[10][105]` can be found in the next paragraph. The array `tot_score[105]` stores the total score of all subjects in each test. The parameter indicates the test number. 

The structural morphology array `sc[10][105]` includes an integer `choice_question`, an integer `completion`, an integer `answer_question` , an integer `tot`, and an character `grade`. The 3 integers are used to store the score of each part in a test paper. `tot`is used to store the total score. `grade`is used to store the grade of the subject. The first parameter of `sc[10][105]`means each subject. Details can be found in the following form. The second parameter means the diffterent times of each subject.

| Parameter 1 | Meaning |
| ------- | ----------- |
| 1			  | Chinese |
| 2| Mathematics |
| 3 | English |
| 4 | Physics |
| 5 | Chemistry |
| 6 | Biology |
| Other | NULL |

The integer `all_stu_num`stores the number of the students.

The character array `user_name[MAXN]`stores the user's name.

The integer `user_name_length`stores the length of the string `user_name[MAXN]`.

The integer `class_number`stores the class number.

The integer `allTestTime`stores the total number of tests.

The integer `hr_type`stores the type of hour of the current time.

The integer `currentHour` and `currentMin` stores the hour of current time and minute of current time.



### Main Function

#### The main function, the start of the whole system.

Firstly, we call the initialization function to do some initializing work. Details are explained in the *initialization (first use)* part.

We get the current time in the initialization function(`first_use()`) and get the hourType according to the current time. 5 kinds were divided and the system will show different greetings when entering the system.

Next is our main part, realizing with a `while`loop. We ask for command and explain the operating method and the function of each command number. Then we scan a number as the task command.

**Why we use a `getchar();`here?** Answer: When a number is entered as a command, a newline character (`"\n"`) is also entered into the buffer. If we don't call the getchar function, unexpected error will occur in the next time it read the buffer. Same to the others.

Then a `switch(int)`structure was used to call each function and other works.

The whole system end with return value 0 as usual.

### Add New for All

#### This moudle is used for add scores for all students.

Firstly, as we add scores for all student, we add 1 to `allTestTime`. Then we ask the user to enter the test time. Then a `for`loop is used to add scores for each student in the order of Chinese: Choice Questions, Completion, and Answer Questions; Mathematic (same in detail), English, Physics, Chemistry, and Biology. After that, we calculate the total score and calculate the grade according to the total score.

### Add New for One

#### This moudle is used for add scores for one specific student.

First, we ask the user to enter the test time and the student number of the student who the user wants to add scores on.Then a `for`loop is used to add scores for each student in the order of Chinese: Choice Questions, Completion, and Answer Questions; Mathematic (same in detail), English, Physics, Chemistry, and Biology. After that, we calculate the total score and calculate the grade according to the total score. Finally, we print out "Work done!" as a tips message.

### Look up All

#### This moudle is used for print and list out all the general scores of all students in one test.

We ask the user to enter the test time who wants to look up. Then we print out the title and header of the form. After that, we use a `for`loop to print out the total score of each subject of all the students.

### Look up One

#### This moudle is used for print and list out the specific scores of an specific student in one test.

We ask the user to enter the student number and the test time who wants to look up. Then we print out the specific score of each subjects of this student.

### Export a txt file

#### This moudle is used to print out all the scores of all students into an *.text file

We use a `for`loop to print out the scores of each test. We print out the header of the form and use another `for`loop to print out the score of each subject of each students.

Then we redirect to the console to make sure the output messages will be displayed on the screen instead of the output file. __Attention: the code is different in different compile environments.__

## Other Moudles

### Initialization (first use)

First, we get the current time from the OS to provide greetings in the `main()`function. Then we showing the leading messages and use function `sleep(1);`to wait for 1 second to avoid all the messages are printed out on the screen at the same time. __Attention: change the integer `1`into `1000`in Windows environment. Same to the below in line 59  and line 75.__

Then we read the user's name, the class number and the total number of students.  Then all work are done.

### Exit

#### Used for exit the system.

Included in the main function. We add a confirm part to avoid exit the system unexpectedly by accident or mistake.

## About it

Copyright (C) 2020 Bill Haku

ReadMe File Version: 1.0.2

Program Version: 1.0.1

Update date: 20201219.

