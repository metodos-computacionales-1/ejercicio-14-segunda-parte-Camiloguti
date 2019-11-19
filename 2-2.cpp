#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


// variables constantes globales
const double m=2.0;
const double x=2.0;
const double v=3.0;
const double k=100.0;
const double lambda =1.0;
const double coef =0.2;
const double DeltaT=0.01;
const double t_0=0.0;



// declaracion de funciones

double fy0(double t, double y0, double y1); // derivada de y0
double fy1(double t, double y0, double y1); // derivada de y1

void rk(double t, double h, double & y0, double & y1); // metodo de runge kutta 4 orden 


// metodo de runge kutta 4 orden

double fy0(double t, double y0, double y1)
{
  return y1;
}

double fy1(double t, double y0, double y1)
{
  return (-k/m)*pow(y0, lambda)-coef*y1;
}



void rk(double t, double h, double & y0, double & y1) // metodo de runge kutta 4 orden
{
  double ky10, ky11, ky20, ky21, ky30, ky31, ky40, ky41;
	
  ky10 = h*fy0(t, y0, y1);
  ky11 = h*fy1(t, y0, y1);
  ky20 = h*fy0(t+h/2, y0 + ky10/2, y1 + ky11/2);
  ky21 = h*fy1(t+h/2, y0 + ky10/2, y1 + ky11/2);
  ky30 = h*fy0(t+h/2, y0 + ky20/2, y1 + ky21/2);
  ky31 = h*fy1(t+h/2, y0 + ky20/2, y1 + ky21/2);
  ky40 = h*fy0(t + h, y0 + ky30, y1 + ky31);
  ky41 = h*fy1(t + h, y0 + ky30, y1 + ky31);
	
  y0 = y0 + (1.0/6.0)*(ky10 + 2*ky20 + 2*ky30 + ky40);
  y1 = y1 + (1.0/6.0)*(ky11 + 2*ky21 + 2*ky31 + ky41);
}
