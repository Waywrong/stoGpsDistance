#pragma once
#include <iostream>
#include <math.h>

#define pi 3.14159265358979323846
using namespace std;

class LocationGPS
{
	public:
		double _lat;
		double _lng;

		LocationGPS(){_lat=_lng=0;}

		LocationGPS(double lat, double lng){_lat = lat; _lng = lng;}

		double deg2rad(double deg) {
		  //return (deg * pi / 180);
		  return (deg * 0.017453293);
		}

		double rad2deg(double rad) {
		  //return (rad * 180 / pi);
		  return (rad * 57.295779513);
		}
		
//Def: South latitudes are negative, east longitudes are positive 
		double distanceGPS(LocationGPS locGPS2, char unit) {
		  double theta, dist;
		  if ((_lat == locGPS2._lat) && (_lng == locGPS2._lng)) {
		    return 0;
		  }
		  else {
		    theta = _lng - locGPS2._lng;
		    dist = sin(deg2rad(_lat)) * sin(deg2rad(locGPS2._lat)) + cos(deg2rad(_lat)) * cos(deg2rad(locGPS2._lat)) * cos(deg2rad(theta));
		    dist = acos(dist);
		    dist = rad2deg(dist);
		    switch(unit) {
		      case 'M'://statute miles
		      	dist = dist * 60 * 1.1515;
		        break;
		      case 'K'://kilometers
		      	//dist = dist * 60 * 1.1515 * 1.609344;
		        dist = dist * 111.18957696;
		        break;
		      case 'N'://nautical miles
		        dist = dist * 60 * 1.1515 * 0.8684;
		        break;
		    }
		    return (dist);
		  }
		}

		friend ostream& operator<<(ostream& os, const LocationGPS& LocationGPS)
        {
            os<<"<"<<LocationGPS._lat<<","<<LocationGPS._lng<<">";
            return os;
        }
};