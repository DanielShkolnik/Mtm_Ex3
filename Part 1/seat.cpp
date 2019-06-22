#include "seat.h"

const int NO_PRICE=0;

const char* NoPrice::what() const noexcept override{
return  "Not For Sale !";
}

virtual string Seat::location(){
    return  "line: " + std::to_string(this->line) + ", chair: " + std::to_string(this->chair);
}

Seat::Seat(int line, int chair, int basePrice=NO_PRICE): line(line), chair(chair), basePrice(basePrice){}

GreenRoomSeat::GreenRoomSeat(int line, int chair): Seat(line,chair){}
int GreenRoomSeat::price() override{
throw NoPrice();
}
string GreenRoomSeat::location() override{
return  "Green Room-> " + Seat::location();
}

MainHallSeat::MainHallSeat(int line, int chair, int basePrice):Seat(line,chair,basePrice){}

SpecialSeat::SpecialSeat(int line, int chair, int basePrice):MainHallSeat(line,chair,basePrice){}

GoldenCircleSeat::GoldenCircleSeat(int line, int chair, int basePrice):SpecialSeat(line,chair,basePrice){}
string GoldenCircleSeat::location() override{
return  "Golden Circle-> " + Seat::location();
}
int GoldenCircleSeat::price() override{
return (Seat::basePrice+MainHallSeat::mainHallSeatPrice+SpecialSeat::specialSeatPrice+goldenCircleSeatPrice);
}

DisablePodiumSeat::DisablePodiumSeat(int line, int chair, int basePrice=NO_PRICE):SpecialSeat(line,chair,basePrice){}
string DisablePodiumSeat::location() override{
return  "Disable Podium-> " + Seat::location();
}
int DisablePodiumSeat::price() override{
return disablePodiumSeatPrice;
}

RegularSeat::RegularSeat(const char& area, int line, int chair, int basePrice):MainHallSeat(line,chair,basePrice), area(area){}
string RegularSeat::location() override{
return  "area: " + string(1,this->area) + ", " + Seat::location();
}

FrontRegularSeat::FrontRegularSeat(const char& area, int line, int chair, int basePrice):RegularSeat(area,line,chair,basePrice){}
string FrontRegularSeat::location() override{
return  "Front-> " + RegularSeat::location();
}
int FrontRegularSeat::price() override{
return (Seat::basePrice+MainHallSeat::mainHallSeatPrice+frontRegularSeatPrice);
}

MiddleRegularSeat::MiddleRegularSeat(const char& area, int line, int chair, int basePrice):RegularSeat(area,line,chair,basePrice){}
string MiddleRegularSeat::location() override{
return  "Middle-> " + RegularSeat::location();
}
int MiddleRegularSeat::price() override{
return (Seat::basePrice+MainHallSeat::mainHallSeatPrice+middleRegularSeatPrice);
}

RearRegularSeat::RearRegularSeat(const char& area, int line, int chair, int basePrice):RegularSeat(area,line,chair,basePrice){}
string RearRegularSeat::location() override{
return  "Rear-> " + RegularSeat::location();
}
int RearRegularSeat::price() override{
return (Seat::basePrice+MainHallSeat::mainHallSeatPrice);
}

