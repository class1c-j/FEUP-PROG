/*
    
   The following data type is used to represent dates:
   struct Date {
    unsigned int year, month, day;
   } Date;
   
    a) Write a function void readDate(Date *d) that reads a date from the keyboard, in the
    format year/month/day. For simplicity, consider that the user always inputs a valid
    date.
    
*/

typedef struct {
    unsigned int year, month, day;
} Date;

void readDate(Date *d) {
    std::cout << "year/month/day ? ";
    std::cin >> d->year; std::cin.clear(); std::cin.ignore(1);
    std::cin >> d->month; std::cin.clear(); std::cin.ignore(1);
    std::cin >> d->day; std::cin.clear(); std::cin.ignore(9999, '\n');
}

/*
  
   b) Write a function void writeDate(const Date *d) that writes a date on the screen,
   in the format YYYY/MM/DD, where YYYY, MM and DD represent, respectively, the year,
   the month, and the day (MM and DD with 2 digits).
      
*/

void writeDate(const Date *d) {
    std::cout << std::setfill('0');
    std::cout << std::setw(4) << d->year << "/" << std::setw(2) << d->month << "/" << std::setw(2) << d->day;
}


/*
  
   c) Write a function int compareDates(const Date *d1, const Date *d2) that compares two
   dates, returning -1, 0 or 1, depending on whether the date d1 is before, equal to,
   or after date d2.
   
*/

int compareDates(const Date *d1, const Date *d2) {
    if (d1->year != d2-> year) return d1->year > d2->year ? 1 : -1;
    if (d1->month != d2->month) return d1->month > d2->month ? 1 : -1;
    if (d1->day != d2->day) return d1->day > d2->day ? 1 : -1;
    return 0;
}

/*
  
    d) Write a function void sortDates(Date *d1, Date *d2) that compares and sorts the dates d1
    and d2 so that d2 is after d1
    
*/

void sortDates(Date *d1, Date *d2) {
    if (compareDates(d1, d2) > 0) {
        Date temp = *d1;
        *d1 = *d2;
        *d2 = temp;
    }
}


/*
  
   e) Write a program that reads 2 dates, sorts them, and shows the sorted dates on the screen.
   
*/

int main() {
    Date *d1 = new Date;
    readDate(d1);
    Date *d2 = new Date;
    readDate(d2);
    sortDates(d1, d2);
    writeDate(d1);
    std::cout << '\n';
    writeDate(d2);
}
