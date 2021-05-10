#include <iostream>
#include <map>
#include <string>

class UserMap
{
    private:
        struct u_data_container
        {
            double u_max;
            double u_min;
            double u_sum;
            int u_count;
        } u_data;
        std::map<std::string, u_data_container> u_map;
        int name_count = 0, globe_count = 0;
        double globe_sum = 0;
        double globe_min, globe_max;
        
    public:
        void Update(const std::string&, double);
        int Display() const;
};

void UserMap::Update(const std::string &u_name, double u_value)
{
    if (!globe_count) {
        globe_min = u_value;
        globe_max = u_value;
    }
    else {
        if (u_value < globe_min) {
            globe_min = u_value;
        }
        else if (u_value > globe_max) {
            globe_max = u_value;
        }
    }
    globe_count++;
    globe_sum += u_value;

    // I'm not very sensitive yet with the efficiency of trees and I'll seek chance
    // to improve my algorithm.
    std::map<std::string, u_data_container>::iterator i = u_map.find(u_name);
    if (i == u_map.end()) {
        name_count++;
        u_data = {u_value, u_value, u_value, 1};
        u_map.insert(std::make_pair(u_name, u_data));
    }
    else {
        if (u_value < i -> second.u_min) {
            i -> second.u_min = u_value;
        }
        else if (u_value > i -> second.u_max) {
            i -> second.u_max = u_value;
        }
        i -> second.u_sum += u_value;
        i -> second.u_count++;
    }
}

int UserMap::Display() const
{
    for (std::map<std::string, UserMap::u_data_container>
        ::const_iterator i = u_map.begin();
        i != u_map.end(); i++) {

        std::cout << i -> first << ":\n"
            << "minimum - " << i -> second.u_min << '\n'
            << "maximum - " << i -> second.u_max << '\n'
            << "average - " << i -> second.u_sum
                /i -> second.u_count << '\n';
        if (!std::cout) // Fixed the mistake.
        {
            return 1;
        }
    }
    std::cout << "\nNumber of names: " << name_count << '\n'
        << "Global minimum: " << globe_min << '\n'
        << "Global maximum: " << globe_max << '\n'
        << "Global average: " << globe_sum/globe_count
        << '\n';
    if (!std::cout) {
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    UserMap map_obj;
    std::string input_str;
    double input_double;
    
    while (std::cin >> input_str >> input_double) {
        map_obj.Update(input_str, input_double);
    }
    if (!std::cin.eof()) {
        return 1;
    }
    if (!map_obj.Display()) {
        return 0;
    }
    else {
        return 1;
    }
}
