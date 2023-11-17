
//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//

/*
 *
 *	Linked List lab.
 *	- Build a library for singly linked list.
 *	- Replace the airport array in main with a Linked List.
 *  - sort the array.
 *
 */

#include "slist.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Airport {
public:
  char code[5];
  double longitude;
  double latitude;
};

double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int invalidAirports(linkedList *list, int length);

void simpleSortTotal(linkedList *list, int length);

int main() {
  ifstream infile;
  int i = 0;
  linkedList *airportList = new linkedList();
  int airportCount;
  Airport *a;
  infile.open("airport-codes_US.csv", ifstream::in);
  if (infile.is_open()) {
    int c = 0;
    char pH2[256];
    infile.getline(pH2, 256, '\n');
    while (infile.good()) {
      a = new Airport();
      char pH[100];
      char cNum[10];

      infile.getline(a->code, 256, ',');
      infile.getline(pH, 256, ',');
      infile.getline(pH, 256, ',');
      infile.getline(cNum, 256, ',');
      a->longitude = atof(cNum);
      infile.getline(cNum, 256, ',');
      a->latitude = atof(cNum);
      infile.getline(pH, 256, '\n');
      // cout << a->code << " long: " << a->longitude << " lat: " << a->latitude
      // << endl;
      airportList->add(a);

      /*
      if (!(c % 1000))
      {
          cout << airportArr[c]->code << " long: " << airportArr[c]->longitude
      << " lat: " << airportArr[c]->latitude <<  endl; cout <<
      airportArr[c+1]->code << endl; //" long: " << airportArr[c+1]->longitude
      << " lat: " << airportArr[c+1]->latitude <<  endl;
      }
      */
      a = nullptr;
      c++;
    }
    infile.close();
    airportCount = airportList->size();
    simpleSortTotal(airportList, airportCount);
    double austinLong = -97.6655;
    double austinLat = 30.2027;
    for (int c = 0; c < 300; c++) {
      cout << c << endl;
      Airport *a = ((Airport *)airportList->get(c));
      cout << a->code << " Distance: "
           << (distanceEarth(a->latitude, a->longitude, austinLat,
                             austinLong)) /
                  1.60934
           << " miles" << endl
           << endl
           << endl;
    }

  } else {
    cout << "Error opening file";
  }
}

#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) { return (deg * pi / 180); }

//  This function converts radians to decimal degrees
double rad2deg(double rad) { return (rad * 180 / pi); }

/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r) / 2);
  v = sin((lon2r - lon1r) / 2);
  return 2.0 * earthRadiusKm *
         asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

/*
        Provide sort routine on linked list

*/
void simpleSortTotal(linkedList *list, int length) {
  double austinLong = -97.66989899;
  double austinLat = 30.19449997;
  for (int i = 0; i < length; i++) {
    Node *a = list->getNode(0);
    Node *b = list->getNode(1);
    for (int j = 0; j < length - 1; j++) {
      Airport *data1 = (Airport *)a->data;
      Airport *data2 = (Airport *)b->data;
      if (distanceEarth(data1->latitude, data1->longitude, austinLat,
                        austinLong) > distanceEarth(data2->latitude,
                                                    data2->longitude, austinLat,
                                                    austinLong)) {
        list->swap(a, b);
      }
      a = a->next;
      b = b->next;
    }
  }
}