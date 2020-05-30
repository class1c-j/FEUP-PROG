/*
 
   A binary image is an image made of black and white pixels. It can be represented in a text file using, for instance,
   character 'b' to represent black pixels and character 'w' to represent white pixels. For example, the binary image
   on the right could be represented by the text file shown below (A); the 2 numbers at the beginning of the text file
   (10 10, in this case) represent the number of lines and the number os columns of the image. Run-length encoding (RLE)
   is a form of lossless data compression in which "runs" of data (sequences in which the same data value occurs in many
   consecutive data elements) are stored as a single data value and count, rather than as the original run;
   this is most useful on data that contains many long runs. Using RLE, the pixels of the image in the example could be
   represented by the sequence illustrated in B, resulting in a compression from 100 characters to 72 characters.
   Example:
   A)Contents of an original image file:
   10 10 bbbbbbbbbbbbbwwwwbbbbbwwwwwwbbbwwwwwwwwbwwwwwwwwwwbwwwwwwwwbbwbwbbwbwbbwbwbbwbwbbwwwbbwwwbbwwwbbwwwb
   B)Compressed file (using RLE) resulting from the original file above:
   10 10 13b4w5b6w3b8w1b10w1b8w2b1w1b1w2b1w1b1w2b1w1b1w2b1w1b1w2b3w2b3w2b3w2b3w1b
  
   a)Write a program that takes as input a binary image file, in the format illustrated in A, and compresses it, using RLE,
   producing a file in the format illustrated in B. The names of the original file and of the compressed file must be passed
   as command line arguments. Being compress the name of the executable code, it must be run using the command
   compress <uncompressedimage> <compressedimage>;
   example: compress  img1  img1c.
   The program must end immediately if the number of arguments is not valid or the original image file does not exist.
  
*/

#include <fstream>
#include <string>
#include <iostream>

void readFile(const std::string &fileName, std::string &content) {
    std::ifstream f_in(fileName, std::ios::binary);
    if (!f_in.is_open()) {
        exit(1);
    }
    char c;
    c = f_in.get();
    while (!f_in.eof()) {
        content += c;
        c = f_in.get();
    }
}

void writeFile(const std::string &fileName, const std::string& content) {
    std::ofstream f_out(fileName, std::ios::binary);
    f_out << content;

}

std::string compressRLE(std::string &content) {
    std::string result;
    for (int i = 0; i < content.size(); i ++) {
        if (isalpha(content.at(i))) {
            int count = 1;
            while (content.at(i) == content.at(i + 1)) {
                count++;
                i++;
            }
            result += std::to_string(count);
            result += content.at(i);
        } else {
            result += content.at(i);
        }
    }
    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Invalid usage!\n";
        exit(1);
    }
    std::string fileRead = argv[1];
    std::string fileWrite = argv[2];
    std::string content;
    readFile(fileRead, content);
    writeFile(fileWrite, compressRLE(content));
}

/*
   Write a program, that takes as input a file representing a compressed image and produces the corresponding uncompressed image.
   It must be executed using the command uncompress <compressedimage> <uncompressedimage>
  
*/

std::string decompressRLE(std::string &content) {
    std::string result;
    size_t index = 0;
    for (int i = 0; i < 2; ++i){
        index = (content.find(' ', index)) + 1;
    }
    std::string dimensions = content.substr(0, index);
    std::string compressed = content.substr(index);
    result += dimensions;
    for (int i = 0; i < compressed.size(); i ++) {
        int n;
        std::string temp;
        while (isdigit(compressed.at(i))) {
            temp += compressed.at(i);
            n = atoi(temp.c_str());
            i++;
        }
        while (n) {
            result += compressed.at(i);
            n--;
        }
    }
    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Invalid usage!\n";
        exit(1);
    }
    std::string content;
    std::string fileRead = argv[1];
    std::string fileWrite = argv[2];
    readFile(fileRead, content);
    writeFile(fileWrite, decompressRLE(content));
    //writeFile(fileWrite, compressRLE(content));
}
