#include<iostream>
#include<mlpack/core.hpp>
#include<mlpack/methods/linear_regression/linear_regression.hpp>

#include "define.h"

using namespace std;
using namespace mlpack;
using namespace arma;

int main(int argc, char** argv){
    if(argc<3) throw runtime_error("error : less no. of args passed");

    arma::mat  predictors, responses;

    cout << "load X_train: " << endl;
    data::Load(argv[1], predictors);
    cout << "size: "<<predictors.n_rows << " x " << predictors.n_cols << endl;
    cout << predictors << endl;
   
    cout << "load y_train: " << endl;
    data::Load(argv[2], responses);
    responses = responses.t();
    cout << "size: "<<responses.n_rows << " x " << responses.n_cols << endl;
    cout << responses << endl;
    
    cout << "Init regressor " << endl;
    regression::LinearRegression regressor;

    cout << "Train the regressor" << endl;
    regressor.Train(predictors, responses);
    arma::vec parameters = regressor.Parameters();
    cout << "Trainned parameter:" << endl;
    cout << parameters << endl;

    cout << "Test:" << endl;
    colvec3 point;
    point[0] = 10;
    point[1] = 20;
    point[2] = 0;

    arma::vec predictions;
    cout << "Make prediction" << endl;
    regressor.Predict(point, predictions);

    cout << "input:" << endl;
    cout << point << endl;
    cout << "prediction: " << predictions;
    cout << "expected ouput: " << BETA0 + BETA1*point[0] + BETA2*point[1] << endl;

    return EXIT_SUCCESS;
}