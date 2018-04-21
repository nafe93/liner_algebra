#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;

vector<double> vector1 = {1,2,3};
vector<double> vector2 = {1,2,3};
vector<vector<double>> vector3 = {{3,2,1},{3,2,1}};
vector<double> result;
vector<double> result2;

/*
 *  easy function
 */
//sum two vectors
vector<double> sum_vector(vector<double> vec1,vector<double> vec2)
{
    vector<double> results;
    transform(vec1.begin(), vec1.end(),
              vec2.begin(),
              back_inserter(results),
              [](double i , double j) { return i+j;});
    return results;
}
//min two vectors
vector<double> subtract_vector(vector<double> vec1,vector<double> vec2)
{
    vector<double> results;
    transform(vec1.begin(), vec1.end(),
              vec2.begin(),
              back_inserter(results),
              [](double i , double j) { return i-j;});
    return results;
}
//const * vector
vector<double> scaler_multiply(vector<double> vec1, double constant)
{
    for(auto i = vec1.begin(); i != vec1.end(); i++)
    {
        *i = *i * constant;
    }
    return vec1;
}
//scolar multiplication two vectors
double dot(vector<double> vec1,vector<double> vec2)
{
    vector<double> results;
    transform(vec1.begin(),vec1.end(),
              vec2.begin(),
              back_inserter(results),
              [](double i, double j){ return i * j;});
    double sum_of_elems = 0;
    for_each(results.begin(),results.end(), [&](double n){
        sum_of_elems += n;
    });
    return sum_of_elems;
}
//square of vector this parametr get the size of vector
double sum_of_squares(vector<double> vec1)
{
    return dot(vec1,vec1);
}
//magnitude of vectors
double magnitude(vector<double> vec)
{
    return sqrt(sum_of_squares(vec));
}
//square distance between two vectors
double  squared_distance(vector<double> vec1,vector<double> vec2)
{
    return sum_of_squares(subtract_vector(vec1,vec2));
}
//distance between two vectors
double distance_vector(vector<double> vec1,vector<double> vec2)
{
    return sqrt(squared_distance(vec1,vec2));
}
/*
 *  complex function
 */
//work with array of vectors (sum) and (min)
vector<double> operator_vectors(vector<vector<double>> vectors, const char* operators)
{
    vector<double>result = vectors[0];
    double i = 1;
    if(operators == "sum")
    {
        for(vector<double> j = vectors[i]; i < vectors.size(); i++)
        {
            result = sum_vector(result,j);
        }
    }else if(operators == "min")
    {
        for(vector<double> j = vectors[i]; i < vectors.size(); i++)
        {
            result = subtract_vector(result,j);
        }
    }
    return result;
}
//arithmetic mean of array elements
vector<double> vector_mean(vector<vector<double>>vectors)
{
    double n = vectors.size();
    return scaler_multiply(operator_vectors(vectors, "sum"),(1/n));
}


int main()
{
    std::cout << "Hello, World!" << std::endl;

    result = sum_vector(vector1,vector2);

    result2 = operator_vectors(vector3, "sum");

    double _dot = magnitude(vector1);

        cout<< _dot << endl;

//    cout << result2[0] << endl;
//
//    cout << result[1] << endl;

    cout << "===" << vector_mean(vector3)[0] << endl;

//    cout << ":::" << scaler_multiply(vector1,5)[2] << endl;

    return 0;
}