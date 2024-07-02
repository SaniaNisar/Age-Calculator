#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

bool isValidDate(int day, int month, int year) {
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > daysInMonth(month, year)) {
        return false;
    }
    return true;
}

int main() {
    int cmonth, cday, cyear;
    int bmonth, bday, byear;

    cout << "                  AGE CALCULATOR                     " << endl;

    while (true) {
        cout << "Enter current date (dd mm yyyy): ";
        cin >> cday >> cmonth >> cyear;
        if (isValidDate(cday, cmonth, cyear)) break;
        cout << "Invalid current date. Please try again." << endl;
    }

    while (true) {
        cout << "Enter birth date (dd mm yyyy): ";
        cin >> bday >> bmonth >> byear;
        if (isValidDate(bday, bmonth, byear)) break;
        cout << "Invalid birth date. Please try again." << endl;
    }

    int dyear = cyear - byear;
    int dmonth = cmonth - bmonth;
    int dday = cday - bday;

    if (dday < 0) {
        dday += daysInMonth(cmonth - 1, cyear);
        dmonth--;
    }

    if (dmonth < 0) {
        dmonth += 12;
        dyear--;
    }

    cout << "You are " << dyear << " years, " << dmonth << " months, and " << dday << " days old." << endl;

    int totalMonths = dyear * 12 + dmonth;
    int totalDays = dyear * 365 + dmonth * 30 + dday; // Approximation

    cout << "You are approximately " << totalMonths << " months old." << endl;
    cout << "You are approximately " << totalDays << " days old." << endl;

    if (dyear < 18) {
        cout << "You are a minor. Enjoy your youth!" << endl;
    } else if (dyear < 65) {
        cout << "You are an adult. Keep thriving!" << endl;
    } else {
        cout << "You are a senior citizen. Embrace your wisdom!" << endl;
    }

    cout << "Keep growing, stay safe, and follow COVID-19 SOPs!" << endl;

    return 0;
}
