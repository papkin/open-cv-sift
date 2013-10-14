#pragma once

#include <vector>
#include <opencv2/imgproc/imgproc.hpp>

#include "OctaveFactory.hpp"

const double sigma = 0.707;

class Blurrer {
private:
	cv::Mat* mpImage;
	OctaveFactory* mpOctaveFactory;
public:
	Blurrer(cv::Mat* pImage, OctaveFactory* pOctaveFactory) {
		this->mpImage = pImage;
		this->mpOctaveFactory = pOctaveFactory;
	}
	Octave* evaluateOctave(int octaveSize) {
		cv::Mat image = *mpImage;
		std::vector < cv::Mat > * pLaplaciansOfGaussians = new std::vector <cv::Mat>();
		for(int i = 0; i != octaveSize; ++i) {
			cv::Mat blurredImage;
		 	GaussianBlur(image, blurredImage, cv::Size(0,0), sigma);
		 	pLaplaciansOfGaussians->push_back((blurredImage-image) * sigma * (i+1) );
			image = blurredImage;
		}
		return mpOctaveFactory->createOctave(pLaplaciansOfGaussians);
	}
};
