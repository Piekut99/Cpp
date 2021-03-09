#ifndef LOAN_H
#define LOAN_H
#include<iostream>

class Loan {
public :
    Loan ();

    // Loan constructor
    Loan ( double debt , int years , int paymentsPerYear , double interestRate );

    // Returns the number of years the loan lasts
    int getYears () const ;
    void setYears (int years );

    // Amount of payments per year ( terminer )
    int getPaymentsPerYear () const ;
    void setPaymentsPerYear ( int paymentsPerYear );

    // Debt
    double getDebt () const ;
    void setDebt ( double debt );

    // Rente
    double getInterestRate () const ;
    void setInterestRate ( double rate );

    // Calculate the total interest of a loan for all the years
    double totalInterest () const ;

    // Calculate the total repayment of a loan including the interests
    double totalPayment () const ;

    // Calculate the total net interest of a loan after tax refund
    double totalInterestTaxDeducted ( double taxDeductionRate ) const ;

    // Output the periodical payments with unpaid balance,
    // paid interest and repayment of each payment to stream
    // object ost
    void outputPeriodicalPayments (std::ostream& ost) const ;

    // Help
    double interestExpenses (double debt) const ;
    double payment() const;
<<<<<<< HEAD
    void printPP(double **arr, int const first, int const second, std::ostream& ost) const;

=======
    double ** initializeArray(double ** array);
>>>>>>> parent of 293ad1a ([working])
private :
    double _debt , _interestRate;
    int _years , _paymentsPerYear;
};

#endif // LOAN_H
