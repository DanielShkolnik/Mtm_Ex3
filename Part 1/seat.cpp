#include "seat.h"


// Implement of the function gets const char* and returns string
const char* NoPrice::what() const noexcept{
return  "Not For Sale !";
}

// Implement of the function that returns string in a specific format of location
string Seat::location(){
    return  "line: " + std::to_string(this->line) + ", chair: " + std::to_string(this->chair);
}

// Implement of the function constructs an object of Seat
Seat::Seat(int line, int chair, int basePrice): line(line), chair(chair), basePrice(basePrice){}

// Implement of the function constructs an object of GreenRoomSeat
GreenRoomSeat::GreenRoomSeat(int line, int chair): Seat(line,chair){}

// Implement of the function throws exception
int GreenRoomSeat::price() {
throw NoPrice();
}

// Implement of the function that returns string
string GreenRoomSeat::location() {
return  "Green Room-> " + Seat::location();
}

// Implement of the function constructs an object of MainHallSeat
MainHallSeat::MainHallSeat(int line, int chair, int basePrice):Seat(line,chair,basePrice){}

// Implement of the function constructs an object of SpecialSeat
SpecialSeat::SpecialSeat(int line, int chair, int basePrice):MainHallSeat(line,chair,basePrice){}

// Implement of the function constructs an object of GoldenCircleSeat
GoldenCircleSeat::GoldenCircleSeat(int line, int chair, int basePrice):SpecialSeat(line,chair,basePrice){}

// Implement of the function that returns string
string GoldenCircleSeat::location() {
return  "Golden Circle-> " + Seat::location();
}

// Implement of the function that calculate and return int the indicates the price of this specific seat
int GoldenCircleSeat::price() {
return (Seat::basePrice+MainHallSeat::mainHallSeatPrice+SpecialSeat::specialSeatPrice+goldenCircleSeatPrice);
}

// Implement of the function constructs an object of DisablePodiumSeat
DisablePodiumSeat::DisablePodiumSeat(int line, int chair, int basePrice):SpecialSeat(line,chair,basePrice){}

// Implement of the function that returns string
string DisablePodiumSeat::location() {
return  "Disable Podium-> " + Seat::location();
}

// Implement of the function that calculate and return int the indicates the price of this specific seat
int DisablePodiumSeat::price() {
return disablePodiumSeatPrice;
}

// Implement of the function constructs an object of RegularSeat
RegularSeat::RegularSeat(const char& area, int line, int chair, int basePrice):MainHallSeat(line,chair,basePrice), area(area){}

// Implement of the function that returns string
string RegularSeat::location() {
return  "area: " + string(1,this->area) + ", " + Seat::location();
}

// Implement of the function constructs an object of FrontRegularSeat
FrontRegularSeat::FrontRegularSeat(const char& area, int line, int chair, int basePrice):RegularSeat(area,line,chair,basePrice){}

// Implement of the function that returns string
string FrontRegularSeat::location() {
return  "Front-> " + RegularSeat::location();
}

// Implement of the function that calculate and return int the indicates the price of this specific seat
int FrontRegularSeat::price() {
return (Seat::basePrice+MainHallSeat::mainHallSeatPrice+frontRegularSeatPrice);
}

// Implement of the function constructs an object of MiddleRegularSeat
MiddleRegularSeat::MiddleRegularSeat(const char& area, int line, int chair, int basePrice):RegularSeat(area,line,chair,basePrice){}

// Implement of the function that returns string
string MiddleRegularSeat::location() {
return  "Middle-> " + RegularSeat::location();
}

// Implement of the function that calculate and return int the indicates the price of this specific seat
int MiddleRegularSeat::price() {
return (Seat::basePrice+MainHallSeat::mainHallSeatPrice+middleRegularSeatPrice);
}

// Implement of the function constructs an object of RearRegularSeat
RearRegularSeat::RearRegularSeat(const char& area, int line, int chair, int basePrice):RegularSeat(area,line,chair,basePrice){}

// Implement of the function that returns string
string RearRegularSeat::location() {
return  "Rear-> " + RegularSeat::location();
}

// Implement of the function that calculate and return int the indicates the price of this specific seat
int RearRegularSeat::price() {
return (Seat::basePrice+MainHallSeat::mainHallSeatPrice);
}

