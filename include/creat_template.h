#ifndef _CreatTemplate_H_
#define _CreatTemplate_H_
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

namespace creat_template
{
enum Kind
{
    OWN = 0,
    MNIST = 1
};
class CreatTemplate
{
private:
    string train_path;          // 训练集路径
    string template_path;       // 模板文件路径
    int th;
public:
    CreatTemplate(Kind kind);
    ~CreatTemplate();

    void create();
};
    
} // namespace number_detector
#endif