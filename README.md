✈️ Flight Booking System (C++)

A simple Flight Booking Management System built using C++.
This project demonstrates Object-Oriented Programming (OOP) concepts such as classes, inheritance, polymorphism, and file handling.

🚀 Features

✅ Add new flights with details (flight number, origin, destination, departure time, seats, price).

✅ Book tickets for available flights.

✅ Cancel booked tickets.

✅ View passenger details.

✅ Search flights by destination or flight number.

✅ Store and retrieve data using file handling.

🛠️ Tech Stack

Language: C++

Paradigm: Object-Oriented Programming (OOP)

Concepts Used: Classes, Inheritance, Polymorphism, Encapsulation, File Handling

📂 Project Structure
FlightBooking/
│── main.cpp          # Entry point
│── Flight.h          # Flight class definition
│── Flight.cpp        # Flight class implementation
│── Booking.h         # Booking class definition
│── Booking.cpp       # Booking class implementation
│── utils.h           # Helper functions
│── data/             # Stores flight and booking records
│── README.md         # Project documentation

▶️ How to Run

Clone the repository:

git clone https://github.com/Shine124-sys/flight-booking-cpp.git
cd flight-booking-cpp


Compile the code:

g++ main.cpp Flight.cpp Booking.cpp -o flight_booking


Run the program:

./flight_booking

📸 Example Output
Welcome to Flight Booking System
1. Add Flight
2. View Flights
3. Book Ticket
4. Cancel Ticket
5. Exit
Enter your choice:

📖 Learning Outcomes

Understanding OOP concepts in C++.

Implementing real-world systems with classes and objects.

Hands-on with file I/O for data persistence.

Designing a menu-driven console application.

🔮 Future Improvements

✈️ GUI version with Qt or SFML.

✈️ Database integration (MySQL/SQLite).

✈️ Online booking simulation.