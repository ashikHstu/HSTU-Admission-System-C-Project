#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

int cse[75];
int eee[75];
int ece[75];
int total_cse,total_eee,total_ece;
int total_ad_cse,total_ad_eee,total_ad_ece;

struct registered
{
    char name[30];
    char mobile[15];
    char email[30];
    char pass[15];
};

struct registered othority[100];
int total_othority,current_othority=0;


void defult_othority();
void total_ad_feth();
void view_profile();
void signup();
void starting_interface();
void signin_up();
void login();
void store_chanced();
int chanced(int r);
void main_menu();
void check_result();
void admit_student();
void is_completed();
int ad_chek(int roll);
void show_cse_info(int r);
void show_eee_info(int r);
void show_ece_info(int r);
void log_out();
void exit_massage();


struct admited_student
{
    int admision_roll;
    int student_id;
    char dept[10];
    char name[20];
    char fathers_name[20];
    char mothers_name[20];
    char d_of_b[10];
    char admited_by[30];
};
struct admited_student cse_ad[75];
struct admited_student eee_ad[75];
struct admited_student ece_ad[75];

int main()
{
    store_chanced();
    defult_othority();
    total_ad_feth();
    starting_interface();
    //store_chanced();
    signin_up();

}


///_____________________________________________________________
/** this is for starting interface */

void starting_interface()
{
    printf("______________________________________________________________________\n\n");
    char st1[]="WELCOME TO THE HSTU ADMISSION SYSTEM PROGRAM.\n";
    int l=strlen(st1);
    for(int i=0; i<l; i++)
    {
        printf("%c",st1[i]);
        Sleep(30);
    }
    printf("______________________________________________________________________\n\n");
    Sleep(300);

    printf("The current admission system of HSTU is time consuming.\n\nIt's really a boaring process which is faced by \nEvery student of HSTU during their addmission.\n\nThis program will take info from student and will store them to a file. \n");
    //printf("This program will simply take info of student and store them.\n");
    printf("Press any key to continue.\n");
    char ch=getch();
    system("cls");

}


///__________________________________________________________________
/**this is for sign in or register option*/
void signin_up()
{
    int command_number;
retype:
    printf("\nPlease enter\n\t1 for log in\n\t2 for register\n\t3 for exit code.\n\t");
    scanf("%d",&command_number);
    if(command_number==1)
    {
        login();
    }
    else if(command_number==2)
    {
        signup();
    }
    else if(command_number==3)
    {
        exit_massage();
        return;
    }
    else
    {
        system("CLS");
        printf("Oops, please Enter a valid number\n\n");
        goto retype;
    }

}

///___________________________________________________________
/**   This is the signup function */
void login()
{
    char name[30];
    system("cls");
    printf("\n\nEnter username : ");
    scanf("%*c");
    scanf("%[^\n]",name);
    scanf("%*c");
    ///printf("Entered name is : %s\n",name);
    for(int i=0; i<total_othority; i++)
    {
        if(strcmp(othority[i].name,name)==0)
        {
            system("cls");
            char pass[30];
            printf("\n\nEnter Password : ");
            scanf("%[^\n]",pass);
            scanf("%*c");
           /// printf("entered pass is : %s\n",pass);
            if(strcmp(othority[i].pass,pass)==0)
            {
                current_othority=i;
                ///printf("current othority : %d\n",i);
                system("cls");
                printf("Congreats %s , you have successfully logged in. \n",othority[i].name);
                printf("Press any key to go to the main menu. \n");
                char ch=getch();
                ///system("cls");
                main_menu();
                return;
            }
            else
            {
                system("cls");
                printf("Opps, you have entered a wrong key. \n");
                signin_up();
                return;

            }
        }
    }
    system("cls");
    printf("Opps, Username not found.\n");
    signin_up();
    // scanf("%[^\n]",)
}

///____________________________________________________________
/**to feth total admition report           */
void total_ad_feth()
{
    FILE *fp;
    fp=fopen("admit_info.txt","r");
    fscanf(fp,"%d %d %d",&total_ad_cse,&total_ad_eee,&total_ad_ece);
    fclose(fp);
}

