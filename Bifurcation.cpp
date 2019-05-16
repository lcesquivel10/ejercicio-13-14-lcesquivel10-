#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;

void Bifurcation(double FD){
  int N_t=20000;
  int N_trans=18000;

  double dt = 0.04;
  double t;

  double g=9.8;
  double l=9.8;
  double omega_D=2./3.;
  double q=0.5;
  double T_MAX=0.01*N_t;

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
  int I,J = 0;
  int counter = 0;
  double Theta_Max = 0;
  double Theta_Int = 0;
  for(int i=N_trans;i<N_t;i++){
    if(abs((i-N_trans)*dt-(2*n)*M_PI/omega_D) < dt/2){
      I=J;
      J=i;
      n = n + 1;
    }else{
      continue;
    }
    Theta_Max = 0;
    for(int i = I; i < J;i++){
      if(abs(omega[i])<1e-1){
        if(theta[i]>Theta_Max){
          Theta_Max=theta[i];
        }
      }
    }
    if(counter == 1){
      Theta_Int = Theta_Max;
    }
    if(abs(Theta_Int - Theta_Max) < 1e-2 && (counter > 1)){
      break;
    }
    if(counter >= 1){
      cout << FD << '\t' << Theta_Max << endl;
    }
    counter = counter + 1;
  }
}


int main(void){
  double FD_min = 1.35;
  double FD_max = 1.485;
  int N = 500;
  double D_FD = abs(FD_max - FD_min)/N;
  for(int i = 0; i < N; i++){
    Bifurcation(FD_min + i*D_FD);
  }

  return 0;
}
