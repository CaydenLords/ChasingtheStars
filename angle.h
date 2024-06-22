
#define TWO_PI 6.28318530718
#define PI (TWO_PI / 2)
#include <cmath>    // for floor()
#include <iostream>  // for cout
#include <cassert>   // for assert()
using namespace std;

class TestAngle;

/************************************
 * ANGLE
 ************************************/
class Angle
{
friend TestAngle;
protected:
    // An angle in radians.
    double radians;
    // An angle in degrees.
    double degrees;

    /************************************
    * NORMALIZE
    * This function will take a radian as
    * parameter and reduce it to between
    * 0 and 2pi.
    ************************************/
    double normalize(double radians) const
    {
        // Calculate the number of full revolutions
        double revolutions = floor(radians / TWO_PI);

        // Reduce the angle to the range [0, 2pi)
        double normalizedRadians = radians - revolutions * TWO_PI;

        // Ensure the result is non-negative
        if (normalizedRadians < 0)
        {
            normalizedRadians += TWO_PI;
        }

        // Return the normalized value
        return normalizedRadians;
    }

    /************************************
    * CONVERT TO DEGREES
    * This function will take radians as a parameter
    * and return degrees.
    ************************************/
    double convertToDegrees(double radians) const
    {
        double degrees = normalize(radians) * 180.0 / acos(-1);
        return degrees;
    }

    /************************************
    * CONVERT TO RADIANS
    * This function will take degrees as a parameter
    * and return radians.
    ************************************/
    double convertToRadians(double degrees) const
    {
        double radians = degrees * acos(-1) / 180.0;
        return normalize(radians);
    }

public:
    // Constructor
    Angle(double degrees, double radians) : degrees(degrees), radians(radians) {}

    // Default constructor
    Angle() 
    {
        radians = 0.0;
        degrees = 0.0;
    }

    // Non-default constructor
    Angle(int degrees)
    {
        radians = convertToRadians(degrees);
        degrees = degrees;
    }

    // Copy constructor
    Angle(const Angle& rhs)
    {
        radians = rhs.radians;
        degrees = rhs.convertToDegrees(radians);
    }

    /************************************
    * GET DEGREES
    * This function will return
    * the angle in degrees.
    ************************************/
    inline double getDegrees() const
    {
        return radians * 180.0 / acos(-1);
    }

    /************************************
    * GET RADIANS
    * This function will return
    * the angle in radians.
    ************************************/
    inline double getRadians() const
    {
        return radians;
    }

    /************************************
    * SET DEGREES
    * This function will take degrees as
    * a parameter and update the attribute
    * with the passed parameter.
    ************************************/
    inline void setDegrees(double degrees)
    {
        // Unwrap the angle to be within [0, 360)
        while (degrees >= 360)
        {
            degrees -= 360.0;
        }

        while (degrees < 0.0)
        {
            degrees += 360.0;
        }

        // Update the attribute with the adjusted angle
        this->degrees = degrees;
    }

    /************************************
    * SET RADIANS
    * This function will take radians as
    * a parameter and update the attribute
    * with the passed parameter.
    ************************************/
    inline void setRadians(double radians)
    {
        // Unwrap the angle to be within 0 and 2pi
        while (radians >= TWO_PI)
        {
            radians -= TWO_PI;
        }

        while (radians < 0.0)
        {
            radians += TWO_PI;
        }

        // Update the attribute with the adjusted angle
        this->radians = radians;
    }

    /************************************
    * DISPLAY
    * This function will display a degree value
    * to 1 decimal place of accuracy.
    ************************************/
    inline virtual void display(std::ostream& out) const
    {
        cout.setf(ios::fixed);     // "fixed" means don't use scientific notation
        cout.setf(ios::showpoint); // "showpoint" means always show the decimal point
        cout.precision(1);         // Set the precision to 1 decimal place of accuracy.

        // Display the value
        std::cout << getDegrees();
    }

    // Assignment operator
    inline Angle& operator=(const Angle & rhs)
    {
        degrees = rhs.degrees;
        radians = rhs.convertToRadians(degrees);

        return *this;
    }

    // Negative Operator
    inline Angle operator-() const 
    {
        return Angle(std::fmod(degrees + 180.0, 360.0));
    }

    // Equals operator
    bool operator==(const Angle& rhs) const
    {
        return degrees == rhs.degrees;
    }

    // Nonequals operator
    bool operator!=(const Angle& rhs) const
    {
        return degrees != rhs.degrees;
    }

    // Increment operator, prefix
    virtual Angle& operator++()
    {
        degrees += 1.0;
        return *this;
    }

    // Increment operator, postfix
    virtual Angle& operator++(int postfix)
    {
        Angle temp(*this);
        degrees += 1.0;;
        return temp;
    }

    // Decrement operator, prefix
    virtual Angle& operator--() 
    {
        degrees -= 1.0;
        return *this;
    }

    // Decrement operator, postfix
    virtual Angle operator--(int) 
    {
        Angle temp(*this);
        degrees -= 1.0;;
        return temp;
    }

    // Friend function for insertion operator
    friend std::ostream& operator<<(std::ostream& out, const Angle& rhs);

    // Friend function for extraction operator
    friend std::istream& operator>>(std::istream& in, Angle& rhs);

};

// Insertion operator
std::ostream& operator<<(std::ostream& out, const Angle& rhs);

// Extraction operator
std::istream& operator>>(std::istream& in, Angle& rhs);


class AngleRadians : public Angle
{
public:
    // Constructor
    AngleRadians(double degrees, double radians) : Angle(degrees, radians) {}

    inline virtual void display(std::ostream& out) const
    {
        // Get degrees, convert to radians
        double degs = getDegrees();
        double rads = convertToRadians(degs);

        cout.setf(ios::fixed);     // "fixed" means don't use scientific notation
        cout.setf(ios::showpoint); // "showpoint" means always show the decimal point
        cout.precision(2);         // Set the precision to 2 decimal places of accuracy.

        // Display the value
        std::cout << rads;
    }

    virtual Angle& operator++()
    {
        degrees += (1 / 8) * PI;
        return *this;
    }

    virtual Angle& operator--()
    {
        degrees -= (1 / 8) * PI;
        return *this;
    }
};