///____________________________________________________________
/**    This function is used to create a user id    */
void signup()
{
    system("cls");
    scanf("%*c");
    printf("Enter username  : ");
    scanf("%[^\n]",othority[total_othority].name);
    scanf("%*c");
    printf("Enter mobile no : ");
    scanf("%[^\n]",othority[total_othority].mobile);
    scanf("%*c");
    printf("Enter Email     : ");
    scanf("%[^\n]",othority[total_othority].email);
    scanf("%*c");
    printf("Enter password  : ");
    scanf("%[^\n]",othority[total_othority].pass);
    scanf("%*c");
    system("cls");
    printf("Congratulation %s , you have successfully registered. \n",othority[total_othority].name);
    current_othority=total_othority;
    total_othority++;
    printf("Press any key to go to main menu.\n");
    char ch;
    ch=getch();
    main_menu();
}
void log_out()
{
    current_othority=-1;
    system("CLS");
    signin_up();
}

///__________________________________________________________________
/** to make a defult othority         */
void defult_othority()
{
    strcpy(othority[0].name,"CSE");
    strcpy(othority[0].mobile,"+8800000000000");
    strcpy(othority[0].email,"hstucse@gmail.com");
    strcpy(othority[0].pass,"2019");

    total_othority=1;
    current_othority=0;
}


