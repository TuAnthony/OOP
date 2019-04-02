In this practice I implemented a JSON data structure using inheritance and borrowed from Andrew Sutton repository which
we are allowed to do for the json.cpp and json.hpp. I wrote a program that accepted JSON input from any reddit as standard
input and printed the title and the author of each post in the content of the subreddit. I also built a list of post objects
and printed them. I had to design and implenement a model of reddit post using data structures.

I created a reddit class that contained struct called post which was required and its main purpose is to have the information
from each reddit post such as the author name, title, upvotes, downvotes, and the amount of comment inthe post. In my main I gathered
information from JSON text file and stored it in vectors for post objects. After that I printed the data from the required vectors and
displayed it. (Which we were required to do)

The source code of JSON.cpp and JSON.hpp were provided by Andrew Sutton the instructor and I was allowed to use it for this practice
assignment based on permission given from the instructions.