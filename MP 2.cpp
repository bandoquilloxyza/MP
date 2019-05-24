//Create a program that would compute the following values based on the given sides of the triangle. Let the measurements of the sides be a user-input.
#include <iostream>
#include <cmath>
#define PI 3.14159265
using namespace std;
 
double angle(double a,double b,double c)
{
	double theta = acos((pow(a,2)+pow(b,2)-pow(c,2))/(2*a*b))*180/PI;
	return theta;
}

int main()
{
	double a,b,c;
	double A,B,C;
	double perim, area, p;
	double apothem, circumcenter;

	cout<<"ENTER 1st side: "; 
	cin>>a;
	cout<<"ENTER 2nd side: "; 
	cin>>b;
	cout<<"ENTER 3rd side: "; 
	cin>>c;

//A. Compute for all interior angles.
	if(a+b>c && b+c>a && c+a>b){
		A=angle(b,c,a);
		B=angle(c,a,b);
		C=180-A-B;

		cout<<endl<<"Angle A: "<<A<<endl;
		cout<<"Angle B: "<<B<<endl;
		cout<<"Angle C: "<<C<<endl<<endl;
		
//B. Classify whether scalene, isosceles, or equilateral.
		//if all three sides are equal	
		if(a == b && a == c && b == c)
		  cout<<"Equilateral Triangle"<<endl<<endl;
		
		//all sides are different, no same length
		else if(a != b && a != c && b != c)
		  cout<<"Scalene Triangle"<<endl<<endl;

        //only two sides are equal		  
		else
		  cout<<"Isosceles Triangle"<<endl<<endl;
		
//C. Determine the area and perimeter.
		perim = a + b + c;
		p=.5*perim;
		area=sqrt(p *(p - a)*(p - b)*(p - c)); 
		
		cout<<"Area: "<<area<<endl;
		cout<<"Perimiter: "<<perim<<endl<<endl;
		
//D. Classify whether acute triangle, right triangle, or obtuse triangle.	
        //all angles are acute/ less than 90 degrees
		if(A>0 && A<90 && B>0 && B<90 && C>0 && C<90)
			cout<<"Acute Triangle"<<endl<<endl;
		
		//one angle is obtuse/ more than 90 degrees	
		else if(A>90 || B>90 || C>90)
			cout<<"Obtuse Triangle"<<endl<<endl;
			
		//one angle is a right angle/90 degrees	
		else if(a*a+b*b==c*c || b*b+c*c==a*a || c*c+a*a==b*b)
			cout<<"Right Triangle"<<endl<<endl;
	
//E. Compute for length of apothem and circumcenter.	
		circumcenter = (a*b*c) / sqrt(((a+b+c)*(b+c-a)*(c+a-b)*(a+b-c)));
		apothem = 2*area/perim;
		
		cout<<"Length of Apothem: "<<apothem<<endl;
		cout<<"Circumcenter: "<<circumcenter<<endl<<endl;
	}
	//if entered does not fit requirements
	else
		cout<<"Not a triangle";

	return 0;
}
