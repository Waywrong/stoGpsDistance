#include <stdlib.h>
#include <string>
#include <iostream>
#include "gpsDistance.h"
#include "LocationGPS.h"
using namespace std;

int main()
{
	//LocationGPS locGPS1(25.077216,121.232124);//airport
	//LocationGPS locGPS2(25.0345676,121.5571208);//office

	// LocationGPS locGPS1(25.0339639,121.56447219999995);//101
	// LocationGPS locGPS2(25.035352,121.56618800000001);//att4fun
	//LocationGPS locGPS2(25.0366148,121.56666719999998);//a9

	LocationGPS locGPS1(85.001,104.000);
	LocationGPS locGPS2(85.000,104.000);

	cout<<"p1:"<<locGPS1<<endl;
	cout<<"p2:"<<locGPS2<<endl;
#if 0
	double dDis = distanceGPS(locGPS1._lat,locGPS1._lng,locGPS2._lat,locGPS2._lng,'K');
	cout<<"distance:"<<dDis<<" km"<<endl;
#else
	double dDis = locGPS1.distanceGPS(locGPS2,'K');
	cout<<"distance:"<<dDis<<" km"<<endl;
#endif
    return 0;
}


// 101-att	231.734m(my)->208.37(google)
// att-a9	148.478-->140.04

//1.direct rad distance看是否正比於distanceGPS
