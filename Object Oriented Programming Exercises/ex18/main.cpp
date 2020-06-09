/*
 * Implement and test a program that uses the class hierarchy presented in the theoretical lectures:
 * FEUP_person, Teacher and Student.
 */

#include "FeupPerson.h"
#include "Student.h"
#include "Class.h"
#include "Teacher.h"

int main() {
    Class* c1 = new Class("EDA");
    Class* c2 = new Class("EDU");

    std::vector<FeupPerson*> p(3);

    p[0] = new Teacher(987, "Pedro Santos", "Rua do Pedro", "Assistente", "MIB");
    p[1] = new Student(123, "Nuno Silva", "Rua do Nuno", "MIB", 3);
    p[2] = new Student(234, "Ana Sousa", "Rua da Ana", "MIEIC", 2);
    std::cout << "BEFORE DYNAMIC_CAST:\n";
    for (unsigned int i=0; i < p.size(); i++)
        p[i]->showRecord();
    for(unsigned int i=0; i < p.size(); i++) {
        Teacher *t = dynamic_cast<Teacher *>(p[i]);
        if (t != NULL)
            t->addClassTaught(c1);
        else {
            Student *s = dynamic_cast<Student *>(p[i]);
            if (s != NULL)
                s->addClassTaken(c2);
        }
    }
    std::cout << "AFTER DYNAMIC_CAST:\n";
    for(unsigned int i=0; i<p.size(); i++)
        p[i]->showRecord();

}