#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
Mat image, gray, im1, im2, im3, im4, im5, im6, im7, im8;

void process(){
    image.convertTo(gray, CV_8U);
    cvtColor(gray, gray, CV_BGR2GRAY);

    gray.copyTo(im8);
    gray.copyTo(im7);
    gray.copyTo(im6);
    gray.copyTo(im5);
    gray.copyTo(im4);
    gray.copyTo(im3);
    gray.copyTo(im2);
    gray.copyTo(im1);

    for (int y = 0; y < gray.rows; y++) {
        for (int x = 0; x < gray.cols; x++) {
            im8.at<uchar>(y, x) = (gray.at<uchar>(y, x) & uchar(128)) ? uchar(255) : uchar(0);
            im7.at<uchar>(y, x) = (gray.at<uchar>(y, x) & uchar( 64)) ? uchar(255) : uchar(0);
            im6.at<uchar>(y, x) = (gray.at<uchar>(y, x) & uchar( 32)) ? uchar(255) : uchar(0);
            im5.at<uchar>(y, x) = (gray.at<uchar>(y, x) & uchar( 16)) ? uchar(255) : uchar(0);
            im4.at<uchar>(y, x) = (gray.at<uchar>(y, x) & uchar(  8)) ? uchar(255) : uchar(0);
            im3.at<uchar>(y, x) = (gray.at<uchar>(y, x) & uchar(  4)) ? uchar(255) : uchar(0);
            im2.at<uchar>(y, x) = (gray.at<uchar>(y, x) & uchar(  2)) ? uchar(255) : uchar(0);
            im1.at<uchar>(y, x) = (gray.at<uchar>(y, x) & uchar(  1)) ? uchar(255) : uchar(0);
        }
    }
}

void imShow(){
    namedWindow("Lena",  CV_WINDOW_AUTOSIZE);
    namedWindow("Gray",  CV_WINDOW_AUTOSIZE);
    namedWindow("1-bit", CV_WINDOW_AUTOSIZE);
    namedWindow("2-bit", CV_WINDOW_AUTOSIZE);
    namedWindow("3-bit", CV_WINDOW_AUTOSIZE);
    namedWindow("4-bit", CV_WINDOW_AUTOSIZE);
    namedWindow("5-bit", CV_WINDOW_AUTOSIZE);
    namedWindow("6-bit", CV_WINDOW_AUTOSIZE);
    namedWindow("7-bit", CV_WINDOW_AUTOSIZE);
    namedWindow("8-bit", CV_WINDOW_AUTOSIZE);

    imshow("Lena",image);
    imshow("Gray", gray);
    imshow("1-bit", im1);
    imshow("2-bit", im2);
    imshow("3-bit", im3);
    imshow("4-bit", im4);
    imshow("5-bit", im5);
    imshow("6-bit", im6);
    imshow("7-bit", im7);
    imshow("8-bit", im8);
//    imwrite("/home/kb1prb13/LOCAL/IG_1-14/2016-2017/Image/Intensity/lena.jpg", im7);
    waitKey(0);
}

int main() {
    image = imread("/home/kb1prb13/LOCAL/IG_1-14/2016-2017/Image/Intensity/lena.png", 1);
    if (!image.data) return -1;
    
    image.convertTo(out,CV_8U);
    for(int y=0;y<out.cols;y++){
        for(int x=0;x<out.rows;x++){
            out.at<uchar>(y,x) /= 2;
        }
    }
    process();
    imShow();
    return 0;
}
