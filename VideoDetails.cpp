#include "VideoDetails.h"
using namespace std;
VideoDetails::VideoDetails(std::string &filename)
{

	if (filename.empty())
	{
		printf("open camera to take frames!");
		_file.open(0);
	}
	else
	{
		_file.open(filename);
		_fps = (int)_file.get(CAP_PROP_FPS);
	}

	_width =  _file.get(CAP_PROP_FRAME_WIDTH);
	_height = _file.get(CAP_PROP_FRAME_HEIGHT);
	_frameNum = _file.get(CAP_PROP_FRAME_COUNT);

	/* Return to the beginning */
	_file.set(CAP_PROP_POS_FRAMES, 0);
	_file.read(_frame);
	cout<<"video fps = "<<_fps<<endl;
}
VideoDetails::~VideoDetails()
{
	_file.release();
	if (writer_create==true){
		writer_frame->release();
	}
};

void VideoDetails::VideoWriter_Initial(Ptr<IVideoWriter> writer, std::string& filename, int fps)
{
	int AviForamt = 0;
	//int fps = 60; // or 25 
    cv::Size2i AviSize( _width,_height);
	int AviColor = 1; //0: binary  1:color
	VideoWriter( filename, VideoWriter::fourcc('M', 'J', 'P', 'G'),fps,AviSize,AviColor);
	writer_create = true;
}