//main.cpp
//Rodolfo Lamug
//rlamug

#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include "video.h"

using namespace std;

const int MAX = 100; //Max number of videos allowed in the array
Video *vids[MAX]; //Array of pointers to videos to store the videos

int main(){

        string title, url, comment, order;
        float length;
        int rating, videoCount = 0;

        getline(cin, order);
        //Need to use getline because cin >> string will not work.
        while(getline(cin,title)){
                if (videoCount == MAX){ //Prints out error message if the user tries to specify more than 100 videos
                        cerr << "Too many videos, giving up." << endl;
                        return 1;
                }
                getline(cin,url);
                getline(cin, comment);
                cin >> length;
                cin >> rating;
                cin.ignore(); //Gets rid of extra line feed before reading the next description and prevents getline from reading an empty line
                vids[videoCount] = new Video(title, url, comment, length, rating); //Creates a new Video object
                videoCount++;
        }

        if (order == "rating"){ //Orders videos by rating using the bubble sort algorithm if user inputs "rating"
                for (int last = videoCount - 1; last > 0; last--)
                        for(int curr = 0; curr < last; curr++)
                                if(vids[curr] -> stars(vids[curr + 1]))
                                        swap(vids[curr], vids[curr + 1]);
                for (int i = 0; i < videoCount; i++)
                {
                        vids[i] -> print();
                }
        }

        else if (order == "length"){ // Orders videos by length using the bubble sort algorithm if user inputs "length"
                for (int last = videoCount - 1; last > 0; last--)
                        for (int curr = 0; curr < last; curr++)
                                if (vids[curr] -> longer(vids[curr + 1]))
                                        swap(vids[curr], vids[curr + 1]);
                for (int i = 0; i < videoCount; i++)
                {
                        vids[i] -> print();
                }
        }

        else if (order == "title"){ //Orders videos by length using the bubble sort algorithm if user inputs "title"
                for(int last = videoCount -1; last > 0; last--)
                        for(int curr = 0; curr < last; curr++)
                                if(vids[curr] -> alphabet(vids[curr + 1]))
                                        swap(vids[curr], vids[curr + 1]);
                for(int i = 0; i < videoCount; i++)
                { 
                        vids[i] -> print();
                }
        }

        else { //If user types in invalid order type, this prints out error message and terminates the program
                cerr << order << " is not a legal sorting method, giving up." << endl;
                return 1;
        }

        return 0;
}
