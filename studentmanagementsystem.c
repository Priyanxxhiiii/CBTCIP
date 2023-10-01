#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int roll;
    char name[15];
    char surname[15];
    float subject1, subject2, subject3, subject4, subject5;
    float avg;
    float highest;
    float lowest;
    float total;
};

struct student *s;

char getGrade(int average)
{
    if(average>80)
        return 'A';
    else if(average>60)
        return 'B';
    else if(average>45)
        return 'C';
    else
        return 'F';
}

int main()
{
    int i,n;
    printf("Enter number of students:");
    scanf("%d",&n);
    s=(struct student *)malloc(sizeof(struct student)*n);

    for(i=0;i<n;i++)
    {
        printf("Enter roll number of %d student:",i+1);
        scanf("%d",&s[i].roll);
        printf("Enter name of %d student:",i+1);
        scanf(" %s",s[i].name);
        printf("Enter surname of %d student:",i+1);
        scanf(" %s",s[i].surname);
        printf("Enter marks of subject 1:");
        scanf("%f",&s[i].subject1);
        printf("Enter marks of subject 2:");
        scanf("%f",&s[i].subject2);
        printf("Enter marks of subject 3:");
        scanf("%f",&s[i].subject3);
        printf("Enter marks of subject 4:");
        scanf("%f",&s[i].subject4);
        printf("Enter marks of subject 5:");
        scanf("%f",&s[i].subject5);

        //Calculate total
        s[i].total=(s[i].subject1 + s[i].subject2 + s[i].subject3 + s[i].subject4 + s[i].subject5);
        
        // Calculate average
        s[i].avg=((s[i].subject1 + s[i].subject2 + s[i].subject3 + s[i].subject4 + s[i].subject5)/5);

        // Calculate highest and lowest
        s[i].highest=s[i].subject1;
        s[i].lowest=s[i].subject1;

        if(s[i].subject2>s[i].highest)
            s[i].highest=s[i].subject2;
        else if(s[i].subject2<s[i].lowest)
            s[i].lowest=s[i].subject2;

        if(s[i].subject3>s[i].highest)
            s[i].highest=s[i].subject3;
        else if(s[i].subject3<s[i].lowest)
            s[i].lowest=s[i].subject3;

        if(s[i].subject4>s[i].highest)
            s[i].highest=s[i].subject4;
        else if(s[i].subject4<s[i].lowest)
            s[i].lowest=s[i].subject4;

        if (s[i].subject5>s[i].highest)
            s[i].highest=s[i].subject5;
        else if (s[i].subject5<s[i].lowest)
            s[i].lowest=s[i].subject5;
    }

    printf("\nYou have entered:\n");
    printf("Roll\tSub1\tSub2\tSub3\tSub4\tSub5\tTotal\tAverage\t\tGrade\t\tHighest\t\tLowest\t\tName\n");
    for (i=0;i<n;i++)
    {
        char grade=getGrade(s[i].avg);
        printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t\t%c\t\t%.2f\t\t%.2f\t\t%s %s\n",s[i].roll,s[i].subject1,s[i].subject2,s[i].subject3,s[i].subject4,s[i].subject5,s[i].total,s[i].avg,grade,s[i].highest,s[i].lowest,s[i].name,s[i].surname);
    }

    free(s);

    return 0;
}