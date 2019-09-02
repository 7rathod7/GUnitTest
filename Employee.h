#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H
#include <string>
#include <iostream>
class Employee {
    std::string m_name;
    double m_basicPay;
    static int m_startEmployeeId;
    static double m_DA;
    static double m_HRA;
  public:
    Employee(std::string,double);
    virtual double payroll()=0;
    virtual double appraisal()=0;
    virtual void display()=0;
    int generateEmployeeId();
    double getBasicPay() const;
    double getDA() const;
    double getHRA() const;
    std::string getName() const;
    virtual ~Employee();
};
#endif // __EMPLOYEE_H
