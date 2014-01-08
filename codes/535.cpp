#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<cmath>
#define pi 3.141592653589793
#define r 6378

using namespace std;

struct point{
public:
	double la,ln;
	point() {}
	point(double lat, double lon){
		la = lat;
		ln = lon;
	}
};

double sDist(double lat1, double long1, double lat2, double long2){
	return acos(sin(lat1)*sin(lat2) + cos(lat1)*cos(lat2)*cos(long1)*cos(long2) + cos(lat1)*cos(lat2)*sin(long1)*sin(long2))*r;
}

int main(){
	map<string,point> cities;
	string city;

	while(true){
		cin >> city;
		if(city=="#")
			break;

		double lat, lon;
		scanf("%lf %lf\n",&lat,&lon);
		lat = lat*pi/180;
		lon = lon*pi/180;
		cities[city] = point(lat,lon);
	}

	while(true){
		string c1, c2;
		cin >> c1 >> c2;
		if(c1=="#" && c2=="#")
			break;
			
		cout << c1 << " - " << c2 << endl;
		if(!cities.count(c1) || !cities.count(c2)){
			printf("Unknown\n");
		}
		else if(c1 == c2){
			printf("0 km\n");
		}
		else{
			point city1 = cities[c1];
			point city2 = cities[c2];
			double dist = sDist(city1.la,city1.ln,city2.la,city2.ln);
			printf("%d km\n",(int)(dist+0.5));
		}
	}
	return 0;
}
