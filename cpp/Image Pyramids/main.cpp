/**
    CS-11 Asn 2, checks.cpp
    main.cpp
    Purpose: EXAMPLE - Use the OpenCV functions pyrUp and pyrDown
    to downsample or upsample a given image.

    @author Mac-FF kmlajceps@gmail.com
    @version 1.1 01/06/17
*/

#include <opencv2/core/core.hpp>
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
void pyrDownUp(const std::string & path);

int main()
{
    std::string path = "sample/*.jpg";
    std::vector<std::string> paths = glob(path);
    if(!paths.empty())
        for_each(paths.begin(), paths.end(), pyrDownUp);
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

void pyrDownUp(const std::string & path)
{
    cv::Mat image = cv::imread(path, CV_LOAD_IMAGE_ANYCOLOR | CV_LOAD_IMAGE_ANYDEPTH);
    if(!image.empty())
    {
        cv::pyrDown(image, image, cv::Size(image.cols / 2, image.rows / 2 ));
        cv::pyrUp(image, image, cv::Size(image.cols * 2, image.rows * 2 ));
        std::string newPath = fs::basename(path) + "_pyr" + fs::extension(path);
        cv::imwrite(newPath, image);
        std::cout << "Create image: " << newPath << std::endl;
    }
    else printErn(path);
}
