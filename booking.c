#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "booking.h"

extern Hall halls[MAX_HALLS];

char *languages[] = {"English", "Telugu", "Kannada", "Tamil"};

int bookTicket()
{
    char ch;
    int lang;
    // Display list of available halls
    displayHalls();

    printf("If you want to go main menu Select [y] else select [n]: ");
    scanf(" %c", &ch);

    // Prompt user to select language
    if (ch != 'y')
    {
        printf("\nSelect language for this movie:\n");
        for (int i = 0; i < 4; i++)
            printf("%d. %s\n", i + 1, languages[i]);

        // Validate language input
        while (1)
        {
            printf("\nEnter your choice on language: ");
            scanf("%d", &lang);

            if (lang < 1 || lang > 4)
            {
                printf("❌ Invalid language.Please Select from above!\n");
                continue;
            }
            break;
        }
    }
    else
        return 1;

    // printf("If you want to return to main menu Select [N] else select [Y]: ");
    // scanf(" %c", &ch);
    // if (ch != 'N')

    int choice;
    // Validate hall selection input
    while (1)
    {
        printf("\nSelect Hall to book (1-%d): ", MAX_HALLS);
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ; // Clear input buffer
            printf("❌ Invalid input!\n");
            continue;
        }
        if (choice < 1 || choice > MAX_HALLS)
        {
            printf("❌ Invalid Hall!\n");
            continue;
        }
        break;
    }

    // Get hall index (0-based)
    int hallindex = choice - 1;
    displaySeats(hallindex); // Show current seat status

    int seats[4], count = 0;
    char input[30];
    getchar(); // Clear newline from buffer

    // Seat booking: allow booking up to 4 valid seats

    while (1)
    {
        printf("\nEnter seat numbers to book [Max 4 seats]: ");
        fgets(input, sizeof(input), stdin); // Read seat numbers
        char *token = strtok(input, " ");
        while (token && count < 4)
        {
            int s = atoi(token); // Convert token to integer seat number

            if (s < 1 || s > MAX_SEATS)
            {
                printf("⚠️ Seat %d is invalid.\n", s);
            }
            else if (halls[hallindex].seats[s - 1])
            {
                printf("❌ Invalid! This is is already Booked,please choose another seat");
            }
            else
            {
                seats[count++] = s;
            }
            token = strtok(NULL, " ");
        }
        if (count == 0)
        {
            printf("❌ No valid seats selected. Please try again.\n");
            continue;
        }
        else
        {
            break;
        }
    }

    Ticket t;
    printf("Enter your name: ");
    fgets(t.name, MAX_NAME, stdin);
    t.name[strcspn(t.name, "\n")] = 0; // Remove newline

    // Validate phone number
    int valid = 0;
    while (!valid)
    {
        printf("Enter phone number (10 digits only): ");
        scanf("%s", t.phone);

        if (t.phone[0] == '0')
        {
            printf("❌ Phone number shouldn't start with 0.\n");
            continue;
        }
        if (strlen(t.phone) != 10)
        {
            printf("❌ Phone number must be exactly 10 digits.\n");
            continue;
        }
        valid = 1;
        for (int i = 0; i < 10; i++)
        {
            if (t.phone[i] < '0' || t.phone[i] > '9')
            {
                printf("❌ Phone number must contain digits only.\n");
                valid = 0;
                break;
            }
        }
    }

    // Call snack menu and calculate total cost
    int total = snacksMenu();
    float amount;
    float final = total + 150.0 * count; // 150 per ticket
    printf("Your Total Amount Is : %.2f\n", final);
    printf("Pay The Amount Here To Book The Ticket [Rs->%.2f] : ", final);
    scanf("%f", &amount);

    // Simulate payment processing
    int i = 1;
    printf("\nProcessing the payment");
    while (i <= 4)
    {
        if (i < 5)
        {
            printf(".");
            fflush(stdout); // To immediately print "."
            sleep(1);       // Delay for visual effect
        }
        i++;
    }

    // Check if payment is exact
    if (amount != final)
    {
        printf("⚠️ Payment failed.\n");
        return -1;
    }
    else
        printf("\nPayment Done ✅\n\n");

    // Copy booking details into ticket
    strcpy(t.movie, halls[hallindex].movie);
    strcpy(t.hall, halls[hallindex].name);
    strcpy(t.time, halls[hallindex].time);
    strcpy(t.language, languages[lang - 1]);
    t.amount = final;
    t.seatCount = count;

    // Update hall seat status and assign to ticket
    for (int i = 0; i < count; i++)
    {
        t.seats[i] = seats[i];
        halls[hallindex].seats[seats[i] - 1] = 1;
    }

    // Save ticket to CSV file
    FILE *csv = fopen("bookings.csv", "a");
    if (csv)
    {
        fseek(csv, 0, SEEK_END);
        if (ftell(csv) == 0)
            fprintf(csv, "Name,Phone,Movie,Theatre,Time,Language,Seats,Amount\n");

        char seatStr[50] = "";
        for (int i = 0; i < count; i++)
        {
            char buffer[6];
            sprintf(buffer, "%d", seats[i]);
            strcat(seatStr, buffer);
            if (i < count - 1)
                strcat(seatStr, " ");
        }

        fprintf(csv, "%s,%s,%s,%s,%s,%s,%s,%.2f\n",
                t.name, t.phone, t.movie, t.hall, t.time, t.language, seatStr, t.amount);
        fclose(csv);

        // Display ticket summary
        printf("\n✅ Booking Confirmed!\n");
        printf("=====================================================\n");
        printf("|                 🎟️ MOVIE TICKET                 |\n");
        printf("-----------------------------------------------------\n");
        printf("Name: %s\nPhone: %s\nMovie: %s\nHall: %s\nTime: %s\nLanguage: %s\nSeats: ",
               t.name, t.phone, t.movie, t.hall, t.time, t.language);
        for (int i = 0; i < count; i++)
            printf("%d ", seats[i]);
        printf("\nAmount: %.2f\n", t.amount);
    }
    return 0;
}

