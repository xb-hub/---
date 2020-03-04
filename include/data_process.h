#include <opencv2/opencv.hpp>
using namespace cv;

namespace data_process
{

class DataProcess
{
private:
    char train_path[1000], test_path[1000];
    int min_height, min_width;
public:
    DataProcess(/* args */);
    ~DataProcess();

    void process(Mat image);
};
}
