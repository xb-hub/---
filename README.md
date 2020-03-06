# 数字识别

- 开发环境 Ubuntu18.04

## 目录结构
```
.
└── 实验报告一
    ├── build                       //存放cmake编译中间文件
    ├── CMakeLists.txt              //cmake文件
    ├── demo
    │   ├── creat_demo.cpp          //用于创建模板文件
    │   ├── data_demo.cpp           //用于创建数据集和测试集
    │   └── detector_demo.cpp       //识别测试集数字图像
    ├── image
    │   ├── num.png
    │   ├── test_num                //存放测试图像
    │   │   ├── 0
    │   │   ├── 1
    │   │   ├── 2
    │   │   ├── 3
    │   │   ├── 4
    │   │   ├── 5
    │   │   ├── 6
    │   │   ├── 7
    │   │   ├── 8
    │   │   ├── 9 
    │   │   ├── creat_link.sh       //用于创建测试图像文件路径和标签的脚本
    │   │   └── link.txt            //图像文件路径和标签的文件
    │   └── train_num               //存放训练图像
    │       ├── 0
    │       ├── 1
    │       ├── 2
    │       ├── 3
    │       ├── 4
    │       ├── 5
    │       ├── 6
    │       ├── 7
    │       ├── 8
    │       ├── 9
    │       ├── creat_link.sh
    │       └── link.txt
    ├── include
    │   ├── creat_template.h
    │   ├── data_process.h
    │   └── number_detector.h
    ├── README.md
    ├── src
    │   ├── creat_template.cpp
    │   ├── data_process.cpp
    │   └── number_detector.cpp
    └── template                    //存放模板文件
        └── template.txt            //模板文件
```

## 编译步骤
```
-   mkdir build
-   cd build
-   cmake ..
-   make
```
## 运行步骤

### mnist数据集
```
通过脚步文件生成link.txt文件，此文件内每行保存图片路径和标签，运行后两个数据集文件夹内都会生成一个link.txt文本文件
- cd image/num_test
- bash ./creat_link.sh
- cd ../num_train
- bash ./creat_link.sh

通过运行creat_demo读取训练集制作模板文件，运行后将模板数据写入template/template.txt文件内，每行数据第一个字符为标签，往后为每个测试训练数据的模板
-   cd ../../build
-   ./creat_demo

读取测试集通过和模板文件匹配，找到最优标签输出，并和测试集内标签比较判断识别是否正确
-   ./detector_demo
```

### 使用自己的数据集
```
1.进入build执行data_process，分割图片生成训练集和测试集，执行脚本生成link.txt,往后步骤同minst数据集步骤
-  cd build
-  ./data_process
- cd image/own_test_num
- bash ./creat_link.sh
- cd ../own_train_num
- bash ./creat_link.sh
```