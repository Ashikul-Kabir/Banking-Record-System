#include <iostream>

using namespace std;

class Vehicle
{
protected:
    float promofare, onlineFare, Total, grandTotal, dist, promoCode, distFare, durationFare;

public:
    void displayCar()
    {
        cout << "\nA car is inherited from the vehicle categories.\n";
    }

    void displayMotorcycle()
    {
        cout << "\nA motorcycle is inherited from the vehicle categories.\n";
    }

    void displayBicycle()
    {
        cout << "\nA Bicycle is inherited from the vehicle categories.\n";
    }
};

class Car : public Vehicle
{
protected:
    char choice, paymentMethod;

public:
    float tmp, speed = 60.0 / 60.0, baseFare = 50.0;

    Car(char veh, float distance, float promo, char payment)
    {
        this->choice = veh;
        this->dist = distance;
        this->paymentMethod = payment;
        this->promoCode = promo;
    }

    void getFare(float promoCode)
    {
        if (dist < 0)
        {
            dist = 0;
        }

        //Calculating fare before promotion applied
        distFare = dist * 25;
        durationFare = (dist / speed) * 2;
        Total = baseFare + distFare + durationFare;

        //Flat promo
        if (promoCode == 1)
        {
            promofare = 50;
            grandTotal = Total - 50;
            if (grandTotal < 0)
            {
                grandTotal = 0;
            }
        }

        //Percent promo
        else if (promoCode == 2)
        {
            promofare = Total * 0.2;
            grandTotal = Total - promofare;
        }

        //Capped percent promo
        else if (promoCode == 3)
        {
            promofare = Total * 0.25;
            grandTotal = Total - promofare;
            if (promofare > 60)
            {
                promofare = 60;
                grandTotal = Total - promofare;
            }
        }

        if (paymentMethod == 'o' || paymentMethod == 'O')
        {
            tmp = promofare;
            onlineFare = tmp * 0.1;
            grandTotal = Total - (onlineFare + promofare);

            if (grandTotal < 0)
            {
                grandTotal = 0;
            }
        }

        else if (paymentMethod == 'c' || paymentMethod == 'C')
        {
            return;
        }
    }

    void displayFare(char paymentMethod)
    {
        cout << "\n------Invoice------\n";
        cout << "Base fare: " << baseFare << " TK" << endl;
        cout << "Distance fare: " << distFare << " TK" << endl;
        cout << "Duration fare: " << durationFare << " TK" << endl;
        cout << "Total fare: " << Total << " TK" << endl;

        if (paymentMethod == 'o' || paymentMethod == 'O')
        {
            cout << "Online discount: " << onlineFare << " TK" << endl;
        }

        cout << "Promo fare: " << promofare << " TK" << endl;
        cout << "Grand Total: " << grandTotal << " TK" << endl;
    }
};

class Motorcycle : public Vehicle
{
protected:
    char choice, paymentMethod;

public:
    float tmp, speed = 70.0 / 60.0, baseFare = 30.0;

    Motorcycle(char veh, float distance, float promo, char payment)
    {
        this->choice = veh;
        this->dist = distance;
        this->paymentMethod = payment;
        this->promoCode = promo;
    }

    void getFare(float promoCode)
    {
        if (dist < 0)
        {
            dist = 0;
        }

        //Calculating fare before promotion applied
        distFare = dist * 15;
        durationFare = (dist / speed) * 2;
        Total = baseFare + distFare + durationFare;

        //Flat promo
        if (promoCode == 1)
        {
            promofare = 50;
            grandTotal = Total - 50;
            if (grandTotal < 0)
            {
                grandTotal = 0;
            }
        }

        //Percent promo
        else if (promoCode == 2)
        {
            promofare = Total * 0.2;
            grandTotal = Total - promofare;
        }

        //Capped percent promo
        else if (promoCode == 3)
        {
            promofare = Total * 0.25;
            grandTotal = Total - promofare;
            if (promofare > 60)
            {
                promofare = 60;
                grandTotal = Total - promofare;
            }
        }

        else
        {
            cout << "Invalid promocode!\n";
            return;
        }

        if (paymentMethod == 'o' || paymentMethod == 'O')
        {
            tmp = promofare;
            onlineFare = tmp * 0.1;
            grandTotal = Total - (onlineFare + promofare);

            if (grandTotal < 0)
            {
                grandTotal = 0;
            }
        }

        else if (paymentMethod == 'c' || paymentMethod == 'C')
        {
            return;
        }
    }

