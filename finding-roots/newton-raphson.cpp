#include <iostream>
#include<bits/stdc++.h>
using namespace std;
pair<float,float> find_interval(float (*function)(float)){
    float i = 0;
    while(i<20){
        cout<<i<<" ";
        if (function(i)<0 && function(i+1)>0) return {i,i+1};
        else if(function(i)>0 && function(i+1)<0)return {i+1,i} ;
        i++;
    }
    return {0,0};
}

float regula_falsi_method(float (*function)(float),float (*f_prime)(float)){
    pair<float,float>interval=find_interval(function);
    cout<<endl;
    float x_next = interval.second,x;
    do{
        x=x_next;
        x_next=x-function(x)/f_prime(x);
        
    }while(x_next!=x);
    
        
    return x_next;
}
float f(float x){
    return pow(x,3)-x*x-9;
}
float f_prime(float x){
    float h = 0.001;
    return (f(x + h) - f(x - h)) / (2 * h);
}
int main()
{
    float a=regula_falsi_method(f,f_prime);
    cout<<"the root of the equation is "<<a<<endl;
    cout<<abs(f(a));

    return 0;
}