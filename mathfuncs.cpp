#include "functions_set.h"

//Finds sequence according to the Collatz hypothesis, where given any positive integer and the following rules:
// if it's odd, multiply by 3 and add one
// if it's even, divide by 2
//and repeating this process, it will eventually terminate in the sequence "..., 4, 2, 1."
void collatz(long int user_input) {
    if(user_input <= 0){
        std::cout << "Please enter a positive integer.";
    }
    else if(user_input <= 2 || user_input == 4){
        std::cout << "Your number is already a terminal.";
    }
    else {
        while (user_input > 2 && user_input != 4) {
            if (user_input % 2 == 0) {
                user_input /= 2;
            } else {
                user_input = user_input * 3 + 1;
            }
            std::cout << user_input << " ";
        }
    }
}

//Prompts user to choose if they would like to find a term or the entire list of numbers leading up to the term.
void fibonacci(long int termnum){
    std::string func_choice{1};

    std::cout << "Would you like to find the term or the sequence leading up to it? \'s\' for the sequence,";
    std::cout << "\'t\' for the specific term." << std::endl;
    std::cin >> func_choice;

    if(func_choice == "s"){
        fib_seq(termnum);
    }

    else if(func_choice == "t"){
        fib_term(termnum);
    }
    else{
        std::cout << "Error: not a valid input. Try again." << std::endl;
        fibonacci(termnum);
    }
}

//If user would like to find entire sequence
void fib_seq(long int termnum){
    long unsigned int set3[3]={1, 0, 0};
    for (int i = 0; i < termnum; i++) {
        //set3[2] is the specific number, while set3[0] and set3[1] store the previous two numbers.
        set3[2] = set3[0] + set3[1];
        set3[0] = set3[1];
        set3[1] = set3[2];

        //For aesthetics, the sequence has commas between terms, and a period at the end of the sequence.
        std::cout << set3[2] << ((i == termnum - 1) ? "." : ", ");
    }
}

//If user would like to find only the term.
void fib_term(long int termnum){
    long unsigned int set3[3]={1, 0, 0};
    for (int i = 0; i < termnum; i++) {
        //Like before, set3[2] is the specific number, while set3[0] and set3[1] store the previous two numbers.
        set3[2] = set3[0] + set3[1];
        set3[0] = set3[1];
        set3[1] = set3[2];
    }

    std::cout << set3[2];
}

//Prints out all the possible ways where a number can be made with the sum of consecutive positive integers.
//Note: user_input as a 1-term friendly sequence is not counted. 
void friendly(long unsigned user_input) {
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
void friendly_counter(long unsigned int user_input) {
    int result{0};
    for(int i = 2; i * i / 2 < user_input; i++) {
        if (i % 2 == 0 && user_input % i != 0 && 2 * user_input % i == 0) {
            result=result+1;
        } else if (i % 2 == 1 && user_input % i == 0) {
            result=result+1;
        }
    }
    std::cout << result;
}

//For finding the GCD
void gcd(long int a, long int b){
    long int divisor{1};

    //Cycles through values of i, to find if i is a possible factor.
    int i{1};
    while(i<=a && i<=b){
        if(a%i==0 && b%i==0){
            divisor=i;
        }
        i++;
    }

    std::cout << divisor;
}

//The GCD calculator that is only used to calculate the LCM
long int gcd_lcm(long int a, long int b){
    long int divisor{1};

    //Cycles through values of i, to find if i is a possible factor.
    int i{1};
    while(i<=a && i<=b){
        if(a%i==0 && b%i==0){
            divisor=i;
        }
        i++;
    }

    return(divisor);
}

//For finding the LCM
void lcm(long int a, long int b){
    gcd_lcm(a, b);

    //Using LCM = (a*b)/GCD
    std::cout << a*b/gcd_lcm(a, b);
}

//Flips a number, and tells the user whether or not their number is a palindrome
void palindrome(long int user_input) {
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

    std::cout << reverse << ": ";
    if (user_input == reverse) {
        std::cout << "Your number is a palindrome!";
    } else {
        std::cout << "Your number is NOT a palindrome!";
    }
}

//Identifies if input is prime or not
bool prime(long unsigned int user_input){
    int i{1};
    if(user_input == 1){
        std::cout << "Not prime";
        return(false);
    }
    if(user_input%2 == 0){
        std::cout << "Not prime";
        return(false);
    }
    while(i <= (pow(user_input, 0.5)-1)/2){
        if(user_input % (2*i + 1) == 0){
            std::cout << "Not prime";
            return(false);
        }
        i++;
    }

    std::cout << "Prime";
    return(false);
}

//Using primebool, returns primes within range
void primerange(long int input1, long int input2){
    while(input1 <= input2) {
        if(primebool(input1)) {
            std::cout << input1 << std::endl;
        }
        input1++;
    }
}

//Returns a bool to whether input is prime or not
bool primebool(long int user_input){
    int i{1};
    if(user_input%2 == 0){
        return(false);
    }
    while(i <= (pow(user_input, 0.5)-1)/2){
        if(user_input % (2*i + 1) == 0){
            return(false);
        }
        i++;
    }

    return(true);
}
