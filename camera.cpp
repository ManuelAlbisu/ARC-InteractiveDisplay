#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char *argv[]) {
    // capture video from camera
    cv::VideoCapture cap(0);

    // check if video stream has opened successfully
    if(!cap.isOpened()) {
        std::cout << "Error opening video stream or file" << std::endl;
        return -1;
    }

    while(true) {
        // capture frame-by-frame
        cv::Mat frame;
        cap >> frame;

        // checks if frame is empty
        if(frame.empty())
            break;

        // display the resulting frame
        cv::imshow("Video Stream", frame);

        // Press ESC to kill video stream
        char c = (char)cv::waitKey(25);

        if(c == 27)
            break;
    }

    // release the video capture when done
    cap.release();

    // closes all frames
    cv::destroyAllWindows();
    return 0;
}
