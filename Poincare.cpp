#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;

void Poincare(double FD){
  int N_t=200000;
  int N_trans=100000;

  double dt = 0.04;
  double t;

  double g=9.8;
  double l=9.8;
  double omega_D=2./3.;
  double q=0.5;
  double T_MAX=0.04*N_t;

  double omega[N_t];
  double theta[N_t];

  omega[0]=0.;
  theta[0]=0.2;


  for(int i=0;i<N_t;i++){
    t = (i+1)*dt;
    omega[i+1] = omega[i] - (g/l)*sin(theta[i])*dt - q*omega[i]*dt + FD*sin(omega_D*t)*dt;
    theta[i+1] = theta[i] + omega[i+1]*dt;
    if(theta[i+1] > M_PI){
      theta[i+1]=theta[i+1]-2.*M_PI;
    }else if(theta[i+1] < -M_PI){
      theta[i+1]=theta[i+1]+2.*M_PI;
    }
  }
  int n=1;
  ofstream MiData("Poincare_"+to_string(FD)+".dat");
  for(int i=0;i<N_t;i++){
    if(abs((i)*dt-(2*n)*M_PI/omega_D) < dt/2){
      MiData << theta[i] << '\t' << omega[i] << '\t' << i*dt << endl;
      n = n + 1;
    }
  }
}


int main(void){
  Poincare(1.4);
  Poincare(1.44);
  Poincare(1.465);
  return 0;
}

