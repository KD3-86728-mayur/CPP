#include <stdio.h>

struct Date
{
    /* data */
    int day;
    int month;
    int year;

};

void initData(struct Date *ptr){
    ptr->day = 10;
    ptr->month = 9;
    ptr->year = 2024;
}

void printData(struct Date *ptr){
    printf("Date is : %d - %d - %d \n",ptr->day,ptr->month,ptr->year);
}
void acceptDataFromConsole(struct Date *ptr){
    printf("Enter the date ");
    scanf("%d %d %d",&ptr->day,&ptr->month,&ptr->year);

}

int num(){
    int n;
    printf("For Exit Enter 0 \n");
    printf("For Accept Date enter 1 \n");
    printf("For Printing Date Enter 2 \n");
    scanf("%d",&n);
    return n;

}

int main(){

    struct Date d1;
    struct Date d2;
    int nu;
    while((nu=num()) != 0){
        switch (nu)
        {
        case 0:
            break;
        case 1:
            acceptDataFromConsole(&d1);
            break;
        case 2:
            printData(&d1);
            break;
        default:
            printf("Wrong input");
            break;
        }
        

    }
    
   

    return 0;
}