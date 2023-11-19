#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>
#include <math.h>
#include <map>

//20	314910	Mo2	Ar1

//TODO: -Algorytm gotowy, -poszczególne kana³y, -wybór ROI, -wersja adaptacyjna?
class Project1 {

	cv::Mat img;
	std::map<int, int> histogram;
	std::map<int, int> equlized_histogram;
	std::vector<double> cdf;

public:
	Project1(const std::string& path) {
		img = cv::imread(path, cv::IMREAD_GRAYSCALE);
		if (img.empty()) {
			std::cerr << "B³¹d: Nie uda³o siê wczytaæ obrazu." << std::endl;
			exit(EXIT_FAILURE);
		}
		else {
			print_original_image();

			calculate_histogram();
			print_histogram();

			calculate_cdf();
			histogram_equalization();

			calculate_histogram();
			print_histogram();

			print_equalized_image();
		}
	}

	void calculate_histogram() {

		for (unsigned int i = 0; i < img.rows; i++) {
			for (unsigned int j = 0; j < img.cols; j++) {
				int intensity = static_cast<int>(img.at<uchar>(i, j));
				histogram[intensity]++;
			}
		}

		for (int i = 0; i <= 255; ++i) {
			if (histogram.count(i) <= 0) {
				histogram[i] = 0;
			}
			
		}
	}

	void calculate_cdf() {

		double sum = 0.0;
		
		for (auto& row : histogram) {
			sum += row.second;
			cdf.push_back(sum);
		}

		//Normalize CDF
		for (double& x : cdf) {
			x /= sum;
		}
		
	}

	void histogram_equalization() {
		for (unsigned int i = 0; i < img.rows; i++) {
			for (unsigned int j = 0; j < img.cols; j++) {
				int intensity = static_cast<int>(img.at<uchar>(i, j));
				img.at<uchar>(i, j) = static_cast<uchar>(cdf[intensity] * 255.0);
			}

		}
	}

	void print_original_image() {
		cv::imshow("Original image", img);
		cv::waitKey(0);
	}

	void print_histogram() {
		std::cout << "Histogram:\n";
		for (auto& row : histogram) {
			std::cout << row.first << ", " << row.second << std::endl;
		}
		std::cout << std::endl << std::endl << std::endl;
	}
	void print_equalized_image() {
		cv::imshow("Equalized image", img);
		cv::waitKey(0);
		std::cout << "Histogram dla drugiego zdjecia: \n";
		
	}
};
int main() {

	//std::string path = "C:/Users/marcin/Desktop/na insta dêbki23/IMG_9903.png";
	std::string path = "C:/Users/marcin/Desktop/test.jpg";


	Project1 project(path);
	return 0;
}
