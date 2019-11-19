#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

// variables constantes globales
const float m=5.0;
const float x=3.0;
const float v=2.0;
const float k=50.0;
float dT;
float t0=0.0;

// funciones
void Euler_m(float m,float x, float v, float k, float dT,string name);


void Euler_m(float m,float x, float v, float k, float dT, string name)
{
  ofstream outfile;
    
  outfile.open(name);
    
  float yn=1.0;
    
    
  for(t0=0.0 ;t0<=17.0;t0+=dT)
  {
      double x_n=x;
      
      double v_n=v;
      
      
      x += (dT*v_n);
      
      v -= (dT*(k/m)*x_n);
      
      outfile<<t_0<<"  "<<x<<"  "<<v<<"\n";
  }  
   outfile.close();
}

