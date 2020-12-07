#include <iostream>

using namespace std;

const int PLANE_SPEED = 20;
const int TRAIN_SPEED = 15;
const int CAR_SPEED = 5;

const int PLANE_COST = 5;
const int TRAIN_COST = 3;
const int CAR_COST = 4;

struct travelResult
{
    double time;
    double cost;

    friend ostream& operator << (ostream& out, const travelResult& obj)
    {
        return out << "Time: " << obj.time << ". Cost: " << obj.cost << endl;
    }
};

class PassengerCarrier
{
protected:
    double speed;
    double cost;

    PassengerCarrier(double speed, double cost) : speed(speed), cost(cost)
    {

    }

    travelResult calculateCost(double distance, int passengers) const
    {
        double time = distance / speed;
        double cost = passengers * distance * this->cost;
        return travelResult{ time, cost };
    }
};

class Plane : PassengerCarrier
{
public:
    Plane() : PassengerCarrier(PLANE_SPEED, PLANE_COST)
    {

    }

    void calculateTravelCost(double distance, int passengers) const
    {
        travelResult result = PassengerCarrier::calculateCost(distance, passengers);
        cout << "Travel result by plane. " << result;
    }
};

class Train : PassengerCarrier
{
public:
    Train() : PassengerCarrier(TRAIN_SPEED, TRAIN_COST)
    {

    }

    void calculateTravelCost(double distance, int passengers) const
    {
        travelResult result = PassengerCarrier::calculateCost(distance, passengers);
        cout << "Travel result by train. " << result;
    }
};

class Car : PassengerCarrier
{
public:
    Car() : PassengerCarrier(CAR_SPEED, CAR_COST)
    {

    }

    void calculateTravelCost(double distance, int passengers) const
    {
        travelResult result = PassengerCarrier::calculateCost(distance, passengers);
        cout << "Travel result by car. " << result;
    }
};

int main()
{
    cout << "1. Plane" << endl;
    cout << "2. Train" << endl;
    cout << "3. Car" << endl;
    
    int transport;
    cin >> transport;

    cout << "Travel distant: ";

    int distance;
    cin >> distance;

    cout << "Passengers: ";

    int passengers;
    cin >> passengers;

    switch(transport)
    {
    case 1:
    {
        Plane plane;
        plane.calculateTravelCost(distance, passengers);
        break;
    }
    case 2:
    {
        Train train;
        train.calculateTravelCost(distance, passengers);
        break;
    }
    case 3:
    {
        Car car;
        car.calculateTravelCost(distance, passengers);
        break;
    }
    default:
        cout << "Unknown carriage. Exit";
        return 0;
    }
}
