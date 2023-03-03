//LEARNPROGRAMO - PROGRAMMING MADE SIMPLE
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
//#include<ctype.h>                   //contains toupper(), tolower(),etc
//#include<dos.h>                     //contains _dos_getdate
#include<time.h>

#define RETURNTIME 15

char catagories[][15]= {"Computer","Electronics","Electrical","Civil","Mechnnical","Architecture"};
void returnfunc(void);
void mainmenu(void);
void addbooks(void);
void deletebooks(void);
void editbooks(void);
void searchbooks(void);
void issuebooks(void);
void viewbooks(void);
void closeapplication(void);
int  getdata();
int  checkid(int);
int t(void);
void Password();
void issuerecord();
void loaderanim();

//list of global files that can be acceed form anywhere in program
FILE *fp,*ft,*fs;


//list of global variable
int s;
char findbook;
char password[10]= {"codewithc"};

struct meroDate
{
    int mm,dd,yy;
};
struct books
{
    int id;
    char stname[20];
    char name[20];
    char Author[20];
    int quantity;
    float Price;
    int count;
    int rackno;
    char *cat;
    struct meroDate issued;
    struct meroDate duedate;
};
struct books a;
int main()
{
    Password();
    getch();
    return 0;

}
void mainmenu()
{
    system("cls");
    int i;
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 - MAIN MENU - \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\xDB\xDB\xDB\xDB\xB2 1. Add Books   ");
    printf("\n\xDB\xDB\xDB\xDB\xB2 2. Delete books");
    printf("\n\xDB\xDB\xDB\xDB\xB2 3. Search Books");
    printf("\n\xDB\xDB\xDB\xDB\xB2 4. Issue Books");
    printf("\n\xDB\xDB\xDB\xDB\xB2 5. View Book list");
    printf("\n\xDB\xDB\xDB\xDB\xB2 6. Edit Book's Record");
    printf("\n\xDB\xDB\xDB\xDB\xB2 7. Close Application");
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    t();
    printf("\nEnter your choice:");
    switch(getch())
    {
    case '1':
        addbooks();
        break;
    case '2':
        deletebooks();
        break;
    case '3':
        searchbooks();
        break;
    case '4':
        issuebooks();
        break;
    case '5':
        viewbooks();
        break;
    case '6':
        editbooks();
        break;
    case '7':
    {
        system("cls");
        //printf("********************************************");
        //printf("\nExiting in 3 second...........>");
        //Sleep(3000);
        exit(0);
    }
    default:
    {
        printf("\n\aWrong Entry!!Please re-entered correct option");
        if(getch())
            mainmenu();
    }

    }
}
void addbooks(void)    //funtion that add books
{
    system("cls");
    int i;
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 - SELECT CATEGOIES - \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\xDB\xDB\xDB\xDB\xB2 1. Computer");
    printf("\n\xDB\xDB\xDB\xDB\xB2 2. Electronics");
    printf("\n\xDB\xDB\xDB\xDB\xB2 3. Electrical");
    printf("\n\xDB\xDB\xDB\xDB\xB2 4. Civil");
    printf("\n\xDB\xDB\xDB\xDB\xB2 5. Mechanical");
    printf("\n\xDB\xDB\xDB\xDB\xB2 6. Architecture");
    printf("\n\xDB\xDB\xDB\xDB\xB2 7. Back to main menu");
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\nEnter your choice:");
    scanf("%d",&s);

    if(s==7)
        mainmenu() ;

    system("cls");
    fp=fopen("Bibek.dat","ab+");
    if(getdata()==1)
    {
        a.cat=catagories[s-1];
        fseek(fp,0,SEEK_END);
        fwrite(&a,sizeof(a),1,fp);
        fclose(fp);
        printf("\nThe record is sucessfully saved");
        printf("\nSave any more?(Y / N):");
        if(getch()=='n')
            mainmenu();
        else
            system("cls");
        addbooks();
    }
}
void deletebooks()    //function that delete items from file fp
{
    system("cls");
    int d;
    char another='y';
    while(another=='y')  //infinite loop
    {
        system("cls");
        findbook='n';
        printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 - Delete Book - \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        printf("\n\xDB\xDB\xDB\xB2 Enter Book ID to delete :");
        scanf("%d",&d);
        fp=fopen("Bibek.dat","rb+");
        rewind(fp);
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(a.id==d)
            {
                printf("\xDB\xDB\xDB\xB2  The book record is available");
                printf("\n\xDB\xDB\xDB\xB2  Book name is %s",a.name);
                printf("\n\xDB\xDB\xDB\xB2  Rack No. is %d",a.rackno);
                findbook='t';
                break;
            }
        }
        if(findbook!='t')
        {
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            printf("\nNo record is found modify the search");
            if(getch())
                mainmenu();
        }
        if(findbook=='t' )
        {
            printf("\n\xDB\xDB\xDB\xB2  Do you want to delete it?(Y/N):");
            if(getch()=='y')
            {
                ft=fopen("test.dat","wb+");  //temporary file for delete
                rewind(fp);
                while(fread(&a,sizeof(a),1,fp)==1)
                {
                    if(a.id!=d)
                    {
                        fseek(ft,0,SEEK_CUR);
                        fwrite(&a,sizeof(a),1,ft); //write all in tempory file except that
                    }                              //we want to delete
                }
                fclose(ft);
                fclose(fp);
                remove("Bibek.dat");
                rename("test.dat","Bibek.dat"); //copy all item from temporary file to fp except that
                fp=fopen("Bibek.dat","rb+");    //we want to delete
                if(findbook=='t')
                {
                    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                    printf("\nThe record is sucessfully deleted");
                    printf("\nDelete another record?(Y/N)");
                }
            }
            else
                mainmenu();
            fflush(stdin);
            another=getch();
        }
    }
    mainmenu();
}
void searchbooks()
{
    system("cls");
    int d;
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 - Search Books - \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\xDB\xDB\xDB\xB2 1. Search By ID");
    printf("\n\xDB\xDB\xDB\xB2 2. Search By Name");
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\nEnter Your Choice");
    fp=fopen("Bibek.dat","rb+"); //open file for reading propose
    rewind(fp);   //move pointer at the begining of file
    switch(getch())
    {
    case '1':
    {
        system("cls");
        printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 - Search Books - \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        printf("\n\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 - Search Books By ID - \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        printf("\n\xDB\xDB\xDB\xB2 Enter the book id:");
        scanf("%d",&d);
        printf("\xDB\xDB\xDB\xB2 Searching........");
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(a.id==d)
            {
                Sleep(2);
                printf("\n\xDB\xDB\xDB\xB2 The Book is available");
                printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                printf("\n\xB2 ID:%d",a.id);
                printf("\n\xB2");
                printf("\n\xB2 Name:%s",a.name);
                printf("\n\xB2");
                printf("\n\xB2 Author:%s ",a.Author);
                printf("\n\xB2");
                printf("\n\xB2 Qantity:%d ",a.quantity);
                printf("\n\xB2");
                printf("\n\xB2 Price:Rs.%.2f",a.Price);
                printf("\n\xB2");
                printf("\n\xB2 Rack No:%d ",a.rackno);
                printf("\n\xB2");
                printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                findbook='t';
            }

        }
        if(findbook!='t')  //checks whether conditiion enters inside loop or not
        {
            printf("\n\xDB\xDB\xDB\xB2 \aNo Record Found");
        }
        printf("\n\xDB\xDB\xDB\xB2 Try another search?(Y/N)");
        if(getch()=='y')
            searchbooks();
        else
            mainmenu();
        break;
    }
    case '2':
    {
        char s[15];
        system("cls");
        printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 - Search Books By Name - \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        printf("\n\xDB\xDB\xDB\xB2 Enter Book Name:");
        scanf("%s",s);
        int d=0;
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(strcmp(a.name,(s))==0) //checks whether a.name is equal to s or not
            {
                printf("\n\xDB\xDB\xDB\xB2 The Book is available");
                printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                printf("\n\xB2 ID:%d",a.id);
                printf("\n\xB2");
                printf("\n\xB2 Name:%s",a.name);
                printf("\n\xB2");
                printf("\n\xB2 Author:%s",a.Author);
                printf("\n\xB2");
                printf("\n\xB2 Qantity:%d",a.quantity);
                printf("\n\xB2");
                printf("\n\xB2 Price:Rs.%.2f",a.Price);
                printf("\n\xB2");
                printf("\n\xB2 Rack No:%d ",a.rackno);
                printf("\n\xB2");
                printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                d++;
            }

        }
        if(d==0)
        {
            printf("\n\xDB\xDB\xDB\xB2 \aNo Record Found");
        }
        printf("\n\xDB\xDB\xDB\xB2 Try another search?(Y/N)");
        if(getch()=='y')
            searchbooks();
        else
            mainmenu();
        break;
    }
    default :
        getch();
        searchbooks();
    }
    fclose(fp);
}
void issuebooks(void)  //function that issue books from library
{
    int t;

    system("cls");
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 - ISSUE SECTION - \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\xDB\xDB\xDB\xDb\xB2 1. Issue a Book");
    printf("\n\xDB\xDB\xDB\xDb\xB2 2. View Issued Book");
    printf("\n\xDB\xDB\xDB\xDb\xB2 3. Search Issued Book");
    printf("\n\xDB\xDB\xDB\xDb\xB2 4. Remove Issued Book");
    printf("\n\xDB\xDB\xDB\xDb\xB2 5. Go to Main Menu");
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\nEnter a Choice:");
    switch(getch())
    {
    case '1':  //issue book
    {
        system("cls");
        int c=0;
        char another='y';
        while(another=='y')
        {
            system("cls");
            c=0;
            printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 - Issue Book - \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            printf("\n\xDB\xDB\xDB\xDb\xB2 Enter the Book Id:");
            scanf("%d",&t);
            fp=fopen("Bibek.dat","rb");
            fs=fopen("Issue.dat","ab+");
            if(checkid(t)==0) //issues those which are present in library
            {
                printf("\n\xDB\xDB\xDB\xDb\xB2 The book record is available");
                printf("\n\xDB\xDB\xDB\xDb\xB2 There are %d unissued books in library ",a.quantity);
                printf("\n\xDB\xDB\xDB\xDb\xB2 The name of book is %s",a.name);
                printf("\n\xDB\xDB\xDB\xDb\xB2 Enter student name:");
                scanf("%s",a.stname);
//struct dosdate_t d; //for current date
//_dos_getdate(&d);
//a.issued.dd=d.day;
//a.issued.mm=d.month;
//a.issued.yy=d.year;
                //gotoxy(10,12);
                printf("\n\xDB\xDB\xDB\xDb\xB2 Issued date=%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);
                printf("\n\xDB\xDB\xDB\xDb\xB2 The BOOK of ID %d is issued",a.id);
                a.duedate.dd=a.issued.dd+RETURNTIME;   //for return date
                a.duedate.mm=a.issued.mm;
                a.duedate.yy=a.issued.yy;
                if(a.duedate.dd>30)
                {
                    a.duedate.mm+=a.duedate.dd/30;
                    a.duedate.dd-=30;

                }
                if(a.duedate.mm>12)
                {
                    a.duedate.yy+=a.duedate.mm/12;
                    a.duedate.mm-=12;

                }
                printf("\n\xDB\xDB\xDB\xDb\xB2 To be return:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
                fseek(fs,sizeof(a),SEEK_END);
                fwrite(&a,sizeof(a),1,fs);
                fclose(fs);
                c=1;
            }
            if(c==0)
            {
                printf("\n\xDB\xDB\xDB\xDb\xB2 No record found");
            }
            printf("\n\xDB\xDB\xDB\xDb\xB2 Issue any more(Y/N):");
            fflush(stdin);
            another=getche();
            fclose(fp);
        }
        issuebooks();
        break;
    }
    case '2':  //show issued book list
    {
        system("cls");
        int j=4;
        printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Issued book list \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("====================================================================================\n");
        printf("STUDENT NAME    CATEGORY    ID        BOOK NAME       ISSUED DATE     RETURN DATE \n");
        printf("====================================================================================\n");
        fs=fopen("Issue.dat","rb");
        while(fread(&a,sizeof(a),1,fs)==1)
        {

            printf("%s\t\t",a.stname);
            printf("%s\t",a.cat);
            printf("%d\t",a.id);
            printf("%s\t",a.name);
            printf("%d-%d-%d\t",a.issued.dd,a.issued.mm,a.issued.yy );
            printf("%d-%d-%d\n",a.duedate.dd,a.duedate.mm,a.duedate.yy);
//struct dosdate_t d;
//_dos_getdate(&d);
//            printf("Current date=%d-%d-%d",d.day,d.month,d.year);
            j++;

        }
        printf("====================================================================================\n");
        fclose(fs);
        getch();
        issuebooks();
    }
    break;
    case '3':   //search issued books by id
    {

        int p,c=0;
        char another='y';
        while(another=='y')
        {
            system("cls");
            c=0;
            printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 - Search Issued Books - \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            printf("\n\xDB\xDB\xDB\xDb\xB2 Enter the Book Id:");
            scanf("%d",&p);
            fs=fopen("Issue.dat","rb");
            while(fread(&a,sizeof(a),1,fs)==1)
            {
                if(a.id==p)
                {
                    issuerecord();
                    printf("\nPress any key to see next record .......");
                    getch();
                    //issuerecord();
                    c=1;
                }

            }
            fflush(stdin);
            fclose(fs);
            if(c==0)
            {
                printf("\n\xDB\xDB\xDB\xDb\xB2 No Record Found");
            }
            printf("\n\xDB\xDB\xDB\xDb\xB2 Try Another Search?(Y/N)");
            another=getch();
        }
        issuebooks();
    }
    break;
    case '4':  //remove issued books from list
    {
        int b;
        FILE *fg;  //declaration of temporary file for delete
        char another='y';
        while(another=='y')
        {
            system("cls");
            printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 - Remove Issued Books - \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            findbook = 'n';
            char delName[20] = "";
            printf("\n\xDB\xDB\xDB\xDb\xB2 Enter book id to remove:");
            scanf("%d",&b);
            fs=fopen("Issue.dat","rb+");
            while(fread(&a,sizeof(a),1,fs)==1)
            {
                if(a.id==b)
                {
                    issuerecord();
                    printf("\n\xDB\xDB\xDB\xDb\xB2 Do You Want to Remove it?(Y/N)");
                    findbook='t';
                    if(getch()=='y')
                    {
                        strcpy(delName,a.stname);
                        break;
                    }
                }
            }
            if(findbook!='t')
            {
                printf("\n\xDB\xDB\xDB\xDb\xB2  No Record Found");
            }
            else if (strcmp(delName,"")!=0)
            {

                fg=fopen("record.dat","wb+");
                rewind(fs);
                while(fread(&a,sizeof(a),1,fs)==1)
                {
                    if(!((a.id==b)&&(strcmp(a.stname,delName)==0)))
                    {
                        fseek(fs,0,SEEK_CUR);
                        fwrite(&a,sizeof(a),1,fg);
                    }
                }
                fclose(fs);
                fclose(fg);
                remove("Issue.dat");
                rename("record.dat","Issue.dat");
                printf("\n\xDB\xDB\xDB\xDb\xB2  The issued book is removed from list");
            }
            fclose(fs);
            printf("\n\xDB\xDB\xDB\xDb\xB2  Delete any more?(Y/N)");
            another=getch();
        }
        issuebooks();
        break;
    }
    case '5':  //remove issued books from list
    {
        mainmenu();
        break;
    }
    default:
        printf("\n\aWrong Entry!!");
        getch();
        mainmenu();
        break;
    }
    returnfunc();
}
void viewbooks(void)  //show the list of book persists in library
{
    int i=0,j;
    system("cls");
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Book List \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("=====================================================================================\n");
    printf(" CATEGORY     ID          BOOK NAME     AUTHOR       QTY         PRICE       RackNo \n");
    printf("=====================================================================================\n");
    j=4;
    fp=fopen("Bibek.dat","rb");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        printf("%s\t",a.cat);
        printf("%d\t",a.id);
        printf("%s\t",a.name);
        printf("%s\t\t",a.Author);
        printf("%d\t",a.quantity);
        printf("%.2f\t",a.Price);
        printf("%d",a.rackno);
        printf("\n");
        j++;
        i=i+a.quantity;
    }
    printf("====================================================================================\n");
    printf("\n\xDB\xDB\xDB\xDb\xB2 Total Books =%d",i);
    fclose(fp);
    returnfunc();
}
void editbooks(void)  //edit information about book
{
    system("cls");
    int c=0;
    int d,e;
    char another='y';
    while(another=='y')
    {
        system("cls");
        printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 - Edit Books Section - \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        printf("\n\xDB\xDB\xDB\xDb\xB2 Enter Book Id to be edited:");
        scanf("%d",&d);
        fp=fopen("Bibek.dat","rb+");
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(checkid(d)==0)
            {
                printf("\n\xDB\xDB\xDB\xDb\xB2 The book is availble");
                printf("\n\xDB\xDB\xDB\xDb\xB2 The Book ID:%d",a.id);
                printf("\n\xDB\xDB\xDB\xDb\xB2 Enter new name:");
                scanf("%s",a.name);
                printf("\xDB\xDB\xDB\xDb\xB2 Enter new Author:");
                scanf("%s",a.Author);
                printf("\xDB\xDB\xDB\xDb\xB2 Enter new quantity:");
                scanf("%d",&a.quantity);
                printf("\xDB\xDB\xDB\xDb\xB2 Enter new price:");
                scanf("%f",&a.Price);
                printf("\xDB\xDB\xDB\xDb\xB2 Enter new rackno:");
                scanf("%d",&a.rackno);
                printf("\xDB\xDB\xDB\xDb\xB2 The record is modified");
                fseek(fp,ftell(fp)-sizeof(a),0);
                fwrite(&a,sizeof(a),1,fp);
                fclose(fp);
                c=1;
            }
            if(c==0)
            {
                printf("\n\xDB\xDB\xDB\xDb\xB2 No record found");
            }
        }
        printf("\n\xDB\xDB\xDB\xDb\xB2 Modify another Record?(Y/N)");
        fflush(stdin);
        another=getch() ;
    }
    returnfunc();
}
void returnfunc(void)
{
    {
        printf("\n Press ENTER to return to main menu");
    }
a:
    if(getch()==13) //allow only use of enter
        mainmenu();
    else
        goto a;
}
int getdata()
{
    int t;
    system("cls");
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 - Add Book - \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\xDB\xDB\xDB\xDb\xB2 Enter the Information Below");
    printf("\n\xDB\xDB\xDB\xDb\xB2 Category:");
    printf("%s",catagories[s-1]);
    printf("\n\xDB\xDB\xDB\xDb\xB2 Book ID:\t");
    scanf("%d",&t);
    if(checkid(t) == 0)
    {
        printf("\n\xDB\xDB\xDB\xDb\xB2 \aThe book id already exists\a");
        getch();
        mainmenu();
        return 0;
    }
    a.id=t;
    printf("\xDB\xDB\xDB\xDb\xB2 Book Name:");
    scanf("%s",a.name);
    printf("\xDB\xDB\xDB\xDb\xB2 Author:");
    scanf("%s",a.Author);
    printf("\xDB\xDB\xDB\xDb\xB2 Quantity:");
    scanf("%d",&a.quantity);
    printf("\xDB\xDB\xDB\xDb\xB2 Price:");
    scanf("%f",&a.Price);
    printf("\xDB\xDB\xDB\xDb\xB2 Rack No:");
    scanf("%d",&a.rackno);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    return 1;
}
int checkid(int t)  //check whether the book is exist in library or not
{
    rewind(fp);
    while(fread(&a,sizeof(a),1,fp)==1)
        if(a.id==t)
            return 0;  //returns 0 if book exits
    return 1; //return 1 if it not
}
int t(void) //for time
{
    time_t t;
    time(&t);
    printf("\nDate and time:%s\n",ctime(&t));

    return 0 ;
}

void Password(void) //for password option
{

    system("cls");
    char ch,pass[20],password[20]="bvrit";
    int i=0;

    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 - Password Protected - \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    //printf("*************************** Password Protected **************************\n");

    printf("\n\n\xDB\xDB\xDB\xDb\xB2 Enter Password as 'bvrit':");

    while(ch!=13)
    {
        ch=getch();
        if(ch!=13 && ch!=8)
        {
            putch('*');
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';
    if(strcmp(pass,password)==0)
    {
        printf("\n\n Password matched, wait....");
        //printf("\nPress any key to countinue.....");
        //getch();
        Sleep(800);
        mainmenu();
    }
    else
    {
        printf("\n\n\xDB\xDB\xDB\xDb\xB2  \aWarning!! Incorrect Password");
        getch();
        Password();
    }
}
void issuerecord()  //display issued book's information
{
    system("cls");
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\xDB\xDB\xDB\xDb\xB2 The Book has taken by %s",a.stname);
    printf("\n\xDB\xDB\xDB\xDb\xB2 Issued Date:%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);
    printf("\n\xDB\xDB\xDB\xDb\xB2 Returning Date:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
    printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
}
