#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <string>
#include <iostream>
#include "AudioFile.h"
#include "detect.h"
using namespace cv;
using namespace std;

int main (int argc, const char *argv[])
{
    Mat video_stream;
    VideoCapture cap(0);
    namedWindow("Facial Detection");

    string classifier_loc = "/usr/share/opencv4/haarcascades/haarcascade_frontalface_alt.xml"; 
    CascadeClassifier face_cascade;
    face_cascade.load(classifier_loc);

    vector<Rect> faces;

    AudioFile audio_file("look_at_me.wav");

    int empty_frame_count = 0;
    while (true)
    {
        face_cascade.detectMultiScale(video_stream, faces, 1.1, 4, CASCADE_SCALE_IMAGE, Size(30, 30));
        cap.read(video_stream);
        
        if (faces.empty())
        {
            cout << "No faces detected" << endl;
            empty_frame_count++;
            if (empty_frame_count % 10 == 0)
            {
                cout << "Playing audio" << endl;
                audio_file.play();
            }
        } else {
            empty_frame_count = 0;
        }


        for (Rect face : faces)
        {
            Mat faceROI = video_stream(face);
            rectangle(video_stream, face, Scalar(255, 0, 0), 2, 8, 0);
        }

        imshow("Facial Detection", video_stream);
        if (waitKey(10) == 27) break;
    }
    return 0;
}
