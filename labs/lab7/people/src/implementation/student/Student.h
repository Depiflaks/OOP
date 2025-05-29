//
// Created by smmm on 29.05.2025.
//

#ifndef STUDENT_H
#define STUDENT_H
#include "implementation/StudentImpl.h"
#include "interface/student/IStudent.h"

class Student final : public StudentImpl<IStudent>
{

};

#endif // STUDENT_H
