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

float bisection_method(float (*function)(float)){
    pair<float,float>interval=find_interval(function);
    cout<<endl;
    while(abs(interval.first-interval.second)>pow(10,-4)){
        float mid = (interval.first+interval.second)/2;
        float ni = function(mid);
        if(ni<0)interval.first=mid;
        else if(ni>0)interval.second=mid;
        else return mid;
        cout<<interval.first<<","<<interval.second<<endl;
    }
    return (interval.first+interval.second)/2;
}
float f(float x){
    return pow(x,3)-x*x-9;
}

int main()
{
    float a=bisection_method(f);
    cout<<"the root of the equation is "<<a<<endl;
    cout<<abs(f(a));

    return 0;
}