/**
    CS-11 Asn 2, main.cpp
    Purpose: EXAMPLE - Blob Detection Using OpenCV

    @author Mac-FF kmlajceps@gmail.com
    @version 1.1 01/06/17
*/

#include <opencv2/core/core.hpp>
#include "opencv2/opencv.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <glob.h>
#include <string>
#include <vector>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

std::vector<std::string> glob(const std::string & path);
void printErn(const std::string & text);
void detectBlob(const std::string & path);

int main()
{
    std::string path = "sample/*.jpg";
    std::vector<std::string> paths = glob(path);
    if(!paths.empty())
        for_each(paths.begin(), paths.end(), detectBlob);
    else
        printErn(path);
    return 0;
}
std::vector<std::string> glob(const std::string & path)
{
    glob_t glob_result;
    glob(path.c_str(), GLOB_TILDE, NULL, & glob_result);
    std::vector<std::string> ret;
    for(unsigned int i = 0; i < glob_result.gl_pathc; i++)
        ret.push_back(std::string(glob_result.gl_pathv[i]));
    globfree(& glob_result);
    return ret;
}

void printErn(const std::string & text)
{
    std::cout << "ERROR: Cannot load file as image: " << text << std::endl;
}

void detectBlob(const std::string & path)
{
    cv::Mat image = cv::imread(path, CV_LOAD_IMAGE_GRAYSCALE |
                               CV_LOAD_IMAGE_ANYDEPTH);
    if(!image.empty())
    {
        std::vector<cv::KeyPoint> keypoints;
        cv::SimpleBlobDetector::Params params;
        cv::SimpleBlobDetector detector(params);
        detector.detect(image, keypoints);
        cv::drawKeypoints( image, keypoints, image, cv::Scalar(0,0,255),
                          cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS );
        std::string newPath = fs::basename(path) + "_blob" + fs::extension(path);
        cv::imwrite(newPath, image);
        std::cout << "Create image: " << newPath << std::endl;
    }
    else printErn(path);
}
