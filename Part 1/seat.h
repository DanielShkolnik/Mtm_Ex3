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
class NoPrice: public exception
{
public:
    const char* what() const noexcept override;
};

// ---------------------------------------------
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

// ---------------------------------------------
class GreenRoomSeat: public Seat
{
public:
    GreenRoomSeat(int line, int chair);
    int price() override;
    string location() override;
    ~GreenRoomSeat() override= default;

};

// ---------------------------------------------
class MainHallSeat: public Seat
{
protected:
    int const mainHallSeatPrice=100;
public:
    MainHallSeat(int line, int chair, int basePrice);
};

// ---------------------------------------------
class SpecialSeat:public MainHallSeat
{
protected:
    int const specialSeatPrice=300;
public:
    SpecialSeat(int line, int chair, int basePrice);
};

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

// ---------------------------------------------
class RegularSeat:public MainHallSeat
{
private:
    const char& area;
public:
    RegularSeat(const char& area, int line, int chair, int basePrice);
    string location() override;
};

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