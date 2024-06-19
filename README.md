# Hostel Accommodation System

This project is a simple Hostel Accommodation System implemented in C++ using MySQL for database management. The system allows users to reserve beds in a hostel, check the availability of beds, and manage student reservations.

## Features

- Connect to MySQL database
- Insert hostel data into the database
- Reserve a bed for a student
- Check bed availability
- Update the number of available beds

## Prerequisites

- C++ Compiler
- MySQL Server
- MySQL Connector/C++ Library
- CMake (optional, for building the project)

## Getting Started

### MySQL Setup

1. Install MySQL Server and MySQL Workbench.
2. Create a database named `mydb`.
3. Create a table named `hostel` with the following structure:
    ```sql
    CREATE TABLE hostel (
        Name VARCHAR(50) NOT NULL PRIMARY KEY,
        Bed INT,
        Fee INT
    );
    ```
4. Insert initial data into the `hostel` table:
    ```sql
    INSERT INTO hostel (Name, Bed, Fee) VALUES ('3Star', 5, 5000);
    ```

### C++ Setup

1. Install the MySQL Connector/C++ library.
2. Clone this repository:
    ```bash
    git clone https://github.com/Sumit123sm/Hostel_Accommodation.git
    cd Hostel_Accommodation
    ```
3. Build the project using your preferred method. If using CMake:
    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```
4. Run the executable:
    ```bash
    ./HostelAccommodation
    ```

## Code Overview

The main components of the project include:

- `Hostel` class: Represents a hostel with a name, number of beds, and fee per bed.
- MySQL connection setup: Establishes a connection to the MySQL database.
- Main loop: Provides a menu for reserving beds and exiting the system.
## Contributing
Contributions are welcome! Please fork the repository and submit a pull request with your changes.
## Acknowledgments
MySQL documentation
C++ reference documentation
Open-source community
