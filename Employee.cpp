#include "Employee.h"

int Employee::m_startEmployeeId = 142100;
double Employee::m_DA = 200000;
double Employee::m_HRA = 120000;

Employee::Employee(std::string name,double basicPay):m_name(name),m_basicPay(basicPay) {
}

int Employee::generateEmployeeId() {
    return ++m_startEmployeeId;
}

double Employee::getBasicPay() const {
    return m_basicPay;
}

double Employee::getDA() const {
    return Employee::m_DA;
}
double Employee::getHRA() const {
    return Employee::m_HRA;
}
std::string Employee::getName() const {
    return m_name;
}
Employee::~Employee() {}
