#ifndef __TRAINEE_H
#define __TRAINEE_H
#include "Employee.h"
#include <map>
#include<ostream>
class Trainee:public Employee {
    int m_id;
    std::string m_trackName;
    std::map<std::string,double> m_scoreModules;
  public:
    Trainee(std::string,double,std::string);
    double payroll();
    double appraisal();
    void display();
    void addModuleScore(std::string,double);
    int getEmployeeId();
    double getAggregateScore();
    std::string getTrackName();
    friend std::ostream& operator<<(std::ostream&,Trainee&);
};
#endif // __TRAINEE_H
