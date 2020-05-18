#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
    cv::Mat img1, img2;
    cv::namedWindow("Example 1", cv::WINDOW_AUTOSIZE);
    img1 = cv::imread(argv[1]);
    cv::imshow("Example 1", img1);
    cv::pyrDown(img1, img2);
    cv::imshow("Example 2", img2);
    cv::waitKey(0);
    return 0;
}