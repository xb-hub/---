#include <iostream>
#include <vector>
#include "../include/data_process.h"

using namespace std;
using namespace data_process;

DataProcess::DataProcess():
        min_height(20),
        min_width(10)
{

}

DataProcess::~DataProcess()
{

}

void DataProcess::process(Mat image)
{
    realpath("../image/own_train_num", train_path);
    realpath("../image/own_test_num", test_path);
    // realpath("../image/num_train", train_path);
    // realpath("../image/num_test", test_path);
    resize(image, image, Size(640, 480));
    Mat cut_image, tmp = ~image.clone();
    // 二值化
    threshold(image, image, 127, 255, CV_THRESH_BINARY_INV);

    // 闭操作
    dilate(image, image, Mat());
    erode(image, image, Mat());

    vector<vector<Point>> contours;
    findContours(image, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    int no = 0;
    for(int i = 0; i < contours.size(); i++)
    {
        Rect rect = boundingRect(contours[i]);
        rect.x -= 5;    rect.y -= 4;
        rect.width += 10;   rect.height += 8;
        if(rect.width < min_width || rect.height < min_height)
        {
            continue;
        }
        char filename[1000];
        cut_image = tmp(rect);
        resize(cut_image, cut_image, Size(28, 28));
        if(no % 16 != 15)
        {
            sprintf(filename, "%s/%d/%d_%d.jpg", train_path, 9 - no / 16, 9 - no / 16, no % 16);
        }
        else
        {
            sprintf(filename, "%s/%d/%d_%d.jpg", test_path, 9 - no / 16, 9 - no / 16, 15 - no % 16);
        }
        imwrite(filename, cut_image);
        rectangle(image, rect, Scalar(255, 255, 255), 1);
        no++;
    }
    imshow("image", image);
    cvWaitKey(0);
}