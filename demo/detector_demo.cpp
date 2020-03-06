#include "../include/number_detector.h"

using namespace std;
using namespace number_detector;

int main()
{
    Kind kind = MNIST;
    // Kind kind = OWN;
    NumberDetector* number_detector = new NumberDetector(kind);
    number_detector->detector();
}