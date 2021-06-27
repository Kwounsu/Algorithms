int isLaepYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 != 0) 
            return 1;
        else if (year % 400 == 0)
            return 1;
    }
    return 0;
}