void searchTicket()
{
    // Prompt user to enter phone number for ticket search
    char phone[15];
    printf("Enter your Phone number to view your ticket: ");
    scanf("%s", phone);

    // Open the bookings.csv file in read mode
    FILE *fp = fopen("bookings.csv", "r");
    if (!fp)
    {
        // If file is not found, display error and return
        printf("❌ bookings.csv not found.\n");
        return;
    }

    char line[256];
    int found = 0;
    fgets(line, sizeof(line), fp); // Skip the CSV header line

    // Read each line (ticket record) from the CSV file
    while (fgets(line, sizeof(line), fp))
    {
        // Declare variables to hold parsed ticket information
        char name[50], ph[15], movie[50], hall[50], time[20], language[20], seats[50];
        float amount;

        // Parse the line from CSV using sscanf
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%f",
               name, ph, movie, hall, time, language, seats, &amount);

        // Compare entered phone number with current record's phone number
        if (strcmp(ph, phone) == 0)
        {
            // If matched, set found flag and display ticket info
            found = 1;
            printf("\n================🎟️ Ticket Found ================\n");
            printf("Name: %s\nPhone: %s\nMovie: %s\nTheatre: %s\nTime: %s\nLanguage: %s\nSeats: %s\nAmount: Rs.%.2f\n",
                   name, ph, movie, hall, time, language, seats, amount);
            printf("==============================================\n");
        }
    }

    // If no matching ticket is found
    if (!found)
        printf("\n❌ No ticket found with phone number %s.\n", phone);

    // Close the file
    fclose(fp);
}

