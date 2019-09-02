#include "Trainee.h"

Trainee::Trainee(std::string name,double basicPay,std::string trackname):Employee(name,basicPay),
m_id(generateEmployeeId()),m_trackName(trackname) {
}

int Trainee::getEmployeeId() {
    return m_id;
}

void Trainee::addModuleScore(std::string name,double score) {
    m_scoreModules[name]=score;
}

double Trainee::getAggregateScore() {
    double totalScore=0;
    std::map<std::string,double>::iterator iter;
    for(iter=m_scoreModules.begin(); iter!=m_scoreModules.end(); ++iter) {
        totalScore += iter->second;
    }
    return totalScore;
}

double Trainee::appraisal() {
    double amount;
    if (m_scoreModules.size() != 0)
        amount = (getAggregateScore() / (100*m_scoreModules.size())) * 0.1;
    return amount*getBasicPay();
}

double Trainee::payroll() {
    return appraisal()+getBasicPay()+getDA()+getHRA();
}

std::string Trainee::getTrackName() {
    return m_trackName;
}

void Trainee::display() {
    std::cout << "Trainee Id : " << getEmployeeId() << "\n"
              << "Trainee Name : " << getName() << "\n"
              << "Trainee's track : " << getTrackName() << "\n";
}

std::ostream& operator<<(std::ostream& rout,Trainee& trainee) {
    rout << "Trainee Id : " << trainee.getEmployeeId() << "\n"
         << "Trainee Name : " << trainee.getName() << "\n"
         << "Trainee's track : " << trainee.getTrackName() << "\n";
    return rout;
}
