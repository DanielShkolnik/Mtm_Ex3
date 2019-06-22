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
    virtual ~Seat()= default;

protected:
    int line;
    int chair;
    int basePrice;
public:
    Seat(int line, int chair, int basePrice=NO_PRICE): line(line), chair(chair), basePrice(basePrice){}
};

// ---------------------------------------------
class GreenRoomSeat: public Seat
{
public:
    GreenRoomSeat(int line, int chair): Seat(line,chair){}
    int price() override{
        throw NoPrice();
    }
    string location() override{
        return  "Green Room-> " + Seat::location();
    }
    ~GreenRoomSeat() override= default;

};

// ---------------------------------------------
class MainHallSeat: public Seat
{
protected:
    int const mainHallSeatPrice=100;
public:
    MainHallSeat(int line, int chair, int basePrice):Seat(line,chair,basePrice){}
};

// ---------------------------------------------
class SpecialSeat:public MainHallSeat
{
protected:
    int const specialSeatPrice=300;
public:
    SpecialSeat(int line, int chair, int basePrice):MainHallSeat(line,chair,basePrice){}
};

// ---------------------------------------------
class GoldenCircleSeat:public SpecialSeat
{
private:
    int const goldenCircleSeatPrice=1000;
public:
    GoldenCircleSeat(int line, int chair, int basePrice):SpecialSeat(line,chair,basePrice){}
    string location() override{
        return  "Golden Circle-> " + Seat::location();
    }
    int price() override{
        return (Seat::basePrice+MainHallSeat::mainHallSeatPrice+SpecialSeat::specialSeatPrice+goldenCircleSeatPrice);
    }
    ~GoldenCircleSeat() override= default;
};

// ---------------------------------------------
class DisablePodiumSeat:public SpecialSeat
{
private:
    int const disablePodiumSeatPrice=200;
public:
    DisablePodiumSeat(int line, int chair, int basePrice=NO_PRICE):SpecialSeat(line,chair,basePrice){}
    string location() override{
        return  "Disable Podium-> " + Seat::location();
    }
    int price() override{
        return disablePodiumSeatPrice;
    }
    ~DisablePodiumSeat() override= default;
};

// ---------------------------------------------
class RegularSeat:public MainHallSeat
{
private:
    const string& area;
public:
    RegularSeat(const string& area, int line, int chair, int basePrice):MainHallSeat(line,chair,basePrice), area(area){}
    string location() override{
        return  "area: " + this->area + " " + Seat::location();    //"area: " + this->area + Seat::location();
    };
};

// ---------------------------------------------
class FrontRegularSeat:public RegularSeat
{
private:
    int const frontRegularSeatPrice=500;
public:
    FrontRegularSeat(const string& area, int line, int chair, int basePrice):RegularSeat(area,line,chair,basePrice){}
    string location() override{
        return  "Front-> " + RegularSeat::location();
    }
    int price() override{
        return (Seat::basePrice+MainHallSeat::mainHallSeatPrice+frontRegularSeatPrice);
    }
    ~FrontRegularSeat() override= default;
};

// ---------------------------------------------
class MiddleRegularSeat:public RegularSeat
{
private:
    int const middleRegularSeatPrice=250;
public:
    MiddleRegularSeat(const string& area, int line, int chair, int basePrice):RegularSeat(area,line,chair,basePrice){}
    string location() override{
        return  "Middle-> " + RegularSeat::location();
    }
    int price() override{
        return (Seat::basePrice+MainHallSeat::mainHallSeatPrice+middleRegularSeatPrice);
    }
    ~MiddleRegularSeat() override= default;
};

// ---------------------------------------------
class RearRegularSeat:public RegularSeat
{
public:
    RearRegularSeat(const string& area, int line, int chair, int basePrice):RegularSeat(area,line,chair,basePrice){}
    string location() override{
        return  "Middle-> " + RegularSeat::location();
    }
    int price() override{
        return (Seat::basePrice+MainHallSeat::mainHallSeatPrice);
    }
    ~RearRegularSeat() override= default;
};

// ---------------------------------------------
