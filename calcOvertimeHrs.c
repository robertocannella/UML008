#include <stdio.h>
#include "employee.h"

//*************************************************************
// Function: calcOvertimeHrs
//
// Purpose: Calculates the overtime hours worked by an employee
//          in a given week for each employee.
//
// Parameters:
//
//   emp_ptr     - pointer to an employee struct array
//   size        - number of employees
//
// Returns: void
//
//**************************************************************

void calcOvertimeHrs (struct employee * emp_ptr, int size)
{
	
    int i;  // array and loop index

    // calculate overtime hours for each employee
    for (i = 0; i < size; ++i)
    {  
        // Any overtime ?
        if (emp_ptr->hours >= STD_HOURS)
        {
            emp_ptr->overtimeHrs = emp_ptr->hours - STD_HOURS;
        }
        else // no overtime
        {
  	        emp_ptr->overtimeHrs = 0;
        }
        ++emp_ptr;
        
    } // for


} // calcOvertimeHrs