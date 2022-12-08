//computing volatility index using model free exponential moving average in C++

#include <iostream>
#include <vector>

double exponential_moving_average(std::vector<double> data, int n, double alpha);
double volatility_index(std::vector<double> data, int n, double alpha);

// Define a function to calculate the exponential moving average
double exponential_moving_average(std::vector<double> data, int n, double alpha)
{
    double ema = data[0];
    for (int i = 1; i < n; i++)
    {
        ema = alpha * data[i] + (1 - alpha) * ema;
    }
    return ema;
}

// Define a function to calculate the volatility index
double volatility_index(std::vector<double> data, int n, double alpha)
{
    double ema = exponential_moving_average(data, n, alpha);
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (data[i] - ema) * (data[i] - ema);
    }
    double volatility = sum / n;
    return volatility;
}

int main()
{
    // Declare a vector to store the stock prices
    std::vector<double> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Calculate the volatility index using model free exponential moving average
    double alpha = 0.5; // Define the smoothing factor
    int n = data.size(); // Get the size of the vector
    double vol_index = volatility_index(data, n, alpha);

    // Print the result
    std::cout << "The volatility index is: " << vol_index << std::endl;

    return 0;
}

// See also https://stackoverflow.com/questions/10990618/calculate-rolling-moving-average-in-c