#include <stdio.h>
#include "employee.h"

//*************************************************************
// Function: calcNetPay
//
// Purpose: Calculates the net pay as the gross pay minus any
//          state and federal taxes owed for each employee.
//          Essentially, their "take home" pay.
//
// Parameters:
//
//   emp_ptr     - pointer to an employee struct array
//   size        - number of employees
//
// Returns: void
//
//**************************************************************

void calcNetPay (struct employee * emp_ptr, int size)
{
	int i;               // loop and array index
	float theTotalTaxes; // the total state and federal tax
    
    // calculate the take home pay for each employee
    for (i=0; i < size; ++i)
    {
        // calculate the total state and federal taxes
        theTotalTaxes = emp_ptr->stateTax + emp_ptr->fedTax;
	
        // calculate the net pay
        emp_ptr->netPay =  emp_ptr->grossPay - theTotalTaxes;

        ++emp_ptr;
    } // for
	
} // calcNetPay