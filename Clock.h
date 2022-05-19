#pragma once
#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <cmath>
using namespace std;

/*!
 @class Clock
 @Author Tyler Evans
 @discussion class is made to structure the data for a clock
 @brief basic clock object
 */
class Clock{
private:
    //things needed for a basic clock
    string clockId = "";
    double second = 0.0;
    double min = 0.0;
    double hour = 0.0;
    double day = 0.0;
    double year = 0.0;
    double secTick = 0.0;
    const double SECONDS_MILL = 1000000;
    
    //double leapYr = 0.0;
    bool LEAP = true;
    bool clockState = true;
    //things needed for addtional features
    double secConst = 1.0;
    double minSec = 60.0;
    // 60 seconds for one min
    double minHour = 60.0;
    //60 min for one hour
    double dayHours = 24.0;
    // 24 hours for one day
    double dayYear = 365.0;
    //365.25.. days normally but rounded down so 365.0
    double leapYear = 366.0;
public:
    //constructor  and member functions
    
    Clock();
    //clock constructor basic setup
    Clock(double yr, double dy, double hr, double mn);
    //clock detailed set up
    Clock(double yr, double dy, double hr, double mn, double sc);
    //clock detailed constructor all details
    Clock(double yr, double dy, double hr, double mn, double sc, double dayToYear, double hoursToDay, double hoursToMin, double secToMin, bool leapYr);
    //end of all the constructor functions
    
    //member functions
    /*!
     @function convertTime
     @brief converts clock times to another clock
     @discussion Makes the current object the time in acordence with the other so you can have time go well with another
     */
    void convertTime(Clock &a);
    
    /*!
     @Function Tick
     @brief starts the clock
     @discussion starts the clock with its class methods
     */
    void Tick();
    
    /*!
     @function Tick
     @brief starts clock with seed
     @param tic tic
     @discussion starts the clock with a time seed
     */
    void Tick(double tic);
    
    /*!
     @function Stop
     @brief stops the clock
     @discussion stops the clock 
     */
    void Stop();
    
    /*!
     @function Start
     @brief starts the clock
     @discussion starts the clock*/
    void Start();
    
    /*!
        @function isLeapYear
     @brief returns if leap year
     @discussion detrmines if it is a leap year
     */
    
    bool static isLeapYear(double yr);
    
    
    //adding functions
    
    /*!
     @function addSec
     @brief adds one second
     @discussion will add a second and add if seconds reach a certain level
     */
    
    void addSec();
    /*!
     @function addMin
     @brief adds a min
     @discussion used within the addSec method for automatically adding up the intended seconds for an hour
     */
    
    void addMin();
    /*!
     @function addHour
     @brief adds a hour
     @discussion used within the addMin method for automatically adding up the intended hour
     */
    
    void addHour();
    /*!
     @function addDay
     @brief is used to add a day to the class object
     @discussion used within the addHour function automatically adding up to the intented amount of the day
     */
    
    void addDay();
    /*!
     @function addYear
     @brief adds one year to the class object
     @discussion used within the addDay function it automatically is set adding on years until the data type is overloaded
     */
    
    void addYear();
    //seting functions
    //typical time seting
    
    /*!
     @function setSec
     @brief sets the second
     @discussion sets the second of the class object
     */
    void setSec(double sec);
    /*!
     @function setMin
     @brief sets the min of the function
     @discussion sets the min of the clas object
     */
    
    void setMin(double m);
    /*!
     @function setHour
     @brief sets the hour
     @discussion sets the hour of the class object
     */
    
    void setHour(double h);
    /*!
     @function setDay
     @brief sets the day
     @discussion sets the day of the class object
     */
    
    void setDay(double d);
    /*!
     @function setYears
     @brief sets the year
     @discussion declares the year of the class object
     */
    
    void setYear(double y);
    
    /*!
     @function setLeap
     @brief sets if thier is a leap year
     @discussion sets the condition if leap year is needed
     */
    void setLeap(bool t);
    //addtional functionaility
    /*!
     @function setSecConst
     @brief sets the second const value
     @discussion Somtimes clocks are diffrent sometimes a second is delayed...
     */
    void setSecConst(double s);
    /*!
     @function setMinSec
     @brief sets the minSec conversion
     @discussion sets the min sec conversion
     */
    void setMinSec(double s);
    
 
    /*!
     @function setSecHours
     @brief sets the second to hours conversion
     @discussion sets the second to hours conversion
     */
    
    void setSecHours(double h);
    /*!
     @function setDayHours
     @brief sets the dayHour conversion
     @discussion sets the dayHour conversion
     */
    
    void setDayHours(double d);
    /*!
     @function setDayYear
     @brief sets the day to year conversion used in the class
     @discussion sets the day to year conversion
     */
    
    void setDayYear(double y);
    /*!
     @function setSecTick
     @brief sets the clock tick
     @discussion WARNING smaller ticks makes more usage of cpu method sets the tick for the clock
     */
    void setSecTick(double tic);
    //getter functions
    
    /*!
     @function getSec
     @brief returns sec
     @discussion returns sec of the class object
     */
    
    double getSec();
    /*!
     @function getMin
     @brief returns min
     @discussion returns the min of the class object
     */
    
    double getMin();
    /*!
     @function getHour
     @brief returns the hour
     @discussion returns the day of the clock object
     */
    
    double getHour();
    /*!
     @function getDay
     @brief returns the day
     @discussion returns the day of the clock object
     */
    
    double getDay();
    /*!
     @function getYear
     @brief returns the year
     @discussion returns the year of the clock object
     */
    
    double getYear();
    /*!
     @function getSecConst
     @brief returns the second const
     @function returns the second const*/
    double getSecConst();
     /*!
      @function getMinSec
      @brief retrurns the minSec on the clock
      @discussion returns the minSec of the given class object
      */
    
    double getMinSec();
    /*!
     @function getMinHours
     @brief returns the minHours conversion
     @discussion returns the minHour conversion on the hourSec double
     */
    double getMinHours();
    /*!
     @function getDayHours
     @brief returns the dayHours conversion
     @discussion returns the dayHour conversion on the dayHour double
     */
    double getDayHours();
    /*!
     @function getDayYear
     @brief returns the dayYear conversion
     @discussion returns the dayYear of the clock object
     */
    double getDayYear();
    /*!
     @function setId
     @brief sets the clock id
     @discussion sets id for the clock object in order to differ class objects providing futher unique ability
     */
    void setId(string str);
};
