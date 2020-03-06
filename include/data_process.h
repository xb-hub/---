#include <opencv2/opencv.hpp>
using namespace cv;

namespace data_process
{

class DataProcess
{
private:
    char train_path[1000], test_path[1000];     // 训练集保存路径，测试保存集路径
    int min_height, min_width;      // 轮廓最小宽高
    int size_;                      // 样本尺寸
    int th;                         // 反转二值化阈值
public:
    DataProcess(/* args */);
    ~DataProcess();

    void process(Mat image);
};
}
