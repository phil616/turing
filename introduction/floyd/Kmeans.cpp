#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

std::vector<std::string> string_split(std::string str, std::string pattern)
{
	std::string::size_type pos;
	std::vector<std::string> result;
	str += pattern;
	int size = str.size();

	for(int i = 0; i < size; i++)
    {
		pos = str.find(pattern, i);
		if(pos < size)
        {
			std::string s = str.substr(i, pos - i);
			result.push_back(s);
			i = pos + pattern.size() - 1;
		}
	}
	return result;
}

double strDouble(string str){
    char *ch = new char[0];
    double d;
    for (int i = 0;i != str.length(); i++)
    {
        ch[i] = str[i];
    }
    d = atof(ch);
    return d;
}

class Cluster
{
    

};

class Iris
{
public:
    Iris(string path){
        ifstream ifs;
        ifs.open(path,ios::in);
        string line;
        vector<string> lines;
        while(getline(ifs,line))
        {
            lines.push_back(line);
        }
        ifs.close();
        vector<string> rets;
        this->length = lines.size();
        for(int i = 0;i < lines.size(); i++)
        {
            rets = string_split(lines[i],",");
            line1.push_back(strDouble(rets[0]));
            line2.push_back(strDouble(rets[1]));
            line3.push_back(strDouble(rets[2]));
            line4.push_back(strDouble(rets[3]));
            type.push_back(rets[4]);
        }
    };

    string target_file_path;

    vector<string> type;
    vector<double> line1;
    vector<double> line2;
    vector<double> line3;
    vector<double> line4;
    int length;

    void add()

};



int main(){
    string filePath;
    //cin >> filePath;
  //  Iris iris = Iris(filePath)
    vector<int> p;

}