#include<iostream>
#include <vector>
#include <fstream>
#include <functional>
#include <memory>
#include <filesystem>

using namespace std;

auto recursiveGetFileNamesByExtension = [](const filesystem::path& path, const string& extension) {
    vector<string> fileNames;
    
    for (const auto& p : filesystem::recursive_directory_iterator(path)) {
        if (p.is_regular_file() && p.path().extension() == extension) {
            fileNames.push_back(p.path().filename().string());
        }
    }
    
    return fileNames;
};

int main()
{


string path = "D:\\dir1";
string extension = ".txt";
    
vector<string> fileNames = recursiveGetFileNamesByExtension(path, extension);
    
for (const auto& fileName : fileNames) {
        cout << fileName << endl;
    }


return 0;

}