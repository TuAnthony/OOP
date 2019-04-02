//Anthony Tung
//OOP Practice 6

#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include "reddit.h"
#include "json.h"

int main()
{
    std::string fileName;
    std::ifstream inFile;
    std::cout << "Please enter a json file" << std::endl;
    std::cin >> fileName;
    inFile.open(fileName);
    if(!inFile.is_open())
    {
        std::cout << "Error cannot open file.";
    }
    else
    {
        std::string data;
        Post post;
        std::vector<Post> postVec;
        int postNum = 0;
        while(inFile >> data)
        {
            //get author
            if(data == "Author:")
            {
                inFile >> data;
                data.erase(0,1);
                data.erase(data.length()-2,2);
                post.author = data;

                postVec.push_back(post);
                postNum++;
            }
            //obtains the title
            if(data == "Title:")
            {
                inFile >> data;
                while(data.back() != '"')
                {
                    data += inFile.get();
                }
                post.title = data;
            }
            //obtains the upvotes
            if(data == "upvotes:")
            {
                inFile >> data;
                while(data.back() != '"')
                {
                    data += inFile.get();
                }
                post.upvotes = atoi(data.c_str());
            }
            //obtain the downvotes
            if(data == "downvotes:")
            {
                inFile >> data;
                while(data.back() != '"')
                {
                    data += inFile.get();
                }
                post.downvotes = atoi(data.c_str());
            }
            //obtain the number of comments
            if(data == "number of comments:")
            {
                inFile >> data;
                while(data.back() != '"')
                {
                    data += inFile.get();
                }
                post.numOfComments = atoi(data.c_str());
            }
        }

        for(int i = 0; i < postVec.size(); i++)
        {
            std::cout << postVec[i].author << " posted " << postVec[i].title << std::endl;
            std::cout << "Upvotes: " << postVec[i].upvotes << " Downvotes: " << postVec[i].downvotes << " Number of Comments: " << postVec[i].numOfComments << std::endl << std::endl;
        }
    }
}
