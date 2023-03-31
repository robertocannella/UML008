//*************************************************************
// Function: calcMedian
//
// Purpose: Calculate the median of various inputs. Populates
//          a median struct using the stored employee data
//
// Parameters:
//
//   emp_ptr     - pointer to an employee struct array
//   size        - number of employees
//   empMed_ptr  - pointer to median struct
//
// Returns: void
//
//**************************************************************
#include <printf.h>
#include "statistics.h"
#include "math.h"

void calcMedian(struct employee * emp_ptr, struct median * empMed_ptr, int size) {

    float total[size];
    int i;

    // Calculate median for net pay
    for (i = 0; i < size; ++i) {
        total[i] = emp_ptr->netPay;
        ++emp_ptr;
    }
    empMed_ptr->median_netPay =  calculateMedian(total, size);

    emp_ptr -= size;
    // Calculate median for federal tax
    for (i = 0; i < size; ++i) {
        total[i] = emp_ptr->fedTax;
        ++emp_ptr;
    }
    empMed_ptr->median_fedTax =  calculateMedian(total, size);

    emp_ptr -= size;
    // Calculate median for state tax
    for (i = 0; i < size; ++i) {
        total[i] = emp_ptr->stateTax;
        ++emp_ptr;
    }
    empMed_ptr->median_stateTax =  calculateMedian(total, size);

    emp_ptr -= size;
    // Calculate median for gross pay
    for (i = 0; i < size; ++i) {
        total[i] = emp_ptr->grossPay;
        ++emp_ptr;
    }
    empMed_ptr->median_grossPay =  calculateMedian(total, size);

    emp_ptr -= size;
    // Calculate median for overtime hours
    for (i = 0; i < size; ++i) {
        total[i] = emp_ptr->overtimeHrs;
        ++emp_ptr;
    }
    empMed_ptr->median_overtimeHrs =  calculateMedian(total, size);

    emp_ptr -= size;
    // Calculate median for hours
    for (i = 0; i < size; ++i) {
        total[i] = emp_ptr->hours;
        ++emp_ptr;
    }
    empMed_ptr->median_hours =  calculateMedian(total, size);

    emp_ptr -= size;
    // Calculate median of wages
    for (i = 0; i < size; ++i) {
        total[i] = emp_ptr->wageRate;
        ++emp_ptr;
    }
    empMed_ptr->median_wageRate =  calculateMedian(total, size);

}
//*************************************************************
// Function: calcSD
//
// Purpose: Calculate the standard deviation of various inputs. Populates
//          a std_dev struct using the stored employee data
//
// Parameters:
//
//   emp_ptr     - pointer to an employee struct array
//   size        - number of employees
//   stdDev      - pointer to a std_dev struct
//
// Returns: Void
//
//**************************************************************
void calcSD(struct employee * emp_ptr, struct std_dev * empStdDev_ptr, int size) {

    float total[size];
    int i;


    // Calculate Std Dev for net pay
    for (i = 0; i < size; ++i) {
        total[i] = emp_ptr->netPay;
        ++emp_ptr;
    }
    empStdDev_ptr->std_dev_netPay =  calculateSD(total, size);

    emp_ptr -= size;
    // Calculate Std Dev for federal tax
    for (i = 0; i < size; ++i) {
        total[i] = emp_ptr->fedTax;
        ++emp_ptr;
    }
    empStdDev_ptr->std_dev_fedTax =  calculateSD(total, size);

    emp_ptr -= size;
    // Calculate Std Dev for state tax
    for (i = 0; i < size; ++i) {
        total[i] = emp_ptr->stateTax;
        ++emp_ptr;
    }
    empStdDev_ptr->std_dev_stateTax =  calculateSD(total, size);

    emp_ptr -= size;
    // Calculate Std Dev for gross pay
    for (i = 0; i < size; ++i) {
        total[i] = emp_ptr->grossPay;
        ++emp_ptr;
    }
    empStdDev_ptr->std_dev_grossPay =  calculateSD(total, size);

    emp_ptr -= size;
    // Calculate Std Dev for overtime hours
    for (i = 0; i < size; ++i) {
        total[i] = emp_ptr->overtimeHrs;
        ++emp_ptr;
    }
    empStdDev_ptr->std_dev_overtimeHrs =  calculateSD(total, size);

    emp_ptr -= size;
    // Calculate Std Dev for hours
    for (i = 0; i < size; ++i) {
        total[i] = emp_ptr->hours;
        ++emp_ptr;
    }
    empStdDev_ptr->std_dev_hours =  calculateSD(total, size);

    emp_ptr -= size;
    // Calculate Std Dev for hours
    for (i = 0; i < size; ++i) {
        total[i] = emp_ptr->wageRate;
        ++emp_ptr;
    }
    empStdDev_ptr->std_dev_wageRate =  calculateSD(total, size);

}

// Utility Functions


// *************************************************************
// Function: calculateMedian
//
// Purpose: Calculate the median of a float array
//
// Parameters:
//
//   data           - array float values
//   n              - the size of the array
//
//  Returns: float  - the median float of the array
//
//**************************************************************

float calculateMedian(float data[],int n){


    sort(data,n);

    n = (n+1) / 2 - 1;      // -1 as array indexing in C starts from 0

    printf("Median = %2f \n", data[n]);

    return data[n];

}

// *************************************************************
// Function: calculateSD
//
// Purpose: Calculate the standard deviation of a float array
//
// Parameters:
//
//   data           - array float values
//   size            - the size of the array
//
//  Returns: float  - the standard deviation float of the array
//
//**************************************************************
float calculateSD(float data[], int size) {
    float sum = 0.0, mean, SD = 0.0;
    int i;
    for (i = 0; i < size; ++i) {
        sum += data[i];
    }
    mean = sum / size;
    for (i = 0; i < size; ++i) {
        SD += pow(data[i] - mean, 2);
    }
    return sqrt(SD / size);
}

// *************************************************************
// Function: swap
//
// Purpose: swaps two pointer values
//
// Parameters:
//
//   p           - pointer to a variable
//   q           - pointer to a variable
//   t           - temporary holder
//
//  Returns: nothing
//
//**************************************************************

void swap(int *p,int *q) {
    int t;

    t=*p;
    *p=*q;
    *q=t;
}

// *************************************************************
// Function: sort
//
// Purpose: sorts two variable by reference.
//
// Parameters:
//
//   a           - float array
//   n           - size of the array
//
//  Returns: nothing
//
//**************************************************************

void sort(float a[],int n) {
    int i,j;

    for(i = 0;i < n-1;i++) {
        for(j = 0;j < n-i-1;j++) {
            if(a[j] > a[j+1])
                swap(&a[j],&a[j+1]);
        }
    }
}