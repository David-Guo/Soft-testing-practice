#include <stdio.h>

const char* Triangle(int a, int b, int c) {
    
    if(a <= 0 || b <= 0 || c<= 0)
        return "Invalid input";

    if ((a < b + c && b < a + c && c < a + b) == 0) 
        return "NotATriangle";

    if(a == b && b == c)
        return "Equilateral";

    if(a == b || b ==c || c == a)
        return "Isosceles";

    if(a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b)
        return "Scalene";

    return "Right triangle";
}


const char* NextDay(int year, int month, int day) {
    int tomoYear = year;
    int tomoMonth = month;
    int tomoDay;
    int isLeapYear = ((year%4 == 0) && (year%100 != 0)) || (year%400 == 0);
    if ( year < 0 ) return "Invalid input";
    if ( month < 1 || month > 12) return "Invalid input";
    if ( day < 1 || day >31) return "Invalid input";
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10:
            if (day < 31)
                tomoDay = day + 1;
            else {
                tomoDay = 1;
                tomoMonth = month + 1;
            } break;
        case 4: case 6: case 9: case 11:
            if (day < 30)
                tomoDay = day + 1;
            else {
                tomoDay = 1;
                tomoMonth = month +1;
            } break;
        case 12:
            if (day < 31)
                tomoDay = day + 1;
            else{
                tomoDay = 1;
                tomoMonth = 1;
                tomoYear = year + 1;
            } break;
        case 2:
            if (day < 28)
                tomoDay = day + 1;
            else if (day == 28) {
                if (isLeapYear)
                    tomoDay = day + 1;
                else {
                    tomoDay = 1;
                    tomoMonth = 3;
                }
            }
            else {
                if (isLeapYear) {
                    tomoDay = 1;
                    tomoMonth = 3;
                }
                else return "Invalid input";
            } break;
    }

    static char output[30];
    sprintf(output, "%d/%d/%d", tomoYear, tomoMonth, tomoDay);
    return output;
}


const char* Commission(int locks, int stocks, int barrels) {
    int lockPrice = 45;
    int stockPrice = 35;
    int barrelPrice = 25;
    int commission;
    int sales;
    static char output[10];
    if (locks < 0 || locks > 70) return "Invalid input";
    if (stocks < 0 || stocks > 80) return "Invalid input";
    if (barrels < 0 || barrels > 90) return "Invalid input";
    sales = locks * lockPrice + stocks * stockPrice + barrels * barrelPrice;
    if (sales > 1800) {
        commission = 0.1 * 1000;
        commission = commission + 0.15 * 1800;
        commission = commission + 0.2 * (sales - 1800);
    }
    else if (sales > 1000) {
        commission = 0.1 * 1000;
        commission = commission + 0.15 * (sales - 1000);
    }
    else 
        commission = 0.1 * sales;
    sprintf(output, "%d", commission);
    return output;
}

