#ifndef SEAT_H
#define SEAT_H
#include <iostream>
#include <string>
using std::string;
using std::exception;
using std::cout;
using std::endl;

const int NO_PRICE=0;

// ---------------------------------------------
/**
 class NoPrice is a sub-class of exception class that used to handle exception in the program
 NoPrice has public function what() to handle the exception
 */
class NoPrice: public exception
{
public:
    const char* what() const noexcept override;
};

// ---------------------------------------------
/**
 * class Seat is the main class that is the father of all the sub-classes and gather all the common attributes
 * to all the sub-classe :
 * price() - pure virtual function the the sub-classes execute that calculate the price of the seat
 * location() - virtual function that is used to store the location of the seat
 * line - protected member that is used to store the line of the seat
 * chair - protected member that is used to store the number of the chair of the seat
 * basePrice - protected member that is used to store the starting price of the seat
 * Seat - constructor of the seat that gets line, chair and basePrice.
 */
class Seat
{
public:
    virtual int price() = 0;
    virtual string location();
    virtual ~Seat()= default;

protected:
    int line;
    int chair;
    int basePrice;
public:
    Seat(int line, int chair, int basePrice=NO_PRICE);
};


/**
 * class GreenRoomSeat is sub-class of Seat:
 * GreenRoomSeat(int line, int chair) - Constructor of GreenRoomSeat
 * price() - execute of the father function
 * location() - execute of the father function
 * ~GreenRoomSeat() - execute of the GreenRoomSeat destructor
 */
// ---------------------------------------------
class GreenRoomSeat: public Seat
{
public:
    GreenRoomSeat(int line, int chair);
    int price() override;
    string location() override;
    ~GreenRoomSeat() override= default;

};

/**
 * class MainHallSeat is sub-class of Seat:
 * mainHallSeatPrice - protected member that stores the class extra fee for the seat
 * MainHallSeat - constructor that gets line, chair, basePrice
 */
// ---------------------------------------------
class MainHallSeat: public Seat
{
protected:
    int const mainHallSeatPrice=100;
public:
    MainHallSeat(int line, int chair, int basePrice);
};

/**
 * class SpecialSeat is sub-class of MainHallSeat:
 * specialSeatPrice - protected member that stores the class extra fee for the seat
 * SpecialSeat - constructor that gets line, chair, basePrice
 */
// ---------------------------------------------
class SpecialSeat:public MainHallSeat
{
protected:
    int const specialSeatPrice=300;
public:
    SpecialSeat(int line, int chair, int basePrice);
};

/**
 * class GoldenCircleSeat is sub-class of SpecialSeat:
 * goldenCircleSeatPrice - member that stores the class extra fee for the seat
 * GoldenCircleSeat - constructor that gets line, chair, basePrice
 * price() - execute of the father function
 * location() - execute of the father function
 * ~GoldenCircleSeat() - execute of the GreenRoomSeat destructor
 */
// ---------------------------------------------
class GoldenCircleSeat:public SpecialSeat
{
private:
    int const goldenCircleSeatPrice=1000;
public:
    GoldenCircleSeat(int line, int chair, int basePrice);
    string location() override;
    int price() override;
    ~GoldenCircleSeat() override= default;
};

/**
 * class DisablePodiumSeat is sub-class of SpecialSeat:
 * disablePodiumSeatPrice - member that stores the class extra fee for the seat
 * DisablePodiumSeat - constructor that gets line, chair, basePrice(this parameter is not used)
 * price() - execute of the father function
 * location() - execute of the father function
 * ~DisablePodiumSeat() - execute of the GreenRoomSeat destructor
 */
// ---------------------------------------------
class DisablePodiumSeat:public SpecialSeat
{
private:
    int const disablePodiumSeatPrice=200;
public:
    DisablePodiumSeat(int line, int chair, int basePrice=NO_PRICE);
    string location() override;
    int price() override;
    ~DisablePodiumSeat() override= default;
};

/**
 * class RegularSeat is sub-class of MainHallSeat:
 * area - member that stores all the sub-classes seat area
 * RegularSeat - constructor that gets area, line, chair, basePrice
 * location() - execute of the father function
 */
// ---------------------------------------------
class RegularSeat:public MainHallSeat
{
private:
    const char& area;
public:
    RegularSeat(const char& area, int line, int chair, int basePrice);
    string location() override;
};

/**
 * class FrontRegularSeat is sub-class of RegularSeat:
 * frontRegularSeatPrice - member that stores the class extra fee for the seat
 * FrontRegularSeat - constructor that gets area, line, chair, basePrice
 * price() - execute of the father function
 * location() - execute of the father function
 * ~FrontRegularSeat() - execute of the GreenRoomSeat destructor
 */
// ---------------------------------------------
class FrontRegularSeat:public RegularSeat
{
private:
    int const frontRegularSeatPrice=500;
public:
    FrontRegularSeat(const char& area, int line, int chair, int basePrice);
    string location() override;
    int price() override;
    ~FrontRegularSeat() override= default;
};

/**
 * class MiddleRegularSeat is sub-class of RegularSeat:
 * middleRegularSeatPrice - member that stores the class extra fee for the seat
 * MiddleRegularSeat - constructor that gets area, line, chair, basePrice
 * price() - execute of the father function
 * location() - execute of the father function
 * ~MiddleRegularSeat() - execute of the GreenRoomSeat destructor
 */
// ---------------------------------------------
class MiddleRegularSeat:public RegularSeat
{
private:
    int const middleRegularSeatPrice=250;
public:
    MiddleRegularSeat(const char& area, int line, int chair, int basePrice);
    string location() override;
    int price() override;
    ~MiddleRegularSeat() override= default;
};

/**
 * class RearRegularSeat is sub-class of RegularSeat:
 * RearRegularSeat - constructor that gets area, line, chair, basePrice
 * price() - execute of the father function
 * location() - execute of the father function
 * ~RearRegularSeat() - execute of the GreenRoomSeat destructor
 */
// ---------------------------------------------
class RearRegularSeat:public RegularSeat
{
public:
    RearRegularSeat(const char& area, int line, int chair, int basePrice);
    string location() override;
    int price() override;
    ~RearRegularSeat() override= default;
};

// ---------------------------------------------
#endif