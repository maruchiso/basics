#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <unordered_map>
#include <vector>
#include <math.h>
#include <map>
//20	314910	Mo2	Ar1


void ar1(cv::Mat img) {
	//mapujemy ze sob¹ intensywnoœæ (0 - 255) i czêstoœæ z jak¹ wystêpuj¹ piksele o danej wartoœci intensywnoœci
	std::unordered_map<int, int> histogram;
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			int intensity = static_cast<int>(img.at<uchar>(i, j));
			histogram[intensity]++;
		}
	}
	for (const auto& row : histogram) {
		std::cout << row.first << ", " << row.second << std::endl;
	}
	std::cout << "------------------" << std::endl;
	//probability of occurance of a pixel
	std::unordered_map<int, int> cdf;
	int sum = 0;
	//print probability
	for (auto& row : histogram) {
		row.second = round(row.second / 256);
		sum += row.second;
		
		std::cout << row.first << ", " << row.second << std::endl;
		
	}
	std::unordered_map<int, int> equalized_histogram;


}
class 
void equalization_histogram(cv::Mat img) {

}
int main() {
	
	std::string path = "C:/Users/marcin/Desktop/na insta dêbki23/IMG_9903.png";
	cv::Mat img = cv::imread(path, cv::IMREAD_GRAYSCALE);
	//cv::resize(img, img, { 512, 512 }, 0, 0, cv::INTER_NEAREST);
	ar1(img);
	//cv::imshow("Image", img);
	//cv::waitKey(0);
	
	
	return 0;
}
