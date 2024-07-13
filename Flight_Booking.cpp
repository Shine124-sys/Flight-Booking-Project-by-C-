#include <iostream>
#include <mysql.h>  // Include MySQL C API header
#include <sstream>
#include <windows.h>

using namespace std;

const char* HOST = "localhost";
const char* USER = "root";
const char* PASS = "password";
const char* DB = "mydb";

class Flight {
private:
    string Fnum, Dep, Des;
    int Seat;

public:
    Flight(string Fnum, string dep, string Des, int Seat) : Fnum(Fnum), Dep(dep), Des(Des), Seat(Seat) {}

    string getFnum() {
        return Fnum;
    }

    string getDep() {
        return Dep;
    }

    string getDes() {
        return Des;
    }

    int getSeat() {
        return Seat;
    }
};

void display(MYSQL* conn) {
    string dis = "SELECT * FROM Airline";
    if (mysql_query(conn, dis.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    }
    else {
        MYSQL_RES* res;
        res = mysql_store_result(conn);
        if (res) {
            int num = mysql_num_fields(res);
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(res))) {
                for (int i = 0; i < num; i++) {
                    cout << " " << row[i];
                }
                cout << endl;
            }
            mysql_free_result(res); // Free result set
        }
        else {
            cout << "Error: Couldn't retrieve result" << endl;
        }
    }
}

int main() {
    MYSQL* conn;
    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, HOST, USER, PASS, DB, 3306, NULL, 0)) {
        cout << "Error: " << mysql_error(conn) << endl;
        return 1; // Exit program on connection error
    }
    else {
        cout << "Connected to database!" << endl;
    }

    Flight f1("Flight102", "UAE", "Canada", 50);
    Flight f2("Flight103", "UAE", "Canada", 30);
    Flight f3("Flight105", "UAE", "Canada", 20);

    stringstream ss1, ss2, ss3;
    ss1 << f1.getSeat();
    string strs1 = ss1.str();

    ss2 << f2.getSeat();
    string strs2 = ss2.str();

    ss3 << f3.getSeat();
    string strs3 = ss3.str();

    string insert1 = "INSERT INTO Airline(Fnum, Departure, Destination, Seat) VALUES('" + f1.getFnum() + "', '" + f1.getDep() + "', '" + f1.getDes() + "', '" + strs1 + "')";
    string insert2 = "INSERT INTO Airline(Fnum, Departure, Destination, Seat) VALUES('" + f2.getFnum() + "', '" + f2.getDep() + "', '" + f2.getDes() + "', '" + strs2 + "')";
    string insert3 = "INSERT INTO Airline(Fnum, Departure, Destination, Seat) VALUES('" + f3.getFnum() + "', '" + f3.getDep() + "', '" + f3.getDes() + "', '" + strs3 + "')";

    if (mysql_query(conn, insert1.c_str()) || mysql_query(conn, insert2.c_str()) || mysql_query(conn, insert3.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    }
    else {
        cout << "Inserted successfully" << endl;
    }

    Sleep(3000);

    bool exit = false;
    while (!exit) {
        system("cls");
        display(conn);
        cout << endl;

        cout << "Welcome To Airlines Reservation System" << endl;
        cout << "******************************************" << endl;
        cout << "1. Reserve A seat in Flight" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your Choice: ";
        
        int val;
        cin >> val;

        if (val == 1) {
            string flight;
            cout << endl;
            cout << "Enter Flight Number: ";
            cin >> flight;

            int total;
            string check = "SELECT Seat FROM Airline WHERE Fnum = '" + flight + "'";
            if (mysql_query(conn, check.c_str())) {
                cout << "Error: " << mysql_error(conn) << endl;
            }
            else {
                MYSQL_RES* res = mysql_store_result(conn);
                if (res) {
                    MYSQL_ROW row = mysql_fetch_row(res);
                    if (row) {
                        total = atoi(row[0]);
                        total--;
                        stringstream sst;
                        sst << total;
                        string strT = sst.str();
                        string update = "UPDATE Airline SET Seat = '" + strT + "' WHERE Fnum = '" + flight + "'";
                        if (mysql_query(conn, update.c_str())) {
                            cout << "Error: " << mysql_error(conn) << endl;
                        }
                        else {
                            cout << "Seat reserved successfully in: " << flight << endl;
                        }

                        if (total == 0) {
                            cout << "Sorry! No seats available!" << endl;
                        }
                    }
                    else {
                        cout << "Flight not found!" << endl;
                    }
                    mysql_free_result(res); // Free result set
                }
                else {
                    cout << "Error: Couldn't retrieve result" << endl;
                }
            }
            Sleep(3000);
        }
        else if (val == 2) {
            exit = true;
            cout << "Goodbye!" << endl;
            Sleep(3000);
        }
        else {
            cout << "Invalid Input" << endl;
            Sleep(3000);
        }
    }

    mysql_close(conn); // Close MySQL connection
    return 0;
}
