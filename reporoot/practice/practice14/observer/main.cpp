#include <iostream>
#include "GradeBook.h"
#include "Averager.h"
#include "Notifier.h"

int main() {
    GradeBook gradeBook;
    Averager averager;
    Notifier notifier;

    gradeBook.addObserver(&averager);
    gradeBook.addObserver(&notifier);

    gradeBook.setGrade(85); 
    gradeBook.setGrade(59);  
    return 0;
}
