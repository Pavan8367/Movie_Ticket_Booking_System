#include <stdio.h>
#include <string.h>
#include "booking.h"

Hall halls[MAX_HALLS]; // hall ia an array here

// hall intialization
void initializeHalls()
{
    strcpy(halls[0].name, "INOX");
    strcpy(halls[0].movie, "Mirchi");
    strcpy(halls[0].time, "10:00 AM");
    halls[0].rating = 4.5;

    strcpy(halls[1].name, "PVR");
    strcpy(halls[1].movie, "Bahubali");
    strcpy(halls[1].time, "1:00 PM");
    halls[1].rating = 4.8;

    strcpy(halls[2].name, "SV Cinemas");
    strcpy(halls[2].movie, "Chatrapathi");
    strcpy(halls[2].time, "4:00 PM");
    halls[2].rating = 4.2;

    strcpy(halls[3].name, "Gangadhar Talkies");
    strcpy(halls[3].movie, "Salaar");
    strcpy(halls[3].time, "7:00 PM");
    halls[3].rating = 4.7;

    strcpy(halls[4].name, "Shiva Theatre");
    strcpy(halls[4].movie, "Saaho");
    strcpy(halls[4].time, "9:30 PM");
    halls[4].rating = 4.3;

    for (int i = 0; i < MAX_HALLS; i++)
    {
        for (int j = 0; j < MAX_SEATS; j++)
        {
            halls[i].seats[j] = 0;
        }
    }
}

void displayHalls()
{
    printf("\n======================== Movies Running Today ========================\n");
    printf("| %-2s | %-20s | %-15s | %-8s | %-6s |\n", "No", "Theatre", "Movie", "Time", "Rating");
    printf("-------------------------------------------------------------------------\n");

    for (int i = 0; i < MAX_HALLS; i++)
    {
        printf("| %-2d | %-20s | %-15s | %-8s | %-6.1f |\n",
               i + 1,
               halls[i].name,
               halls[i].movie,
               halls[i].time,
               halls[i].rating);
    }

    printf("=========================================================================\n");
}

void displaySeats(int hallIndex)
{
    printf("\n\n");
    printf("                .-------------------------------------.\n");
    printf("                |                                     |\n");
    printf("                |                                     |\n");
    printf("                |                SCREEN               |\n");
    printf("                |                                     |\n");
    printf("                |                                     |\n");
    printf("                '-------------------------------------'\n");
    printf("\n---------------------------------------------------------------------\n\n");

    printf("Ticket Price per seat is Rs.150.\n");
    printf("Green color seats are Available to book\n\n");
    for (int i = 0; i < MAX_SEATS; i++)
    {
        if (halls[hallIndex].seats[i] == 0)
            printf(" %2d[🟩]", i + 1);
        else
            printf("%2d[🟥] ", i + 1);

        if ((i + 1) % 10 == 0)
            printf("\n\n\n");
    }
}

void listMoviesOnly()
{
    printf("\n======================== Movies Running Today ========================\n");
    printf("| %-2s | %-20s | %-15s | %-8s | %-6s |\n", "No", "Theatre", "Movie", "Time", "Rating");
    printf("-------------------------------------------------------------------------\n");

    for (int i = 0; i < MAX_HALLS; i++)
    {
        printf("| %-2d | %-20s | %-15s | %-8s | %-6.1f |\n",
               i + 1,
               halls[i].name,
               halls[i].movie,
               halls[i].time,
               halls[i].rating);
    }

    printf("=========================================================================\n");
}
