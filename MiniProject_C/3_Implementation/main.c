#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "movie.h"


extern int flag_a;//flag for admin login
extern int flag_u; //flag for user login
struct movie_details m;

int main()
{
   int choice;
   do{
    printf("\n");
    printf("\n********************************** MAIN MENU ******************************************************\n");
    printf("\n 1 -- Admin Login \n");
    printf("\n 2 -- User Login \n");
    printf("\n 3 -- New User Registration \n");
    printf("\n****************************************************************************************************\n");
    scanf("%d", &choice);
    system("cls");


   switch(choice)
       {
       case 1:
        {
            char admin_username[20];
            char admin_password[20];
            printf("\n************************************* ADMIN LOGIN ******************************************\n");
            printf("\n");
            printf("           Enter username: \t");
            scanf("%19s",admin_username);
            printf("           Enter password: \t");
            scanf("%19s",admin_password);

            admin_login(admin_username,admin_password);

            printf("\n Press Enter to continue \n");
            while((getchar())!='\n'); //clear the input buffer
            getchar();
            system("cls"); // clear screen

            if(flag_a)
            {
             int ch2;
                do{
                printf("\n");
                printf("\n************************************ ADMIN PANEL *************************************\n");
                printf("\n 1 - Add Movies \n");
                printf("\n 2 - View All Bookings \n" );
                printf("\n**************************************************************************************\n");
                scanf("%d", &ch2);
                system("cls");

                    switch(ch2)
                    {
                    case 1:
                        {
                        int code;
                        char name[60];
                        char timing[10];
                        char date[20];
                        int price;
                        int seat;
                         printf("Enter movie code \t");
                         scanf("%d", &code);


                        printf("Enter movie name \t");
                        while((getchar())!='\n');
                        scanf("%60[^\n]",name);


                        printf("Enter show timing \t");
                        while((getchar())!='\n');
                        scanf("%10[^\n]",timing);

                        printf("Enter release date \t");
                        while((getchar())!='\n');
                        scanf("%20[^\n]",date);

                        printf("Enter ticket price \t");
                        scanf("%d",&price);

                        printf("Enter number of seats available \t");
                        scanf("%d", &seat);

                        add_movies(code,name,timing,date,price,seat);

                        printf("\n Press Enter to continue \n");
                        while((getchar())!='\n');
                        getchar();
                        system("cls");

                        break;
                        }
                    case 2:
                        {

                        view_bookings();
                        printf("\n Press Enter to go back to admin panel");
                        while((getchar())!='\n');
                        getchar();
                        system("cls");

                        break;
                        }
                    case 0:
                        exit(0);
                        break;

                    default:
                    printf("Not a valid choice");
                    }

           }while(ch2!=0);
        }
        break;
        }
       case 2:
            {
                char username[20];
                char password[20];
                printf("\n************************************* USER LOGIN ******************************************\n");
                printf("\n");
                printf("           Enter username: \t");
                while((getchar())!='\n');
                scanf("%20[^\n]", username);

                printf("           Enter password: \t");
                while((getchar())!='\n');
                scanf("%20[^\n]", password);

                user_login(username,password);

                printf("\n Press Enter to continue \n");
                while((getchar())!='\n');
                getchar();
                system("cls");

                if(flag_u)
                    {
                    int ch3;
                    do{
                    printf("\n*************************************** USER PANEL ************************************\n");
                    printf("\n 1 - View List Of Movies \n");
                    printf("\n 2 - Book Tickets \n");
                    printf("\n 3 - View Booked Tickets \n");
                    printf("\n 4 - Search For Movies \n");
                    printf("\n***************************************************************************************\n");
                    scanf("%d",&ch3);
                    system("cls");

                        switch(ch3)
                        {
                        case 1:
                            {

                            view_movies();
                            printf("\n Press Enter to go to User Panel \n");
                            while((getchar())!='\n');
                            getchar();
                            system("cls");

                            break;
                            }
                        case 2:
                            {
                            char movie[60];
                            int seat;

                            FILE *fp;
                            fp=fopen("movie_list.txt","r+"); //opening file for reading and writing
                                //printing all the available movie details
                            printf("\n************************************MOVIES****************************************\n");
                            while(fread(&m, sizeof(struct movie_details),1,fp))
                            {
                            printf("\n       Movie Code      : %d",m.movie_code);
                            printf("\n       Movie Name      : %s",m.movie_name);
                            printf("\n       Release Date    : %s",m.release_date);
                            printf("\n       Show Timing     : %s",m.show_timing);
                            printf("\n       Ticket Price    : %d",m.ticket_price);
                            printf("\n       Available Seats : %d \n",m.seat_no);

                            }
                            printf("\n**********************************************************************************\n");

                            fseek(fp, 0, SEEK_SET); //setting the file pointer to start of file
                            fclose(fp);

                            printf("Enter the name of the movie to book tickets \t");
                            while((getchar())!='\n');
                            scanf("%60[^\n]",movie);

                            printf(" \n Enter number of seats to book  \t");
                            scanf("%d", &seat);

                            book_tickets(movie,seat);

                            printf("\nPress Enter to go back to User Panel\n");
                            while((getchar())!='\n');
                            getchar();
                            system("cls");
                            break;
                            }
                        case 3:
                            {
                            view_booked();
                            printf("\nPress Enter to continue\n");
                            while((getchar())!='\n');
                            getchar();
                            system("cls");

                            break;
                            }
                        case 4:
                            {
                                char m_name[60];
                                printf("Enter the name of the movie you want to search:\t");
                                while((getchar())!='\n');
                                scanf("%60[^\n]",m_name);

                                search(m_name);

                                printf("Press Enter to continue");
                                while((getchar())!='\n');
                                getchar();
                                system("cls");
                            break;
                            }
                        case 0:
                            exit(0);
                            break;

                        default:
                        printf("Not a valid choice");
                        }
                    }while(ch3!=0);
                    }
            break;
            }
    case 3:
        {
        char fname[30];
        char uname[20];
        char pass[20];
        char mob_no[20];
        while((getchar())!='\n');
        printf("\nEnter your full name\t");
        scanf("%30[^\n]", fname);

        printf("\nEnter your Username\t");
        while((getchar())!='\n');
        scanf("%20[^\n]", uname);

        printf("\nEnter your password\t");
        while((getchar())!='\n');
        scanf("%20[^\n]", pass);

        printf("\nEnter your mobile number\t");
        while((getchar())!='\n');
        scanf("%20[^\n]", mob_no);

        user_reg(fname,uname,pass,mob_no);

        printf("\n Press Enter to continue \n");
        while((getchar())!='\n');
        getchar();
        system("cls");

        break;
        }

    case 0:
        exit(0);
        break;

       default:
        printf("Enter a valid choice");


       }
}
while(choice!=0);
}

