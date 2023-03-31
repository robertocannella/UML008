#include <stdio.h>
#include "employee.h"

//*************************************************************
// Function: calcEmployeeTotals
//
// Purpose: Performs a running total (sum) of each employee
//          floating point member in the array of structures 
//
// Parameters:
//
//   emp_ptr     - pointer to an employee struct array
//   size        - number of employees
//   tot_ptr     - pointer to a totals structure
//
// Returns: void
//
//**************************************************************

void calcEmployeeTotals (struct employee  * emp_ptr,
                                  struct totals *  tot_ptr,
                                  int size)
{
	
    int i; /* loop and array index */
    
    // total up each floating point item for all employees
    for (i = 0; i < size; ++i)
    {
        // add current employee data to our running totals
        tot_ptr->total_wageRate     += emp_ptr->wageRate;
        tot_ptr->total_hours        += emp_ptr->hours;
        tot_ptr->total_overtimeHrs  += emp_ptr->overtimeHrs;
        tot_ptr->total_grossPay     += emp_ptr->grossPay;
        tot_ptr->total_stateTax     += emp_ptr->stateTax;
        tot_ptr->total_fedTax       += emp_ptr->fedTax;
        tot_ptr->total_netPay       += emp_ptr->netPay;

        ++emp_ptr; /* go to next employee */

    } // for

	
} // calcEmployeeTotals