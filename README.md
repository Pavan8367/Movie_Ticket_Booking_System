# Movie_Ticket_Booking_System
🎟️ Movie Ticket Booking System
This is a console-based Movie Ticket Booking System developed in C as part of my hands-on learning journey at Emertxe Information Technologies. The project simulates a real-time ticket booking system for movie theaters, including features such as seat selection, payment handling, and ticket cancellation.

📌 The Movie Ticket Booking System is a console-based application developed in C programming language that mimics the functionality of a real-world movie theater booking platform. This project was developed as part of my learning journey at Emertxe Information Technologies, allowing me to apply my skills in file handling, modular programming, and structured data management.

🧰 Components & Tools Used

🔣 Programming Language
C Programming
Core logic written using structured and modular C
Focus on memory-safe, beginner-friendly syntax

🧱 Code Structure
Header and Source Files (.h & .c)
booking.h, main.c, booking.c, etc.
Encapsulated data and logic for modularity and reusability

📁 File Handling
CSV (Comma Separated Values) Format
Stores booking data persistently in bookings.csv
Allows ticket search and modification

👨‍💼 User Interface
Command-Line Interface (CLI)
Menu-driven system for booking, cancelling, searching, etc.
Text-based seat layout for selection
Language selection options (English, Telugu, Kannada, Tamil)

📊 Data Structures
Structs
Hall for each movie hall with seating info, movie details
Ticket for storing user and booking info

🧮 Functional Modules
Booking Module: Takes user input and allocates seats
Search Module: Retrieves tickets by phone number
Cancellation Module: Removes selected seats and handles refunds
Snack Billing Module: Adds snack prices to ticket total
Display Module: Shows seat availability, movie list, etc.

💾 Development Environment
Text Editor/IDE: Code written in editors like VS Code or Emertxe's IDE
GCC Compiler: Compilation using standard C compiler (gcc)
Terminal: Linux shell or Command Prompt used for input/output

⚙️ Working Principle of Movie Ticket Booking System

The Movie Ticket Booking System is a menu-driven console-based application that enables users to interactively book, search, cancel, and view movie tickets. It uses C programming and CSV file handling to simulate real-time ticket operations in a movie hall environment.

🧩 1. Initialization of Movie Halls
Predefined movie halls are initialized using the initializeHalls() function.
Each hall has attributes like name, movie, time, rating, and an array of seat availability.

🪑 2. Seat Management
Each hall has a seating layout represented by an integer array.
0 → Seat available
1 → Seat booked
displaySeats() visually shows seat availability for each hall.

🎫 3. Ticket Booking
User selects a hall, number of seats, and seat numbers.
Inputs personal information and language preference.
Total price is calculated based on seat count and optional snack menu.
Booking is recorded in bookings.csv with all ticket details.

🔎 4. Ticket Search
searchTicket() enables users to find their ticket(s) using their phone number.

It reads and filters data from bookings.csv and displays matching entries.

❌ 5. Ticket Cancellation
Users provide hall and seat number to cancel.
The system:
Updates the hall’s seat array (marks seat as available)
Calculates partial refund (50%)
Updates bookings.csv using a temporary file to reflect changes

🍿 6. Snacks Menu (Optional)
snacksMenu() allows users to add snacks during booking.
Cost is added to total ticket amount.

📊 7. Seat Availability Display
seatsRemaining() shows available seats for each hall.
Helps users decide where to book.

💾 8. Persistent Storage
All booking and ticket information is stored in a CSV file (bookings.csv), ensuring data is not lost between runs.

🎯 Features :

📽️ List All Available Movie Halls
Displays movie name, show timings, language, and rating for each hall.

⏰ Show Movie Timings & Language Options
Multiple language choices: English, Telugu, Kannada, Tamil
Each movie hall has predefined show times.

🪑 Display Available Seats with Booking Status
Seat layout shown in a user-friendly manner
Booked vs available seats are clearly indicated.

🙋 Book Up to 4 Seats per Ticket
Choose multiple seats in one go
Validates seat numbers and availability.

💵 Simple Payment Simulation
Calculates total amount based on selected seats and snacks
No real payment gateway, safe to test and run.

🍿 Snacks Purchase Menu
Optional snack selection during booking
Menu includes popcorn, coke, burger, sandwich, and combo packs
Cost added to final bill automatically.

📄 Store Ticket Information in CSV File
All bookings saved in bookings.csv
Ensures persistence across program runs.

🔍 Search Tickets by Phone Number
Retrieve ticket details using the registered mobile number
Useful for viewing or confirming existing bookings.

❌ Cancel Booked Tickets
Seat(s) can be cancelled
50% refund logic implemented
bookings.csv is updated after cancellation.

🧾 Generate Ticket Summary
Displays all ticket details after booking:
Name, Phone, Movie, Theatre, Time, Language, Seats, Amount

MovieTicketBooking/
│
├── main.c              # Main entry point  
├── booking.c           # Core booking logic  
├── booking.h           # Header file with declarations  
├── bookings.csv        # Stores ticket booking data  
├── Makefile            # For compilation (optional)  
└── README.md           # Project documentation  

🧠 Key Concepts Applied :

File I/O using fopen, fprintf, fscanf, etc.
Structs for storing hall and ticket info
Dynamic memory and buffer handling
Input validation and defensive programming
Modular design using .c and .h files

<img width="1547" height="658" alt="Screenshot 2025-07-31 152340" src="https://github.com/user-attachments/assets/f4c02702-ca15-4e8c-858d-c5c749a5dd61" />

<img width="1080" height="994" alt="Screenshot 2025-07-31 152427" src="https://github.com/user-attachments/assets/2b77f3f5-def7-42e2-95e5-c6366ae4f156" />

<img width="1029" height="387" alt="Screenshot 2025-07-31 152540" src="https://github.com/user-attachments/assets/fd2cce54-4457-4e79-a04e-ff92b2018273" />

<img width="1313" height="454" alt="Screenshot 2025-07-31 152720" src="https://github.com/user-attachments/assets/9454fa36-5ba2-4ab8-bc4e-15a08c7efc07" />

Project demo : https://drive.google.com/file/d/1sHuq7OP9zYckdDv9uzUwFvaM576QKLzN/view?usp=sharing

👩‍💻 Developed By Pavan Kumar G V Graduate Engineer – Embedded Systems Enthusiast 📧 gvpavanec008@gmail.com



