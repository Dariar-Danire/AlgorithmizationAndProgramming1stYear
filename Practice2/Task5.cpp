#include <iostream>

struct Complex{
  double re;  // Действительная часть
  double im;  // Мнимая часть
};

Complex make_complex(std::string num){  
    Complex c;  
    std::string real="", imag="";  
    bool fl=true;  
    long i,pul=0;  
    for(i=0;i<num.length();i++){  
        if(num[i]!=' '){  
            if(fl){  
                if(pul==0) {  
                    real+=num[i];  
                    pul++;}  
                else{  
                if(num[i]!='-' && num[i]!='+') real+=num[i];  
                else{  
                    imag+=num[i];  
                    fl=false;  
                }}  
            }else{  
                imag+=num[i];  
            }  
        }  
    }  
    c.re=std::stod(real);  
    c.im=std::stod(imag);  
    return c;  
}  
  
Complex sum(Complex c1, Complex c2){  
    Complex res;  
    res.re=c1.re+c2.re;  
    res.im=c1.im+c2.im;  
    return res;  
}  
Complex sub(Complex c1, Complex c2){  
    Complex res;  
    res.re=c1.re-c2.re;  
    res.im=c1.im-c2.im;  
    return res;  
}  
Complex mul(Complex c1, Complex c2){  
    Complex res;  
    res.re=c1.re*c2.re-c1.im*c2.im;  
    res.im=c1.re*c2.im+c1.im*c2.re;  
    return res;  
}  
Complex div(Complex c1, Complex c2){  
    Complex res;  
    res.re=(c1.re*c2.re+c1.im*c2.im)/(c2.re*c2.re+c2.im*c2.im);  
    res.im=(c1.im*c2.re-c1.re*c2.im)/(c2.re*c2.re+c2.im*c2.im);  
    return res;  
}  
int print(Complex c){  
    if(c.im==-0) c.im=0;  
    if(c.im>=0) std::cout<<c.re<<"+"<<c.im<<"j\n";  
    else std::cout<<c.re<<c.im<<"j\n";  
    return 0;  
}

int main()
{
    std::string num;
    std::getline(std::cin, num, 'j');
    Complex c1 = make_complex(num);
    
    std::getline(std::cin, num, 'j');
    Complex c2 = make_complex(num);
    
    print(sum(c1, c2));
    print(sub(c1, c2));
    print(mul(c1, c2));
    print(div(c1, c2));
}
