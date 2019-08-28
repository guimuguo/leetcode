#include<iostream>
using namespace std;
class pow{
public:
    double powCal(double x, int n){
        if(n == 0){
            return 1;
        }else if(n%2 == 0){
            return powCal(x, n/2)*powCal(x, n/2);
        }else{
            return x*powCal(x, n/2)*powCal(x, n/2);
        }
    }
};
int main(int argc, char* argv[]){
    if(argc != 3){
        cout<<"to calculate pow(x,n), plz give the arguments, arg1 = x, arg2 = n"<<endl;
        return -1;
    }
    pow p;
    double x = atof(argv[1]);
    int n = atoi(argv[2]);
    cout<<p.powCal(x,n)<<endl;
    return 0;
}
