#include <iostream>
#include <vector>
#include "creat_template.h"

using namespace std;
using namespace creat_template;

CreatTemplate::CreatTemplate(Kind kind) :
    template_path("../template/template.txt"),
    th(127)
{
    if(kind == MNIST)
    {
        train_path = "../image/num_train/link.txt";
    }
    else if(kind == OWN)
    {
        train_path = "../image/own_train_num/link.txt";
    }
}

CreatTemplate::~CreatTemplate()
{

}

void CreatTemplate::create()
{
    fstream file(train_path);
    ofstream os(template_path, fstream::out | ios_base::trunc);
    string link, file_path;
    int label, count = 0, value;
    Mat number;
    while (getline(file, link)) // 根据路径找到文件
    {
        string template_ = "";
        file_path = link.substr(0, link.size() - 2);    // 数据图片路径
        label = link.back() - '0';                      // 数据标签
        number = imread(file_path, IMREAD_GRAYSCALE);   // 打开图片
        // 遍历图像并计算灰度值，和设定的阈值th进行比较
        // for(int i = 0; i < 7; i++)      // 压缩处理
        // {
        //     for(int j = 0; j < 7; j++)
        //     {
        //         count = 0;
        //         for(int m = 0; m < 4; m++)
        //         {
        //             for(int n = 0; n < 4; n++)
        //             {
        //                 value = (int)number.at<uchar>(i * 4 + m,j * 4 + n);
        //                 if(value > th) count++;
        //             }
        //         }
        //         template_ += count >= 8 ? "1" : "0";
        //     }
        // }
        for(int i = 0; i < number.rows; i++)     // 直接处理
        {
            for(int j = 0; j < number.cols; j++)
            {
                template_ += (int)number.at<uchar>(i,j) >= th ? "0" : "1";
            }
        }
        os << label << template_ << endl;
    }
    file.close();
    os.close();
}