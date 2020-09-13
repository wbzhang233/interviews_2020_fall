//
// Created by wbzhang on 2020/7/31.
//

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class LeastSquare{
    double a, b;
public:
    LeastSquare(const vector<double>& x, const vector<double>& y)
    {
        double t1=0, t2=0, t3=0, t4=0;
        for(int i=0; i<x.size(); ++i)
        {
            t1 += x[i]*x[i];
            t2 += x[i];
            t3 += x[i]*y[i];
            t4 += y[i];
        }
        a = (t3*x.size() - t2*t4) / (t1*x.size() - t2*t2);
        //b = (t4 - a*t2) / x.size();  
        b = (t1*t4 - t2*t3) / (t1*x.size() - t2*t2);
    }

    double getY(const double x) const
    {
        return a*x + b;
    }

    vector<double> getResult()
    {
        return {this->a,this->b};
    }

    void print() const
    {
        cout<<"y = "<<a<<"x + "<<b<<"\n";
    }

};

int main(int argc, char *argv[])
{

    vector<double> x={1,2,3,4};
    vector<double> y={6,5,7,10};

    LeastSquare ls(x, y);
    ls.print();

    vector<double> res=ls.getResult();
    cout<<"a:"<<res[0]<<" b:"<<res[1]<<endl;

    cout<<"Input x:\n";
    double x0;
    while(cin>>x0)
    {
        cout<<"y = "<<ls.getY(x0)<<endl;
        cout<<"Input x:\n";
    }

    return 0;
}  