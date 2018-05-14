#include <iostream>
#include <math.h>

double q1_punto(double p1);
double q2_punto(double p2);
double p1_punto(double q1);
double p2_punto(double q1, double q2);
//double valor_k(double x_i, double f_i);


int main(){
    double delta_t = 0.006;
    int t_total = 3000;
    double a = 1/(2*sqrt(2));
    int N_t = t_total/delta_t;
    
    // cond iniciales
    double q1_past = a;
    double q2_past = -1*a;
    double p1_past = 0;
    double p2_past = 0;
    
    double q1;
    double q2;
    double p1;
    double p2;
    
    double t = 0;
    while(t<N_t){
        
        double k1_q1 = q1_punto(p1_past);
        double k1_q2 = q2_punto(p2_past);
        double k1_p1 = p1_punto(q1_past);
        double k1_p2 = p2_punto(q1_past, q2_past);
        
        double k2_q1 = q1_punto(p1_past + (delta_t/2.0)*k1_p1);
        double k2_q2 = q2_punto(p2_past + (delta_t/2.0)*k1_p2);
        double k2_p1 = p1_punto(q1_past + (delta_t/2.0)*k1_q1);
        double k2_p2 = p2_punto(q1_past + (delta_t/2.0)*k1_q1, q2_past + (delta_t/2.0)*k1_q2);
        
        double k3_q1 = q1_punto(p1_past + (delta_t/2.0)*k2_p1);
        double k3_q2 = q2_punto(p2_past + (delta_t/2.0)*k2_p2);
        double k3_p1 = p1_punto(q1_past + (delta_t/2.0)*k2_q1);
        double k3_p2 = p2_punto(q1_past + (delta_t/2.0)*k2_q1, q2_past + (delta_t/2.0)*k2_q2);
        
        double k4_q1 = q1_punto(p1_past + (delta_t*k3_p1));
        double k4_q2 = q2_punto(p2_past + (delta_t*k3_p2));
        double k4_p1 = p1_punto(q1_past + (delta_t*k3_q1));
        double k4_p2 = p2_punto(q1_past + (delta_t*k3_q1), q2_past + (delta_t*k1_q2));
        
        double k_q1 = (delta_t/6.0)*(k1_q1 + 2*k2_q1 + 2*k3_q1 + k4_q1);
        double k_q2 = (delta_t/6.0)*(k1_q2 + 2*k2_q2 + 2*k3_q2 + k4_q2);
        double k_p1 = (delta_t/6.0)*(k1_p1 + 2*k2_p1 + 2*k3_p1 + k4_p1);
        double k_p2 = (delta_t/6.0)*(k1_p2 + 2*k2_p2 + 2*k3_p2 + k4_p2);
        
        q1 = q1_past + k_q1;
        q2 = q2_past + k_q2;
        p1 = p1_past + k_p1;
        p2 = p2_past + k_p2;
        
        if(((q1_past<0) && (q1>0)) || ((q1_past>0) && (q1<0))){
            std::cout << q2 << " " << p2 << std::endl;
        }
     
        q1_past = q1;
        q2_past = q2;
        p1_past = p1;
        p2_past = p2;
        
        t += delta_t;
    }
    return 0;
        
}

double q1_punto(double p1){
    return p1;
}

double q2_punto(double p2){
    return p2;
}

double p1_punto(double q1){
    double epsilon = 10e-3;
    double deno = (4*q1*q1) + (epsilon*epsilon);
    double deno_pot = pow(deno, 3/2);
    return (-2*q1)/deno_pot;
}

double p2_punto(double q1, double q2){
    double epsilon = 10e-3;
    double cons = (epsilon*epsilon)/4.0 ;
    double u = q1 - q2;
    double v = q1 + q2;
    double deno1 = (u*u) + cons ;
    double deno2 = (v*v) + cons ;
    double deno1_pot = pow(deno1, 3/2);
    double deno2_pot = pow(deno2, 3/2);
    return (u/deno1_pot) - (v/deno2_pot);
}


//double valor_k(double x_i, double f_i){
//    double k1 = f_i(x_i);
//    double k2 = f_i(x_i + (delta_t/2.0)*k1);
//    double k3 = f_i(x_i + (delta_t/2.0)*k2);
//    double k4 = f_i(x_i + (delta_t*k3));
//    return (delta_t/6.0)*(k1 + 2*k2 + 2*k3 + k4);
//}

