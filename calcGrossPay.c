#include <stdio.h>
#include "employee.h"

//*************************************************************
// Function: calcGrossPay
//
// Purpose: Calculates the gross pay based on the the normal pay
//          and any overtime pay for a given week for each
//          employee.
//
// Parameters:
//
//   employeeData - array of employees (i.e., struct employee)
//   size - the array size (i.e., number of employees)
//
// Returns: void
//
//**************************************************************

void calcGrossPay (struct employee * emp_ptr, int size)
{
    int i;                // loop and array index
    float theNormalPay;   // normal pay without any overtime hours
    float theOvertimePay; // overtime pay

    // calculate grossPay for each employee
    for (i=0; i < size; ++i)
    {
        // calculate normal pay and any overtime pay
        theNormalPay = emp_ptr->wageRate *
                       (emp_ptr->hours - emp_ptr->overtimeHrs);
        theOvertimePay = emp_ptr->overtimeHrs *
                         (OT_RATE * emp_ptr->wageRate);
  
        // calculate gross pay for employee as normalPay + any overtime pay
        emp_ptr->grossPay = theNormalPay + theOvertimePay;

        ++emp_ptr;
    }

} // calcGrossPay