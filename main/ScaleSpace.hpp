#pragma once

#include <cv.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <vector>

#include "Octave.hpp"
class ScaleSpace {
private:
	std::vector <Octave*> mOctaves;
	OctaveFactory* mpOctaveFactory;
	BlurrerFactory* mpBlurrerFactory;
public:
	ScaleSpace(OctaveFactory* pOctaveFactory, BlurrerFactory* pBlurrerFactory) {
		mpOctaveFactory = pOctaveFactory;
		mpBlurrerFactory = pBlurrerFactory;
	}
	void readImage(cv::Mat* pImage, int numberOfOctaves) {
		cv::Mat image = *pImage;
		for(int i = 0; i != numberOfOctaves; ++i) {
			Blurrer* pBlurrer = mpBlurrerFactory->createBlurrer(
				&image,
				mpOctaveFactory
			);
			mOctaves.push_back(pBlurrer->evaluateOctave(5));
			cv::Mat resizedImage;
			resize(image, resizedImage, cv::Size(0,0), 0.5, 0.5);
			image = resizedImage;
			//TODO Sort the constants out (Dependecy Injection)
			//TODO No hardcoding
		}
	}
};
