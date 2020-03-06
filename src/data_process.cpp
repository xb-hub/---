#include <iostream>
#include <vector>
#include "data_process.h"

using namespace std;
using namespace data_process;

DataProcess::DataProcess():
        min_height(20),
        min_width(10),
        size_(28),
        th(105)
{

}

DataProcess::~DataProcess()
{

}

void DataProcess::process(Mat image)
{
    realpath("../image/own_train_num", train_path);
    realpath("../image/own_test_num", test_path);
    Mat cut_image, tmp = ~image.clone();
    // 反转二值化
    threshold(image, image, th, 255, CV_THRESH_BINARY_INV);

    // 闭操作
    dilate(image, image, Mat());
    erode(image, image, Mat());

    vector<vector<Point>> contours;
    findContours(image, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    int no = 0;
    for(int i = 0; i < contours.size(); i++)
    {
        Rect rect = boundingRect(contours[i]);
        // 处理最小矩形轮廓,防止图像转成28*28时变形
        rect.x -= 4;    rect.y -= 4;
        rect.width += 8;   rect.height += 8;
        if(rect.width < min_width || rect.height < min_height)
        {
            continue;
        }
        char filename[1000];
        cut_image = tmp(rect);
        resize(cut_image, cut_image, Size(size_, size_));
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
    // imshow("image", image);
    // cvWaitKey(0);
}