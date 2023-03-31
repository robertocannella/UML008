/************************************************************************/
/*                                                                      */
/*  HOMEWORK:   8                                                       */
/*                                                                      */
/*  Name:   Roberto Cannella                                            */
/*                                                                      */
/*  Class:  C Programming                                               */
/*                                                                      */
/*  Date:   2023-04-2                                                   */
/*                                                                      */
/*  Description:  Program which determines gross pay based on overtime  */
/*                and outputs a formatted answer.  Employee information */
/*                is stored in an array of structures and referenced    */
/*                through the use of pointers.                          */
/************************************************************************/

// necessary header files
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "statistics.h"

/************************************************************************/
/*                           Function: Main                             */
/************************************************************************/

int main ()
{
    
    // Set up a local variable to store the employee information
    // Initialize the name, tax state, clock number, and wage rate
    struct employee emp[NUM_EMPL] = {
        { {"Connie", "Cobol"}, "MA", 98401, 10.60},
        { {"Mary", "Apl"}, "NH", 526488, 9.75 },
        { {"Frank", "Fortran"}, "VT", 765349, 10.50 },
        { {"Jeff", "Ada"}, "NY", 34645, 12.25 },
        { {"Anton", "Pascal"},"CA",127615, 8.35 }
    };
    struct employee * emp_ptr;      /* pointer to an employee structure */
    emp_ptr = emp;                  /* point to beginning of emp array */

    // set up structure to store totals and initialize all to zero
    struct totals tot  = {0,0,0,0,0,0,0};
    struct totals * tot_ptr;        /* pointer to a totals structure */
    tot_ptr = &tot;                 /* point to beginning of totals structure */


    // set up structure to store min and max values and initialize all to zero
    struct min_max employeeMinMax = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    // set up structure to store standard deviation values and initialize all to zero
    struct std_dev employeeStdDev = {0,0,0,0,0,0,0};

    // set up structure to store median values and initialize all to zero
    struct median employeeMedian = {0,0,0,0,0,0,0};

    // Call functions as needed to read and calculate information

    // Prompt for the number of hours worked by the employee
    getHours (emp_ptr, NUM_EMPL);

    // Calculate the overtime hours
    calcOvertimeHrs (emp_ptr, NUM_EMPL);
       
    // Calculate the weekly gross pay
    calcGrossPay (emp_ptr, NUM_EMPL);

    // Calculate the state tax                                       
    calcStateTax (emp_ptr, NUM_EMPL);

    // Calculate the federal tax                                                   
    calcFedTax (emp_ptr, NUM_EMPL);
 
    // Calculate the net pay after taxes   
    calcNetPay (emp_ptr, NUM_EMPL);
        
    // Keep a running sum of the employee totals
    calcEmployeeTotals (emp_ptr, tot_ptr, NUM_EMPL);
                                             
    // Keep a running update of the employee minimum and maximum values
    // Note:  This remains a Call by Value design
    employeeMinMax = calcEmployeeMinMax (emp,
                                         employeeMinMax,
                                         NUM_EMPL);

    // Keep a running update of the standard deviation totals
    // Note:  This remains a Call by Value design
    employeeStdDev = getSD(emp, employeeStdDev, NUM_EMPL);

    // Keep a running update of the standard deviation totals
    // Note:  This remains a Call by Value design
    employeeMedian = getMedian(emp, employeeMedian, NUM_EMPL);

    // Print the column headers
    printHeader();

    // print out final information on each employee
    printEmp (emp, NUM_EMPL);
    
    // print the totals and averages for all float items
    printEmpStatistics (tot, employeeMinMax, employeeStdDev, employeeMedian,  NUM_EMPL);

    return (0); /* success */

} // main
