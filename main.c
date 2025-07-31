#include <stdio.h>
#include "booking.h"

// Ticket t[150];

int main()
{
    initializeHalls();
    int choice;
    do
    {
        printf("\n------------------------------------------------------------------\n");
        printf("                      =====USER MENU=====\n");
        printf("------------------------------------------------------------------\n");
        printf("1.List The Movies\n");
        printf("2.Book Movie Ticket\n");
        printf("3.View My Tickets\n");
        printf("4.Avaialable Seats In Halls\n");
        printf("5.Cancel Ticket\n");
        printf("6.Exit\n");

        while (1)
        {
            printf("Enter your choice: ");

            if (scanf("%d", &choice) != 1)
            {
                while (getchar() != '\n') // clear the input buffer
                    ;
                printf("-------------------------------------\n");
                printf("   You Have Choosed Invalid Choice!\n");
                printf("-------------------------------------\n");
                continue;
            }
            break;
        }

        switch (choice)
        {
        case 1:
            listMoviesOnly();
            break;
        case 2:
            bookTicket();
            break;
        case 3:
            searchTicket();
            break;
        case 4:
            seatsRemaining();
            break;
        case 5:
            cancelTicket();
            break;
        case 6:
            printf("--------------------------------------------------------------\n");
            printf("     Thank you for using movie Ticket Booking System😊\n");
            printf("--------------------------------------------------------------\n");
            break;
        default:
            printf("Invalid choice\n");
            continue;
        }
    } while (choice != 6);
    return 0;
}