///_____________________________________________________________________________
/**    MAIN MENU ****************************************/
void main_menu()
{
    system("cls");
    int v;
    printf("Please enter the key you required : \n");
again:
    printf("\n1 to cheek result.\n");
    printf("2 to admit a student.\n");
    printf("3 to cheek if admission is completed.\n");
    printf("4 to view my profile.\n");
    printf("5 to log out.\n");
    printf("6 to exit code.\n");
    scanf("%d",&v);
    if(v==1)
    {
        ///cheek result
        check_result();    ///completed

    }
    else if(v==2)
    {
        ///admit student    ///completed
        admit_student();
    }
    else if(v==3)
    {
        ///cheek if addmission is completed
        is_completed();          ///completed
    }
    else if(v==4)
    {
        ///view profile
        view_profile();     ///completed
    }
    else if(v==5)
    {
        ///log out
        log_out();
    }
    else if(v==6)
    {
        exit_massage();
        return;
    }
    else
    {
        system("cls");
        printf("Please enter a valid key.\n\n");
        goto again;
    }
}
///___________________________________________________________
/**this is for check result */
void check_result()
{
    system("cls");
    printf("Enter the roll number you want to check : ");
    int roll;
    scanf("%d",&roll);
    int check=chanced(roll);
    if(check==1)
    {
        printf("Congreatulations! roll %d is selected for CSE. \n",roll);
    }
    else if(check==2)
    {
        printf("Congreatulations! roll %d is selected for EEE. \n",roll);
    }
    else if(check==3)
    {
        printf("Congreatulations! roll %d is selected for ECE. \n",roll);
    }
    else
    {
        printf("Sorry :( , this roll is not selected.\n");
    }
    int key;
cr :
    printf("\n\npress a valid key : \n");
    printf("\t 1 for main menu.\n");
    printf("\t 2 for check another result.\n");
    scanf("%d",&key);
    if(key==1)
        main_menu();
    else if(key==2)
        check_result();
    else
    {
        system("cls");
        goto cr;
    }

}
///__________________________________________________________________
/** This is for admit a new student */
void admit_student()
{
     FILE *fp;
    system("cls");
    printf("Please enter the roll no : \n");
    int roll;
    scanf("%d",&roll);
    int chk=chanced(roll);
    int chk2=ad_chek(roll);
    if(chk2==1)
    {
        printf("This admission is already completed(Dept CSE).\n");
    }
    else if(chk2==2)
    {
        printf("This admission is already completed(Dept EEE).\n");
    }
    else if(chk2==3)
    {
        printf("This admission is already completed(Dept ECE).\n");
    }
    else if(chk==1)
    {
        printf("Roll no %d is selected for CSE.\n",roll);

        /**struct admited_student
        {
        int admision_roll;
        int student_id;
        char dept[10];
        char name[20];
        char fathers_name[20];
        char mothers_name[20];
        char d_of_b[10];
        char admited_by[30];
        };
        struct admited_student cse_ad[75];
        struct admited_student eee_ad[75];
        struct admited_student ece_ad[75];
        */
        ///Admission started for cse


        printf("Please enter the required information for admissition. \n");

        cse_ad[total_ad_cse].admision_roll=roll;
        cse_ad[total_ad_cse].student_id=(1902000+total_ad_cse+1);
        strcpy(cse_ad[total_ad_cse].admited_by,othority[current_othority].name);
       /// printf("othority , current othority name : %s\n",othority[current_othority].name);

        printf("Name           : ");
        scanf("%s",&cse_ad[total_ad_cse].name);
        printf("Fathers name   : ");
        scanf("%s",&cse_ad[total_ad_cse].fathers_name);
        printf("Mothers name   : ");
        scanf("%s",&cse_ad[total_ad_cse].mothers_name);
        printf("Date of Birth  : ");
        scanf("%s",&cse_ad[total_ad_cse].d_of_b);

        printf("Admission roll : %d\n",cse_ad[total_ad_cse].admision_roll);
        printf("Student ID     : %d\n",cse_ad[total_ad_cse].student_id);
        printf("Admitted by    : %s\n",cse_ad[total_ad_cse].admited_by);


        /// This part is for file print
                fp=fopen("Admitted_cse.txt","a");

        fprintf(fp,"Serial number  : %d\n\n",total_ad_cse+1);
        fprintf(fp,"Name           : %s\n",cse_ad[total_ad_cse].name);
        fprintf(fp,"Father name    : %s\n",cse_ad[total_ad_cse].fathers_name);
        fprintf(fp,"Mother name    : %s\n",cse_ad[total_ad_cse].mothers_name);
        fprintf(fp,"Date of Birth  : %s\n",cse_ad[total_ad_cse].d_of_b);
        fprintf(fp,"Admission roll : %d\n",cse_ad[total_ad_cse].admision_roll);
        fprintf(fp,"Student ID     : %d\n",cse_ad[total_ad_cse].student_id);
        fprintf(fp,"Admitted by    : %s\n\n",cse_ad[total_ad_cse].admited_by);
        fclose(fp);
         total_ad_cse++;
         FILE *fp1;
         fp1=fopen("admit_info.txt","w");
         fprintf(fp1,"%d %d %d\n",total_ad_cse,total_ad_eee,total_ad_ece);
         fclose(fp1);
    }
    else if(chk==2)
    {
        printf("Roll no %d is selected for EEE.\n",roll);

        ///Admission started for EEE

        printf("Please enter the required information for admissition. \n");

        eee_ad[total_ad_eee].admision_roll=roll;
        eee_ad[total_ad_eee].student_id=(1902200+total_ad_eee+1);
        strcpy(eee_ad[total_ad_eee].admited_by,othority[current_othority].name);

        printf("Name           : ");
        scanf("%s",&eee_ad[total_ad_eee].name);
        printf("Fathers name   : ");
        scanf("%s",&eee_ad[total_ad_eee].fathers_name);
        printf("Mothers name   : ");
        scanf("%s",&eee_ad[total_ad_eee].mothers_name);
        printf("Date of Birth  : ");
        scanf("%s",&eee_ad[total_ad_eee].d_of_b);

        printf("Admission roll : %d\n",eee_ad[total_ad_eee].admision_roll);
        printf("Student ID     : %d\n",eee_ad[total_ad_eee].student_id);
        printf("Admitted by    : %s\n",eee_ad[total_ad_eee].admited_by);

        /// This part is for file print
                fp=fopen("Admitted_eee.txt","a");

        fprintf(fp,"Serial number  : %d\n\n",total_ad_eee+1);
        fprintf(fp,"Name           : %s\n",eee_ad[total_ad_eee].name);
        fprintf(fp,"Father name    : %s\n",eee_ad[total_ad_eee].fathers_name);
        fprintf(fp,"Mother name    : %s\n",eee_ad[total_ad_eee].mothers_name);
        fprintf(fp,"Date of Birth  : %s\n",eee_ad[total_ad_eee].d_of_b);
        fprintf(fp,"Admission roll : %d\n",eee_ad[total_ad_eee].admision_roll);
        fprintf(fp,"Student ID     : %d\n",eee_ad[total_ad_eee].student_id);
        fprintf(fp,"Admitted by    : %s\n\n",eee_ad[total_ad_eee].admited_by);
        fclose(fp);
         total_ad_eee++;
         FILE *fp1;
         fp1=fopen("admit_info.txt","w");
         fprintf(fp1,"%d %d %d\n",total_ad_cse,total_ad_eee,total_ad_ece);
         fclose(fp1);

    }
    else if(chk==3)
    {
        printf("Roll no %d is selected for ECE.\n",roll);

        ///Admission started for ece

        printf("Please enter the required information for admissition. \n");

        ece_ad[total_ad_ece].admision_roll=roll;
        ece_ad[total_ad_ece].student_id=(1902100+total_ad_ece+1);
        strcpy(ece_ad[total_ad_ece].admited_by,othority[current_othority].name);

        printf("Name           : ");
        scanf("%s",&ece_ad[total_ad_ece].name);
        printf("Fathers name   : ");
        scanf("%s",&ece_ad[total_ad_ece].fathers_name);
        printf("Mothers name   : ");
        scanf("%s",&ece_ad[total_ad_ece].mothers_name);
        printf("Date of Birth  : ");
        scanf("%s",&ece_ad[total_ad_ece].d_of_b);

        printf("Admission roll : %d\n",ece_ad[total_ad_ece].admision_roll);
        printf("Student ID     : %d\n",ece_ad[total_ad_ece].student_id);
        printf("Admitted by    : %s\n",ece_ad[total_ad_ece].admited_by);

        /// This part is for file print
                fp=fopen("Admitted_ece.txt","a");

        fprintf(fp,"Serial number  : %d\n\n",total_ad_ece+1);
        fprintf(fp,"Name           : %s\n",ece_ad[total_ad_ece].name);
        fprintf(fp,"Father name    : %s\n",ece_ad[total_ad_ece].fathers_name);
        fprintf(fp,"Mother name    : %s\n",ece_ad[total_ad_ece].mothers_name);
        fprintf(fp,"Date of Birth  : %s\n",ece_ad[total_ad_ece].d_of_b);
        fprintf(fp,"Admission roll : %d\n",ece_ad[total_ad_ece].admision_roll);
        fprintf(fp,"Student ID     : %d\n",ece_ad[total_ad_ece].student_id);
        fprintf(fp,"Admitted by    : %s\n\n",ece_ad[total_ad_ece].admited_by);
        fclose(fp);
         total_ad_ece++;
         FILE *fp1;
         fp1=fopen("admit_info.txt","w");
         fprintf(fp1,"%d %d %d\n",total_ad_cse,total_ad_eee,total_ad_ece);
         fclose(fp1);
    }
    else
    {
        printf("This roll is not yet selected for admission.\n");
    }
    int key;
cr :
    printf("\n\npress a valid key : \n");
    printf("\t 1 for main menu.\n");
    printf("\t 2 for admit another student.\n");
    scanf("%d",&key);
    if(key==1)
        main_menu();
    else if(key==2)
        admit_student();
    else
    {
        system("cls");
        goto cr;
    }

}
///__________________________________________________________
/*** Check and print if admittion  is completed.*/
void is_completed()
{
    system("cls");
    printf("Enter the roll no : \n");
    int roll;
    scanf("%d",&roll);
    int chek=ad_chek(roll);

    int chek2=chanced(roll);
    if(chek==1)
    {
        printf("Admission is completed for roll %d (department CSE)\n",roll);
        show_cse_info(roll);
    }
    else if(chek==2)
    {
        printf("Admission is completed for roll %d (department EEE)\n",roll);
        show_eee_info(roll);
    }
    else if(chek==3)
    {
        printf("Admission is completed for roll %d (department ECE)\n",roll);
        show_ece_info(roll);
    }
    else if(chek2==1)
    {
        printf("Admissition not yet completed. Selected for CSE.\n");
    }
    else if(chek2==2)
    {
        printf("Admissition not yet completed. Selected for EEE.\n");
    }
    else if(chek2==3)
    {
        printf("Admissition not yet completed. Selected for ECE.\n");
    }
    else if(chek==-1)
    {
        printf("This roll is not yet selected for admissition.\n");
    }

    int key;
cr :
    printf("\n\npress a valid key : \n");
    printf("\t 1 for main menu.\n");
    printf("\t 2 for check another roll, if admissition is completed.\n");
    scanf("%d",&key);
    if(key==1)
        main_menu();
    else if(key==2)
        is_completed();
    else
    {
        system("cls");
        goto cr;
    }


}
///__________________________________________________
/** This is for admission chek */
int ad_chek(int roll)
{
    for(int i=0; i<total_ad_cse; i++)
    {
        if(roll==cse_ad[i].admision_roll)
        {
            return 1;
        }
    }
    for(int i=0; i<total_ad_eee; i++)
    {
        if(roll==eee_ad[i].admision_roll)
        {
            return 2;
        }
    }
    for(int i=0; i<total_ad_ece; i++)
    {
        if(roll==ece_ad[i].admision_roll)
        {
            return 3;
        }
    }
    return -1;

}

