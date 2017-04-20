#include <iostream>
#include <fstream>

int min = 0, max = 0, lastIndex = 0;
int *BucketAry;


void constructor(int min, int max);

void findMinMax(std::fstream &infile, std::ofstream &output);

void printSortData(std::fstream &infile, std::ofstream &output);

int getIndex(int data);

int main(int argc, char *argv[]) {
    std::fstream infile(argv[1]); // input file
    std::ofstream output(argv[2]); // output file
    findMinMax(infile, output);

    constructor(min, max);
    infile.open(argv[1]);
    printSortData(infile, output);

    return 0;
}

void findMinMax(std::fstream &infile, std::ofstream &output) {
    int num;
    bool firstTime = true;
    while (infile >> num) {
        if (num < 0) output << "Negative number in input";
        if (num > max) max = num;
        if (firstTime) {
            min = num;
            firstTime = false;
        }
        if (num < min) min = num;
    }
    infile.close();
}

void constructor(int min, int max) {
    BucketAry = new int[max - min + 1]();
    lastIndex = max - min + 1;
}

int getIndex(int data) {
    return data - min;
}

void printSortData(std::fstream &infile, std::ofstream &output) {
    int num, index, count;
    while (infile >> num) {
        index = getIndex(num);
        BucketAry[index]++;
    }
    for (int i = 0; i < lastIndex; i++) {
        if (BucketAry[i] != 0) {
            count = BucketAry[i];
            for (int j = 0; j < count; j++) {
                output << i+min << " ";
            }
        }
    }
    infile.close();
    output.close();
}

