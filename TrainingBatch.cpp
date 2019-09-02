#include "TrainingBatch.h"

void TrainingBatch::addTrainee(const Trainee& trainee) {
    m_batch.push_back(trainee);
}

double TrainingBatch::getAverageSalary() {
    double salaries=0;
    if (m_batch.size()) {
        std::list<Trainee>::iterator iter;
        for(iter=m_batch.begin(); iter!=m_batch.end(); ++iter) {
            salaries+=iter->payroll();
        }
    } else
        return 0.0;
    return salaries/m_batch.size();
}

int TrainingBatch::getBatchSize() const {
    return m_batch.size();
}
