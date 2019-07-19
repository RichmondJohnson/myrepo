#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include <string>
#include <cstddef>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    std::map<std::string, std::string> tagMap;
    std::vector<std::string> trackVec;
    std::string headerStr = "";
    std::string inputLine;

    int num_tags, num_queries;
    std::cin >> num_tags;
    std::cin >> num_queries;

    std::getline(std::cin, inputLine);

    for(int iter = 0; iter < num_tags; iter++)
    {
        std::string sendStr;
        std::string tagStr;
        std::string keyStr, valueStr;
        std::getline(std::cin, inputLine);
        stringstream ss(inputLine);
        char dummyChar;
        ss >> dummyChar;

        if((inputLine[0] == '<') && (inputLine[1] == '/'))
        {
            ss >> dummyChar;
            ss >> sendStr;
            std::string::iterator i = sendStr.end() - 1; *i = '\0';
            // std::cout << sendStr << std::endl;
            std::size_t found = headerStr.rfind('.');
            if (found != std::string::npos)
                headerStr.replace (found, 1, "\0");
            else
                headerStr = "";
        }
        else if(inputLine[0] == '<')
        {
            ss >> sendStr;
            tagStr = (headerStr == "") ? sendStr : headerStr + "." + sendStr;
            trackVec.push_back(tagStr);
            std::size_t found;
            for(ss >> sendStr;;)
            {
                // std::cout << sendStr << std::endl;
                keyStr = tagStr + "~" + sendStr;
                ss >> sendStr;
                if((ss >> sendStr) && (found = sendStr.find('>')) != std::string::npos)
                {
                    // std::cout << sendStr << std::endl;
                    break;
                }
                valueStr = sendStr;
                // std::cout << keyStr << valueStr << std::endl;
                tagMap.insert(std::pair<std::string, std::string>(keyStr, valueStr));
            }
            std::string::iterator i = sendStr.end() - 1; *i = '\0';
            // std::replace(sendStr.begin(), sendStr.end(), '"', (char)'');
            sendStr.erase(std::remove(sendStr.begin(), sendStr.end(), '"'), sendStr.end());
            valueStr = sendStr;
            // std::cout << keyStr << valueStr << std::endl;
            tagMap.insert(std::pair<std::string, std::string>(keyStr, valueStr));
            headerStr = (headerStr == "") ? tagStr : headerStr;
            // std::cout << keyStr << valueStr << headerStr << std::endl;
        }
        else
        {
            continue;
        }
    }

    for(int iter = 0; iter < num_queries; iter++)
    {
        std::string queryStr;
        std::getline(std::cin, queryStr);

// if ( m.find("f") == m.end() ) {
//   // not found
// } else {
//   // found
// }
        if(tagMap.find(queryStr) == tagMap.end())
            std::cout << "Not Found!\0" << "\n"; //std::endl;
        else
            std::cout << tagMap[queryStr] << "\n"; // std::endl;
    }

    return 0;
}
