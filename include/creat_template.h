#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

namespace creat_template
{
class CreatTemplate
{
private:
    string train_path;          // 训练集路径
    string template_path;       // 模板文件路径
    int th;
public:
    CreatTemplate(/* args */);
    ~CreatTemplate();

    void create();
};
    
} // namespace number_detector
