#include <cmath>
#include <iostream>
#include <vector>
#define PI  3.14
#define g   9.81
double rad_to_degree(float rad){
    return  rad * (180/PI);
};
std::vector<double> dyn_eq(double t , double v_init , double degree){
    double x = v_init * std::cos(degree)*t;
    double y = v_init * std::sin(degree)*t  -  0.5*g*std::pow(t,2);
    return {x,y};

};
int main(){
    double t_final = 3.0;  //Final Runtime 5 sec
    double v_init = 10.0;
    double input = 0.0;
    double t_sample = 0.01;
    double current_time = 0.0;
    while (true)
    {
    std::cout << "Please enter value:";
    std::cin  >> input;
        if (input > 1.54 || input < -1.54){
            std::cout << "Pleae enter the value between 1.54 and -1.54" << std::endl;
        }else{
            std::cout << rad_to_degree(input) << std::endl;
            break;
        }
    }
    while (true){
        if (t_final - current_time > t_sample){
                current_time = current_time + t_sample;
                std::vector<double> result = dyn_eq(current_time, v_init, input);
                std::cout <<"Position x:" << result[0]<< " Position y:" << result[1] << std::endl;
                if (current_time > 0.1 && result[1]  <= 0.0 ){
                    std::cout << "Projectile hit the ground" << std::endl;
                    break;
                }
        }
    }
    return 0;
}
