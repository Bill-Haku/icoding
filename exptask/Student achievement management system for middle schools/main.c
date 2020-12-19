//
//  main.c
//  Student achievement management system for middle schools
//
//  Created by HakuBill on 2020/10/22.
//

//Attention!! There are 3 places you need to pay attention to and change if you don not use macOS!!

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> // ##If you use Windows OS, change here into <windows.h>. ## (If you use macOS or Linux, you don't need to.)
#include <time.h>

const int MAXN=2e6;

struct student {
    struct score {
        int choice_question;
        int completion;
        int answer_question;
        int tot;
        char grade;
    } sc[10][105];   //parameter1: 1 to 6 is for chinese, math, english, physics, chemstry and biology. parameter2: the times of one subject
    int tot_score[105];  //total score
    char name[20];
}stu[MAXN];
int all_stu_num;    //the number of students
char user_name[MAXN];
int user_name_length=1;
int class_number;
int allTestTime;
int hr_type;
int currentHour, currentMin;

void first_use() {
    time_t now;
    struct tm *tm_now;
    time(&now);
    tm_now = localtime(&now);
    int hour = tm_now->tm_hour;
    currentHour=hour;
    currentMin=tm_now->tm_min;
    if(hour>=0&&hour<=6)
        hr_type=1;
    else if(hour>=7&&hour<=11)
        hr_type=2;
    else if(hour>=12&&hour<=13)
        hr_type=3;
    else if(hour>=14&&hour<=18)
        hr_type=4;
    else if(hour>=19&&hour<=23)
        hr_type=5;
    
    printf("Welcome to the Student Achievement management System for Middle Schools.\n");
    sleep(1);   //Change the integer into 1000 if there is no obvious pause in the windows. Same to the blew (in line 59).
    printf("This is a program developed by Bai Jiajun in Octember, 2020.\n");
    sleep(1);
    printf("First of all, please enter your name here and end with an Enter: ");
    int i=1;
    while(scanf("%c",&user_name[i])) {
        if(user_name[i]=='\n')
            break;
        i++;
        user_name_length=i-1;
    }
    printf("And then please enter your class number here and end with an Enter: ");
    scanf("%d",&class_number);
    getchar();
    printf("Nice!\nAnd then enter the number of students in your class here: ");
    scanf("%d",&all_stu_num);
    getchar();
    printf("Nice! You have finished all the work you need to do before using this system\n");
    sleep(1);
    printf("Enjoy using it from now on!\n\n");
}

