/*
 
   Adapt the program presented in the lecture notes for computing the average score for each student and the average score
   for each quizz, using a 2D array, so that the number of students and the number of questions can be specified in run-time,
   by the user ofthe program. Use dynamic memory allocation for the 2D array.
   
*/


#include <iostream>
#include <iomanip>

void fill_grades(int **grade, int number_students, int number_quizzes) {
    for (int st_num = 0; st_num < number_students; st_num ++) {
        for (int quiz_num = 0; quiz_num < number_quizzes; quiz_num ++) {
            grade[st_num][quiz_num] = 10 + rand() % 11;
        }
    }
}

void compute_st_ave(int **grade, double *st_ave, int number_students, int number_quizzes) {
    for (int st_num = 0; st_num < number_students; st_num ++) {
        double sum = 0;
        for(int quiz_num = 0; quiz_num < number_quizzes; quiz_num ++) {
            sum += grade[st_num][quiz_num];
        }
        st_ave[st_num] = sum/number_quizzes;
    }
}

void compute_quiz_ave(int **grade, double *quiz_ave, int number_students, int number_quizzes) {
    for (int quiz_num = 0; quiz_num < number_quizzes; quiz_num ++) {
        double sum = 0;
        for (int st_num = 0; st_num < number_students; st_num ++) {
            sum += grade[st_num][quiz_num];
        }
        quiz_ave[quiz_num] = sum/number_students;
    }
}

void display(int **grade, const double *st_ave, const double *quiz_ave, int number_students, int number_quizzes) {
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(1);
    std::cout << std::setw(10) << "Student" << std::setw(5) << "Ave" << std::setw(15) << "Quizzes\n";
    for (int st_num = 0; st_num < number_students; st_num ++) {
        std::cout << std::setw(10) << st_num + 1 << std::setw(5) << st_ave[st_num] << " ";
        for (int quiz_num = 0; quiz_num < number_quizzes; quiz_num ++) {
            std::cout << std::setw(5) << grade[st_num][quiz_num];
        }
        std::cout << std::endl;
    }
}

int main() {
    int n_students, n_quizzes;
    std::cout << "Number of students ? "; std::cin >> n_students;
    std::cout << "Number of quizzes ? "; std::cin >> n_quizzes;
    int** grade = new int*[n_students];
    for (int i = 0; i < n_students; i ++) {
        grade[i] = new int[n_quizzes];
    }
    double *st_ave;
    st_ave = new double[n_students];
    double *quiz_ave;
    quiz_ave = new double[n_quizzes];

    fill_grades(grade, n_students, n_quizzes);
    compute_st_ave(grade, st_ave, n_students, n_quizzes);
    display(grade, st_ave, quiz_ave, n_students, n_quizzes);
}
