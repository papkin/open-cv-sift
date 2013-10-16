#include <iostream>
#include <cv.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "Blurrer.hpp"
#include "OctaveFactory.hpp"
#include "Octave.hpp"
#include "BlurrerFactory.hpp"
#include "ScaleSpace.hpp"

int main(int argc, char* argv[]) {
	cv::Mat image = cv::imread(argv[1], 1);
	cvtColor(image, image, CV_BGR2GRAY);
	OctaveFactory* pOctaveFactory = new OctaveFactory();
	BlurrerFactory* pBlurrerFactory = new BlurrerFactory();
	ScaleSpace* pScaleSpace = new ScaleSpace(pOctaveFactory, pBlurrerFactory);
	pScaleSpace->generate(&image, 3, 5);
	pScaleSpace->getFeatures();
	return 0;
}
