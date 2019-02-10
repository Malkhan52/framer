#include <opencv2/opencv.hpp>
#include <iostream>
#include <boost/lexical_cast.hpp>
#include <string>
 
using namespace std;
using namespace cv;
 
int main(int argc,char* argv[]){
  int count = -1;
  //cout<<argv[1]<<endl;
  VideoCapture cap(argv[1]);
  namedWindow("Frame",WINDOW_AUTOSIZE); 
    
   if(!cap.isOpened()){
   cout << "Error opening video stream or file" << endl;
   return -1;
  }
  Mat frame;   
  while(1){
 
    char c;
	waitKey(1);
	
    	c = getchar();
	cout<<c<<endl;//getchar();
    if(c=='s'){
	    cap >> frame;   
   
    if (frame.empty())
      break;
 
    imshow("Frame", frame );
    count++;
	string str = boost::lexical_cast<string>(count);
	string name = "frame_" + str + ".png";
	//cout<<"Writing"<<endl;
        imwrite(argv[2] + name, frame);	
	//cout<<"Writen"<<endl;
    }
    else if(c==27){
	break;
    }
    else if(c=='p'){
        cap>>frame;
	if (frame.empty())
      break;
 
    imshow("Frame", frame );
//    waitKey(1);
    }		
  }
    
  cap.release();
 
  destroyAllWindows();
     
  return 0;
}
