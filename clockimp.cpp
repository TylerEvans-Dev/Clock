#include "Clock.h"
/*
 Constructors
 */
Clock::Clock(){
    //things needed for a basic clock
    second = 0.0;
    min = 0.0;
    hour = 0.0;
    day = 0.0;
    year = 0.0;
    //things needed for addtional features
    minSec = 60.0;
    // 60 seconds for one min
    minHour = 60.0;
    //60 min for one hour
    dayHours = 24.0;
    // 24 hours for one day
    dayYear = 365.0;
    //365.25.. days normally but rounded down so 365.0
}

Clock::Clock(double yr, double dy, double hr, double mn){
    min = mn;
    hour = hr;
    day = dy;
    year = yr;
}

Clock::Clock(double yr, double dy, double hr, double mn, double sc){
    second = sc;
    min = mn;
    hour = hr;
    day = dy;
    year = yr;
}

Clock:: Clock(double yr, double dy, double hr, double mn, double sc, double dayToYear, double hoursToDay, double hoursToMin, double secToMin, bool leapYr){
    second = sc;
    min = mn;
    hour = hr;
    day = dy;
    year = yr;
    dayYear = dayToYear;
    dayHours = hoursToDay;
    minHour = hoursToMin;
    minSec = secToMin;
}
/*
 END OF CONSTRUCTORS
 */

/*
 HELPER FUNCTIONS
 */
void Clock::convertTime(Clock &a){
    //year section here
    year = (a.getYear() * a.getDayYear()) / dayYear;
    //day section here
    day = (a.getDay() * a.getDayHours()) / dayHours;
    //hour section here
    hour = (a.getHour() * a.getMinHours()) / minHour;
    //mins here
    min = (a.getMin() * a.getMinSec()) / minSec;
    //sec here
    second = (a.getSec() * a.getSecConst()) / secConst;
}
bool Clock::isLeapYear(double yr){
    //help from wiki how for math
    int leapYr = (int)yr;
    const int check1 = 4;
    const int check2 = 100;
    const int check3 = 400;
    if((((leapYr % check2) != 0) && ((leapYr % check1) == 0))) {
        return true;
    }
    else{
        if(leapYr % check2 == 0 && leapYr % check3 == 0){
            return true;
        }
        return false;
    }
}
void Clock::Tick(){
    while(clockState == true){
        usleep(1 * SECONDS_MILL);
        addSec();
        cout << "CLOCK_ID:_ " << clockId << endl;
        cout << "Year: "<< year << " Day: " << day << " Hour: " << hour << " Min: " << min << " Sec: " << second << endl;
    }
}
void Clock::Tick(double tic){
    while(clockState == true){
        secConst = tic;
        usleep(tic * SECONDS_MILL);
        addSec();
        cout << "CLOCK_ID:_ " << clockId << endl;
        cout << "Year: "<< year << " Day: " << day << " Hour: " << hour << " Min: " << min << " Sec: " << second << endl;
    }
}
void Clock::Stop(){
    clockState = false;
}
void Clock::Start(){
    clockState = true;
    Tick();
}
/*
 time function
 */
void Clock::addSec(){
    second += 1;
    if(second == minSec){
        addMin();
        second = 0;
    }
}

void Clock::addMin(){
    min += 1;
    if(min == minHour){
        addHour();
        min = 0;
    }
}

void Clock::addHour(){
    hour += 1;
    if(hour == dayHours){
        addDay();
        hour = 0;
    }
}
void Clock::addDay(){
    day += 1;
    if((Clock::isLeapYear(year) == false && LEAP == true)){
        if(day == dayYear){
            day  = 0;
            addYear();
        }
    }
        else{
            if(day >= dayYear){
                day =0;
                addYear();
            }
        }
}
void Clock::addYear(){
    year += 1;
}
/*
 setter functions
 */

void Clock::setLeap(bool t){
    LEAP = t;
}

void Clock::setSec(double sec){
    second = sec;
}

void Clock::setMin(double m){
    min = m;
}

void Clock::setHour(double h){
    hour = h;
}

void Clock::setDay(double d){
    day = d;
}

void Clock::setYear(double y){
    year = y;
}

void Clock::setSecConst(double a){
    secConst = a;
}

void Clock::setMinSec(double s){
    minSec = s;
}

void Clock::setSecHours(double h){
    minHour = h;
}

void Clock::setDayHours(double d){
    dayHours = d;
}

void Clock::setDayYear(double y){
    dayYear = y;
}
void Clock::setSecTick(double tic){
    secTick = tic;
}
/*
 getter functions
 */

double Clock::getSec(){
    return second;
}

double Clock::getMin(){
    return min;
}

double Clock::getHour(){
    return hour;
}

double Clock::getDay(){
    return day;
}

double Clock::getYear(){
    return year;
}
double Clock::getSecConst(){
    return secConst;
}
double Clock::getMinSec(){
    return minSec;
}

double Clock::getMinHours(){
    return minHour;
}

double Clock::getDayHours(){
    return dayHours;
}

double Clock::getDayYear(){
    return dayYear;
}

void Clock::setId(string str){
    clockId = str;
}
