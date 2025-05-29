//
// Created by smmm on 29.05.2025.
//

#ifndef ISTUDENT_H
#define ISTUDENT_H

#include "interface/person/IPerson.h"

#include <string>

struct IStudent : public IPerson {
    [[nodiscard]] virtual std::string GetUniversity() const = 0;
    virtual void SetUniversity(const std::string&) = 0;
    [[nodiscard]] virtual std::string GetStudentId() const = 0;
    virtual void SetStudentId(const std::string&) = 0;
};

struct IAdvancedStudent : public IStudent {
    [[nodiscard]] virtual std::string GetDissertationTopic() const = 0;
    virtual void SetDissertationTopic(const std::string&) = 0;
};

#endif //ISTUDENT_H
