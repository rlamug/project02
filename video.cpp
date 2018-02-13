// video.cpp
// Rodolfo Lamug
// rlamug

#include "video.h"
#include <iostream>
#include <string>

using namespace std;

Video::Video (string title, string url, string comment, float length, int rating){
        m_title = title;
        m_url = url;
        m_comment = comment;
        m_length = length;
        m_rating = rating;
}
//function that prints the videos
void Video::print(){
        cout << m_title << ", " << m_url << ", " << m_comment << ", " << m_length << ", ";
        for (int r = m_rating; r > 0; r--){
                cout << "*";
        }
        cout << endl;
}
//function that returns true if the current video is longer than the given video (other) and false if it is not
bool Video::longer (Video *other){
        return m_length > other -> m_length;
}
//function that returns true if the current video's rating is shorter than the given video (other) and false if it is not
bool Video::stars (Video *other){
        return m_rating < other -> m_rating;
}
//function that returns true if the current video's title is alphanumerically greater than the given video (other) and false if it is not
bool Video::alphabet (Video *other){
        return m_title > other -> m_title;
}
