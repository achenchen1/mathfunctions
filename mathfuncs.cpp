#include "functions_set.h"

//Finds sequence according to the Collatz hypothesis, where given any positive integer and the following rules:
// if it's odd, multiply by 3 and add one
// if it's even, divide by 2
//and repeating this process, it will eventually terminate in the sequence "..., 4, 2, 1."
void Sequences::collatz(){
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
        std::cout << "2 1";
    }
}

//If user would like to find entire sequence
void Sequences::fib_seq(){
    long unsigned int array[3] = {1, 0, 0};
    for(int i = 0; i < terminalnumber; i++){
        array[2] = array[0] + array[1];
        array[0] = array[1];
        array[1] = array[2];

        std::cout << array[2] << " ";
    }
}

//If user would like to find only the term.
long unsigned int Sequences::fib_term(){
    long unsigned int array[3] = {1, 0, 0};
    for(int i = 0; i < terminalnumber; i++){
        array[2] = array[0] + array[1];
        array[0] = array[1];
        array[1] = array[2];
    }
    return(array[2]);
}

//Prints out all the possible ways where a number can be made with the sum of consecutive positive integers.
//Note: user_input as a 1-term friendly sequence is not counted.
void Misc::friendly() {
    int i{1};
    while (i * i / 2 < user_input) {
        long int down = (user_input / i - i / 2);
        long int up = (user_input / i + i / 2);

        /*
        For friendly numbers where there are an even number of consecutive integers, then user_input%i must give a decimal
        of 0.5; for example, 5/2 has a sequence of length 2, 2+3, and 5/2 = 2.5.
        i%2 checks if the sequence has an even number of digits, user_input%i checks that the user_input is not a multiple
        of i, and 2*user_input%i == 0 ensures that the terminating decimal is 0.5 and not other decimals such as 0.75.
        */
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
int Misc::friendly_counter() {
    int result{0};
    for(int i = 2; i * i / 2 < user_input; i++) {
        //See above in Misc::friendly(long unsigned user_input) for explanation of even-numbered sequences
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
long int Misc::reverse() {
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
bool Misc::palindrome() {
    return(reverse() == user_input);
}

//The GCD calculator
long unsigned int Nums::gcd(){
    long unsigned int divisor{1};

    //Cycles through values of i, to find if i is a possible factor.
    long unsigned int i{1};
    while(i<=primary_input && i<=secondary_input){
        if(primary_input%i==0 && secondary_input%i==0){
            divisor=i;
        }
        i++;
    }
    return(divisor);
}

//For finding the LCM
long unsigned int Nums::lcm(){
    gcd();

    //Using LCM = (a*b)/GCD
    return(primary_input*secondary_input/gcd());
}

//Takes arithmetic mean
long double Nums::amean(){
    double user_input{1};
    double sum{0};

    for(int i = 0; i < primary_input; i++){
        std::cin >> user_input;
        sum = sum + user_input;
    }

    return(sum/primary_input);
}

//Takes geometric mean
long double Nums::gmean(){
    double user_input{1};
    double product{1};

    for(int i = 0; i < primary_input; i++){
        std::cin >> user_input;
        product = product * user_input;
    }

    return(pow(product, 1.0/primary_input));
}

//Takes harmonic mean
long double Nums::hmean(){
    double user_input{1};
    double recip{0};

    for(int i = 0; i < primary_input; i++){
        std::cin >> user_input;
        if(user_input == 0){
            std::cout << "ERROR: dividing by ";
            return(0);
        }
        recip = 1/user_input + recip;
    }

    return(primary_input/recip);
}

//Using primebool, returns primes within range
void Nums::primerange(){
    while(primary_input <= secondary_input) {
        if(primebool()) {
            std::cout << primary_input << std::endl;
        }
        primary_input++;
    }
}

//Returns a bool to whether input is prime or not
bool Nums::primebool(){
    int i{1};
    if(primary_input == 1) {
        return (false);
    }
    if(primary_input%2 == 0){
        return(false);
    }
    while(i <= (pow(primary_input, 0.5)-1)/2){
        if(primary_input % (2*i + 1) == 0){
            return(false);
        }
        i++;
    }
    return(true);
}
