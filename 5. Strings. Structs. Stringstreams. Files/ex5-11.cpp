/*
  
   Redo problem 5.2.b so that the person names are read from a text file, whose name is entered by the user.
   Each line of the text file contains a person's name.
   Build two versions of the program, in which:
   
   a) the sorted names are written to the standard ouput (the screen);
   
*/

void readNames(std::vector<std::string> &names, const std::string& file) {
    std::ifstream f_in;
    f_in.open(file);
    if (!f_in.is_open()) {
        std::cerr << "File not found\n";
    } else {
        std::string s;
        while (std::getline(f_in, s)) {
            names.push_back(s);
        }
    }
    f_in.close();
}

void testA() {
    std::string file;
    std::vector<std::string> names;
    std::cout << "File ? ";
    std::cin >> file;
    readNames(names, file);
    std::sort(names.begin(), names.end());
    for (auto i : names) {
        std::cout << i << std::endl;
    }
}


/*
 
   b) the sorted names are written to a file having the same name as the input file name, with the suffix
   "_sorted";
   example: if the input file name is "names.txt" the output file name must be "names_sorted.txt".
  
*/

void writeNames(const std::vector<std::string> &names, const std::string &file) {
    std::string f_name = file + "_sorted";
    std::ofstream f_out(f_name);
    for (const std::string& i : names) {
        f_out << i << "\n";
    }
}

void testB() {
    std::string file;
    std::vector<std::string> names;
    std::cout << "File ? ";
    std::cin >> file;
    readNames(names, file);
    std::sort(names.begin(), names.end());
    writeNames(names, file);
}

int main() {
    //testA();
    testB();
}
