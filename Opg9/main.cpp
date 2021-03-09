#include <iostream>
#include "Loan.h"

using namespace std;

int main()
{
    double debt, interestRate;
    int    years, paymentsPerYear;
    //cout << "Please input debt, years, number of payments and the interest rate" << endl;
    //cin >> debt >> years >> paymentsPerYear >> interestRate;

    //Loan loan(debt, years, paymentsPerYear, interestRate);
    Loan loan(100000, 30, 4, 3);
    /* cout <<"The total payments is = " << loan.totalPayment() << "kr" << endl;
    cout <<"The total interest is = " << loan.totalInterest() << "kr" <<endl;
    cout <<"The total tax deduction is = " << loan.totalInterestTaxDeducted(30.6) << "kr" << endl;
    */
    loan.outputPeriodicalPayments(cout);
    return 0;
}
