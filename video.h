// video.h
// Rodolfo Lamug
// rlamug

#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
#include <string>

using namespace std;

class Video
{
        public:
                Video(string title, string url, string comment, float length, int rating);
                void print();
                bool longer(Video *other);
                bool stars(Video *other);
                bool alphabet(Video *other);

        private:
                string m_title, m_url, m_comment;
                float m_lenght;
                int m_rating;
};
#endif
