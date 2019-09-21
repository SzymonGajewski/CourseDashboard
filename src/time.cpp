#include "time.hpp"
#include <iostream>
#include<stdexcept>

day::day(int day)
{
    this->day_ = day;
}
month::month(int month)
{
    this->month_ = month;
}
year::year(int year)
{
    this->year_=year;
}
date::date( int    day,
            int  month,
            int   year)
    :   Day_(day),
        Month_(month),
        Year_(year)
{
    checkdate();
}
void date::checkdate()
{ 
      if(Day_.day_>31) throwError();
      if(Month_.month_>12) throwError(); 
        std::cout<<Day_.day_<<" "<<Month_.month_<<" "<<Year_.year_<<std::endl;
}
void date::throwError()
{
    throw  std::runtime_error("zle podana data");
}
date date::getDate()
{
    return *this;
}
sec::sec(int sec)
{
    sec_=sec;
}
min::min(int min)
{
    min_=min;
}
hour::hour(int hour)
{
    hour_=hour;
}
times::times( int sec,
            int min,
            int hour)
    :Sec_(sec),
    Min_(min),
    Hour_(hour)
{
    checktime();
}
void times::checktime()
{
    if(Sec_.sec_>60) throwError();
    if(Min_.min_>60) throwError();
    if(Hour_.hour_>23) throwError();
}

times times::getTime()
{
    return *this;
}
void times::throwError()
{
    throw  std::runtime_error("zle podana godzina");
}
