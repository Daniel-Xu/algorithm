#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string convert(string s)
{
    int pos = s.find('.', 0);
    int intpart = atoi(s.substr(0, pos).c_str());
    double fpart = atof(s.substr(pos, s.size()-pos).c_str());

    cout << intpart << " " << fpart << endl;
    string intstr = "", fstr="";

    while(intpart > 0){
        if(intpart & 1) 
            intstr = "1"+intstr; 
        else
            intstr = "0"+intstr; 
        intpart >>= 1;
    }
    
    while(fpart > 0) {
        if(fstr.length() > 32) 
            return "ERROR";

        fpart *= 2;

        if(fpart >= 1 ){
            fstr += "1";
            fpart -= 1;
        }else
            fstr += "0";
    }

    return intstr + "." + fstr;
}


int main(int argc, char const *argv[])
{
    
    string s("19.25");
    cout << "original string is: " << s << endl;
    cout << convert(s) << endl;
    return 0;
}
