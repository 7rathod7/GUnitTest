#include<iostream>
#include "Trainee.h"
#include "TrainingBatch.h"
#include <gtest/gtest.h>

namespace Assessment {
namespace trainee {
class TraineeTest:public ::testing::Test {
  protected:
    Trainee *traineePtr;
    void SetUp() {
        traineePtr = new Trainee("rathod",100000,"New Mobility");
    }
    void TearDown() {
        delete traineePtr;
    }
};

TEST_F(TraineeTest, parametricConstructor) {
    EXPECT_EQ("rathod", traineePtr->getName());
    EXPECT_EQ(142101, traineePtr->getEmployeeId());
    EXPECT_EQ(420000, traineePtr->payroll());
    EXPECT_EQ("New Mobility", traineePtr->getTrackName());
    EXPECT_EQ(0,traineePtr->getAggregateScore());
}

TEST_F(TraineeTest, autoEmployeeIdGeneration) {
    EXPECT_EQ(142102,traineePtr->getEmployeeId());
    Trainee otherTrainee("dinesh",200000,"Diagnostic");
    EXPECT_EQ(142103,otherTrainee.getEmployeeId());
    EXPECT_EQ(0,otherTrainee.getAggregateScore());
    EXPECT_EQ("dinesh", otherTrainee.getName());
    EXPECT_EQ(520000, otherTrainee.payroll());
    EXPECT_EQ("Diagnostic", otherTrainee.getTrackName());
}

TEST_F(TraineeTest, addModuleScore) {
    traineePtr->addModuleScore("C++",50);
    traineePtr->addModuleScore("Java",50);
    traineePtr->addModuleScore("Python",50);
    EXPECT_EQ(150,traineePtr->getAggregateScore());
}

TEST_F(TraineeTest,payroll) {
    traineePtr->addModuleScore("C++",50);
    traineePtr->addModuleScore("Java",50);
    traineePtr->addModuleScore("Python",50);
    EXPECT_EQ(425000,traineePtr->payroll());
}

TEST_F(TraineeTest, display) {
    std::string input= "Trainee Id : 142106\nTrainee Name : rathod\nTrainee's track : New Mobility\n";
    ::testing::internal::CaptureStdout();
    traineePtr->display();
    std::string output = ::testing::internal::GetCapturedStdout();
    EXPECT_EQ(input,output);
}

TEST_F(TraineeTest, operatorOverloading) {
    std::string input= "Trainee Id : 142107\nTrainee Name : rathod\nTrainee's track : New Mobility\n";
    ::testing::internal::CaptureStdout();
    std::cout << *traineePtr;
    std::string output = ::testing::internal::GetCapturedStdout();
    EXPECT_EQ(input,output);
}

TEST_F(TraineeTest,appraisal) {
    traineePtr->addModuleScore("C++",50);
    traineePtr->addModuleScore("Java",50);
    traineePtr->addModuleScore("Python",50);
    EXPECT_EQ(5000,traineePtr->appraisal());
}
}

namespace DynamicBindingTest {
TEST(DynamicBindingTest, display) {
    Trainee trainee("tony",100000,"Marvel");
    std::string input= "Trainee Id : 142109\nTrainee Name : tony\nTrainee's track : Marvel\n";
    ::testing::internal::CaptureStdout();
    Employee &employee = trainee;
    employee.display();
    std::string output = ::testing::internal::GetCapturedStdout();
    EXPECT_EQ(input,output);
}

TEST(DynamicBindingTest, appraisal) {
    Trainee trainee("tony",100000,"Marvel");
    trainee.addModuleScore("AI",100);
    trainee.addModuleScore("Athletic",100);
    Employee &employee=trainee;
    EXPECT_EQ(10000,employee.appraisal());
}
TEST(DynamicBindingTest, payroll) {
    Trainee trainee("tony",100000,"Marvel");
    trainee.addModuleScore("AI",100);
    trainee.addModuleScore("Athletic",100);
    Employee &employee=trainee;
    EXPECT_EQ(430000,employee.payroll());
}
}

namespace Batch {
TEST(TrainingBatchTest, addTrainee) {
    TrainingBatch batch;
    EXPECT_EQ(0,batch.getAverageSalary());
    EXPECT_EQ(0,batch.getBatchSize());
    batch.addTrainee(Trainee("tony",200000,"Marvel"));
    batch.addTrainee(Trainee("steve",100000,"Marvel"));
    EXPECT_EQ(2,batch.getBatchSize());
}

TEST(TrainingBatchTest, getAverageSalary) {
    TrainingBatch batch;
    batch.addTrainee(Trainee("tony",200000,"Marvel"));
    batch.addTrainee(Trainee("steve",100000,"Marvel"));
    EXPECT_EQ(470000,batch.getAverageSalary());
}
}

}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
//    Trainee trainee("tony",1000000,"New Mobility");
//    std::cout << trainee.getEmployeeId() << "\n";
//    Trainee trainee1("stark",11000,"New Mobility");;
//    std::cout << trainee1.getEmployeeId() << "\n";
//    Trainee trainee2("iron man",10000000,"New Mobility");;
//    std::cout << trainee2.getEmployeeId() << "\n";
//    Trainee trainee3("robert jr downey",5000000,"New Mobility");;
//    std::cout << trainee3.getEmployeeId() << "\n";
//
//    trainee1.addModuleScore("c++",19);
//    trainee1.addModuleScore("java",10.1);
//    trainee1.addModuleScore("python",1);
//
//    std::cout << trainee1.getAggregateScore() << "\n";
//    std::cout << trainee1.appraisal() << "\n";
//    std::cout << trainee1.payroll() << "\n";
//
//    trainee1.display();
//
//    std::cout << "---------------------------------\n";
//    std::cout << trainee3;
//
//    Employee &employee = trainee2;
//
//    employee.display();
//
//    TrainingBatch batch;
//    batch.addTrainee(trainee);
//    batch.addTrainee(trainee1);
//    batch.addTrainee(trainee2);
//    batch.addTrainee(trainee3);
//
//    std::cout << batch.getAverageSalary() << "\n";

    return 0;
}
