#pragma once

#include <chrono>
#include<stdexcept>



struct day
{   
    day(int);
     int day_;
};

struct month
{
    month(int);
    int month_;
};

struct year
{
     year(int);
      int year_;
};

class date
{
public:
    date(int    Day_,
         int Month_,
         int   Year_);
    date getDate();
    
private:
    
    
    day Day_;
    month Month_;
    year Year_;

    void checkdate();
    void throwError();

};
struct sec
{
    int sec_;
    sec(int);
};
struct min 
{
    int min_;
    min(int);
};
struct hour
{
    int hour_;
    hour(int);
};

class times
{
public:
    times(int    Sec_,
         int    Min_,
         int    Hour_);
    times getTime();
    
private:    
    
    sec Sec_;
    min Min_;
    hour Hour_;

    void checktime();
    void throwError();

};

