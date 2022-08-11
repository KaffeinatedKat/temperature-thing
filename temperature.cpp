#include <iostream>
#include <cctype>


struct Temperature {
    double val;
    char type;

    double toCelsius() {
        if (type == 'C') {
            return val;
        }
        type = 'C';
        return (val - 32) * 5 / 9;
    }

    double toFahrenheit() {
        if (type == 'F') {
            return val;
        }
        type = 'F';
        return (val * 9 / 5) + 32; 
    }
};



int main() {
    double temperature;
    char input;
    Temperature temp;

    printf("Temperature to convert: ");
    std::cin >> temp.val >> temp.type;
    
    if (toupper(temp.type) == 'F') {
        printf("%.2lf degrees fahrenheit is %.2lf degrees celsius\n", temp.val, temp.toCelsius());
    } else if (toupper(temp.type) == 'C') {
        printf("%.2lf degrees celsius is %.2lf degrees fahrenheit\n", temp.val, temp.toFahrenheit());
    } else {
        main();
    }


    do { 
        printf("Would you like to convert again? [y/n] ");
        std::cin >> input;
    } while (input != 'y' && input != 'n'); // prompt till responce is 'y' or 'n'

    if (input == 'n') { return 0; } // exit if 'n'
    main();

}
