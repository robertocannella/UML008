#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "employee.h"

//*************************************************************
// Function: calcStateTax
//
// Purpose: Calculates the State Tax owed based on gross pay
//          for each employee.  State tax rate is based on the 
//          the designated tax state based on where the
//          employee is actually performing the work.  Each
//          state decides their tax rate.
//
// Parameters:
//
//   emp_ptr     - pointer to an employee struct array
//   size        - number of employees
//
// Returns: void
//
//**************************************************************

void calcStateTax (struct employee * emp_ptr, int size)
{
	
	int i; // loop and array index
	
	// calculate state tax based on where employee works
	for (i=0; i < size; ++i)
    {
        // Make sure tax state is all uppercase
        if (islower(emp_ptr->taxState[0]))
            toupper(emp_ptr->taxState[0]); // make upper case
        if (islower(emp_ptr->taxState[1]))
            toupper(emp_ptr->taxState[1]); // make upper case
	    
        // calculate state tax based on where employee resides
        if (strcmp(emp_ptr->taxState, "MA") == 0)
            emp_ptr->stateTax = emp_ptr->grossPay * MA_TAX_RATE;
        else if (strcmp(emp_ptr->taxState, "NH") == 0)
            emp_ptr->stateTax = emp_ptr->grossPay * NH_TAX_RATE;
        else if (strcmp(emp_ptr->taxState, "VT") == 0)
            emp_ptr->stateTax = emp_ptr->grossPay * VT_TAX_RATE;
        else if (strcmp(emp_ptr->taxState, "CA") == 0)
           emp_ptr->stateTax = emp_ptr->grossPay * CA_TAX_RATE;
        else
            // any other state is the default rate
            emp_ptr->stateTax = emp_ptr->grossPay * DEFAULT_TAX_RATE;

        ++emp_ptr;
    } // for
	   
} // calcStateTax