#ifndef __TRAININGBATCH_H
#define __TRAININGBATCH_H
#include "Trainee.h"
#include <list>
class TrainingBatch {
    std::list<Trainee> m_batch;
  public:
    void addTrainee(const Trainee&);
    double getAverageSalary();
    int getBatchSize() const;
};
#endif // __TRAININGBATCH_H
