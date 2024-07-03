#include <iostream>
#include <string>


using namespace std;

class Flight
{
private:
    string flight_schedule[MAX_FLIGHTS][5];
    int flight_count;

public:
    Flight() : flight_count(0) {}

    void addFlight(string flight_number, string date_of_departure,
                   string departure_point, string destination_point,
                   int available_economy_seats, int available_business_seats)
    {

        flight_schedule[flight_count][0] = flight_number;
        flight_schedule[flight_count][1] = date_of_departure;
        flight_schedule[flight_count][2] = departure_point;
        flight_schedule[flight_count][3] = destination_point;
        flight_schedule[flight_count][4] = to_string(available_economy_seats);
        flight_schedule[flight_count][5] = to_string(available_business_seats);
        flight_count++;
    }
};

class Reservation
{
private:
    string customer_name;
    string passport_number;
    string contact_number;
    string flight_number;

public:
    Reservation(string name, string passport, string contact) : customer_name(name), passport_number(passport), contact_number(contact), flight_number("") {}

    bool makeReservation(Flight &flight, string date_of_departure,
                         string departure_point, string destination_point,
                         string seat_type)
    {
        flight_number = "some flight number";
        return true;
    }

    void displayReservation()
    {
        if (!flight_number.empty())
        {
            cout << "Passenger Name: " << customer_name << endl;
            cout << "Passport Number: " << passport_number << endl;
            cout << "Flight Number: " << flight_number << endl;
        }
        else
        {
            cout << "No confirmed reservation." << endl;
        }
    }
};

int main()
{
    Flight flights;
    flights.addFlight("AB123", "2024-03-05", "City A", "City B", 100, 50);

    Reservation reservation("John Doe", "P12345678", "555-1234");
    if (reservation.makeReservation(flights, "2024-03-05", "City A", "City B", "Economy"))
    {
        cout << "Reservation successful!" << endl;
    }
    else
    {
        cout << "Reservation failed." << endl;
    }

    reservation.displayReservation();

    return 0;
}