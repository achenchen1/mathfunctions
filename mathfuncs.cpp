#include "functions_set.h"

//Finds sequence according to the Collatz hypothesis, where given any positive integer and the following rules:
// if it's odd, multiply by 3 and add one
// if it's even, divide by 2
//and repeating this process, it will eventually terminate in the sequence "..., 4, 2, 1."
void Sequences::collatz(long int terminalnumber){
    if(terminalnumber <= 0){
        std::cout << "Please enter a positive integer.";
    }
    else if(terminalnumber <= 2 || terminalnumber == 4){
        std::cout << "Your number is already a terminal.";
    }
    else {
        while (terminalnumber > 2 && terminalnumber != 4) {
            if (terminalnumber % 2 == 0) {
                terminalnumber /= 2;
            } else {
                terminalnumber = terminalnumber*3 + 1;
            }
            std::cout << terminalnumber << " ";
        }
    }
}

//If user would like to find entire sequence
void Sequences::fib_seq(long int terminalnumber){
    long unsigned int set3[3]={1, 0, 0};
    for (int i = 0; i < terminalnumber; i++) {
        //set3[2] is the specific number, while set3[0] and set3[1] store the previous two numbers.
        set3[2] = set3[0] + set3[1];
        set3[0] = set3[1];
        set3[1] = set3[2];

        //For aesthetics, the sequence has commas between terms, and a period at the end of the sequence.
        std::cout << set3[2] << ((i == terminalnumber - 1) ? "." : ", ");
    }
}

//If user would like to find only the term.
long unsigned int Sequences::fib_term(long int terminalnumber){
    long unsigned int set3[3]={1, 0, 0};
    for (int i = 0; i < terminalnumber; i++) {
        //Like before, set3[2] is the specific number, while set3[0] and set3[1] store the previous two numbers.
        set3[2] = set3[0] + set3[1];
        set3[0] = set3[1];
        set3[1] = set3[2];
    }

    return(set3[2]);
}

//Prints out all the possible ways where a number can be made with the sum of consecutive positive integers.
//Note: user_input as a 1-term friendly sequence is not counted.
void Misc::friendly(long unsigned user_input) {
    int i{1};
    while (i * i / 2 < user_input) {
        long int down = (user_input / i - i / 2);
        long int up = (user_input / i + i / 2);

        //For even numbers, when the user_input is divided by i, it must a return 5 in the tenths digit, i.e. n+0.5
        //(n represents an integer)
        //2*user_input%i instructs it to only look at quotients with 0.5, eliminating some exceptions such as n+0.75
        if (i%2 == 0 && user_input%i != 0 && 2*user_input%i == 0) {
            while (down < up - 1) {
                std::cout << down + 1 << " + ";
                down++;
            }
            std::cout << up << std::endl;
        }
            //Odd numbers take less work; as long as user_input is divisible, then there is a sequence
        else if (i % 2 == 1 && user_input % i == 0) {
            while (down < up) {
                std::cout << down << " + ";
                down++;
            }
            std::cout << up << std::endl;
        }
        i++;
    }
}

//Will count how many friendly sequences there are, but will not display them.
int Misc::friendly_counter(long unsigned int user_input) {
    int result{0};
    for(int i = 2; i * i / 2 < user_input; i++) {
        if (i % 2 == 0 && user_input % i != 0 && 2 * user_input % i == 0) {
            result = result + 1;
        }
        else if (i % 2 == 1 && user_input % i == 0) {
            result = result + 1;
        }
    }
    return(result);
}

//Flips a number, and tells the user whether or not their number is a palindrome
long int Misc::reverse(long int user_input) {
    long int result{0};
    long int reverse{0};
    long int i{0};

    long int digits;
    digits = int(log10(user_input) + 1);

    while (i < digits) {
        //Turns user_input to a number between 0 and 10, and returns the integer value of the ones digit.
        result = user_input / int((pow(10, i))) % int((pow(10, 1)));
        i++;
        reverse = reverse + result * int(pow(10, digits - i));
    }

    return(reverse);
}

//Determines whether or not your number is a palindrome
bool Misc::palindrome(long int user_input) {
    return(reverse(user_input) == user_input);
}

//The GCD calculator
long int Nums::gcd(long int num1, long int num2){
    long int divisor{1};

    //Cycles through values of i, to find if i is a possible factor.
    int i{1};
    while(i<=num1 && i<=num2){
        if(num1%i==0 && num2%i==0){
            divisor=i;
        }
        i++;
    }
    return(divisor);
}

//For finding the LCM
long int Nums::lcm(long int num1, long int num2){
    gcd(num1, num2);

    //Using LCM = (a*b)/GCD
    return(num1*num2/gcd(num1, num2));
}

//Takes arithmetic mean
long double Nums::amean(unsigned int quantnum){
    double user_input{1};
    double sum{0};

    for(int i = 0; i < quantnum; i++){
        std::cin >> user_input;
        sum = sum + user_input;
    }

    return(sum/quantnum);
}

//Takes geometric mean
long double Nums::gmean(unsigned int quantnum){
    double user_input{1};
    double product{1};

    for(int i = 0; i < quantnum; i++){
        std::cin >> user_input;
        product = product * user_input;
    }
    
    return(pow(product, 1.0/quantnum));
}

//Takes harmonic mean
long double Nums::hmean(unsigned int quantnum){
    double user_input{1};
    double recip{0};

    for(int i = 0; i < quantnum; i++){
        std::cin >> user_input;
        if(user_input == 0){
            std::cout << "ERROR: dividing by ";
            return(0);
        }
        recip = 1/user_input + recip;
    }

    return(quantnum/recip);
}

//Identifies if input is prime or not
bool Primes::prime(long unsigned int prime1){
    int i{1};
    if(prime1 == 1){
        return(false);
    }
    if(prime1%2 == 0){
        return(false);
    }
    while(i <= (pow(prime1, 0.5)-1)/2){
        if(prime1 % (2*i + 1) == 0){
            return(false);
        }
        i++;
    }
    return(false);
}

//Using primebool, returns primes within range
void Primes::primerange(long int prime1, long int prime2){
    while(prime1 <= prime2) {
        if(primebool(prime1)) {
            std::cout << prime1 << std::endl;
        }
        prime1++;
    }
}

//Returns a bool to whether input is prime or not
bool Primes::primebool(long int prime1){
    int i{1};
    if(prime1%2 == 0){
        return(false);
    }
    while(i <= (pow(prime1, 0.5)-1)/2){
        if(prime1 % (2*i + 1) == 0){
            return(false);
        }
        i++;
    }

    return(true);
}
