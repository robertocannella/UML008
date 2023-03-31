#include <stdio.h>
#include "employee.h"

//*************************************************************
// Function: calcEmployeeMinMax
//
// Purpose: Accepts various floating point values from an
//          employee and adds to a running update of min
//          and max values
//
// Parameters:
//
//   emp_ptr        - pointer to an employee struct array
//   empMinMax_ptr  - structure containing a running totals
//                         of all fields above
//   size           - number of employees
//
// Returns: void
//
//**************************************************************

void calcEmployeeMinMax (struct employee * emp_ptr,
                                   struct min_max * empMinMax_ptr,
                                   int size)
{

    int i; // array and loop index
    
    // if this is the first set of data items, set 
    // them to the min and max
    empMinMax_ptr->min_wageRate = emp_ptr->wageRate;
    empMinMax_ptr->min_hours = emp_ptr->hours;
    empMinMax_ptr->min_overtimeHrs = emp_ptr->overtimeHrs;
    empMinMax_ptr->min_grossPay = emp_ptr->grossPay;
    empMinMax_ptr->min_stateTax = emp_ptr->stateTax;
    empMinMax_ptr->min_fedTax = emp_ptr->fedTax;
    empMinMax_ptr->min_netPay = emp_ptr->netPay;
        
    // set the max to the first element members
    empMinMax_ptr->max_wageRate = emp_ptr->wageRate;
    empMinMax_ptr->max_hours = emp_ptr->hours;
    empMinMax_ptr->max_overtimeHrs = emp_ptr->overtimeHrs;
    empMinMax_ptr->max_grossPay = emp_ptr->grossPay;
    empMinMax_ptr->max_stateTax = emp_ptr->stateTax;
    empMinMax_ptr->max_fedTax = emp_ptr->fedTax;
    empMinMax_ptr->max_netPay = emp_ptr->netPay;
	
	// compare the rest of the items to each other for min and max
    for (i = 0; i < size; ++i)
    {
		
        // check if current Wage Rate is the new min and/or max
        if (emp_ptr->wageRate < empMinMax_ptr->min_wageRate)
        {
            empMinMax_ptr->min_wageRate = emp_ptr->wageRate;
        }
        if (emp_ptr->wageRate > empMinMax_ptr->max_wageRate)
        {
            empMinMax_ptr->max_wageRate = emp_ptr->wageRate;
        }

        // check if current Gross Pay is the new min and/or max
		if (emp_ptr->grossPay < empMinMax_ptr->min_grossPay)
        {
            empMinMax_ptr->min_grossPay = emp_ptr->grossPay;
        }
        if (emp_ptr->grossPay > empMinMax_ptr->max_grossPay)
        {
            empMinMax_ptr->max_grossPay = emp_ptr->grossPay;
        }

        // check if current Hours is the new min and/or max
        if (emp_ptr->hours < empMinMax_ptr->min_hours)
        {
            empMinMax_ptr->min_hours = emp_ptr->hours;
        }
        if (emp_ptr->hours > empMinMax_ptr->max_hours)
        {
            empMinMax_ptr->max_hours = emp_ptr->hours;
        }

        // check if current Overtime Hours is the new min and/or max
        if (emp_ptr->overtimeHrs < empMinMax_ptr->min_overtimeHrs)
        {
            empMinMax_ptr->min_overtimeHrs = emp_ptr->overtimeHrs;
        }
        if (emp_ptr->overtimeHrs > empMinMax_ptr->max_overtimeHrs)
        {
            empMinMax_ptr->max_overtimeHrs = emp_ptr->overtimeHrs;
        }

        // check if current State Tax is the new min and/or max
        if (emp_ptr->stateTax < empMinMax_ptr->min_stateTax)
        {
            empMinMax_ptr->min_stateTax = emp_ptr->stateTax;
        }
        if (emp_ptr->stateTax > empMinMax_ptr->max_stateTax)
        {
            empMinMax_ptr->max_stateTax = emp_ptr->stateTax;
        }

        // check if current Fed Tax is the new min and/or max
        if (emp_ptr->fedTax < empMinMax_ptr->min_fedTax)
        {
            empMinMax_ptr->min_fedTax = emp_ptr->fedTax;
        }
        if (emp_ptr->fedTax > empMinMax_ptr->max_fedTax)
        {
            empMinMax_ptr->max_fedTax = emp_ptr->fedTax;
        }

        // check if current Net Pay is the new min and/or max
        if (emp_ptr->netPay < empMinMax_ptr->min_netPay)
        {
            empMinMax_ptr->min_netPay = emp_ptr->netPay;
        }
        if (emp_ptr->netPay > empMinMax_ptr->max_netPay)
        {
            empMinMax_ptr->max_netPay = emp_ptr->netPay;
        }

        ++emp_ptr;
		
    } // else if

	
} // calcEmployeeMinMax