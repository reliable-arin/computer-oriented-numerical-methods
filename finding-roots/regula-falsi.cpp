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

float regula_falsi_method(float (*function)(float)){
    pair<float,float>interval=find_interval(function);
    cout<<endl;
    float a=1.0,b=1.0;
    while(abs(a)>0.0001 && abs(b)>0.0001){
        cout<<interval.first<<","<<interval.second<<endl;
        a = function(interval.first);
        b = function(interval.second);
        float nv=(interval.first*b - interval.second*a)/(b-a);
        float ni = function(nv);
        if(ni<0)interval.first=nv;
        else if(ni>0)interval.second=nv;
        else return nv;
    }
    a = function(interval.first);
    b = function(interval.second);
        
    return (interval.first*b-interval.second*a)/b-a;
}
float f(float x){
    return pow(x,3)-4*x-9;
}

int main()
{
    float a=regula_falsi_method(f);
    cout<<"the root of the equation is "<<a<<endl;
    cout<<abs(f(a));

    return 0;
}