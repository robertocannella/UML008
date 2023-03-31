#include <stdio.h>
#include "employee.h"

//*************************************************************
// Function: calcFedTax
//
// Purpose: Calculates the Federal Tax owed based on the gross 
//          pay for each employee
//
// Parameters:
//
//   emp_ptr     - pointer to an employee struct array
//   size        - number of employees
//
// Returns: void
//
//**************************************************************

void calcFedTax (struct employee * emp_ptr, int size)
{
	
    int i;  // loop and array index
    
    // calculate the federal tax for each employee
    for (i=0; i < size; ++i)
    {
        // Fed Tax is the same for all regardless of state
        emp_ptr->fedTax = emp_ptr->grossPay * FED_TAX_RATE;

        ++emp_ptr;

    } // for
	
} // calcFedTax
