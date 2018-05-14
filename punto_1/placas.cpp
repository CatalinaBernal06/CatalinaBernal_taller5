#include <iostream>
#include <math.h>

int main(){
    double L = 5.0;
    double l = 2.0;
    double d = 1.0;
    double h = 5.0/512.0;
    double v0 = 100.0;
    int N = 2*((L/h)*(L/h));
    
    int dim = int(L/h);
    
    double **E_x = new double*[dim];
    double **E_y = new double*[dim];
    
    double **V_past = new double*[dim];
    double **V = new double*[dim];
    
    for(int i = 0; i<dim; i++){
        E_x[i] = new double[dim];
        E_y[i] = new double[dim];
        V_past[i] = new double[dim];
        V[i] = new double[dim];
    
    }
    
    //condiciones de placas en matriz
    int mid = dim/2;
    int p_inf = mid + int((d/h)/2);
    int p_sup = mid - int((d/h)/2);
    int ini = mid - int((l/h)/2);
    int fin = mid + int((l/h)/2);
    
    //for(int i= 0; i<N_x; i++){
    //E_x[i][0] = 0;
    //E_x[0][i] = 0;
    //E_x[dim][i] = 0;
    //E_x[i][dim] = 0;
   
    //E_y[i][0] = 0;
    //E_y[0][i] = 0;
    //E_y[dim][i] = 0;
    //E_y[i][dim] = 0;
    //}
    
    for(int p = ini; p<fin; p++){
        V_past[p_inf][p] = v0/2.0;
        V_past[p_sup][p] = -1*v0/2.0;
        V[p_inf][p] = v0/2.0;
        V[p_sup][p] = -1*v0/2.0;
    }
    
    int k = 0;
    while(k < N){
        for(int i = 1; i<dim-1; i++){
            for(int j = 1; j<dim-1; j++){
                if((i==p_inf + 1) && ((j>ini) && (j<fin))){
                    V[i][j] = -1*v0/2.0;
                }
                else if((i==p_sup + 1) && ((j>ini) && (j<fin))){
                    V[i][j] = v0/2.0;
                }
                else{
                    V[i][j] = ((1.0/4.0)*(V_past[i][j+1] + V[i][j-1] + V_past[i+1][j] + V[i-1][j]));
                }
        }
            
    }
        for(int i = 0; i<dim; i++){
            for(int j = 0; j<dim; j++){
                V_past[i][j] = V[i][j];
            }
        }
        k += 1;
    }
    
    for(int i = 1; i<dim-1; i++){
        for(int j = 1; j<dim-1; j++){
            E_x[i][j] =  ((1.0/(2.0*h))*(V[i][j+1] - V[i][j-1]));
            E_y[i][j] = ((1.0/(2.0*h))*(V[i+1][j] - V[i-1][j]));
           
        }
    }

    for(int i = 0; i<dim; i++){
        for(int j = 0; j<dim; j++ ){
            std::cout << V[i][j] << " " << E_x[i][j] << " " << E_y[i][j] << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}
