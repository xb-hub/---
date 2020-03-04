#include "../include/data_process.h"
using namespace data_process;
using namespace cv;
using namespace std;

int main()
{
    Mat image = imread("../image/num.png", IMREAD_GRAYSCALE);
    DataProcess* Process = new DataProcess();
    Process->process(image);
}