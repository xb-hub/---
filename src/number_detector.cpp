#include <iostream>
#include "../include/number_detector.h"

using namespace std;
using namespace number_detector;

NumberDetector::NumberDetector() : 
    // test_path("../image/num_test/link.txt"),
    test_path("../image/own_test_num/link.txt"),
    template_path("../template/template.txt"),
    th(127)
{

}

NumberDetector::~NumberDetector()
{

}

void NumberDetector::detector()
{
    vector<int> ans[10];
    fstream test_file(test_path);
    string test_link, template_link, file_path;
    int test_label, template_label, value, count = 0;
    Mat number;
    double current_count = 0, total = 0;
    while (getline(test_file, test_link))
    {
        string template_ = "";
        fstream template_file(template_path);
        file_path = test_link.substr(0, test_link.size() - 2);    // 数据图片路径
        test_label = test_link.back() - '0';                      // 数据标签
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
        for(int i = 0; i < 28; i++)     // 直接处理
        {
            for(int j = 0; j < 28; j++)
            {
                template_ += number.at<uchar>(i,j) >= th ? "0" : "1";
            }
        }
        int i = 0, max_dist = INT_MAX;
        while (getline(template_file, template_link))
        {
            int dist = 0;
            template_label = template_link[0] - '0';
            string tmp = template_link.substr(1, template_link.size() - 1);
            for(int j = 0; j < tmp.size(); j++)
            {
                if(tmp[j] != template_[j])
                {
                    dist++;
                }
            }
            ans[template_label].push_back(dist);
            if(dist < max_dist)
            {
                ans_label = template_label;
                max_dist = dist;
            }
        }
        if(ans_label == test_label)  current_count++;
        total++;
        cout << "识别结果：" << ans_label << "  " << "测试标签：" << test_label << endl;
    }
    cout << "------------------------------------------------" << endl;
    cout << "测试样本总数：" << total << endl;
    cout << "识别正确个数：" << current_count << endl;
    cout << "正确率：" << current_count / total * 100 << "%  错误率：" << (total - current_count) / total * 100 << "%" << endl;
}
