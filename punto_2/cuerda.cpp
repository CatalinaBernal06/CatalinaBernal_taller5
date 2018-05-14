#include <iostream>
#include <cmath>

double valor_u(double x);

int main(){
    double x = 0.0;
    double T = 40.0;
    double rho = 10.0;
    double L = 100.0;
    int t_max = 200;
    double c = sqrt(T/rho);
    double delta_x = 0.001;
    double delta_t = 0.0001;
    
    double k = (c*c)*(delta_t * delta_t) /((delta_x*delta_x));
    int N_x = L/delta_x +1 ;
    int N_t = t_max/delta_t;
    
    double *u = new double[N_x];
    double *u_past = new double[N_x];
    double *u_jp = new double[N_x];
    
    
    for(int i=0; i<N_x ; i++){
        x =i*delta_x;
        u[i] = valor_u(x);
        u_past[i] = valor_u(x);
        u_jp[i] = valor_u(x);
        
        std::cout << u_past[i] << " " ;
    }
    
    std::cout << std::endl;
    
    //Extremos fijos
    u[0] = 0;
    u[N_x - 1] = 0;
    
    int j = 1;
    int t = 0;
    while(t<t_max){
        
        for(int i = 1; i< N_x-1; i++){
            std::cout << u_past[i] << " ";
        }
        std::cout << std::endl;
        
        for( int i=1; i<N_x-1 ; i++){
            if(j==1){
                u[i] = (k/2)*(u_past[i+1] - 2*u_past[i] + u_past[i-1]) + u_past[i];
            }
            else{
                u[i] = k * (u_past[i+1] - 2*u_past[i] + u_past[i-1]) - u_jp[i] + 2*u_past[i] ;
            }
        }
    
        t +=1;
        
        for (int i = 1; i<N_x - 1 ; i++){
            u_jp[i] = u_past[i];
            u_past[i] = u[i];
            
    }
        j +=1;
    }
    
    
    return 0;
}


double valor_u(double x){
    double L = 100.0;
    if(x <= 0.8*L){
        return 1.25*x/L;
    }
    else{
        return 5.0 - (5.0*x/L);
    }
}
