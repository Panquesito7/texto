#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include "scales.hpp"

using namespace cv;
using namespace std;


vector<string> convertMatIntoArray(const cv::Mat& material) {
    vector<string> lines;
    for (int i{0}; i < material.rows; i++) {
        string line;
        for (int j{0}; j < material.cols; j++) {
            int pixel = (int)material.at<uchar>(i,j);
            line += GRAYSCALE[pixel % GRAYSCALE.length()];
        }
        lines.push_back(line);
    }
    return lines;
}


void write(const vector<string>& input) {
    for(const auto& value : input){
        cout << value;
    }
}

int main(){
    Mat image = imread("../image.png");

    if (image.empty()){
        cout << "couldn't read image";
        return -1;
    }

    cvtColor(image, image, COLOR_BGR2GRAY);

    vector<string> imageChar = convertMatIntoArray(image);
    write(imageChar);
    return 0;
}

