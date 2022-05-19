/*Tyler Evans
 * 25.6.2021
 * To test out threading function and function pointers
 */
#include <iostream>
#include <string>
//here is the lib
#include <thread>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include "Clock.h"

void checkIf();

using namespace std;
int main(){
    //Credit to bozhu for helping me understand threading in c++
    Clock * t = new Clock();
    Clock * z = new Clock();
    Clock  d = Clock();
    t->setId("CLOCK 1");
    z->setDay(55);
    z->setId("CLOCK 2");
    z->setMin(3);
    d.setId("Clock 3");
    thread th(&Clock::Start, t);
    thread re(&Clock::Start, d);
    thread se(&Clock::Start, z);
    thread o(checkIf);
    th.join();

  /*
   1.work on threading see if function pointer works with methods
   3.see if you can get one clock to run with another
   4.see if you can get a clock to stop after a certain period of time
   5.see if you can use the system time
   */
    cout << "Thank you for your time\n";
    delete t;
    delete z;
    return 0;
}
void checkIf(){
    cin.get();
}
