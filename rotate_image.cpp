#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat input_image = imread("input.jpg");

    if (input_image.empty())
    {
        cerr << "error while loading the image " << endl;
        return -1;
    }

    // getting the size of input image
    int m = input_image.rows;
    int n = input_image.cols;

    Mat output_image(n, m, CV_8UC3);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            output_image.at<Vec3b>(j, m - 1 - i) = input_image.at<Vec3b>(i, j);
        }
    }

    imwrite("output.jpg", output_image);

    cout << "image is rotated successfully" << endl;

    return 0;
}