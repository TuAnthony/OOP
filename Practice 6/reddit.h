//Anthony Tung
//OOP Practice 6

#ifndef REDDIT_H_INCLUDED
#define REDDIT_H_INCLUDED

struct Post
{
    int numComments;
    int upvotes;
    int downvotes;
    std::string title;
    std::string author;
};

#endif // REDDIT_H_INCLUDED