void cancelTicket()
{
    int hallNum, seatNum;
    char line[300], temp[300];

    // Show list of halls
    displayHalls();

    // Ask user for hall number
    printf("\nEnter hall number: ");
    scanf("%d", &hallNum);
    if (hallNum < 1 || hallNum > MAX_HALLS)
    {
        printf("❌ Invalid hall number.\n");
        return;
    }

    // Ask user for seat number to cancel
    printf("Enter seat number to cancel: ");
    scanf("%d", &seatNum);
    if (seatNum < 1 || seatNum > MAX_SEATS)
    {
        printf("❌ Invalid seat number.\n");
        return;
    }

    // Open original booking file for reading and a temp file for writing
    FILE *fp = fopen("bookings.csv", "r");
    FILE *tempFp = fopen("temp.csv", "w");

    if (!fp || !tempFp)
    {
        printf("❌ Error opening file.\n");
        return;
    }

    // Read and copy the header line to temp file
    fgets(line, sizeof(line), fp);
    fprintf(tempFp, "%s", line);

    int found = 0; // Flag to track if ticket was found

    // Process each line of the bookings.csv file
    while (fgets(line, sizeof(line), fp))
    {
        char *lineCopy = strdup(line); // Make a copy of current line
        char *tokens[10];              // Store individual CSV fields
        int i = 0;

        // Tokenize line by comma to extract CSV fields
        char *token = strtok(line, ",");
        while (token != NULL && i < 10)
        {
            tokens[i++] = token;
            token = strtok(NULL, ",");
        }

        // If line doesn't have enough fields, skip processing
        if (i < 8)
        {
            fprintf(tempFp, "%s", lineCopy); // Copy it as is
            free(lineCopy);
            continue;
        }

        // Extract seat field and parse seat numbers
        char seatField[100];
        strcpy(seatField, tokens[6]); // 7th column is seats

        int seats[10], seatCount = 0;
        char *seatPtr = strtok(seatField, " ");
        while (seatPtr != NULL)
        {
            seats[seatCount++] = atoi(seatPtr); // Store seat number
            seatPtr = strtok(NULL, " ");
        }

        int newSeats[10], newCount = 0;
        int seatRemoved = 0;

        // Check each seat to find the one being cancelled
        for (int j = 0; j < seatCount; j++)
        {
            if (seats[j] == seatNum)
            {
                seatRemoved = 1;
                halls[hallNum - 1].seats[seatNum - 1] = 0; // Mark seat as available
            }
            else
            {
                newSeats[newCount++] = seats[j]; // Retain other seats
            }
        }

        if (seatRemoved)
        {
            found = 1;
            // Calculate per seat price and refund amount
            float amount = atof(tokens[7]);
            float perSeatPrice = amount / seatCount;
            float newAmount = perSeatPrice * newCount;

            float refund = perSeatPrice * 0.5; // 50% refund
            printf("\n✅ Ticket for seat %d cancelled successfully.\n", seatNum);
            printf("💰 Refund amount: ₹%.2f (50%% of ₹%.2f per seat)\n", refund, perSeatPrice);

            if (newCount == 0)
            {
                // If no seats left after cancellation, skip writing this line
                free(lineCopy);
                continue;
            }

            // Rebuild seat string after removal
            char newSeatStr[50] = "";
            for (int j = 0; j < newCount; j++)
            {
                char tempStr[10];
                sprintf(tempStr, "%d", newSeats[j]);
                strcat(newSeatStr, tempStr);
                if (j != newCount - 1)
                    strcat(newSeatStr, " ");
            }

            // Write updated record with new seat info and new amount
            fprintf(tempFp, "%s,%s,%s,%s,%s,%s,%s,%.2f\n",
                    tokens[0], tokens[1], tokens[2], tokens[3],
                    tokens[4], tokens[5], newSeatStr, newAmount);
        }
        else
        {
            // Seat not found in this line, write original line
            fprintf(tempFp, "%s", lineCopy);
        }

        free(lineCopy); // Free memory allocated by strdup
    }

    // Close both files
    fclose(fp);
    fclose(tempFp);

    // Replace original file with updated file
    remove("bookings.csv");
    rename("temp.csv", "bookings.csv");

    // If no matching seat was found
    if (!found)
    {
        printf("\n❌ No ticket found for seat %d in hall %d.\n", seatNum, hallNum);
    }
}

void seatsRemaining()
{
    // Print header section
    printf("------------------------------------------------------------------\n");
    printf("                         Available Seats \n");
    printf("------------------------------------------------------------------\n");

    // Loop through each hall
    for (int i = 0; i < MAX_HALLS; i++)
    {
        int count = 0;

        // Count available (unbooked) seats in current hall
        for (int j = 0; j < MAX_SEATS; j++)
        {
            if (halls[i].seats[j] == 0) // 0 means available
                count++;
        }

        // Display hall name, movie, and number of available seats
        printf("\n%s | (%s) | Available Seats  :  [ %d ]\n", halls[i].name, halls[i].movie, count);
    }
}
