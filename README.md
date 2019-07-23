# An example of linear regression using mlpack

Edited from https://www.youtube.com/watch?v=O_AlbzguUQQ

Linux support only.

### Presequisite:
    sudo apt install libmlpack-dev

### Build:
    mkdir build 
    cd build
    cmake ..
    make -j4

### Run
    ./make_data X_train.csv y_train.csv
    ./mlpack-linear-regression X_train.csv y_train.csv