    void displayFare(char paymentMethod)
    {
        if (paymentMethod != 'c' && paymentMethod != 'C' && paymentMethod != 'o' && paymentMethod != 'O')
        {
            cout << "\nInvalid input!\n";
            return;
        }

        cout << "\n------Invoice------\n";
        cout << "Base fare: " << baseFare << " TK" << endl;
        cout << "Distance fare: " << distFare << " TK" << endl;
        cout << "Duration fare: " << durationFare << " TK" << endl;
        cout << "Total fare: " << Total << " TK" << endl;

        if (paymentMethod == 'o' || paymentMethod == 'O')
        {
            cout << "Online discount: " << onlineFare << " TK" << endl;
        }

        cout << "Promo fare: " << promofare << " TK" << endl;
        cout << "Grand Total: " << grandTotal << " TK" << endl;
    }
};

class Bicycle : public Vehicle
{
protected:
    char choice, paymentMethod;

public:
    float tmp, speed = 20.0 / 60.0, baseFare = 20.0;

    Bicycle(char veh, float distance, float promo, char payment)
    {
        this->choice = veh;
        this->dist = distance;
        this->paymentMethod = payment;
        this->promoCode = promo;
    }

    void getFare(float promoCode)
    {
        if (dist < 0)
        {
            dist = 0;
        }

        //Calculating fare before promotion applied
        distFare = dist * 10;
        durationFare = (dist / speed) * 2;
        Total = baseFare + distFare + durationFare;

        //Flat promo
        if (promoCode == 1)
        {
            promofare = 50;
            grandTotal = Total - 50;
            if (grandTotal < 0)
            {
                grandTotal = 0;
            }
        }

        //Percent promo
        else if (promoCode == 2)
        {
            promofare = Total * 0.2;
            grandTotal = Total - promofare;
        }

        //Capped percent promo
        else if (promoCode == 3)
        {
            promofare = Total * 0.25;
            grandTotal = Total - promofare;
            if (promofare > 60)
            {
                promofare = 60;
                grandTotal = Total - promofare;
            }
        }
        else
        {
            cout << "Invalid promocode!\n";
            return;
        }

        if (paymentMethod == 'o' || paymentMethod == 'O')
        {
            tmp = promofare;
            onlineFare = tmp * 0.1;
            grandTotal = Total - (onlineFare + promofare);

            if (grandTotal < 0)
            {
                grandTotal = 0;
            }
        }

        else if (paymentMethod == 'c' || paymentMethod == 'C')
        {
            return;
        }
    }

    void displayFare(char paymentMethod)
    {
        if (paymentMethod != 'c' && paymentMethod != 'C' && paymentMethod != 'o' && paymentMethod != 'O')
        {
            cout << "\nInvalid input!\n";
            return;
        }

        cout << "\n------Invoice------\n";
        cout << "Base fare: " << baseFare << " TK" << endl;
        cout << "Distance fare: " << distFare << " TK" << endl;
        cout << "Duration fare: " << durationFare << " TK" << endl;
        cout << "Total fare: " << Total << " TK" << endl;

        if (paymentMethod == 'o' || paymentMethod == 'O')
        {
            cout << "Online discount: " << onlineFare << " TK" << endl;
        }

        cout << "Promo fare: " << promofare << " TK" << endl;
        cout << "Grand Total: " << grandTotal << " TK" << endl;
    }
};

int main()
{
    char veh, payment;
    float promo;
    float distance;

    while (true)
    {
        cout << "\n---Welcome to McB Rides---\n";
        cout << "Choose your vehicle(a/b/c): \na. Car\nb. Motorcycle\nc. Bicycle\n";
        cin >> veh;

        if (veh != 'a' && veh != 'A' && veh != 'b' && veh != 'B' && veh != 'c' && veh != 'C')
        {
            cout << "Invalid! Please try again.\n";
            return 0;
        }

        cout << "Enter distance: ";
        cin >> distance;
        cout << "Choose promo code: 1/2/3\n";
        cin >> promo;

        if (promo != 1 && promo != 2 && promo != 3)
        {
            cout << "Invalid promocode!\n";
            return 0;
        }

        cout << "Enter payment method(C/O): \nCash\nOnline\n";
        cin >> payment;

        if (payment != 'c' && payment != 'C' && payment != 'o' && payment != 'O')
        {
            cout << "\nInvalid input!\n";
            return 0;
        }

        if (veh == 'a' || veh == 'A')
        {
            Car car(veh, distance, promo, payment);
            car.getFare(promo);
            car.displayCar();
            car.displayFare(payment);
        }

        else if (veh == 'b' || veh == 'B')
        {
            Motorcycle motorcycle(veh, distance, promo, payment);
            motorcycle.getFare(promo);
            motorcycle.displayMotorcycle();
            motorcycle.displayFare(payment);
        }

        else if (veh == 'c' || veh == 'C')
        {
            Bicycle bicycle(veh, distance, promo, payment);
            bicycle.getFare(promo);
            bicycle.displayBicycle();
            bicycle.displayFare(payment);
        }
    }

    return 0;
}