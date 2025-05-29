//
// Created by smmm on 29.05.2025.
//
#include "implementation/advancedStudent/AdvancedStudent.h"
#include "implementation/student/Student.h"

#include <iostream>

int main() {
    Student student("Иван", "Иванов", "Иванович", "ул. Ленина, 1",
                     "МГУ", "A12345");
    student.SetAddress("ул. Пушкина, 10");
    std::cout << "Студент: " << student.GetFirstName() << " "
              << student.GetLastName() << ", Университет: "
              << student.GetUniversity() << " (ID: "
              << student.GetStudentId() << "), Адрес: "
              << student.GetAddress() << std::endl;

    AdvancedStudent grad("Петр", "Петров", "Петрович", "ул. Мира, 5",
                          "СПбГУ", "B98765", "Искусственный интеллект");
    std::cout << "Аспирант: " << grad.GetFirstName() << " "
              << grad.GetLastName() << ", Тема диссертации: "
              << grad.GetDissertationTopic() << std::endl;

    return 0;
}
