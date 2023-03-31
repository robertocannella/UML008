#include <stdio.h>
#include "employee.h"

//**************************************************************
// Function: getHours 
// 
// Purpose: Obtains input from user, the number of hours worked 
//          per employee and updates it in the array of structures
//          for each employee.
// 
// Parameters:
//
//   emp_ptr -  pointer to an employee struct array
//   size -     number of employees
// 
// Returns: void
//  
//**************************************************************

void getHours (struct employee * emp_ptr, int size)
{

    int i;  // array and loop index

    // read in hours for each employee
    for (i = 0; i < size; ++i)
    {

        // Read in hours for employee
        printf("\nEnter hours worked by emp # %06li: ", emp_ptr->clockNumber);
        scanf ("%f", &emp_ptr->hours);

        ++emp_ptr;
    }
    
} // getHours