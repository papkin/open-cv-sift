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
	void generate(cv::Mat* pImage, int numberOfOctaves, int blursPerOctave) {
		cv::Mat image = *pImage;
		unsigned scaleDownFactor = 1;
		for(int i = 0; i != numberOfOctaves; ++i) {
			Blurrer* pBlurrer = mpBlurrerFactory->createBlurrer(
				&image,
				mpOctaveFactory
			);
			mOctaves.push_back(pBlurrer->evaluateOctave(blursPerOctave, scaleDownFactor));
			cv::Mat resizedImage;
			resize(image, resizedImage, cv::Size(0,0), 0.5, 0.5);
			image = resizedImage;
			scaleDownFactor *= 2;
		}
	}
	void getFeatures() {
		for(std::vector<Octave*>::iterator octaveIterator = mOctaves.begin(); octaveIterator != mOctaves.end(); ++octaveIterator) {
			(*octaveIterator)->getFeatures();
		}
	}
};