///_____________________________________________________________________
/** Show cse students info who is already admitted                */
void show_cse_info(int r)
{
    /**struct admited_student
       {
       int admision_roll;
       int student_id;
       char dept[10];
       char name[20];
       char fathers_name[20];
       char mothers_name[20];
       char d_of_b[10];
       char admited_by[30];
       };
       struct admited_student cse_ad[75];
       struct admited_student eee_ad[75];
       struct admited_student ece_ad[75];
       */
    for(int i=0; i<total_ad_cse; i++)
    {
        if(r==cse_ad[i].admision_roll)
        {
            printf("Name          : %s\n",cse_ad[i].name);
            printf("Student id    : %d\n",cse_ad[i].student_id);
            printf("Date of birth : %s\n",cse_ad[i].d_of_b);
            printf("Father name   : %s\n",cse_ad[i].fathers_name);
            printf("Mother name   : %s\n",cse_ad[i].mothers_name);
            printf("Dept          : CSE\n");
            printf("Admitted by   : %s\n",cse_ad[i].admited_by);
            return;
        }
    }
}

///_____________________________________________________________________
/** Show eee students info who is already admitted                */
void show_eee_info(int r)
{

    for(int i=0; i<total_ad_eee; i++)
    {
        if(r==eee_ad[i].admision_roll)
        {
            printf("Name          : %s\n",eee_ad[i].name);
            printf("Student id    : %d\n",eee_ad[i].student_id);
            printf("Date of birth : %s\n",eee_ad[i].d_of_b);
            printf("Father name   : %s\n",eee_ad[i].fathers_name);
            printf("Mother name   : %s\n",eee_ad[i].mothers_name);
            printf("Dept          : EEE\n");
            printf("Admitted by   : %s\n",eee_ad[i].admited_by);
            return;
        }
    }
}