void add_new_for_all() {
    allTestTime++;
    printf("How many times is this test?    :");
    int test_time;
    scanf("%d",&test_time);
    getchar();
    for(int j=1;j<=all_stu_num;j++) {
        printf("Student %d:\n",j);
        printf("Now enter the choice question score, the completion score, the answer question score of his/her Chinese in the order.\n");
        printf("Tips: the system will calculate the total score automatically.\n");
        printf("Choice question score:  ");
        scanf("%d",&stu[j].sc[1][test_time].choice_question);
        getchar();
        printf("Completion score:  ");
        scanf("%d",&stu[j].sc[1][test_time].completion);
        getchar();
        printf("Answer question score:  ");
        scanf("%d",&stu[j].sc[1][test_time].answer_question);
        getchar();
        
        printf("\nNow the Math scores.\n");
        printf("Tips: the system will calculate the total score automatically.\n");
        printf("Choice question score:  ");
        scanf("%d",&stu[j].sc[2][test_time].choice_question);
        getchar();
        printf("Completion score:  ");
        scanf("%d",&stu[j].sc[2][test_time].completion);
        getchar();
        printf("Answer question score:  ");
        scanf("%d",&stu[j].sc[2][test_time].answer_question);
        getchar();
        
        printf("\nNow the English scores.\n");
        printf("Tips: the system will calculate the total score automatically.\n");
        printf("Choice question score:  ");
        scanf("%d",&stu[j].sc[3][test_time].choice_question);
        getchar();
        printf("Completion score:  ");
        scanf("%d",&stu[j].sc[3][test_time].completion);
        getchar();
        printf("Answer question score:  ");
        scanf("%d",&stu[j].sc[3][test_time].answer_question);
        getchar();
        
        printf("\nNow the Physics scores.\n");
        printf("Tips: the system will calculate the total score automatically.\n");
        printf("Choice question score:  ");
        scanf("%d",&stu[j].sc[4][test_time].choice_question);
        getchar();
        printf("Completion score:  ");
        scanf("%d",&stu[j].sc[4][test_time].completion);
        getchar();
        printf("Answer question score:  ");
        scanf("%d",&stu[j].sc[4][test_time].answer_question);
        getchar();
        
        printf("\nNow the Chemistry scores.\n");
        printf("Tips: the system will calculate the total score automatically.\n");
        printf("Choice question score:  ");
        scanf("%d",&stu[j].sc[5][test_time].choice_question);
        getchar();
        printf("Completion score:  ");
        scanf("%d",&stu[j].sc[5][test_time].completion);
        getchar();
        printf("Answer question score:  ");
        scanf("%d",&stu[j].sc[5][test_time].answer_question);
        getchar();
        
        printf("\nNow the Biology scores.\n");
        printf("Tips: the system will calculate the total score automatically.\n");
        printf("Choice question score:  ");
        scanf("%d",&stu[j].sc[6][test_time].choice_question);
        getchar();
        printf("Completion score:  ");
        scanf("%d",&stu[j].sc[6][test_time].completion);
        getchar();
        printf("Answer question score:  ");
        scanf("%d",&stu[j].sc[6][test_time].answer_question);
        getchar();
        
        for(int i=1;i<=6;i++) {
            stu[j].sc[i][test_time].tot=stu[j].sc[i][test_time].choice_question+stu[j].sc[i][test_time].answer_question+stu[j].sc[i][test_time].completion;
        
            if(stu[j].sc[i][test_time].tot>=85)
                stu[j].sc[i][test_time].grade='A';
            else if(stu[j].sc[i][test_time].tot>=70&&stu[j].sc[i][test_time].tot<85)
                stu[j].sc[i][test_time].grade='B';
            else if(stu[j].sc[i][test_time].tot>=60&&stu[j].sc[i][test_time].tot<70)
                stu[j].sc[i][test_time].grade='C';
            else if(stu[j].sc[i][test_time].tot<60)
                stu[j].sc[i][test_time].grade='F';
        }
        
        for(int i=1;i<=6;i++)
            stu[j].tot_score[test_time]+=stu[j].sc[i][test_time].tot;
        
        printf("\n");
    }
    printf("Work done!\n\n");
}

