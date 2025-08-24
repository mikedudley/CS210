#include <iostream>
#include <iomanip>
using namespace std;

class InvestmentCalculator {
public:
    // Constructor to initialize member variables
    InvestmentCalculator(double t_initial, double t_monthly, double t_interest, int t_years)
        : m_initialInvestment(t_initial), m_monthlyDeposit(t_monthly),
          m_annualInterest(t_interest), m_numYears(t_years) {}

    // Display report without monthly deposit
    void generateReportWithoutMonthlyDeposit() const {
        double balance = m_initialInvestment;
        double monthlyRate = (m_annualInterest / 100.0) / 12.0;

        cout << "\n  Balance and Interest Without Additional Monthly Deposits\n";
        printHeader();

        for (int year = 1; year <= m_numYears; ++year) {
            double interestEarned = 0.0;

            for (int month = 0; month < 12; ++month) {
                double monthlyInterest = balance * monthlyRate;
                interestEarned += monthlyInterest;
                balance += monthlyInterest;
            }

            printDetails(year, balance, interestEarned);
        }
    }

    // Display report with monthly deposit
    void generateReportWithMonthlyDeposit() const {
        double balance = m_initialInvestment;
        double monthlyRate = (m_annualInterest / 100.0) / 12.0;

        cout << "\n  Balance and Interest With Additional Monthly Deposits\n";
        printHeader();

        for (int year = 1; year <= m_numYears; ++year) {
            double interestEarned = 0.0;

            for (int month = 0; month < 12; ++month) {
                double monthlyInterest = balance * monthlyRate;
                interestEarned += monthlyInterest;
                balance += monthlyInterest;

                balance += m_monthlyDeposit; // Monthly deposit added after interest
            }

            printDetails(year, balance, interestEarned);
        }
    }

private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_numYears;

    // Print column headers
    void printHeader() const {
        cout << "===============================================\n";
        cout << "Year\t\tYear End Balance\tInterest Earned\n";
        cout << "-----------------------------------------------\n";
    }

    // Print one year of data
    void printDetails(int t_year, double t_balance, double t_interest) const {
        cout << t_year << "\t\t$"
             << fixed << setprecision(2) << t_balance << "\t\t$"
             << fixed << setprecision(2) << t_interest << endl;
    }
};

int main() {
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    int numYears;

    cout << "==============================================\n";
    cout << "  Airgead Banking Investment Calculator\n";
    cout << "==============================================\n";

    // Gather user input
    cout << "Enter Initial Investment Amount: $";
    cin >> initialInvestment;

    cout << "Enter Monthly Deposit: $";
    cin >> monthlyDeposit;

    cout << "Enter Annual Interest (%): ";
    cin >> annualInterest;

    cout << "Enter Number of Years: ";
    cin >> numYears;

    // Create calculator object
    InvestmentCalculator calculator(initialInvestment, monthlyDeposit, annualInterest, numYears);

    // Run both reports
    calculator.generateReportWithoutMonthlyDeposit();
    calculator.generateReportWithMonthlyDeposit();

    return 0;
}