///_____________________________________________________________________
/** Show ece students info who is already admitted                */
void show_ece_info(int r)
{

    for(int i=0; i<total_ad_ece; i++)
    {
        if(r==ece_ad[i].admision_roll)
        {
            printf("Name          : %s\n",ece_ad[i].name);
            printf("Student id    : %d\n",ece_ad[i].student_id);
            printf("Date of birth : %s\n",ece_ad[i].d_of_b);
            printf("Father name   : %s\n",ece_ad[i].fathers_name);
            printf("Mother name   : %s\n",ece_ad[i].mothers_name);
            printf("Dept          : ECE\n");
            printf("Admitted by   : %s\n",ece_ad[i].admited_by);
            return;
        }
    }
}

///______________________________________________________________________
/**this is for view profile */
void view_profile()
{
    system("cls");

    printf("\tUsername  : %s\n",othority[current_othority].name);
    printf("\tMobile no : %s\n",othority[current_othority].mobile);
    printf("\tEmail     : %s\n",othority[current_othority].email);

    printf("\n press any key to go to main menu.\n");
    //scanf("%*c%*c");
    char ch=getch();
    main_menu();

}

///____________________________________________________________
/**         Just to store the chanced roll no.      */
void store_chanced()
{
    FILE *fp;
    int i;
    /// CSE input
    fp=fopen("chanced_cse.txt","r");
    total_cse=0;
    while(fscanf(fp,"%d",&cse[total_cse])!=EOF)
    {
        total_cse++;
    }
    fclose(fp);

    ///EEE input
    fp=fopen("chanced_eee.txt","r");
    total_eee=0;
    while(fscanf(fp,"%d",&eee[total_eee])!=EOF)
    {
        total_eee++;
    }
    fclose(fp);

    ///ECE input
    fp=fopen("chanced_ece.txt","r");
    total_ece=0;
    while(fscanf(fp,"%d",&ece[total_ece])!=EOF)
    {
        total_ece++;
    }
    fclose(fp);

}


///_________________________________________________
/**To show the student who got chanced */

int chanced(int r)
{
    for(int i=0; i<total_cse; i++)
    {
        if(cse[i]==r)
        {
            return 1;
        }
    }
    for(int i=0; i<total_eee; i++)
    {
        if(eee[i]==r)
        {
            return 2;
        }
    }
    for(int i=0; i<total_ece; i++)
    {
        if(ece[i]==r)
        {
            return 3;
        }
    }
    return 0;

}

///_______________________________________________________________________________
/**             EXIT MASSAGE               */

void exit_massage()
{
    system("cls");
    printf("\n\n\n\n\n\n\tYou have successfully exited from this program.\n\n");
    printf("\t  Thanks for used this HSTU admission program. \n\n\n\n\n");
    return;
}
