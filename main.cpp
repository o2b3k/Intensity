#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    Mat image, gray, im1, im2, im3, im4, im5, im6, im7, im8;

    image = imread("/home/kb1prb13/LOCAL/IG_1-14/2016-2017/Image/Intensity/lena.png", 1);
    if (!image.data) return -1;

    image.convertTo(gray, CV_8U);
    cvtColor(gray, gray, CV_BGR2GRAY);
    threshold(gray, im1, 128, 255, THRESH_BINARY);
    gray.copyTo(im8, gray);
    gray.copyTo(im7, gray);
    gray.copyTo(im6, gray);
    gray.copyTo(im5, gray);
    gray.copyTo(im4, gray);
    gray.copyTo(im3, gray);
    gray.copyTo(im2, gray);
    gray.copyTo(im1, gray);

    for (int y = 0; y < im8.cols; y++) {
        for (int x = 0; x < im8.rows; x++) {
            im8.at<uchar>(y, x) /=  1;
            im7.at<uchar>(y, x) /=  2;
            im6.at<uchar>(y, x) /=  4;
            im5.at<uchar>(y, x) /=  8;
            im4.at<uchar>(y, x) /= 16;
            im3.at<uchar>(y, x) /= 32;
            im2.at<uchar>(y, x) /= 64;
            im1.at<uchar>(y, x) /= 128;
        }
    }

    gray.assignTo(gray, 128);

//    threshold(im7, im7, 128, 255, THRESH_BINARY);
//    threshold(im7, im7,  64, 255, THRESH_BINARY);
//    threshold(im7, im7,  32, 255, THRESH_BINARY);
//    threshold(im7, im7,  16, 255, THRESH_BINARY);

    namedWindow("Original", CV_WINDOW_AUTOSIZE);
    namedWindow("Gray", CV_WINDOW_AUTOSIZE);
    namedWindow("1-bit", CV_WINDOW_AUTOSIZE);
    namedWindow("2-bit", CV_WINDOW_AUTOSIZE);
    namedWindow("3-bit", CV_WINDOW_AUTOSIZE);
    namedWindow("4-bit", CV_WINDOW_AUTOSIZE);
    namedWindow("5-bit", CV_WINDOW_AUTOSIZE);
    namedWindow("6-bit", CV_WINDOW_AUTOSIZE);
    namedWindow("7-bit", CV_WINDOW_AUTOSIZE);
    namedWindow("8-bit", CV_WINDOW_AUTOSIZE);
    imshow("Original", image);
    imshow("Gray", gray);
    imshow("1-bit", im1);
    imshow("2-bit", im2);
    imshow("3-bit", im3);
    imshow("4-bit", im4);
    imshow("5-bit", im5);
    imshow("6-bit", im6);
    imshow("7-bit", im7);
    imshow("8-bit", im8);
    waitKey(0);
}