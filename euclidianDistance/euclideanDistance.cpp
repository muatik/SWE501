#include "iostream"
#include "cmath"
using namespace std;

struct Point
{
	float x;
	float y;
};

float calculateEuclideanDistance(Point a, Point b)
{
	// this function calculates euclidean distance between point a and point b.
	// calculated result will be returned.
	
	// Formula: square root of ( (A.X - B.X)^2 + (A.Y - B.Y)^2 )
	
	float diffX, diffY;
	float diffXSquare, diffYSquare;
	float distance;

	diffX = a.x - b.x;
	diffXSquare = pow(diffX, 2);

	diffY = a.y - b.y;
	diffYSquare = pow(diffY, 2);

	distance = sqrt(diffXSquare + diffYSquare);
	return distance;
}

int main()
{
	cout << "This program calculates Euclidean distance. \n"
		<< "For more information please follow the link: \n"
		<< "https://en.wikipedia.org/wiki/Euclidean_distance\n";

	// two points are requred for euclidian distance calculation.
	Point a;
	Point b;

	// each point has x and y values. user must enter them.
	cout << "\nEnter PointA.X: ";
	cin >> a.x;
	cout << "Enter PointA.Y: ";
	cin >> a.y;


	cout << "Enter PointB.X: ";
	cin >> b.x;
	cout << "Enter PointB.Y: ";
	cin >> b.y;

	cout << "The distance is " << calculateEuclideanDistance(a, b) << endl;
	return 0;
}