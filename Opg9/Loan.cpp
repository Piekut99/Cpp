#include "Loan.h"
#include <math.h>
#include <array>
#include <iomanip>
Loan::Loan() {}


Loan::Loan ( double debt , int years , int paymentsPerYear , double interestRate )
{
    _debt = debt;
    _years = years;
    _paymentsPerYear = paymentsPerYear;
    _interestRate = interestRate;
};

// Returns the number of years the loan lasts
int Loan::getYears () const {
    return _years;
}
void Loan::setYears (int years ) {
    _years = years;
}

// Amount of payments per year ( terminer )
int Loan::getPaymentsPerYear () const {
    return _paymentsPerYear;
}
void Loan::setPaymentsPerYear ( int paymentsPerYear ) {
    _paymentsPerYear = paymentsPerYear;
}

// Debt
double Loan::getDebt () const {
    return _debt;
}
void Loan::setDebt ( double debt ) {
    _debt = debt;
}

// Rente
double Loan::getInterestRate () const {
    return _interestRate;
}
void Loan::setInterestRate ( double rate ) {
    _interestRate = rate;
}

double Loan::totalInterest() const {
    // lrint uses bankers rounding to int
    return lrint((Loan::totalPayment() - _debt) * 100) / 100.0;
}

double Loan::totalPayment() const {
    double G, r, y;
    int n;
    G = _debt;
    r = _interestRate / _paymentsPerYear / 100;
    n = _paymentsPerYear * _years;
    y = G * r /( 1 - pow(1 + r, -n));

    return y * n;
}

// returns the amount of money the banks earns
double Loan::totalInterestTaxDeducted(double taxDeductionRate) const {
    return Loan::totalInterest() * (taxDeductionRate/100);
}

void Loan::outputPeriodicalPayments(std::ostream &ost) const {
    int n = _paymentsPerYear * _years;
    double debtLeft = _debt;
    double PP[n][3]; {};
    double taxDeductionRate = 30.6 / 100;
    ost << "|Debt Remaining| " << "Interest expence| " << "Taxdeduction|" << std::endl;
    for (int i = 0; i < n ; i++ ) {
        PP[i][0] = debtLeft;
        PP[i][1] = Loan::interestExpenses(debtLeft);
        PP[i][2] = Loan::interestExpenses(debtLeft) * taxDeductionRate;
        debtLeft = debtLeft - (payment() - interestExpenses(debtLeft));
    }
    Loan::print(PP, n, std::cout);
}

double Loan::interestExpenses(double debt) const {
    double r = _interestRate / _paymentsPerYear / 100;
    return debt * r;
}

double Loan::payment() const {
    double G, r, y;
    int n;
    G = _debt;
    r = _interestRate / _paymentsPerYear / 100;
    n = _paymentsPerYear * _years;
    y = G * r /( 1 - pow(1 + r, -n)); // Returns the payment each period

    return y;
}

void Loan::print(double **array, int rows, std::ostream &ost) const{
    double** ptrArray;
    for (int i = 0; i < rows ; i++ ) {
        ptrArray = array;
        std::cout << std::fixed << std::setprecision(2);
        ost << "|"<< std::setw(14) <<ptrArray[i][0] << "|"
         << std::setw(17) << ptrArray[i][1]<< "|"
         << std::setw(13) << ptrArray[i][2]<< "|" << std::endl;
    }
}
/*
std::cout << std::fixed << std::setprecision(2);
ost << "|"<< std::setw(14) <<PP[i][0] << "|"
<< std::setw(17) << PP[i][1]<< "|"
<< std::setw(13) << PP[i][2]<< "|" << std::endl;
*/
