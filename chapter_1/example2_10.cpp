#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv) {
    cv::namedWindow("Example2_11", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Log_Polar", cv::WINDOW_AUTOSIZE);

    cv::VideoCapture capture;
    capture.open(0);

    double fps = capture.get(cv::CAP_PROP_FPS);
    cv::Size size(
        (int)capture.get(cv::CAP_PROP_FRAME_WIDTH),
        (int)capture.get(cv::CAP_PROP_FRAME_HEIGHT)
    );
    
    cv::Mat logpolar_frame, bgr_frame;

    for(;;) {
        
        if (bgr_frame.empty()) break;  
        cv::imshow("Example2_11", bgr_frame);
        cv::logPolar(
            bgr_frame,
            logpolar_frame,
            cv::Point2f(
                bgr_frame.cols / 2,
                bgr_frame.rows / 2  
            ),
            40,
            cv::WARP_FILL_OUTLIERS
        );

        cv::imshow("Log_Polar", logpolar_frame);
        char c = cv::waitKey(10);
        if (c == 27) break;
    }
    capture.release();
}