void add_new_for_one() {
    allTestTime++;
    printf("How many times is this test?    :");
    int test_time;
    scanf("%d",&test_time);
    getchar();
    int stu_num;
    printf("Enter the student number of the student :");
    scanf("%d",&stu_num);
    getchar();
    
    printf("Now enter the choice question score, the completion score, the answer question score of his/her Chinese in the order.\n");
    printf("Tips: the system will calculate the total score automatically.\n");
    printf("Choice question score:  ");
    scanf("%d",&stu[stu_num].sc[1][test_time].choice_question);
    getchar();
    printf("Completion score:  ");
    scanf("%d",&stu[stu_num].sc[1][test_time].completion);
    getchar();
    printf("Answer question score:  ");
    scanf("%d",&stu[stu_num].sc[1][test_time].answer_question);
    getchar();
    
    printf("\nNow the Math scores.\n");
    printf("Tips: the system will calculate the total score automatically.\n");
    printf("Choice question score:  ");
    scanf("%d",&stu[stu_num].sc[2][test_time].choice_question);
    getchar();
    printf("Completion score:  ");
    scanf("%d",&stu[stu_num].sc[2][test_time].completion);
    getchar();
    printf("Answer question score:  ");
    scanf("%d",&stu[stu_num].sc[2][test_time].answer_question);
    getchar();
    
    printf("\nNow the English scores.\n");
    printf("Tips: the system will calculate the total score automatically.\n");
    printf("Choice question score:  ");
    scanf("%d",&stu[stu_num].sc[3][test_time].choice_question);
    getchar();
    printf("Completion score:  ");
    scanf("%d",&stu[stu_num].sc[3][test_time].completion);
    getchar();
    printf("Answer question score:  ");
    scanf("%d",&stu[stu_num].sc[3][test_time].answer_question);
    getchar();
    
    printf("\nNow the Physics scores.\n");
    printf("Tips: the system will calculate the total score automatically.\n");
    printf("Choice question score:  ");
    scanf("%d",&stu[stu_num].sc[4][test_time].choice_question);
    getchar();
    printf("Completion score:  ");
    scanf("%d",&stu[stu_num].sc[4][test_time].completion);
    getchar();
    printf("Answer question score:  ");
    scanf("%d",&stu[stu_num].sc[4][test_time].answer_question);
    getchar();
    
    printf("\nNow the Chemistry scores.\n");
    printf("Tips: the system will calculate the total score automatically.\n");
    printf("Choice question score:  ");
    scanf("%d",&stu[stu_num].sc[5][test_time].choice_question);
    getchar();
    printf("Completion score:  ");
    scanf("%d",&stu[stu_num].sc[5][test_time].completion);
    getchar();
    printf("Answer question score:  ");
    scanf("%d",&stu[stu_num].sc[5][test_time].answer_question);
    getchar();
    
    printf("\nNow the Biology scores.\n");
    printf("Tips: the system will calculate the total score automatically.\n");
    printf("Choice question score:  ");
    scanf("%d",&stu[stu_num].sc[6][test_time].choice_question);
    getchar();
    printf("Completion score:  ");
    scanf("%d",&stu[stu_num].sc[6][test_time].completion);
    getchar();
    printf("Answer question score:  ");
    scanf("%d",&stu[stu_num].sc[6][test_time].answer_question);
    getchar();
    
    for(int i=1;i<=6;i++) {
        stu[stu_num].sc[i][test_time].tot=stu[stu_num].sc[i][test_time].choice_question+stu[stu_num].sc[i][test_time].answer_question+stu[stu_num].sc[i][test_time].completion;
        if(stu[stu_num].sc[i][test_time].tot>=85)
            stu[stu_num].sc[i][test_time].grade='A';
        else if(stu[stu_num].sc[i][test_time].tot>=70&&stu[stu_num].sc[i][test_time].tot<85)
            stu[stu_num].sc[i][test_time].grade='B';
        else if(stu[stu_num].sc[i][test_time].tot>=60&&stu[stu_num].sc[i][test_time].tot<70)
            stu[stu_num].sc[i][test_time].grade='C';
        else if(stu[stu_num].sc[i][test_time].tot<60)
            stu[stu_num].sc[i][test_time].grade='F';

    }
    printf("Work done!\n\n");
}

void look_up_all() {
    printf("Enter the time of the class you want to look up :   ");
    int test_time;
    scanf("%d",&test_time);
    getchar();
    
    printf("\nClass %d Test %d :\n",class_number,test_time);
    printf("Num  Total  Chinese  Math  English  Physics  Chemistry  Biology\n");
    for(int i=1;i<=all_stu_num;i++) {
        printf("%3d  %5d  %7d  %4d  %7d  %7d  %9d  %7d\n", i,stu[i].tot_score[test_time],stu[i].sc[1][test_time].tot,stu[i].sc[2][test_time].tot,stu[i].sc[3][test_time].tot,stu[i].sc[4][test_time].tot,stu[i].sc[5][test_time].tot,stu[i].sc[6][test_time].tot);
    }
    
    printf("\n");
    printf("For specific scores, please look up the record of one specifc student.\n");
    printf("\n");
}

