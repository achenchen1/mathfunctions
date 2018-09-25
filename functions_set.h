#include <iostream>
#ifndef MATH_MATH_H
#define MATH_MATH_H

void fibonacci();
void fib_seq(int termnum);
void fib_term(int termnum);
void gcd();
void lcm();
long int gcd_lcm(long int a, long int b);


void fibonacci(){
    int termnum{0};
    char func_choice{1};

    std::cout << "Would you like to find the term or the sequence leading up to it? \'s\' for the sequence,";
    std::cout << "\'t\' for the specific term." << std::endl;
    std::cin >> func_choice;

    if(func_choice == 's'){
        fib_seq(termnum);
    }

    else if(func_choice == 't'){
        fib_term(termnum);
    }
    else{
        std::cout << "Error!";
    }
}

void fib_seq(int termnum){
    long unsigned int set3[3]={1, 0, 0};
    std::cout << "How many terms would you like?" << std::endl;
    std::cin >> termnum;
    for (int i = 0; i < termnum; i++) {
        set3[2] = set3[0] + set3[1];
        set3[0] = set3[1];
        set3[1] = set3[2];

        std::cout << set3[2] << ((i == termnum - 1) ? "." : ", ");
    }
}

void fib_term(int termnum){
    long unsigned int set3[3]={1, 0, 0};
    std::cout << "Which term would you like?" << std::endl;
    std::cin >> termnum;
    for (int i = 0; i < termnum; i++) {
        set3[2] = set3[0] + set3[1];
        set3[0] = set3[1];
        set3[1] = set3[2];
    }

    std::cout << set3[2];
}

void lcm(){
    long int a;
    long int b;

    std::cout << "Enter your first number:" << std::endl;
    std::cin >> a;
    std::cout << "Enter your second number:" << std::endl;
    std::cin >> b;

    gcd_lcm(a, b);

    std::cout << a*b/gcd_lcm(a, b);
}

long int gcd_lcm(long int a, long int b){
    long int divisor{1};

    if(a>b){
        long int tmp;
        tmp=b;
        b=a;
        a=tmp;
    }

    int i{1};
    while(i<=a){
        if(a%i==0 && b%i==0){
            divisor=i;
        }
        i++;
    }

    return(divisor);
}

void gcd(){
    long int divisor{1};
    long int a{1};
    long int b{1};

    std::cout << "Enter your first number: " << std::endl;
    std::cin >> a;
    std::cout << "Enter your second number: " << std::endl;
    std::cin >> b;

    if(a>b){
        long int tmp;
        tmp=b;
        b=a;
        a=tmp;
    }

    int i{1};
    while(i<=a){
        if(a%i==0 && b%i==0){
            divisor=i;
        }
        i++;
    }

    std::cout << divisor;
}

#endif
