#include "../include/creat_template.h"

using namespace std;
using namespace creat_template;

int main()
{
    Kind kind = MNIST;
    // Kind kind = OWN;
    CreatTemplate* creat_template = new CreatTemplate(kind);
    creat_template->create();
}