void look_up_one() {
    printf("Enter the student number of the student you want to look up :");
    int stu_num;
    scanf("%d",&stu_num);
    getchar();
    printf("Enter the time of the test you want to look up  :");
    int test_time;
    scanf("%d",&test_time);
    getchar();
    
    printf("\nThe score of student %d is:\n",stu_num);
    printf("Subject    Total  Choice Question  Completion  Answer Question  Grade\n");
    printf("  Chinese  %5d  %15d  %10d  %15d  %5c\n", stu[stu_num].sc[1][test_time].tot,stu[stu_num].sc[1][test_time].choice_question,stu[stu_num].sc[1][test_time].completion,stu[stu_num].sc[1][test_time].answer_question,stu[stu_num].sc[1][test_time].grade);
    printf("     Math  %5d  %15d  %10d  %15d  %5c\n", stu[stu_num].sc[2][test_time].tot,stu[stu_num].sc[2][test_time].choice_question,stu[stu_num].sc[2][test_time].completion,stu[stu_num].sc[2][test_time].answer_question,stu[stu_num].sc[2][test_time].grade);
    printf("  English  %5d  %15d  %10d  %15d  %5c\n", stu[stu_num].sc[3][test_time].tot,stu[stu_num].sc[3][test_time].choice_question,stu[stu_num].sc[3][test_time].completion,stu[stu_num].sc[3][test_time].answer_question,stu[stu_num].sc[3][test_time].grade);
    printf("  Physics  %5d  %15d  %10d  %15d  %5c\n", stu[stu_num].sc[4][test_time].tot,stu[stu_num].sc[4][test_time].choice_question,stu[stu_num].sc[4][test_time].completion,stu[stu_num].sc[4][test_time].answer_question,stu[stu_num].sc[4][test_time].grade);
    printf("Chemistry  %5d  %15d  %10d  %15d  %5c\n", stu[stu_num].sc[5][test_time].tot,stu[stu_num].sc[5][test_time].choice_question,stu[stu_num].sc[5][test_time].completion,stu[stu_num].sc[5][test_time].answer_question,stu[stu_num].sc[5][test_time].grade);
    printf("  Biology  %5d  %15d  %10d  %15d  %5c\n", stu[stu_num].sc[6][test_time].tot,stu[stu_num].sc[6][test_time].choice_question,stu[stu_num].sc[6][test_time].completion,stu[stu_num].sc[6][test_time].answer_question,stu[stu_num].sc[6][test_time].grade);
    
    printf("\n");
}

void print_out() {
    freopen("output.txt", "w", stdout);
    
    for(int i=1;i<=allTestTime;i++) {
        printf("Class %d Test %d :\n",class_number,allTestTime);
        printf("Num  Total  Chinese  Math  English  Physics  Chemistry  Biology\n");
        for(int j=1;j<=all_stu_num;j++) {
            printf("%3d  %5d  %7d  %4d  %7d  %7d  %9d  %7d\n", j,stu[j].tot_score[i],stu[j].sc[1][i].tot,stu[j].sc[2][i].tot,stu[j].sc[3][i].tot,stu[j].sc[4][i].tot,stu[j].sc[5][i].tot,stu[j].sc[6][i].tot);
        }
        
        printf("\n");

    }
    fclose(stdout);
    freopen("/System/Applications/Utilities/console","w",stdout);
    // If you use Windows, replace the code above with the code below:
    //freopen("CON","w",stdout);
    // If you use Linux, replace the code above with the code below:
    //freopen("/dev/console","w",stdout);
    printf("\n");

}

int main(int argc, const char * argv[]) {
    first_use();
    int task;
    char IsExit;
    switch (hr_type) {
        case 1:
            printf("Go to sleep please! It's AM %d : %d now.\n", currentHour, currentMin);
            break;
        case 2:
            printf("Good morning, %s! It's AM %d : %d now.\n", user_name,currentHour, currentMin);
            break;
        case 3:
            printf("Have a good lunch, %s! It's PM %d : %d now.\n",user_name, currentHour, currentMin);
            break;
        case 4:
            printf("Gooding afternoon, %s! It's PM %d : %d now.\n", user_name, currentHour, currentMin);
            break;
        case 5:
            printf("Good evening, %s! It's PM %d : %d now.\n", user_name, currentHour, currentMin);
            break;
    }
    while(1) {
        printf("What do you want to do?\nEnter the code before the description!\n");
        printf("1   Add a new record for all students.\n");
        printf("2   Add a new record for a specific student.\n");
        printf("3   Look up the record of all students.\n");
        printf("4   Look up the record of one specific student.\n");
        printf("5   Export a txt form of the records.\n");
        printf("6   Exit the system.\n");
        scanf("%d",&task);
        getchar();
        switch (task) {
            case 1:
                add_new_for_all();
                break;
            case 2:
                add_new_for_one();
                break;
            case 3:
                look_up_all();
                break;
            case 4:
                look_up_one();
                break;
            case 5:
                print_out();
                break;
            case 6:
            ask:printf("Are you sure to exit? (Y/N)\n");
                scanf("%c",&IsExit);
                if(IsExit=='Y')
                    return 0;
                else if(IsExit=='N')
                    continue;
                else {
                    printf("Your input is invalid, please enter again\n");
                    goto ask;
                }
                break;
            default:
                printf("Your input is invalid, please enter again!\n");
                break;
        }
    }
    return 0;
}
