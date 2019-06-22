#include "seat.h"



const char* NoPrice::what() const noexcept{
return  "Not For Sale !";
}

string Seat::location(){
    return  "line: " + std::to_string(this->line) + ", chair: " + std::to_string(this->chair);
}

Seat::Seat(int line, int chair, int basePrice): line(line), chair(chair), basePrice(basePrice){}

GreenRoomSeat::GreenRoomSeat(int line, int chair): Seat(line,chair){}
int GreenRoomSeat::price() {
throw NoPrice();
}
string GreenRoomSeat::location() {
return  "Green Room-> " + Seat::location();
}

MainHallSeat::MainHallSeat(int line, int chair, int basePrice):Seat(line,chair,basePrice){}

SpecialSeat::SpecialSeat(int line, int chair, int basePrice):MainHallSeat(line,chair,basePrice){}

GoldenCircleSeat::GoldenCircleSeat(int line, int chair, int basePrice):SpecialSeat(line,chair,basePrice){}
string GoldenCircleSeat::location() {
return  "Golden Circle-> " + Seat::location();
}
int GoldenCircleSeat::price() {
return (Seat::basePrice+MainHallSeat::mainHallSeatPrice+SpecialSeat::specialSeatPrice+goldenCircleSeatPrice);
}

DisablePodiumSeat::DisablePodiumSeat(int line, int chair, int basePrice):SpecialSeat(line,chair,basePrice){}
string DisablePodiumSeat::location() {
return  "Disable Podium-> " + Seat::location();
}
int DisablePodiumSeat::price() {
return disablePodiumSeatPrice;
}

RegularSeat::RegularSeat(const char& area, int line, int chair, int basePrice):MainHallSeat(line,chair,basePrice), area(area){}
string RegularSeat::location() {
return  "area: " + string(1,this->area) + ", " + Seat::location();
}

FrontRegularSeat::FrontRegularSeat(const char& area, int line, int chair, int basePrice):RegularSeat(area,line,chair,basePrice){}
string FrontRegularSeat::location() {
return  "Front-> " + RegularSeat::location();
}
int FrontRegularSeat::price() {
return (Seat::basePrice+MainHallSeat::mainHallSeatPrice+frontRegularSeatPrice);
}

MiddleRegularSeat::MiddleRegularSeat(const char& area, int line, int chair, int basePrice):RegularSeat(area,line,chair,basePrice){}
string MiddleRegularSeat::location() {
return  "Middle-> " + RegularSeat::location();
}
int MiddleRegularSeat::price() {
return (Seat::basePrice+MainHallSeat::mainHallSeatPrice+middleRegularSeatPrice);
}

RearRegularSeat::RearRegularSeat(const char& area, int line, int chair, int basePrice):RegularSeat(area,line,chair,basePrice){}
string RearRegularSeat::location() {
return  "Rear-> " + RegularSeat::location();
}
int RearRegularSeat::price() {
return (Seat::basePrice+MainHallSeat::mainHallSeatPrice);
}

