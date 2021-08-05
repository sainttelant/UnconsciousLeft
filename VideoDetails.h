#ifndef _VIDEO_DETAILS_H_
#define _VIDEO_DETAILS_H_

#include "opencvheader.h"
#include <opencv2/videoio.hpp>
#include <string.h>
using namespace cv;

class VideoDetails
{
public:
	VideoDetails(std::string& filename);
	~VideoDetails();

	void VideoWriter_Initial(Ptr<IVideoWriter> writer ,std::string& filename, int fps);
	VideoWriter *writer_frame; 
	VideoWriter *writer_GMM; 
	VideoWriter *writer_Diff3; 
	VideoWriter *writer_Foreground; 

	bool writer_create;

	int _currentFrame;  //record current frame
	int _frameNum;      //record total frame number
	int _fps;
	VideoCapture _file;
	Mat _frame;
	char _videoName[50];
	double _width;
	double _height;

};
#endif
