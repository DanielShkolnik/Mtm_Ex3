#include <iostream>
#include <string>
using std::string;
using std::exception;
using std::cout;
using std::endl;

// ---------------------------------------------
class NoPrice: public exception
{
public:
    const char* what() const noexcept override{
        return  "Not For Sale !\n";
    }
};

// ---------------------------------------------
class Seat
{
public:
    virtual int price() = 0;
    virtual string location(){
        return  "line: " + std::to_string(this->line) + ", chair: " + std::to_string(this->chair);
    };

protected:
    int line;
    int chair;
    int basePrice;
public:
    Seat(int line, int chair, int basePrice): line(line), chair(chair), basePrice(basePrice){}
};

// ---------------------------------------------
class GreenRoomSeat: public Seat
{
public:
    GreenRoomSeat(int line, int chair): Seat(line,chair,10){}
    int price() override{
        throw NoPrice();
    }
    string location() override{
        return  "Green Room-> " + Seat::location();
    }

};

// ---------------------------------------------
class MainHallSeat
{
};

// ---------------------------------------------
class SpecialSeat
{
};

// ---------------------------------------------
class GoldenCircleSeat
{
};

// ---------------------------------------------
class DisablePodiumSeat
{
};

// ---------------------------------------------
class RegularSeat
{
};

// ---------------------------------------------
class FrontRegularSeat
{
};

// ---------------------------------------------
class MiddleRegularSeat
{
};

// ---------------------------------------------
class RearRegularSeat
{
};

// ---------------------------------------------
