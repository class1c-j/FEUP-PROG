#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>

/*
 * The following class was defined to store the relevant information about the grades of a student, in a specific course.
 * The final grade depends on the grades obtained in the short exam, the project and the exam of the course.
 */

class Student {
public:
    Student();
    Student(const std::string& code, const std::string& name);
    void setGrades(double shortExam, double project, double exam);
    std::string getCode() const;
    std::string getName()const;
    int getFinalGrade() const; // other get and set methods
    bool isApproved() const; // is the student approved or not ?
    static int weightShortExam, weightProject, weightExam;  // weights in percentage(ex:20,30,50)
private:
    std::string code; // student code
    std::string name; // student complete name
    double shortExam{}, project{}, exam{}; // grades obtained by the student in the different components
    int finalGrade{};
};

/*
 * Write the code of the setGrades() method. This method should also set the value of the finalGrade attribute, taking
 * into account the values of its parameters, and the weights of the shortExam, project, exam components in the
 * finalGrade value, which are, respectively, weightShortExam, weightProject, weightExam. The calculated value must be
 * rounded to the nearest integer; when the decimal part of the calculated value is 0.5 the finalGrade must be rounded
 * up. Justify the use of static qualifier for the attributes weightShortExam, weightProject, weightExam and define
 * them with the values 20, 30 and 50, respectively.
 *
 * It makes sense that those attributes are made static since the exam, project and short exam weight the same in
 * every student's final grade
 */

int Student::weightExam = 50, Student::weightProject = 30, Student::weightShortExam = 20;

void Student::setGrades(double shortExam, double project, double exam) {

    this->shortExam = shortExam;
    this->project = project;
    this->exam = exam;

    double aux = (weightShortExam * shortExam + weightProject * project + weightExam * exam) / 100;

    finalGrade = std::round(aux);
}

/*
 * Implement the remaining methods of class Student and develop a program to test all the methods.
 */

Student::Student() = default;

Student::Student(const std::string & code, const std::string & name) {
    this->code = code;
    this->name = name;
}

std::string Student::getCode() const {
    return code;
}

std::string Student::getName() const {
    return name;
}

int Student::getFinalGrade() const {
    return finalGrade;
}

bool Student::isApproved() const {
    return finalGrade >= 10;
}

void testA() {

    Student st("up382939463", "Sir D");
    st.setGrades(7, 1, 3);

    std::cout << st.getName() << " " << st.getCode() << "\n";
    std::cout << st.isApproved() << " " << st.getFinalGrade() << "\n";

}

/*
 * Write a function, readStudentData(), that reads from the keyboard the code, name and grades of a student (in the short
 * exam, project and exam) and returns an object of type Student, having the attributes read from the keyboard.
 */

Student readStudentData() {

    std::string code, name;
    double shortExam, project, exam;

    std::cout << '\n';

    std::cout << "Student code ? "; std::cin >> code;
    std::cout << "Student name ? "; std::cin >> name;

    Student st(code, name);

    std::cout << "Short exam grade ? "; std::cin >> shortExam;
    std::cout << "Project grade ? "; std::cin >> project;
    std::cout << "Exam grade ? "; std::cin >> exam;

    st.setGrades(shortExam, project, exam);

    return st;
}

/*
 * Write the code of a function, showAboveAverageStudents(), that receives as parameters an output stream and a
 * vector<Student> and writes to the output stream, all the data about the students whose finalGrade is above the
 * average finalGrade. The data fields must be vertically aligned
 */

void showAboveAverageStudents(std::ostream & os, const std::vector<Student> & students) {

    os << "Above average students\n";

    double average{};

    for (const auto& i : students) {
        average += i.getFinalGrade();
    }

    average /= students.size();
    std::vector<Student> above{};

    for (const auto& i : students) {
        if (i.getFinalGrade() > average) {
            above.push_back(i);
        }
    }

    os << std::left << std::setw(15) << "CODE" << std::setw(20) << "NAME" << std::setw(30) << std::right << "GRADE" << "\n";

    for (const auto& i : above) {
        os << std::left << std::setw(15) << i.getCode() << std::setw(20) << i.getName() << std::setw(30) << std::right
           << i.getFinalGrade() << "\n";
    }
}

/*
 * Write a program that reads from the keyboard the data about the students that took a course,storing them into a
 * vector<Student>, and shows on the screen the list of "above average" students
 */

void testB() {

    int n{};
    std::vector<Student> students{};

    std::cout << "How many students ? "; std::cin >> n;
    students.reserve(n);

    for (int i = 0; i < n; i++) {
        students.push_back(readStudentData());
    }

    showAboveAverageStudents(std::cout, students);
}

/*
 * Modify the program so that the student's data is read from a text file and the output is saved to another text file.
 * The input data about each student must be stored in a single text line, all items being separated by semicolons. For
 * example, the data of the example above should be stored as: up20179999;Ana Silva;13.5;17;15.7.
 */

std::vector<Student> readStudentsFile(std::ifstream &fs) {
    char sep{};
    std::string code{}, name{};
    double shortExam{}, project{}, exam{};
    std::vector<Student> students{};
    std::string temp{};
    std::getline(fs, temp, '\n');

    while (!fs.eof()) {

        std::stringstream iss(temp);
        std::getline(iss, code, ';');  // these two attributes are strings so the method bellow would not work
        std::getline(iss, name, ';');
        iss >> shortExam >> sep >> project >> sep >> exam;  // these are ints so the above method would not work
        Student st(code, name);
        st.setGrades(shortExam, project, exam);
        students.push_back(st);
        std::getline(fs, temp, '\n');
    }
    return students;
}

void testC() {
    std::string inFileName = "test.txt";
    std::ifstream ifs(inFileName);
    std::vector<Student> students = readStudentsFile(ifs);
    std::string outFileName = "out.txt";
    std::ofstream ofs(outFileName);
    showAboveAverageStudents(ofs, students);
}

int main() {
    //testA();
    //testB();
    testC();
} 
