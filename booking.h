#ifndef BOOKING_H
#define BOOKING_H

// Maximum number of seats in each hall
#define MAX_SEATS 30

// Maximum number of halls in the system
#define MAX_HALLS 5

// Maximum length for user name
#define MAX_NAME 100

// Language options used in ticket booking
extern char *languages[4];

// Structure to hold information about each hall
typedef struct
{
    char name[50];        // Hall name
    char movie[50];       // Movie playing in the hall
    char time[20];        // Show time
    float rating;         // Movie rating
    int seats[MAX_SEATS]; // Seat availability: 0 = available, 1 = booked
} Hall;

// Structure to hold ticket and user information after booking
typedef struct
{
    char name[MAX_NAME]; // Customer name
    char phone[15];      // Customer phone number
    char movie[50];      // Booked movie name
    char hall[50];       // Booked hall name
    char time[20];       // Show time
    int seats[4];        // Booked seat numbers (max 4)
    int seatCount;       // Number of seats booked
    float amount;        // Total amount paid
    char language[20];   // Selected language
} Ticket;

// Array to store details of all halls
extern Hall halls[MAX_HALLS];

// ===== Function Declarations =====

// Initializes hall names, movies, timings, ratings, and seat availability
void initializeHalls();

// Displays a list of halls with movie, time, and rating
void displayHalls();

// Displays available and booked seats for a specific hall
void displaySeats(int hallindex);

// Displays only movie names available in all halls
void listMoviesOnly();

// Main function to handle ticket booking process
int bookTicket();

// Searches and displays ticket details by phone number
void searchTicket();

// Cancels a specific seat by hall and seat number, and updates booking
void cancelTicket();

// Displays snack menu and returns the selected total cost
float snacksMenu();

// Displays the number of available seats in each hall
void seatsRemaining();

// Optional: can be used to load ticket data from file (commented)
// int loadTicket()

#endif
