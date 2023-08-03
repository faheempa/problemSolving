#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <curl/curl.h>

using namespace std;

// This function is used to get the data from Google about a given string.
// The function takes the string as a parameter and returns a vector of strings.
vector<string> get_data_from_google(string str)
{
    // Create a curl object.
    CURL *curl = curl_easy_init();

    // Set the URL to the Google search engine.
    curl_easy_setopt(curl, CURLOPT_URL, "https://www.google.com/search?q=" + str);

    // Set the user agent.
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/99.0.4844.51 Safari/537.36");

    // Set the maximum number of redirects.
    curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 5);

    // Set the follow location flag.
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);

    // Set the write function.
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_cb);

    // Set the write data.
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);

    // Execute the curl request.
    curl_easy_perform(curl);

    // Get the data from the curl object.
    vector<string> data = get_data_from_curl(curl);

    // Free the curl object.
    curl_easy_cleanup(curl);

    // Return the data.
    return data

}

int int main(int argc, const char** argv) {
    // Get the data from Google.
    vector<string> data = get_data_from_google("Hello World");
    // print it
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << endl;
    }
    return 0;
}